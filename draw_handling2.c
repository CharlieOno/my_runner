/*
** EPITECH PROJECT, 2018
** my_runner
** File description:
** draw handling functions part 2
*/

#include "runner.h"

void	draw_pressenter(prog_t *prog)
{
	sfText 	*text = sfText_create();
	sfFont	*font = sfFont_createFromFile("img/font.ttf");
	sfVector2f	pos = (sfVector2f) {230, 395};

	sfText_setCharacterSize(text, 40);
	sfText_setFont(text, font);
	sfText_setString(text, "Press [ENTER] to continue.");
	sfText_setPosition(text, pos);
	sfRenderWindow_drawText(prog->window, text, NULL);
}

void	cchoice_draw_obj(prog_t *prog, obj_t **sprite)
{
	parralax_right(sprite[2], prog->window, 0.011);
	parralax_right(sprite[1], prog->window, 0.033);
	parralax_right(sprite[0], prog->window, 0.066);
	sf_draw(prog->window, sprite[28]->obj);
	sf_pos(sprite[3]->obj, (sfVector2f) {160, 250});
	sf_pos(sprite[7]->obj, (sfVector2f) {360, 255});
	sf_pos(sprite[10]->obj, (sfVector2f) {580, 310});
	sf_draw(prog->window, sprite[3]->obj);
	sf_draw(prog->window, sprite[7]->obj);
	sf_draw(prog->window, sprite[10]->obj);
	draw_level(prog, sprite[3]);
	draw_lifebar(prog, sprite, sprite[3]);
	draw_level(prog, sprite[7]);
	draw_lifebar(prog, sprite, sprite[7]);
	draw_level(prog, sprite[10]);
	draw_lifebar(prog, sprite, sprite[10]);
	draw_pressenter(prog);
	sfRenderWindow_display(prog->window);
}

void	mchoice_draw_obj(prog_t *prog, obj_t **sprite, int select)
{
	parralax_right(sprite[2], prog->window, 0.011);
	parralax_right(sprite[1], prog->window, 0.033);
	parralax_right(sprite[0], prog->window, 0.066);
	sf_draw(prog->window, sprite[14]->obj);
	draw_mapselect(prog, select);
	sfRenderWindow_display(prog->window);
}