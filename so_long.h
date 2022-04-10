/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoukou <ikoukou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 16:11:31 by ikoukou           #+#    #+#             */
/*   Updated: 2022/04/10 01:33:59 by ikoukou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define W 13
# define D 2
# define S 1
# define A 0
# define UP 126
# define DOWN 125
# define RIGHT 124
# define LEFT 123
# define ESC 53
# define BUFFER_SIZE 1

# include <unistd.h>
# include <stdio.h>
# include <mlx.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct mlx1{
	void	*mlx;
	void	*win;
	void	*floor;
	void	*wall;
	void	*collectible;
	void	*exit;
	void	*exit2;
	void	*player;
	char	**na;
	int		x;
	int		y;
	int		l;
	int		k;
	int		i;
	int		j;
	int		move;
	int		collect;
}	t_so_long;

char	*ft_strrchr(const char *str, int c);
int		ft_strcmp(const char *str1, const char *str2);
void	check_map(char **N);
int		check_p(char **N);
int		check_c(char **N);
int		check_e(char **N);
char	**ft_map(int fd);
void	ft_var(t_so_long *var);
int		ft_strcmp(const char *str1, const char *str2);
char	*ft_strrchr(const char *str, int c);
void	xpm_to_image(t_so_long *var);
void	image_to_window(t_so_long *var);
char	*ft_strdup(char *s1);
int		ft_strchr(char *str, int c);
size_t	ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);
void	ft_putnbr(int n);
void	find_player(t_so_long *p);
void	ft_esc(t_so_long *var);
void	ft_right(t_so_long *var);
void	ft_up(t_so_long *var);
void	ft_left(t_so_long *var);
void	ft_down(t_so_long *var);
void	ft_putchar(char c);
void	rectangular_map(char **N);
int		check_walls(char **N);

#endif
