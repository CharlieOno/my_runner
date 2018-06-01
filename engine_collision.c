/*
** EPITECH PROJECT, 2017
** my_runner
** File description:
** collision handling with the game engine
*/

#include "runner.h"

sfBool	check_collision(sfRectangleShape *rect1, sfRectangleShape *rect2)
{
	sfVector2f  rect1_pos = sfRectangleShape_getPosition(rect1);
	sfVector2f  rect2_pos = sfRectangleShape_getPosition(rect2);
	sfVector2f  rect1_size = sfRectangleShape_getSize(rect1);
	sfVector2f  rect2_size = sfRectangleShape_getSize(rect2);

	if (rect1 == NULL || rect2 == NULL)
		return (0);
	if ((rect1_pos.x + rect1_size.x) > rect2_pos.x
		&& rect1_pos.x < rect2_pos.x + rect2_size.x)
		if ((rect1_pos.y + rect2_size.y) > rect2_pos.y &&
			rect1_pos.y < rect2_pos.y + rect2_size.y)
			return (1);
	return (0);
}

void	collision_charac_mob(obj_t **sprite, int i, int j, int *state)
{
	if (i == j)
		return;
	if (sprite[i]->type != CHARACTER || sprite[j]->type != MOB)
		return;
	if (check_collision(sprite[i]->hit, sprite[j]->hit) && *state != 1)
		remove_hp(sprite[i], sprite[j]->stats.atk);
	*state = check_collision(sprite[i]->hit, sprite[j]->hit);
}

void	collision_charac_mobanim(obj_t **sprite, int i, int j, int *state)
{
	if (i == j)
		return;
	if (sprite[i]->type != CHARACTER || sprite[j]->type != MOBANIM)
		return;
	if (check_collision(sprite[j]->hit, sprite[i]->hit) && *state != 1)
		remove_hp(sprite[i], sprite[j]->stats.atk);
	*state = check_collision(sprite[j]->hit, sprite[i]->hit);
}

void	collision_anim_mob(obj_t **sprite, int i, int j, int *state)
{
	if (i == j)
		return;
	if (sprite[i]->type != ANIM || sprite[j]->type != MOB)
		return;
	if (check_collision(sprite[i]->hit, sprite[j]->hit) && *state != 1)
		remove_hp(sprite[j], sprite[i]->stats.atk);
	*state = check_collision(sprite[i]->hit, sprite[j]->hit);
}

void	engine_collision(prog_t *prog, obj_t **sprite)
{
	static int	**state = NULL;

	state = (state == NULL) ? create_state_list() : state;
	for (int i = 0; i < NB_SPRITE; i++)
		for (int j = 0; j < NB_SPRITE; j++) {
			snd_char(prog, sprite, (int[2]) {i, j}, &state[i][j]);
			snd_anim(prog, sprite, (int[2]) {i, j}, &state[i][j]);
			collision_charac_mobanim(sprite, i, j, &state[i][j]);
			collision_charac_mob(sprite, i, j, &state[i][j]);
			collision_anim_mob(sprite, i, j, &state[i][j]);
			buff_hex_shield(prog, sprite[3]);
			engine_hit(state[i], sprite[i]);
		}
}