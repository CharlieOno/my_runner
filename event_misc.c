/*
** EPITECH PROJECT, 2018
** my_runner
** File description:
** other menus event handling functions
*/

#include "runner.h"

void	win_events(prog_t *prog, sfEvent event)
{
	while (sfRenderWindow_pollEvent(prog->window, &event)) {
		if (event.type == sfEvtClosed)
			sfRenderWindow_close(prog->window);
		if (sfKeyboard_isKeyPressed(sfKeyReturn)) {
			sfSound_play(prog->sound[3]);
			prog->menu = 0;
		}
	}
}

void	cchoice_events(prog_t *prog, sfEvent event, int *select, int *selectd)
{
	while (sfRenderWindow_pollEvent(prog->window, &event)) {
		if (event.type == sfEvtClosed)
			sfRenderWindow_close(prog->window);
		if (navigation_menu_horizontal(&select, &selectd, 0, 2))
			sfSound_play(prog->sound[6]);
	}
}

void	mchoice_events(prog_t *prog, sfEvent event, int *select, int *selectd)
{
	while (sfRenderWindow_pollEvent(prog->window, &event)) {
		if (event.type == sfEvtClosed)
			sfRenderWindow_close(prog->window);
		if (navigation_menu_vertical(&select, &selectd, 0, 8))
			sfSound_play(prog->sound[6]);
		if (sfKeyboard_isKeyPressed(sfKeyEscape))
			prog->menu = 4;
	}
}