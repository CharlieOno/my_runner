/*
** EPITECH PROJECT, 2017
** my_runner
** File description:
** key retrieving functions
*/

#include "runner.h"

int	navigation_menu_vertical(int **select, int **selected, int x, int y)
{
	if (sfKeyboard_isKeyPressed(sfKeyDown)) {
		**select += (**select < y) ? 1 : 0;
		return (1);
	}
	if (sfKeyboard_isKeyPressed(sfKeyUp)) {
		**select -= (**select > x) ? 1 : 0;
		return (1);
	}
	if (sfKeyboard_isKeyPressed(sfKeyReturn))
		**selected = 1;
	return (0);
}

int	navigation_menu_horizontal(int **select, int **selected, int x, int y)
{
	if (sfKeyboard_isKeyPressed(sfKeyRight)) {
		**select += (**select < y) ? 1 : 0;
		return (1);
	}
	if (sfKeyboard_isKeyPressed(sfKeyLeft)) {
		**select -= (**select > x) ? 1 : 0;
		return (1);
	}
	if (sfKeyboard_isKeyPressed(sfKeyReturn))
		**selected = 1;
	return (0);
}

void	pause_events(prog_t *prog, sfEvent event, int *select, int *selected)
{
	while (sfRenderWindow_pollEvent(prog->window, &event)) {
		if (event.type == sfEvtClosed)
			sfRenderWindow_close(prog->window);
		if (navigation_menu_horizontal(&select, &selected, 0, 1))
			sfSound_play(prog->sound[6]);
	}
}

void	game_events(prog_t *prog, obj_t **sprite, sfEvent event)
{
	while (sfRenderWindow_pollEvent(prog->window, &event)) {
		if (event.type == sfEvtClosed)
			sfRenderWindow_close(prog->window);
		if (sfKeyboard_isKeyPressed(sfKeyEscape)) {
			sfSound_play(prog->sound[1]);
			prog->menu = 2;
		}
		if (sfKeyboard_isKeyPressed(sfKeyReturn) &&
			prog->text[0] != 0) {
			prog->delay = 0;
			prog->text[0] = 0;
		}
		key_character(prog, sprite);
	}
}

void	menu_events(prog_t *prog, sfEvent event, int *select, int *selected)
{
	while (sfRenderWindow_pollEvent(prog->window, &event)) {
		if (event.type == sfEvtClosed)
			sfRenderWindow_close(prog->window);
		if (sfKeyboard_isKeyPressed(sfKeyEscape))
			sfRenderWindow_close(prog->window);
		if (navigation_menu_vertical(&select, &selected, 0, 3))
			sfSound_play(prog->sound[6]);
	}
}