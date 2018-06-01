/*
** EPITECH PROJECT, 2017
** my_runner
** File description:
** draw sprites handling functions
*/

#include "runner.h"

void	game_draw_obj(prog_t *prog, obj_t **sprite)
{
	draw_mob(prog, sprite);
	draw_hex(prog, sprite);
	draw_mitty(prog, sprite);
	draw_rog(prog, sprite);
	draw_level_hp(prog, sprite);
	draw_textbox(prog, sprite);
	draw_defeated(prog, sprite[37]);
	reload_anim(prog, sprite);
	sfRenderWindow_display(prog->window);
}

void	menu_draw_obj(prog_t *prog, obj_t **sprite, int select)
{
	parralax_right(sprite[2], prog->window, 0.111);
	parralax_right(sprite[1], prog->window, 0.333);
	parralax_right(sprite[0], prog->window, 0.666);
	sf_draw(prog->window, sprite[14]->obj);
	sf_draw(prog->window, sprite[15]->obj);
	sf_draw(prog->window, sprite[(select == 0) ? 16 : 17]->obj);
	sf_draw(prog->window, sprite[(select == 1) ? 18 : 19]->obj);
	sf_draw(prog->window, sprite[(select == 2) ? 20 : 21]->obj);
	sf_draw(prog->window, sprite[(select == 3) ? 22 : 23]->obj);
	sfRenderWindow_display(prog->window);
}

void	pause_draw_obj(prog_t *prog, obj_t **sprite, int select)
{
	parralax_right(sprite[2], prog->window, 0);
	parralax_right(sprite[1], prog->window, 0);
	parralax_right(sprite[0], prog->window, 0);
	sf_draw(prog->window, sprite[28]->obj);
	sf_draw(prog->window, sprite[24]->obj);
	sf_draw(prog->window, sprite[27]->obj);
	sf_draw(prog->window, sprite[(select == 0) ? 25 : 26]->obj);
	sfRenderWindow_display(prog->window);
}

void	win_draw_obj(prog_t *prog, obj_t **sprite)
{
	sfText 	*text = sfText_create();
	sfFont	*font = sfFont_createFromFile("img/font.ttf");
	sfVector2f	pos = (sfVector2f) {230, 350};

	parralax_right(sprite[2], prog->window, 0.011);
	parralax_right(sprite[1], prog->window, 0.033);
	parralax_right(sprite[0], prog->window, 0.066);
	sf_draw(prog->window, sprite[28]->obj);
	if (prog->state.win)
		sf_draw(prog->window, sprite[32]->obj);
	else
		sf_draw(prog->window, sprite[33]->obj);
	sfText_setCharacterSize(text, 40);
	sfText_setFont(text, font);
	sfText_setString(text, "Press [ENTER] to continue.");
	sfText_setPosition(text, pos);
	draw_defeated(prog, sprite[37]);
	sfRenderWindow_drawText(prog->window, text, NULL);
	sfRenderWindow_display(prog->window);
}