/*
** EPITECH PROJECT, 2018
** my_runner
** File description:
** character sounds functions
*/

#include "runner.h"

void	sound_hex_bubble(prog_t *prog, int *c)
{
	if (prog->state.hex[3] && *c == 0) {
		*c = 1;
		sfSound_play(prog->sound[16]);
		sfSound_play(prog->sound[7]);
	}
}

void	sound_hex(prog_t *prog)
{
	static int	w = 0;
	static int	x = 0;
	static int 	c = 0;

	w = (!prog->state.hex[1]) ? 0 : w;
	x = (!prog->state.hex[2]) ? 0 : x;
	c = (!prog->state.hex[3]) ? 0 : c;
	if (prog->state.hex[1] && w == 0) {
		w = 1;
		sfSound_play(prog->sound[18]);
		sfSound_play(prog->sound[7]);
	}
	if (prog->state.hex[2] && x == 0) {
		x = 1;
		sfSound_play(prog->sound[17]);
		sfSound_play(prog->sound[7]);
	}
	sound_hex_bubble(prog, &c);
}

void	sound_mitty(prog_t *prog)
{
	static int	w = 0;
	static int	x = 0;

	w = (!prog->state.mitty[1]) ? 0 : w;
	x = (!prog->state.mitty[2]) ? 0 : x;
	if (prog->state.mitty[1] && w == 0) {
		w = 1;
		sfSound_play(prog->sound[15]);
		sfSound_play(prog->sound[7]);
	}
	if (prog->state.mitty[2] && x == 0) {
		x = 1;
		sfSound_play(prog->sound[14]);
		sfSound_play(prog->sound[7]);
	}
}

void	sound_rog(prog_t *prog)
{
	static int 	c = 0;

	c = (!prog->state.rog[3]) ? 0 : c;
	if (prog->state.rog[3] && c == 0) {
		c = 1;
		sfSound_play(prog->sound[13]);
		sfSound_play(prog->sound[7]);
	}
}

void	sound_character(prog_t *prog)
{
	switch (prog->charac) {
		case 0:
			sound_hex(prog);
			break;
		case 1:
			sound_mitty(prog);
			break;
		case 2:
			sound_rog(prog);
			break;
	}
}