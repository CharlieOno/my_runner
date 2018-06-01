/*
** EPITECH PROJECT, 2018
** my_runner
** File description:
** misc draw functions - parallax + mob
*/

#include "runner.h"

void	alpha_characters(obj_t **sprite, int select)
{
	sfColor	color = (sfColor) {255, 255, 255, 127};
	sfColor	color2 = (sfColor) {255, 255, 255, 255};

	if (select == 0) {
		sfSprite_setColor(sprite[3]->obj, color2);
		sfSprite_setColor(sprite[7]->obj, color);
		sfSprite_setColor(sprite[10]->obj, color);
	}
	if (select == 1) {
		sfSprite_setColor(sprite[3]->obj, color);
		sfSprite_setColor(sprite[7]->obj, color2);
		sfSprite_setColor(sprite[10]->obj, color);
	}
	if (select == 2) {
		sfSprite_setColor(sprite[3]->obj, color);
		sfSprite_setColor(sprite[7]->obj, color);
		sfSprite_setColor(sprite[10]->obj, color2);
	}
}

void 	parralax_right(obj_t *sprite, sfRenderWindow *window, float speed)
{
	sfVector2f	newpos;

	newpos.x = sprite->pos.x - 1100;
	newpos.y = 0;
	sfSprite_setPosition(sprite->obj, newpos);
	sfRenderWindow_drawSprite(window, sprite->obj, NULL);
	sfSprite_setPosition(sprite->obj, sprite->pos);
	sfRenderWindow_drawSprite(window, sprite->obj, NULL);
	sprite->pos.x -= speed;
	if (sprite->pos.x < 0)
		sprite->pos.x = 1100;
}

void	draw_mob(prog_t *prog, obj_t **sprite)
{
	sfRenderWindow 	*win = prog->window;

	(prog->state.mob[0]) ? sf_draw(win, sprite[12]->obj) : (void)0;
	(prog->state.mob[1]) ? sf_draw(win, sprite[13]->obj) : (void)0;
	(prog->state.mob[2]) ? sf_draw(win, sprite[34]->obj) : (void)0;
	(prog->state.mob[3]) ? sf_draw(win, sprite[35]->obj) : (void)0;
	(prog->state.mob[4]) ? sf_draw(win, sprite[36]->obj) : (void)0;
	(prog->state.mob[5]) ? sf_draw(win, sprite[38]->obj) : (void)0;
	(prog->state.mob[5]) ? sf_draw(win, sprite[39]->obj) : (void)0;
	(prog->state.mob[6]) ? sf_draw(win, sprite[40]->obj) : (void)0;
	(prog->state.mob[6]) ? sf_draw(win, sprite[41]->obj) : (void)0;
	(prog->state.mob[7]) ? sf_draw(win, sprite[42]->obj) : (void)0;
	(prog->state.mob[7]) ? sf_draw(win, sprite[43]->obj) : (void)0;
}