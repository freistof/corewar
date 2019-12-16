/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fireworks_utils.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcorke <rcorke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/16 17:43:32 by rcorke         #+#    #+#                */
/*   Updated: 2019/12/16 17:45:09 by rcorke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		particle_init(t_particle *p, size_t size)
{
	float	init_vel;
	float	col;
	size_t	i;
	uint8_t	init_color;

	init_vel = (((float)rand()) / ((float)RAND_MAX) * (-LINES) - (LINES / \
	(rand() % 4 + 1))) * 0.8;
	init_color = (uint8_t)(rand() % 8);
	col = rand() % COLS;
	i = 0;
	while (i < size)
	{
		p[i].pos[0] = (float)(LINES - 1);
		p[i].pos[1] = col;
		p[i].vel[0] = init_vel;
		p[i].vel[1] = 0.0;
		p[i].life = 1.6;
		p[i].color = init_color;
		p[i].exploded = FALSE;
		i++;
	}
}

/*
** updates particles positions, lifetimes, and velocities
*/

void		particle_update(t_particle *p, float dt, size_t size)
{
	size_t i;

	i = 0;
	while (i < size)
	{
		p[i].life -= dt;
		p[i].pos[0] += p[i].vel[0] * dt;
		p[i].pos[1] += p[i].vel[1] * dt;
		if (p[i].life < 0.76 && !p[i].exploded)
		{
			p[i].exploded = TRUE;
			p[i].center[0] = p[i].pos[0];
			p[i].center[1] = p[i].pos[1];
			p[i].vel[0] = ((float)rand() / (float)RAND_MAX) * 50 - 25;
			p[i].vel[1] = ((float)rand() / (float)RAND_MAX) * 100 - 50;
		}
		i++;
	}
}

/*
** draws particles onto display
*/

void		particle_draw(t_particle *p, size_t size)
{
	size_t	i;
	float	distance;

	attron(COLOR_PAIR(p[0].color));
	i = 0;
	while (i < size)
	{
		i++;
		if (p[i].life > 0.55 && p[i].life < 0.76)
			attron(A_BOLD);
		if (p[i].life < 0.2)
			attron(A_DIM);
		distance = sqrt(
			pow(p[i].pos[0] - p[i].center[0], 2) +
			pow((p[i].pos[1] - p[i].center[1]) * 0.6, 2));
		if (p[i].exploded && distance > 9.5)
			continue;
		mvaddch(p[i].pos[0], p[i].pos[1], 'o');
	}
	attroff(A_BOLD);
	attroff(A_DIM);
	attroff(COLOR_PAIR(p[0].color));
}

void		init_values(WINDOW *window, size_t *size, struct timespec *interval)
{
	start_color();
	cbreak();
	noecho();
	nodelay(window, TRUE);
	curs_set(0);
	init_pair(1, 7, 0);
	init_pair(2, 6, 0);
	init_pair(3, 5, 0);
	init_pair(4, 4, 0);
	init_pair(5, 3, 0);
	init_pair(6, 2, 0);
	init_pair(7, 1, 0);
	*size = 200;
	(*interval).tv_sec = 0;
	(*interval).tv_nsec = 25000000;
}

t_particle	**alloc_and_init_particles(size_t size)
{
	t_particle **all;

	all = (t_particle **)malloc(sizeof(t_particle *) * 4);
	all[0] = (t_particle *)calloc(sizeof(t_particle), size);
	all[1] = (t_particle *)calloc(sizeof(t_particle), size);
	all[2] = (t_particle *)calloc(sizeof(t_particle), size);
	all[3] = (t_particle *)calloc(sizeof(t_particle), size);
	particle_init(all[0], size);
	particle_init(all[1], size);
	particle_init(all[2], size);
	particle_init(all[3], size);
	return (all);
}
