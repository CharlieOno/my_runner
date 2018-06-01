/*
** EPITECH PROJECT, 2018
** my_runner
** File description:
** second part of draw obj ui
*/

#include "runner.h"

void	draw_lifebar(prog_t *prog, obj_t **sprite, obj_t *entity)
{
	sfRectangleShape 	*frame = sfRectangleShape_create();
	sfVector2f	pos1 = sfSprite_getPosition(entity->obj);
	sfVector2f	size1 = sfRectangleShape_getSize(entity->hit);
	double 	part = (entity->stats.hp * 100) / entity->stats.maxhp;

	sfRectangleShape_setSize(frame, (sfVector2f) {82, 10});
	sfRectangleShape_setFillColor(frame, sfWhite);
	pos1.x = pos1.x + size1.x / 2 - 7;
	pos1.y -= 32;
	sfRectangleShape_setPosition(frame, pos1);
	part = (part / 5) * 4 + 2;
	sfSprite_setTextureRect(sprite[30]->obj, (sfIntRect) {0, 0, part, 10});
	sfRenderWindow_drawRectangleShape(prog->window, frame, NULL);
	sf_pos(sprite[29]->obj, pos1);
	sf_pos(sprite[30]->obj, pos1);
	sf_draw(prog->window, sprite[30]->obj);
	sf_draw(prog->window, sprite[29]->obj);
}

char	*concat_str(char *str, char *begin, char *end)
{
	int	i = 0;
	int	j = 0;

	while (begin[i] != '\0') {
		str[i] = begin[i];
		i++;
	}
	while (end[j] != '\0') {
		str[i + j] = end[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}

void	draw_defeated(prog_t *prog, obj_t *blackbox)
{
	static sfText 	*text = NULL;
	char 		str[20];
	sfVector2f	pos1 = (sfVector2f) {10, -10};
	char 		*defeated = my_getchar(prog->state.defeated);

	text = (text == NULL) ? init_text() : text;
	sfText_setCharacterSize(text, 60);
	concat_str((char *)&str, "SCORE ", defeated);
	sfText_setString(text, str);
	sfText_setPosition(text, pos1);
	sf_draw(prog->window, blackbox->obj);
	sfRenderWindow_drawText(prog->window, text, NULL);
}

void	draw_level(prog_t *prog, obj_t *entity)
{
	static sfText 	*level = NULL;
	char 		str[10];
	sfVector2f	pos1;
	sfVector2f	size1;

	level = (level == NULL) ? init_text() : level;
	concat_str((char *)&str, "LV:", my_getchar(entity->stats.lvl));
	sfText_setString(level, str);
	pos1 = sfSprite_getPosition(entity->obj);
	size1 = sfRectangleShape_getSize(entity->hit);
	pos1.x = pos1.x + size1.x / 2 - 60;
	pos1.y -= 50;
	sfText_setPosition(level, pos1);
	sfRenderWindow_drawText(prog->window, level, NULL);
}

void	draw_level_hp(prog_t *prog, obj_t **sprite)
{
	int 	charac_id = 3;

	charac_id = (prog->charac == 1) ? 7 : charac_id;
	charac_id = (prog->charac == 2) ? 10 : charac_id;
	draw_level(prog, sprite[charac_id]);
	draw_lifebar(prog, sprite, sprite[charac_id]);
	for (int i = 12; i < NB_SPRITE; i++)
		if (sprite[i]->type == MOB) {
			draw_level(prog, sprite[i]);
			draw_lifebar(prog, sprite, sprite[i]);
		}
}