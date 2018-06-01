/*
** EPITECH PROJECT, 2017
** my_runner
** File description:
** managing ressource functions
*/

#include "runner.h"

void	exclude_hitbox(obj_t **sprite)
{
	sfVector2f	pos = (sfVector2f) {-5000, -5000};

	for (int i = 0; i < NB_SPRITE; i++) {
		if (sprite[i]->type == CHARACTER || sprite[i]->type == ANIM)
			sfRectangleShape_setPosition(sprite[i]->hit, pos);
	}
}

void	update_hitbox(obj_t *sprite, sfVector2f off)
{
	sfVector2f	pos;

	sprite->pos = sfSprite_getPosition(sprite->obj);
	pos.x = sprite->pos.x + off.x;
	pos.y = sprite->pos.y + off.y;
	sfRectangleShape_setPosition(sprite->hit, pos);
}

sfRectangleShape 	*create_hitbox(sfVector2f size, sfColor color)
{
	sfRectangleShape  *hitbox = sfRectangleShape_create();

	sfRectangleShape_setSize(hitbox, size);
	sfRectangleShape_setFillColor(hitbox, color);
	return (hitbox);
}

obj_t	*create_object(const char *path, sfVector2f pos, sfIntRect rect,
enum objtype given_type)
{
	obj_t	*sprite = malloc(sizeof(obj_t));

	sprite->type = given_type;
	sprite->obj = sfSprite_create();
	sprite->pos = (sfVector2f) {pos.x, pos.y};
	sprite->img = sfTexture_createFromFile(path, NULL);
	sfSprite_setTexture(sprite->obj, sprite->img, sfTrue);
	sfSprite_setPosition(sprite->obj, pos);
	sfSprite_setTextureRect(sprite->obj, rect);
	sprite->frame.left = rect.left;
	sprite->frame.top = rect.top;
	sprite->frame.width = rect.width;
	sprite->frame.height = rect.height;
	sprite->hit = NULL;
	return (sprite);
}

int	**create_state_list(void)
{
	int	**state = malloc(sizeof(int*) * NB_SPRITE + 8);

	for (int i = 0; i < NB_SPRITE ; i++) {
		state[i] = malloc(sizeof(int) * NB_SPRITE + 4);
		for (int j = 0; j < NB_SPRITE; j++)
			state[i][j] = 0;
	}
	return (state);
}