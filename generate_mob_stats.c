/*
** EPITECH PROJECT, 2018
** my_runner
** File description:
** generate stats for mobs
*/

#include "runner.h"

void	stats_truck(obj_t *sprite, int level)
{
	sprite->stats = (info_t) {50, 50, 40, 110, 1};

	while (sprite->stats.lvl != level) {
		sprite->stats.exp += sprite->stats.exp / 10;
		sprite->stats.maxhp += sprite->stats.maxhp / 10;
		sprite->stats.hp += sprite->stats.hp / 10;
		sprite->stats.atk += sprite->stats.atk / 10;
		sprite->stats.lvl += 1;
	}
}

void	stats_car(obj_t *sprite, int level)
{
	sprite->stats = (info_t) {30, 30, 30, 100, 1};

	while (sprite->stats.lvl != level) {
		sprite->stats.exp += sprite->stats.exp / 10;
		sprite->stats.maxhp += sprite->stats.maxhp / 10;
		sprite->stats.hp += sprite->stats.hp / 10;
		sprite->stats.atk += sprite->stats.atk / 10;
		sprite->stats.lvl += 1;
	}
}

void	stats_big(obj_t *sprite, int level)
{
	sprite->stats = (info_t) {75, 75, 35, 130, 1};

	while (sprite->stats.lvl != level) {
		sprite->stats.exp += sprite->stats.exp / 10;
		sprite->stats.maxhp += sprite->stats.maxhp / 10;
		sprite->stats.hp += sprite->stats.hp / 10;
		sprite->stats.atk += sprite->stats.atk / 10;
		sprite->stats.lvl += 1;
	}
}

void	stats_geisha(obj_t *sprite, int level)
{
	sprite->stats = (info_t) {40, 40, 30, 90, 1};

	while (sprite->stats.lvl != level) {
		sprite->stats.exp += sprite->stats.exp / 10;
		sprite->stats.maxhp += sprite->stats.maxhp / 10;
		sprite->stats.hp += sprite->stats.hp / 10;
		sprite->stats.atk += sprite->stats.atk / 10;
		sprite->stats.lvl += 1;
	}
}

void	generate_mob_stats(obj_t **sprite, int state, int level)
{
	switch (state) {
		case 0:
			stats_truck(sprite[12], level);
			break;
		case 1:
			stats_car(sprite[13], level);
			break;
		case 2:
			stats_big(sprite[34], level);
			break;
		case 3:
			stats_geisha(sprite[35], level);
			break;
	}
	generate_mob_stats2(sprite, state, level);
}