/*
** EPITECH PROJECT, 2018
** my_runner
** File description:
** setup mob functions
*/

#include "runner.h"

void 	setup_mob_part1(obj_t **sprite)
{
	sfVector2f	t_pos = (sfVector2f) {-100, 500};
	sfIntRect	t_rect = (sfIntRect) {0, 0, 120, 42};
	sfIntRect	c_rect = (sfIntRect) {232, 0, 78, 37};
	sfIntRect	k_rect = (sfIntRect) {0, 0, 98, 64};
	sfIntRect	l_rect = (sfIntRect) {0, 352, 40, 45};

	sprite[12] = create_object("img/cars.png", t_pos, t_rect, MOB);
	sfSprite_setScale(sprite[12]->obj, (sfVector2f) {2.325, 2.325});
	sprite[12]->stats = (info_t) {50, 50, 40, 110, 1};
	sprite[13] = create_object("img/cars.png", t_pos, c_rect, MOB);
	sfSprite_setScale(sprite[13]->obj, (sfVector2f) {2.325, 2.325});
	sprite[13]->stats = (info_t) {30, 30, 30, 100, 1};
	sprite[34] = create_object("img/bigmob.png", t_pos, k_rect, MOB);
	sfSprite_setScale(sprite[34]->obj, (sfVector2f) {2.0, 2.0});
	sprite[34]->stats = (info_t) {75, 75, 35, 130, 1};
	sprite[35] = create_object("img/envi.png", t_pos, l_rect, MOB);
	sfSprite_setScale(sprite[35]->obj, (sfVector2f) {2.0, 2.0});
	sprite[35]->stats = (info_t) {40, 40, 30, 90, 1};
}

void 	setup_mob_part2(obj_t **sprite)
{
	sfVector2f	t_pos = (sfVector2f) {-100, 500};
	sfIntRect	t_rect = (sfIntRect) {160, 400, 40, 40};
	sfVector2f	n_pos = (sfVector2f) {-100, 300};
	sfIntRect	n_rect = (sfIntRect) {0, 0, 58, 35};
	sfVector2f	k_pos = (sfVector2f) {7333, 3344};
	sfIntRect	k_rect = (sfIntRect) {0, 0, 14, 14};

	sprite[36] = create_object("img/envi.png", t_pos, t_rect, MOB);
	sfSprite_setScale(sprite[36]->obj, (sfVector2f) {2.325, 2.325});
	sprite[36]->stats = (info_t) {50, 50, 40, 130, 1};
	sprite[38] = create_object("img/ufo.png", n_pos, n_rect, MOB);
	sfSprite_setScale(sprite[38]->obj, (sfVector2f) {2.325, 2.325});
	sprite[38]->stats = (info_t) {30, 30, 35, 130, 1};
	sprite[39] = create_object("img/proj.png", k_pos, k_rect, MOBANIM);
	sfSprite_setScale(sprite[39]->obj, (sfVector2f) {2, 2});
	sprite[39]->stats = (info_t) {30, 30, 35, 130, 1};
}

void	setup_mob_part3(obj_t **sprite)
{
	sfVector2f	t_pos = (sfVector2f) {-100, 500};
	sfVector2f	k_pos = (sfVector2f) {7333, 3344};
	sfIntRect	k_rect = (sfIntRect) {0, 0, 14, 14};
	sfVector2f	n_pos = (sfVector2f) {-100, 300};
	sfIntRect	d_rect = (sfIntRect) {0, 280, 120, 80};
	sfIntRect	l_rect = (sfIntRect) {28, 772, 90, 60};

	sprite[40] = create_object("img/static.png", t_pos, d_rect, MOB);
	sfSprite_setScale(sprite[40]->obj, (sfVector2f) {2, 2});
	sprite[40]->stats = (info_t) {120, 120, 20, 150, 1};
	sprite[41] = create_object("img/proj.png", k_pos, k_rect, MOBANIM);
	sfSprite_setScale(sprite[41]->obj, (sfVector2f) {2, 2});
	sprite[41]->stats = (info_t) {120, 120, 20, 150, 1};
	sprite[42] = create_object("img/aerian.png", n_pos, l_rect, MOB);
	sfSprite_setScale(sprite[42]->obj, (sfVector2f) {2, 2});
	sprite[42]->stats = (info_t) {50, 50, 20, 120, 1};
	sprite[43] = create_object("img/proj.png", k_pos, k_rect, MOBANIM);
	sfSprite_setScale(sprite[43]->obj, (sfVector2f) {2, 2});
	sprite[43]->stats = (info_t) {50, 50, 20, 120, 1};
}