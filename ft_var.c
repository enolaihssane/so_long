/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_var.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoukou <ikoukou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 18:22:14 by ikoukou           #+#    #+#             */
/*   Updated: 2022/04/08 20:07:33 by ikoukou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_x(char **n)
{
	int	i;

	i = 0;
	while (n[0] && n[0][i])
		i++;
	return (i - 1);
}

int	get_y(char **n)
{
	int	i;

	i = 0;
	while (n[i])
		i++;
	return (i);
}

int	get_collect(char **n)
{
	int	i;
	int	j;
	int	c;

	i = 0;
	c = 0;
	while (n[i])
	{
		j = 0;
		while (n[i][j])
		{
			if (n[i][j] == 'C')
				c++;
			j++;
		}
		i++;
	}
	return (c);
}

void	ft_var(t_so_long *var)
{
	var->x = get_x(var->na);
	var->y = get_y(var->na);
	var->collect = get_collect(var->na);
	var->mlx = mlx_init();
}
