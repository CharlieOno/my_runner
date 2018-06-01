/*
** EPITECH PROJECT, 2017
** my_runner
** File description:
** setup characters
*/

#include "runner.h"

void 	setup_character_states(prog_t *prog)
{
	prog->state.hex = malloc(sizeof(int) * 4);
	prog->state.mitty = malloc(sizeof(int) * 4);
	prog->state.rog = malloc(sizeof(int) * 4);
	prog->state.hex[0] = 0;
	prog->state.hex[1] = 0;
	prog->state.hex[2] = 0;
	prog->state.hex[3] = 0;
	prog->state.mitty[0] = 0;
	prog->state.mitty[1] = 0;
	prog->state.mitty[2] = 0;
	prog->state.mitty[3] = 0;
	prog->state.rog[0] = 0;
	prog->state.rog[1] = 0;
	prog->state.rog[2] = 0;
	prog->state.rog[3] = 0;
}

void	setup_character_stats(obj_t **sprite)
{
	load_stats(sprite[3], "data/hex.dat");
	sprite[4]->stats = (info_t) {0, 0, 10, 0, 1};
	sprite[5]->stats = (info_t) {0, 0, 15, 0, 1};
	sprite[6]->stats = (info_t) {0, 0, 0, 0, 1};
	load_stats(sprite[7], "data/mitty.dat");
	sprite[8]->stats = (info_t) {0, 0, 20, 0, 1};
	sprite[9]->stats = (info_t) {0, 0, 25, 0, 1};
	load_stats(sprite[10], "data/rog.dat");
	sprite[11]->stats = (info_t) {0, 0, 60, 0, 1};
}

void 	setup_mitty(obj_t **sprite)
{
	sfVector2f	h_pos = (sfVector2f) {10, 450};
	sfIntRect	h_rect = (sfIntRect) {257, 0, 55, 55};
	sfVector2f	s_pos = (sfVector2f) {-100, 450};
	sfIntRect	s_rect = (sfIntRect) {0, 90, 45, 45};
	sfVector2f	hit_pos = (sfVector2f) {-100, 450};
	sfIntRect	hit_rect = (sfIntRect) {120, 120, 40, 40};

	sprite[7] = create_object("img/mitty.png", h_pos, h_rect, CHARACTER);
	sfSprite_setScale(sprite[7]->obj, (sfVector2f) {2.325, 2.325});
	sprite[8] = create_object("img/shrkn.png", s_pos, s_rect, ANIM);
	sfSprite_setScale(sprite[8]->obj, (sfVector2f) {2, 2});
	sprite[9] = create_object("img/envi.png", hit_pos, hit_rect, ANIM);
	sfSprite_setScale(sprite[9]->obj, (sfVector2f) {1.5, 1.5});
}

void 	setup_hex(obj_t **sprite)
{
	sfVector2f	h_pos = (sfVector2f) {10, 450};
	sfIntRect	h_rect = (sfIntRect) {0, 60, 60, 60};
	sfVector2f	shck_pos = (sfVector2f) {-100, 450};
	sfIntRect	shck_rect = (sfIntRect) {240, 52, 20, 52};
	sfVector2f	hit_pos = (sfVector2f) {-100, 450};
	sfIntRect	hit_rect = (sfIntRect) {0, 0, 57, 90};
	sfVector2f	shield_pos = (sfVector2f) {800, 0};
	sfIntRect	shield_rect = (sfIntRect) {0, 0, 102, 100};

	sprite[3] = create_object("img/main.png", h_pos, h_rect, CHARACTER);
	sfSprite_setScale(sprite[3]->obj, (sfVector2f) {2.325, 2.325});
	sprite[4] = create_object("img/shock.png", shck_pos, shck_rect, ANIM);
	sfSprite_setScale(sprite[4]->obj, (sfVector2f) {2, 2});
	sprite[5] = create_object("img/hit.png", hit_pos, hit_rect, ANIM);
	sfSprite_setScale(sprite[5]->obj, (sfVector2f) {1, 1});
	sprite[6] = create_object("img/shield.png", shield_pos, shield_rect,
	ANIM);
	sfSprite_setScale(sprite[6]->obj, (sfVector2f) {2, 2});
}

void 	setup_rog(obj_t **sprite)
{
	sfVector2f	h_pos = (sfVector2f) {10, 500};
	sfIntRect	h_rect = (sfIntRect) {395, 110, 51, 54};
	sfVector2f	e_pos = (sfVector2f) {-100, 0};
	sfIntRect	e_rect = (sfIntRect) {920, 975, 17, 60};

	sprite[10] = create_object("img/rog.png", h_pos, h_rect, CHARACTER);
	sfSprite_setScale(sprite[10]->obj, (sfVector2f) {1.7, 1.7});
	sprite[11] = create_object("img/rog.png", e_pos, e_rect, ANIM);
	sfSprite_setScale(sprite[11]->obj, (sfVector2f) {1.7, 1.7});
}