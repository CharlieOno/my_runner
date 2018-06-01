/*
** EPITECH PROJECT, 2018
** my_runner
** File description:
** generate stats part 2
*/

#include "runner.h"

void	stats_oldman(obj_t *sprite, int level)
{
	sprite->stats = (info_t) {50, 50, 20, 130, 1};

	while (sprite->stats.lvl != level) {
		sprite->stats.exp += sprite->stats.exp / 10;
		sprite->stats.maxhp += sprite->stats.maxhp / 10;
		sprite->stats.hp += sprite->stats.hp / 10;
		sprite->stats.atk += sprite->stats.atk / 10;
		sprite->stats.lvl += 1;
	}
}

void	stats_ufo(obj_t *sprite, obj_t *fire, int level)
{
	sprite->stats = (info_t) {30, 30, 40, 130, 1};
	fire->stats = (info_t) {30, 30, 30, 130, 1};

	while (sprite->stats.lvl != level) {
		sprite->stats.exp += sprite->stats.exp / 10;
		sprite->stats.maxhp += sprite->stats.maxhp / 10;
		sprite->stats.hp += sprite->stats.hp / 10;
		sprite->stats.atk += sprite->stats.atk / 10;
		sprite->stats.lvl += 1;
		fire->stats.exp += fire->stats.exp / 10;
		fire->stats.maxhp += fire->stats.maxhp / 10;
		fire->stats.hp += fire->stats.hp / 10;
		fire->stats.atk += fire->stats.atk / 10;
		fire->stats.lvl += 1;
	}
}

void	stats_yeti(obj_t *sprite, obj_t *fire, int level)
{
	sprite->stats = (info_t) {120, 120, 20, 150, 1};
	fire->stats = (info_t) {120, 120, 20, 150, 1};

	while (sprite->stats.lvl != level) {
		sprite->stats.exp += sprite->stats.exp / 10;
		sprite->stats.maxhp += sprite->stats.maxhp / 10;
		sprite->stats.hp += sprite->stats.hp / 10;
		sprite->stats.atk += sprite->stats.atk / 10;
		sprite->stats.lvl += 1;
		fire->stats.exp += fire->stats.exp / 10;
		fire->stats.maxhp += fire->stats.maxhp / 10;
		fire->stats.hp += fire->stats.hp / 10;
		fire->stats.atk += fire->stats.atk / 10;
		fire->stats.lvl += 1;
	}
}

void	stats_aerian(obj_t *sprite, obj_t *fire, int level)
{
	sprite->stats = (info_t) {60, 60, 30, 100, 1};
	fire->stats = (info_t) {60, 60, 30, 100, 1};

	while (sprite->stats.lvl != level) {
		sprite->stats.exp += sprite->stats.exp / 10;
		sprite->stats.maxhp += sprite->stats.maxhp / 10;
		sprite->stats.hp += sprite->stats.hp / 10;
		sprite->stats.atk += sprite->stats.atk / 10;
		sprite->stats.lvl += 1;
		fire->stats.exp += fire->stats.exp / 10;
		fire->stats.maxhp += fire->stats.maxhp / 10;
		fire->stats.hp += fire->stats.hp / 10;
		fire->stats.atk += fire->stats.atk / 10;
		fire->stats.lvl += 1;
	}
}

void	generate_mob_stats2(obj_t **sprite, int state, int level)
{
	switch (state) {
		case 4:
			stats_oldman(sprite[36], level);
			break;
		case 5:
			stats_ufo(sprite[38], sprite[39], level);
			break;
		case 6:
			stats_yeti(sprite[40], sprite[41], level);
			break;
		case 7:
			stats_aerian(sprite[42], sprite[43], level);
			break;
	}
}