/*
** EPITECH PROJECT, 2018
** my_runner
** File description:
** statistics functions automatisations
*/

#include "runner.h"

int	stats_at_n_step(obj_t *sprite, int i)
{
	switch (i) {
		case 0:
			return (sprite->stats.maxhp);
			break;
		case 1:
			return (sprite->stats.maxhp);
			break;
		case 2:
			return (sprite->stats.atk);
			break;
		case 3:
			return (sprite->stats.exp);
			break;
		case 4:
			return (sprite->stats.lvl);
			break;
	}
	return (0);
}

void	mem_to_buffer(obj_t *sprite, char *buf, int i)
{
	static int 	index = 0;
	int 	length = nbr_length(stats_at_n_step(sprite, i));
	char	*data = my_getchar(stats_at_n_step(sprite, i));

	for (int i = 0; i < 10 - length; i++) {
		buf[index] = '0';
		index += 1;
	}
	for (int i = 0; i < length; i++) {
		buf[index] = data[i];
		index += 1;
	}
	buf[index] = (i != 4) ? '\n' : '\0';
	index += 1;
	index = (i == 4) ? 0 : index;
}

void	save_stats(obj_t *sprite, char *path)
{
	char	*buf = malloc(sizeof(char) * 55);
	int 	fd = open(path, O_RDWR);

	for (int i = 0; i < 5; i++)
		mem_to_buffer(sprite, buf, i);
	write(fd, buf, 55);
}

void	data_into_mem(obj_t *sprite, int infos)
{
	static int 	step = 0;

	sprite->stats.maxhp = (step == 0) ? infos : sprite->stats.maxhp;
	sprite->stats.hp = (step == 1) ? infos : sprite->stats.hp;
	sprite->stats.atk = (step == 2) ? infos : sprite->stats.atk;
	sprite->stats.exp = (step == 3) ? infos : sprite->stats.exp;
	sprite->stats.lvl = (step == 4) ? infos : sprite->stats.lvl;
	step += 1;
	step = (step == 5) ? 0 : step;
}

void	load_stats(obj_t *sprite, char *path)
{
	FILE	*file;
	char	*line = NULL;
	size_t 	len = 0;
	int 	status;

	file = fopen(path, "r");
	if (!file)
		exit(84);
	while (1) {
		status = getline(&line, &len, file);
		if (status == -1)
			break;
		data_into_mem(sprite, my_getnbr(line));
	}
	free(line);
	fclose(file);
}