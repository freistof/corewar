/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fireworks.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcorke <rcorke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/11 18:54:55 by rcorke         #+#    #+#                */
/*   Updated: 2019/12/16 17:49:55 by rcorke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/vm.h"

static void	update_particle(size_t size, t_particle **particles)
{
	particle_update(particles[0], 0.01, size);
	particle_update(particles[1], 0.01, size);
	particle_update(particles[2], 0.01, size);
	particle_update(particles[3], 0.01, size);
}

static void	draw_particles(size_t size, t_particle **particles)
{
	particle_draw(particles[0], size);
	particle_draw(particles[1], size);
	particle_draw(particles[2], size);
	particle_draw(particles[3], size);
}

static void	check_and_init_particles(size_t size, t_particle **particles)
{
	if ((*particles)->life < 1.21 && (*particles)->life > 1.19)
		particle_init(particles[1], size);
	else if ((*particles)->life < 0.81 && (*particles)->life > 0.79)
		particle_init(particles[2], size);
	else if ((*particles)->life < 0.41 && (*particles)->life > 0.39)
		particle_init(particles[3], size);
	else if ((*particles)->life < 0.01)
		particle_init(particles[0], size);
}

static void	free_farticles(t_particle **particles)
{
	free(particles[0]);
	particles[0] = NULL;
	free(particles[1]);
	particles[1] = NULL;
	free(particles[2]);
	particles[2] = NULL;
	free(particles[3]);
	particles[3] = NULL;
	free(particles);
}

void		fireworks(t_game *game)
{
	struct timespec	interval;
	size_t			size;
	t_particle		**particles;

	WINDOW(*(window));
	window = initscr();
	init_values(window, &size, &interval);
	srand((unsigned)time(NULL));
	particles = alloc_and_init_particles(size);
	while (getch() != ' ')
	{
		check_and_init_particles(size, particles);
		erase();
		update_particle(size, particles);
		printw("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\
\t\t\t\t\t\t\t\t\tTHE WINNER IS %s [P%d]", \
		game->players[game->last_reported_live - 1]->name, \
		game->players[game->last_reported_live - 1]->id);
		draw_particles(size, particles);
		refresh();
		nanosleep(&interval, NULL);
	}
	free_farticles(particles);
	endwin();
}
