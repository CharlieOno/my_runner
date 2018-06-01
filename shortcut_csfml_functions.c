/*
** EPITECH PROJECT, 2017
** my_runner
** File description:
** shortcut of csfml functions
*/

#include "runner.h"

void	sf_rect(sfSprite *sprite, sfIntRect frame)
{
	sfSprite_setTextureRect(sprite, frame);
}

void	sf_pos(sfSprite *sprite, sfVector2f vector)
{
	sfSprite_setPosition(sprite, vector);
}

void	sf_move(sfSprite *sprite, sfVector2f vector)
{
	sfSprite_move(sprite, vector);
}

void	sf_draw(sfRenderWindow *window, sfSprite *sprite)
{
	sfRenderWindow_drawSprite(window, sprite, NULL);
}