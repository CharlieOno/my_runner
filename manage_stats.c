/*
** EPITECH PROJECT, 2017
** my_runner
** File description:
** managing stats of differents characters
*/

#include "runner.h"

int	*generate_exp_table(void)
{
	int 	*exp_table = malloc(sizeof(int) * 100);
	int 	initial = 500;

	for (int i = 0; i < 100; i++) {
		exp_table[i] = initial + (initial / 100) * 20;
		initial += (initial / 100) * 20;
	}
	return (exp_table);
}

void	init_stats(obj_t *sprite, int hp, int atk, int exp)
{
	sprite->stats.maxhp = hp;
	sprite->stats.hp = hp;
	sprite->stats.atk = atk;
	sprite->stats.exp = exp;
}

void	rog_heal(obj_t *sprite)
{
	int 	heal = (sprite->stats.maxhp / 100) * 5;

	if (sprite->stats.hp + heal > sprite->stats.maxhp)
		sprite->stats.hp = sprite->stats.maxhp;
	else
		sprite->stats.hp += heal;
}

void	remove_hp(obj_t *sprite, int dmg)
{
	if (sprite->stats.hp - dmg > 0)
		sprite->stats.hp -= dmg;
	else
		sprite->stats.hp = 0;
}

void	add_exp(prog_t *prog, obj_t **sprite, int *state, obj_t *actual)
{
	if (actual->type != MOB || actual->stats.hp > 0)
		return;
	if (*state != 240) {
		prog->state.defeated += 1;
		return;
	}
	switch (prog->charac) {
		case 0:
			sprite[3]->stats.exp += actual->stats.exp;
			break;
		case 1:
			sprite[7]->stats.exp += actual->stats.exp;
			break;
		case 2:
			sprite[10]->stats.exp += actual->stats.exp;
			break;
	}
}