/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkCEP.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoukou <ikoukou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 23:03:12 by ikoukou           #+#    #+#             */
/*   Updated: 2022/04/08 20:18:59 by ikoukou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_p(char **n)
{
	int	i;
	int	j;
	int	p;

	i = 0;
	j = 0;
	p = 0;
	while (n[i] != NULL)
	{
		j = 0;
		while (n[i][j])
		{
			if (n[i][j] == 'P')
				p++;
			j++;
		}
		i++;
	}
	if (p != 1)
		return (1);
	return (0);
}

int	check_c(char **n)
{
	int	i;

	i = 0;
	while (n[i])
	{
		if (ft_strchr(n[i], 'C') == 1)
			return (0);
		i++;
	}
	return (1);
}

int	check_e(char **n)
{
	int	i;

	i = 0;
	while (n[i])
	{
		if (ft_strchr(n[i], 'E') == 1)
			return (0);
		i++;
	}
	return (1);
}
