/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoukou <ikoukou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 18:07:56 by ikoukou           #+#    #+#             */
/*   Updated: 2022/04/08 20:23:26 by ikoukou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_map(int fd)
{
	int			i;
	char		*str;
	static char	*p[1000];

	i = 0;
	str = get_next_line(fd);
	while (str)
	{
		p[i] = str;
		str = get_next_line(fd);
		i++;
	}
	p[i] = NULL;
	close(fd);
	return (p);
}
