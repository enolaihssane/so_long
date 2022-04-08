/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm_img_win.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoukou <ikoukou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 02:33:20 by ikoukou           #+#    #+#             */
/*   Updated: 2022/04/08 21:16:31 by ikoukou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	image_to_window2(t_so_long *var)
{
	if (var->na[var->j][var->i] == 'P')
		mlx_put_image_to_window(var->mlx, var->win,
			var->player, var->k, var->l);
	if (var->na[var->j][var->i] == 'C')
		mlx_put_image_to_window(var->mlx, var->win,
			var->collectible, var->k, var->l);
	if (var->na[var->j][var->i] == 'E' && var->collect != 0)
		mlx_put_image_to_window(var->mlx, var->win,
			var->exit, var->k, var->l);
	if (var->na[var->j][var->i] == 'E' && var->collect == 0)
		mlx_put_image_to_window(var->mlx, var->win,
			var->exit2, var->k, var->l);
	if (var->na[var->j][var->i] == '0')
		mlx_put_image_to_window(var->mlx, var->win,
			var->floor, var->k, var->l);
}

void	image_to_window(t_so_long *var)
{
	var->j = 0;
	var->l = 0;
	var->k = 0;
	while (var->j < var->y)
	{
		var->i = 0;
		while (var->i < var->x)
		{
			if (var->na[var->j][var->i] == '1')
				mlx_put_image_to_window(var->mlx, var->win,
					var->wall, var->k, var->l);
			if (var->na[var->j][var->i] == '0')
				mlx_put_image_to_window(var->mlx, var->win,
					var->floor, var->k, var->l);
			image_to_window2(var);
			var->k += 50;
			var->i++;
		}
		var->k = 0;
		var->l += 50;
		var->j++;
	}
}

void	xpm_to_image(t_so_long *var)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	var->wall = mlx_xpm_file_to_image(var->mlx, "xpmfiles/wall.xpm", &i, &j);
	var->exit = mlx_xpm_file_to_image(var->mlx, "xpmfiles/exit.xpm", &i, &j);
	var->exit2 = mlx_xpm_file_to_image(var->mlx, "xpmfiles/exit2.xpm", &i, &j);
	var->player = mlx_xpm_file_to_image(var->mlx,
			"xpmfiles/player.xpm", &i, &j);
	var->collectible = mlx_xpm_file_to_image(var->mlx,
			"xpmfiles/collectible.xpm", &i, &j);
	var->floor = mlx_xpm_file_to_image(var->mlx, "xpmfiles/floor.xpm", &i, &j);
}
