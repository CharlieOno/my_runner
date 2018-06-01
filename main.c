/*
** EPITECH PROJECT, 2017
** my_runner
** File description:
** main functions
*/

#include "runner.h"

int	main(int ac, char **av)
{
	obj_t	**sprite = malloc(sizeof(obj_t*) * NB_SPRITE);
	prog_t	*prog = malloc(sizeof(prog_t));
	sfEvent 	event;

	(void) av;
	(void) ac;
	if (!sprite || !prog)
		return (84);
	setup(sprite, prog);
	while (sfRenderWindow_isOpen(prog->window))
		menu_handling(sprite, prog, event);
	return (0);
}
