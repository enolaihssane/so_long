/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoukou <ikoukou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 19:17:14 by ikoukou           #+#    #+#             */
/*   Updated: 2022/04/11 01:43:56 by ikoukou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_components1(char **n)
{
	int		i;
	int		j;
	char	*tab;

	i = 0;
	tab = "10CEP";
	while (n[i])
	{
		j = 0;
		while (n[i][j] && n[i][j] != '\n')
		{
			if (ft_strchr(tab, n[i][j]) == 0)
			{
				write (1, &n[i][j], 1);
				write (1, ": is invalid !", 14);
				exit(0);
			}
			j++;
		}
		i++;
	}
}

void	check_components(char **n)
{
	if (check_p(n) != 0)
	{
		write (1, "ONE PLAYER NEEDE !!", 19);
		exit(0);
	}
	if (check_c(n) != 0)
	{
		write (1, "COLLECTIBLE NEEDED !!", 21);
		exit(0);
	}
	if (check_e(n) != 0)
	{
		write (1, "EXIT NEEDED !!", 14);
		exit(0);
	}
}

int	check_wall1(char **n)
{
	int	i;
	int	j;
	int	k;
	int	l;

	j = 0;
	k = 0;
	l = 0;
	i = ft_strlen(n[0]);
	while (n[k] != NULL && n[k][i - 1])
	{
		if (n[k][i - 1] != '1')
			return (1);
		k++;
	}
	while (n[j] != NULL)
		j++;
	while (n[j - 1][l] && n[j - 1][l] != '\n')
	{
		if (n[j - 1][l] != '1')
			return (1);
		l++;
	}
	return (0);
}

int	check_walls(char **n)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (n[0][i] != '\n')
	{
		if (n[0][i] != '1')
			return (1);
		i++;
	}
	while (n[j] != NULL)
	{
		if (n[j][0] != '1')
			return (1);
		j++;
	}
	j = 0;
	while (n[j] != NULL)
		j++;
	if (n[j - 1][i] == '\n')
		return (1);
	if (check_wall1(n))
		return (1);
	return (0);
}

void	check_map(char **n)
{
	if (check_walls(n) == 1)
	{
		write (1, "Error:\n", 8);
		write (1, "ERROR WALLS", 11);
		exit(0);
	}
	check_components(n);
	check_components1(n);
}
