/*
** EPITECH PROJECT, 2017
** my_runner
** File description:
** hitbox setup functions
*/

#include "runner.h"

void	setup_hitbox_mob1(obj_t **sprite)
{
	sfColor		mob = (sfColor) {200, 129, 23, 175};

	sprite[12]->hit = create_hitbox((sfVector2f) {230, 100}, mob);
	sfRectangleShape_setPosition(sprite[3]->hit, (sfVector2f) {-499, 300});
	sprite[13]->hit = create_hitbox((sfVector2f) {180, 85}, mob);
	sfRectangleShape_setPosition(sprite[3]->hit, (sfVector2f) {-318, 300});
	sprite[34]->hit = create_hitbox((sfVector2f) {196, 128}, mob);
	sfRectangleShape_setPosition(sprite[34]->hit, (sfVector2f) {-749, 0});
	sprite[35]->hit = create_hitbox((sfVector2f) {80, 90}, mob);
	sfRectangleShape_setPosition(sprite[35]->hit, (sfVector2f) {-897, 0});
	sprite[36]->hit = create_hitbox((sfVector2f) {80, 80}, mob);
	sfRectangleShape_setPosition(sprite[35]->hit, (sfVector2f) {-989, 0});
	sprite[38]->hit = create_hitbox((sfVector2f) {133, 80}, mob);
	sfRectangleShape_setPosition(sprite[38]->hit, (sfVector2f) {-989, 0});
}

void	setup_hitbox_mob2(obj_t **sprite)
{
	sfColor		mob = (sfColor) {200, 129, 23, 175};

	sprite[39]->hit = create_hitbox((sfVector2f) {28, 28}, mob);
	sfRectangleShape_setPosition(sprite[39]->hit, (sfVector2f) {-989, 0});
	sprite[40]->hit = create_hitbox((sfVector2f) {240, 160}, mob);
	sfRectangleShape_setPosition(sprite[39]->hit, (sfVector2f) {-989, 0});
	sprite[41]->hit = create_hitbox((sfVector2f) {28, 28}, mob);
	sfRectangleShape_setPosition(sprite[41]->hit, (sfVector2f) {-989, 0});
	sprite[42]->hit = create_hitbox((sfVector2f) {180, 120}, mob);
	sfRectangleShape_setPosition(sprite[42]->hit, (sfVector2f) {-989, 0});
	sprite[43]->hit = create_hitbox((sfVector2f) {28, 28}, mob);
	sfRectangleShape_setPosition(sprite[43]->hit, (sfVector2f) {-989, 0});
}

void	setup_hitbox_characters(obj_t **sprite)
{
	sfColor		charac = (sfColor) {70, 100, 100, 175};
	sfColor		anim = (sfColor) {129, 23, 238, 175};

	sprite[3]->hit = create_hitbox((sfVector2f) {60, 130}, charac);
	sfRectangleShape_setPosition(sprite[3]->hit, (sfVector2f) {-999, 300});
	sprite[4]->hit = create_hitbox((sfVector2f) {50, 69}, anim);
	sfRectangleShape_setPosition(sprite[4]->hit, (sfVector2f) {-938, 300});
	sprite[5]->hit = create_hitbox((sfVector2f) {57, 90}, anim);
	sfRectangleShape_setPosition(sprite[5]->hit, (sfVector2f) {-880, 300});
	sprite[6]->hit = create_hitbox((sfVector2f) {150, 150}, anim);
	sfRectangleShape_setPosition(sprite[6]->hit, (sfVector2f) {-729, 300});
	sprite[7]->hit = create_hitbox((sfVector2f) {95, 124}, charac);
	sfRectangleShape_setPosition(sprite[7]->hit, (sfVector2f) {-999, 500});
}

void	setup_hitbox_characters2(obj_t **sprite)
{
	sfColor		charac = (sfColor) {70, 100, 100, 175};
	sfColor		anim = (sfColor) {129, 23, 238, 175};

	sprite[8]->hit = create_hitbox((sfVector2f) {45, 45}, anim);
	sfRectangleShape_setPosition(sprite[8]->hit, (sfVector2f) {-1838, 0});
	sprite[9]->hit = create_hitbox((sfVector2f) {50, 50}, anim);
	sfRectangleShape_setPosition(sprite[9]->hit, (sfVector2f) {-1780, 0});
	sprite[10]->hit = create_hitbox((sfVector2f) {65, 65}, charac);
	sfRectangleShape_setPosition(sprite[10]->hit, (sfVector2f) {-1780, 0});
	sprite[11]->hit = create_hitbox((sfVector2f) {80, 100}, anim);
	sfRectangleShape_setPosition(sprite[11]->hit, (sfVector2f) {-1800, 0});
}