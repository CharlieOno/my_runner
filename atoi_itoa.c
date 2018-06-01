/*
** EPITECH PROJECT, 2017
** my_runner
** File description:
** atoi & itoa functions (my_getnbr & my_getstr)
*/

#include "runner.h"

char	*str_fill(char *str, int nbr, int tmp, int length)
{
	int i = 0;

	while (i != length) {
		str[i++] = (nbr / tmp) % 10 + '0';
		tmp /= 10;
	}
	str[i] = '\0';
	return (str);
}

int	nbr_length(int nbr)
{
	int	length = 0;
	int	tmp = 1;

	while (nbr / tmp > 0) {
		tmp *= 10;
		length++;
	}
	return (length);
}

int	nbr_length_getchar(int nbr, int *tmp)
{
	int	length = 0;

	while (nbr / *tmp > 0) {
		*tmp *= 10;
		length++;
	}
	return (length);
}

char	*my_getchar(int nbr)
{
	char	*str;
	int	tmp = 1;
	int	length = 0;

	str = malloc(sizeof(char) * 10);
	if (!str)
		return (NULL);
	if (nbr == 0)
		return ("0");
	length = nbr_length_getchar(nbr, &tmp);
	tmp /= 10;
	str = str_fill(str, nbr, tmp, length);
	return (str);
}

int	my_getnbr(char *str)
{
	long	nbr = 0;
	int	sign = 0;

	while (*str == '-' || *str == '+')
		(*str++ == '-') ? sign++ : 0;
	while (*str >= '0' && *str <= '9') {
		nbr = nbr * 10;
		nbr = nbr + *str++ - '0';
	}
	return ((sign % 2 == 1) ? nbr * -1 : nbr);
}