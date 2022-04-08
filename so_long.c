/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoukou <ikoukou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 16:10:47 by ikoukou           #+#    #+#             */
/*   Updated: 2022/04/08 19:56:49 by ikoukou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	keyhook(int keycode, t_so_long *var)
{
	find_player(var);
	if (keycode == W || keycode == UP)
		ft_up(var);
	if (keycode == S || keycode == DOWN)
		ft_down(var);
	if (keycode == D || keycode == RIGHT)
		ft_right(var);
	if (keycode == A || keycode == LEFT)
		ft_left(var);
	if (keycode == ESC)
		ft_esc(var);
	mlx_clear_window(var->mlx, var->win);
	image_to_window(var);
	return (0);
}

int	exit_x(void)
{
	exit(0);
}

void	ft_check1(int ac, char *av, int fd)
{
	char	*str;

	if (ac != 2)
	{
		write (1, "2  A R G S  N E E D E D  !!", 27);
		exit(0);
	}
	str = ft_strrchr(av, '.');
	if (!str || ft_strcmp(str, ".ber") != 0)
	{
		write (1, "I N V A L I D   E X T E N T I O N  !!", 37);
		exit(0);
	}
	if (fd == -1)
	{
		perror("error ");
		exit(0);
	}
}

int	main(int ac, char **av)
{
	int			fd;
	t_so_long	var;

	fd = open(av[1], O_RDONLY);
	ft_check1(ac, av[1], fd);
	var.na = ft_map(fd);
	if (!var.na[0])
	{
		write(1, "E M P T Y   M A P  !!", 21);
		free(var.na);
		return (0);
	}
	rectangular_map(var.na);
	check_map(var.na);
	ft_var(&var);
	var.win = mlx_new_window(var.mlx, (var.x * 50), (var.y * 50), "SO_LONG");
	xpm_to_image(&var);
	image_to_window(&var);
	mlx_hook(var.win, 2, 0, keyhook, &var);
	mlx_hook(var.win, 17, 0, exit_x, &var);
	mlx_loop(var.mlx);
}
