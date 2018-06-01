/*
** EPITECH PROJECT, 2017
** my_runner
** File description:
** engine functions to handle stats of a  file
*/

#include "runner.h"

void	reset_map(prog_t *prog)
{
	for (int i = 0; i < 4097; i++)
		prog->map[i] = '\0';
}

void	init_map(prog_t *prog)
{
	prog->map = malloc(sizeof(char) * 4096 + 1);
}

void	buffer_to_map(prog_t *prog, char *line, int index)
{
	int 	i = 0;

	while (line[i] != '\0') {
		prog->map[index] = line[i];
		index++;
		i++;
	}
}

void	load_map(char *path, prog_t *prog)
{
	FILE	*file;
	char	*line = NULL;
	size_t 	len = 0;
	int 	status;
	int 	index = 0;

	file = fopen(path, "r");
	while (1) {
		status = getline(&line, &len, file);
		if (status == -1)
			break;
		buffer_to_map(prog, line, index);
		index += status;
	}
	free(line);
}