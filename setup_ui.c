/*
** EPITECH PROJECT, 2017
** my_runner
** File description:
** setup user interface functions
*/

#include "runner.h"

void 	setup_pause(obj_t **sprite)
{
	sfVector2f	t_pos = (sfVector2f) {0, 150};
	sfIntRect	t_rect = (sfIntRect) {0, 0, 800, 300};
	sfVector2f	e_pos = (sfVector2f) {120, 150};
	sfIntRect	e_rect = (sfIntRect) {0, 0, 1000, 200};
	sfVector2f	k_pos = (sfVector2f) {210, 360};
	sfVector2f	j_pos = (sfVector2f) {220, 290};

	sprite[24] = create_object("img/pause.png", e_pos, e_rect, UI);
	sfSprite_setScale(sprite[24]->obj, (sfVector2f) {0.6, 0.6});
	sprite[25] = create_object("img/yes.png", k_pos, e_rect, UI);
	sfSprite_setScale(sprite[25]->obj, (sfVector2f) {0.4, 0.4});
	sprite[26] = create_object("img/no.png", k_pos, e_rect, UI);
	sfSprite_setScale(sprite[26]->obj, (sfVector2f) {0.4, 0.4});
	sprite[27] = create_object("img/continue.png", j_pos, e_rect, UI);
	sfSprite_setScale(sprite[27]->obj, (sfVector2f) {0.4, 0.4});
	sprite[28] = create_object("img/blck.png", t_pos, t_rect, UI);
}

void	setup_gameui(obj_t **sprite)
{
	sfVector2f	t_pos = (sfVector2f) {-500, -500};
	sfIntRect	t_rect = (sfIntRect) {0, 0, 82, 10};
	sfVector2f	k_pos = (sfVector2f) {0, 500};
	sfIntRect	k_rect = (sfIntRect) {0, 0, 800, 100};
	sfVector2f	e_pos = (sfVector2f) {10, 150};
	sfIntRect	e_rect = (sfIntRect) {0, 0, 1000, 200};
	sfVector2f	n_pos = (sfVector2f) {0, 0};
	sfIntRect	n_rect = (sfIntRect) {0, 0, 800, 70};

	sprite[29] = create_object("img/lifebar.png", t_pos, t_rect, UI);
	sprite[30] = create_object("img/life.png", t_pos, t_rect, UI);
	sprite[31] = create_object("img/blck.png", k_pos, k_rect, UI);
	sprite[32] = create_object("img/victory.png", e_pos, e_rect, UI);
	sfSprite_setScale(sprite[32]->obj, (sfVector2f) {0.8, 0.8});
	sprite[33] = create_object("img/defeat.png", e_pos, e_rect, UI);
	sfSprite_setScale(sprite[33]->obj, (sfVector2f) {0.8, 0.8});
	sprite[37] = create_object("img/blck.png", n_pos, n_rect, UI);
}

void 	setup_menu(obj_t **sprite)
{
	sfVector2f	t_pos = (sfVector2f) {0, 50};
	sfIntRect	t_rect = (sfIntRect) {0, 0, 800, 500};
	sfVector2f	h_pos = (sfVector2f) {-160, 160};
	sfIntRect	h_rect = (sfIntRect) {0, 0, 698, 698};
	sfVector2f	e_pos = (sfVector2f) {340, 115};
	sfIntRect	e_rect = (sfIntRect) {0, 0, 1000, 200};

	sprite[14] = create_object("img/blck.png", t_pos, t_rect, UI);
	sprite[15] = create_object("img/title.png", h_pos, h_rect, UI);
	sfSprite_setScale(sprite[15]->obj, (sfVector2f) {0.8, 0.8});
	sprite[16] = create_object("img/story0.png", e_pos, e_rect, UI);
	sfSprite_setScale(sprite[16]->obj, (sfVector2f) {0.4, 0.4});
	sprite[17] = create_object("img/story1.png", e_pos, e_rect, UI);
	sfSprite_setScale(sprite[17]->obj, (sfVector2f) {0.4, 0.4});
}

void	setup_menu2(obj_t **sprite)
{
	sfVector2f	k_pos = (sfVector2f) {340, 215};
	sfVector2f	j_pos = (sfVector2f) {340, 315};
	sfVector2f	s_pos = (sfVector2f) {340, 415};
	sfIntRect	e_rect = (sfIntRect) {0, 0, 1000, 200};

	sprite[18] = create_object("img/quick0.png", k_pos, e_rect, UI);
	sfSprite_setScale(sprite[18]->obj, (sfVector2f) {0.4, 0.4});
	sprite[19] = create_object("img/quick1.png", k_pos, e_rect, UI);
	sfSprite_setScale(sprite[19]->obj, (sfVector2f) {0.4, 0.4});
	sprite[20] = create_object("img/opt0.png", j_pos, e_rect, UI);
	sfSprite_setScale(sprite[20]->obj, (sfVector2f) {0.4, 0.4});
	sprite[21] = create_object("img/opt1.png", j_pos, e_rect, UI);
	sfSprite_setScale(sprite[21]->obj, (sfVector2f) {0.4, 0.4});
	sprite[22] = create_object("img/quit0.png", s_pos, e_rect, UI);
	sfSprite_setScale(sprite[22]->obj, (sfVector2f) {0.4, 0.4});
	sprite[23] = create_object("img/quit1.png", s_pos, e_rect, UI);
	sfSprite_setScale(sprite[23]->obj, (sfVector2f) {0.4, 0.4});
}