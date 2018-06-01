/*
** EPITECH PROJECT, 2017
** my_runner
** File description:
** changing selected menu functions
*/

#include "runner.h"

void	menu_change(prog_t *prog, obj_t **sprite, int select, int *selected)
{
	if (*selected != 1)
		return;
	prog->menu = (select == 0) ? 4 : prog->menu;
	prog->menu = (select == 1) ? 4 : prog->menu;
	prog->state.mode = (select == 0) ? 0 : 1;
	if (select == 0 || select == 1)
		reload_game(prog, sprite);
	if (select == 3)
		sfRenderWindow_close(prog->window);
	sfSound_play(prog->sound[3]);
	*selected = 0;
}

void	pause_change(obj_t **sprite, prog_t *prog, int select, int *selected)
{
	if (*selected != 1)
		return;
	prog->menu = (select == 0) ? 1 : prog->menu;
	if (select == 0)
		prog->menu = 1;
	if (select == 1) {
		save_stats(sprite[3], "data/hex.dat");
		save_stats(sprite[7], "data/mitty.dat");
		save_stats(sprite[10], "data/rog.dat");
		prog->menu = 0;
		reload_game(prog, sprite);
	}
	sfSound_play(prog->sound[2]);
	*selected = 0;
}

void	cchoice_change(obj_t **sprite, prog_t *prog, int select, int *selectd)
{
	if (*selectd != 1)
		return;
	prog->charac = (select == 0) ? 0 : prog->charac;
	prog->charac = (select == 1) ? 1 : prog->charac;
	prog->charac = (select == 2) ? 2 : prog->charac;
	exclude_hitbox(sprite);
	reload_game(prog, sprite);
	prog->menu = (prog->state.mode == 0) ? 5 : 1;
	sfSound_play(prog->sound[2]);
	*selectd = 0;
}

void	mchoice_mapselect(prog_t *prog, int select)
{
	switch (select) {
		case 3:
			load_map("map/tothenightclub.map", prog);
			break;
		case 4:
			load_map("map/zombieinvasion.map", prog);
			break;
		case 5:
			load_map("map/policeescape.map", prog);
			break;
		case 6:
			load_map("map/runrunrun.map", prog);
			break;
		case 7:
			load_map("map/blackfriday.map", prog);
			break;
		case 8:
			load_map("map/goodluck.map", prog);
			break;
	}
}

void	mchoice_change(obj_t **sprite, prog_t *prog, int select, int *selectd)
{
	if (*selectd != 1)
		return;
	reload_game(prog, sprite);
	reset_map(prog);
	prog->menu = 1;
	switch (select) {
		case 0:
			load_map("map/tutoriel.map", prog);
			break;
		case 1:
			load_map("map/goingoutside.map", prog);
			break;
		case 2:
			load_map("map/fridaynight.map", prog);
			break;
	}
	mchoice_mapselect(prog, select);
	sfSound_play(prog->sound[2]);
	*selectd = 0;
}