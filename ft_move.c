/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoukou <ikoukou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 15:05:35 by ikoukou           #+#    #+#             */
/*   Updated: 2022/04/10 22:10:58 by ikoukou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_esc(t_so_long *var)
{
	mlx_destroy_window(var->mlx, var->win);
	exit(0);
}

void	ft_right(t_so_long *var)
{
	if (var->na[var->i][var->j + 1] == '0')
	{
		var->na[var->i][var->j + 1] = 'P';
		var->na[var->i][var->j] = '0';
		var->j++;
		var->move++;
		ft_putnbr(var->move);
		ft_putchar('\n');
	}
	else if (var->na[var->i][var->j + 1] == 'C')
	{
		var->na[var->i][var->j + 1] = 'P';
		var->na[var->i][var->j] = '0';
		var->j++;
		var->move++;
		var->collect--;
		ft_putnbr(var->move);
		ft_putchar('\n');
	}
	else if (var->na[var->i][var->j + 1] == 'E' && var->collect == 0)
	{
		write(1, "==== GOOD GAME ====", 19);
		mlx_destroy_window(var->mlx, var->win);
		exit(0);
	}
}

void	ft_up(t_so_long *var)
{
	if (var->na[var->i - 1][var->j] == '0')
	{
		var->na[var->i - 1][var->j] = 'P';
		var->na[var->i][var->j] = '0';
		var->i--;
		var->move++;
		ft_putnbr(var->move);
		ft_putchar('\n');
	}
	else if (var->na[var->i - 1][var->j] == 'C')
	{
		var->na[var->i - 1][var->j] = 'P';
		var->na[var->i][var->j] = '0';
		var->i--;
		var->move++;
		var->collect--;
		ft_putnbr(var->move);
		ft_putchar('\n');
	}
	else if (var->na[var->i - 1][var->j] == 'E' && var->collect == 0)
	{
		write(1, "==== GOOD GAME ====", 19);
		mlx_destroy_window(var->mlx, var->win);
		exit(0);
	}
}

void	ft_left(t_so_long *var)
{
	if (var->na[var->i][var->j - 1] == '0')
	{
		var->na[var->i][var->j - 1] = 'P';
		var->na[var->i][var->j] = '0';
		var->j--;
		var->move++;
		ft_putnbr(var->move);
		ft_putchar('\n');
	}
	else if (var->na[var->i][var->j - 1] == 'C')
	{
		var->na[var->i][var->j - 1] = 'P';
		var->na[var->i][var->j] = '0';
		var->j--;
		var->move++;
		var->collect--;
		ft_putnbr(var->move);
		ft_putchar('\n');
	}
	else if (var->na[var->i][var->j - 1] == 'E' && var->collect == 0)
	{
		write(1, "==== GOOD GAME ====", 19);
		mlx_destroy_window(var->mlx, var->win);
		exit(0);
	}
}

void	ft_down(t_so_long *var)
{
	if (var->na[var->i + 1][var->j] == '0')
	{
		var->na[var->i + 1][var->j] = 'P';
		var->na[var->i][var->j] = '0';
		var->i++;
		var->move++;
		ft_putnbr(var->move);
		ft_putchar('\n');
	}
	else if (var->na[var->i + 1][var->j] == 'C')
	{
		var->na[var->i + 1][var->j] = 'P';
		var->na[var->i][var->j] = '0';
		var->i++;
		var->move++;
		var->collect--;
		ft_putnbr(var->move);
		ft_putchar('\n');
	}
	else if (var->na[var->i + 1][var->j] == 'E' && var->collect == 0)
	{
		write(1, "==== GOOD GAME ====", 19);
		mlx_destroy_window(var->mlx, var->win);
		exit(0);
	}
}
