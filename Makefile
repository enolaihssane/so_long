# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ikoukou <ikoukou@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/28 09:08:18 by ikoukou           #+#    #+#              #
#    Updated: 2022/04/10 01:33:34 by ikoukou          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS = so_long.c tools.c xpm_img_win.c get_next_line.c get_next_line_utils.c\
ft_var.c ft_map.c checkCEP.c check_map.c ft_move.c ft_player.c rectangular_map.c

CC = gcc

FLAGS = -Wall -Wextra -Werror

OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c so_long.h
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) -lmlx -framework OpenGL -framework AppKit $^ -o $@


clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
	
.PHONY : all clean fclean re