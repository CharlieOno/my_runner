/*
** EPITECH PROJECT, 2017
** my_runner
** File description:
** drawing sprites on the principal window
*/

#include "runner.h"

void	draw_hex(prog_t *prog, obj_t **sprite)
{
	if (prog->charac != 0)
		return;
	sf_draw(prog->window, sprite[4]->obj);
	sf_draw(prog->window, sprite[3]->obj);
	sf_draw(prog->window, sprite[5]->obj);
	sf_draw(prog->window, sprite[6]->obj);
}

void	draw_mitty(prog_t *prog, obj_t **sprite)
{
	if (prog->charac != 1)
		return;
	sf_draw(prog->window, sprite[7]->obj);
	sf_draw(prog->window, sprite[8]->obj);
	sf_draw(prog->window, sprite[9]->obj);
}

void	draw_rog(prog_t *prog, obj_t **sprite)
{
	if (prog->charac != 2)
		return;
	sf_draw(prog->window, sprite[10]->obj);
	sf_draw(prog->window, sprite[11]->obj);
}