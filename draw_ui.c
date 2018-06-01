/*
** EPITECH PROJECT, 2017
** my_runner
** File description:
** draw user interface functions
*/

#include "runner.h"

void	draw_textbox(prog_t *prog, obj_t **sprite)
{
	sfText 	*text = sfText_create();
	sfFont	*font = sfFont_createFromFile("img/font.ttf");
	sfVector2f	pos = (sfVector2f) {50, 500};

	if (prog->text[0] == 0)
		return;
	sfText_setCharacterSize(text, 40);
	sfText_setFont(text, font);
	sfText_setString(text, prog->text);
	sfText_setPosition(text, pos);
	sf_draw(prog->window, sprite[31]->obj);
	sfRenderWindow_drawText(prog->window, text, NULL);
}

sfText	*init_text(void)
{
	sfText 	*text = sfText_create();
	sfFont	*font = sfFont_createFromFile("img/font.ttf");

	sfText_setCharacterSize(text, 30);
	sfText_setFont(text, font);
	return (text);
}

void	set_string(char *dest, char *src)
{
	int 	i = 0;

	while (src[i] != '\0') {
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
}

char 	**map_name(void)
{
	char 	**maps = malloc(sizeof(char*) * 9);

	for (int i = 0; i < 9; i++)
		maps[i] = malloc(sizeof(char) * 50);
	set_string(maps[0], "Tutorial [LV1]");
	set_string(maps[1], "Going outside [LV2]");
	set_string(maps[2], "Friday night [LV5]");
	set_string(maps[3], "To the night club [LV10]");
	set_string(maps[4], "Zombie invasion [LV15]");
	set_string(maps[5], "Police escape [LV20]");
	set_string(maps[6], "Run run run [LV30]");
	set_string(maps[7], "Black friday [LV40]");
	set_string(maps[8], "Good luck [LV50]");
	return (maps);
}

void	draw_mapselect(prog_t *prog, int select)
{
	static char**	maps = NULL;
	sfText 		*text = init_text();
	int 		offset = 50;
	int 		color = 127;

	maps = (maps == NULL) ? map_name() : maps;
	sfText_setCharacterSize(text, 70);
	for (int i = 0; i < 9; i++) {
		sfText_setString(text, maps[i]);
		sfText_setPosition(text, (sfVector2f) {30, offset});
		color = (i == select) ? 255 : 127;
		sfText_setColor(text, (sfColor) {255, 255, 255, color});
		sfRenderWindow_drawText(prog->window, text, NULL);
		offset += 50;
	}
}