/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fireworks.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcorke <rcorke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/11 18:54:55 by rcorke         #+#    #+#                */
/*   Updated: 2019/12/11 19:34:15 by rcorke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/vm.h"

void	particle_init(particle *p, size_t size)
{
	float init_vel;
	float col;
	size_t i;
	uint8_t init_color;

	// pick random upward velocity
	init_vel = (((float) rand()) / ((float) RAND_MAX) * (-LINES) - (LINES / (rand() % 4 + 1))) * 0.8;

	// pick random color
	init_color = (uint8_t) (rand() % 8);

    // pick random starting column
	col = rand() % COLS;

	// initialize particles
	for (i = 0; i < size; ++i) {
		p[i].pos[0] = (float) (LINES - 1); // start particles at bottom
		p[i].pos[1] = col;
		p[i].vel[0] = init_vel;
		p[i].vel[1] = 0.0;
		p[i].life = 1.6;
		p[i].color = init_color;
		p[i].exploded = FALSE;
	}
}

/**
 * updates particles positions, lifetimes, and velocities
 */
void particle_update(particle *p, float dt, size_t size)
{
	size_t i;

	for (i = 0; i < size; ++i) {
		p[i].life -= dt;
		p[i].pos[0] += p[i].vel[0] * dt;
		p[i].pos[1] += p[i].vel[1] * dt;

		// check if time to explode
		if (p[i].life < 0.76 && !p[i].exploded) {
			p[i].exploded = TRUE;

			p[i].center[0] = p[i].pos[0];
			p[i].center[1] = p[i].pos[1];

			p[i].vel[0] = ((float) rand() / (float) RAND_MAX) * 50 - 25;
			p[i].vel[1] = ((float) rand() / (float) RAND_MAX) * 100 - 50;
		}
	}
}

/**
 * draws particles onto display
 */
void particle_draw(particle *p, size_t size)
{
	size_t i;

	// turn on color scheme
	attron(COLOR_PAIR(p[0].color));

	for (i = 0; i < size; ++i) {
		// display bright characters right after explosion
		if (p[i].life > 0.55 && p[i].life < 0.76)
			attron(A_BOLD);
		// display dim characters right before dying
		if (p[i].life < 0.2)
			attron(A_DIM);
		float distance = sqrt(
			pow(p[i].pos[0] - p[i].center[0], 2) +       // line
			pow((p[i].pos[1] - p[i].center[1]) * 0.6, 2) // column, scaled down
		);
		if (p[i].exploded && distance > 9.5)
			continue;
		// draw the character
		mvaddch(p[i].pos[0], p[i].pos[1], 'o');
	}

	// turn off color scheme
	attroff(A_BOLD);
	attroff(A_DIM);
	attroff(COLOR_PAIR(p[0].color));
}

void fireworks(t_game *game)
{
	WINDOW *window = initscr(); // initialize screen
	noecho();                   // don't display typed characters
	cbreak();                   // don't wait until RETURN is pressed
	nodelay(window, TRUE);      // don't wait for key press
	curs_set(0);                // make cursor invisible
	start_color();              // start color in terminal
	init_pair(1, 7, 0);         // White on black
	init_pair(2, 6, 0);         // Cyan on black
	init_pair(3, 5, 0);         // Magenta on black
	init_pair(4, 4, 0);         // Blue on black
	init_pair(5, 3, 0);         // Yellow on black
	init_pair(6, 2, 0);         // Green on black
	init_pair(7, 1, 0);         // Red on black
	struct timespec interval = { .tv_sec = 0, .tv_nsec = 25000000 };
	size_t size = 200;

	srand((unsigned) time(NULL));
	// reserve memory for particle array
	particle *p = (particle *) calloc(sizeof(particle), size);
	particle *q = (particle *) calloc(sizeof(particle), size);
	particle *r = (particle *) calloc(sizeof(particle), size);
	particle *s = (particle *) calloc(sizeof(particle), size);

	// initialize particle array
	particle_init(p, size);
	particle_init(q, size);
	particle_init(r, size);
	particle_init(s, size);

	// check for user input to quit program
	while (getch() != ' ')
	{
		if (p[0].life < 1.21 && p[0].life > 1.19)
			particle_init(q, size);
		else if (p[0].life < 0.81 && p[0].life > 0.79)
			particle_init(r, size);
		else if (p[0].life < 0.41 && p[0].life > 0.39)
			particle_init(s, size);
		else if (p[0].life < 0.01)
			particle_init(p, size);
		erase();
		particle_update(p, 0.01, size);
		particle_update(q, 0.01, size);
		particle_update(r, 0.01, size);
		particle_update(s, 0.01, size);
		printw("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tTHE WINNER IS: %s", game->players[game->last_reported_live - 1]->name);
		particle_draw(p, size);
		particle_draw(q, size);
		particle_draw(r, size);
		particle_draw(s, size);
		refresh();
		nanosleep(&interval, NULL);
    }

	free(p);
	p = NULL;
	free(q);
	q = NULL;
	free(r);
	r = NULL;
	free(s);
	s = NULL;

	endwin();
}
