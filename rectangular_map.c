/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rectangular_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoukou <ikoukou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 18:00:55 by ikoukou           #+#    #+#             */
/*   Updated: 2022/04/08 22:12:17 by ikoukou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	rectangular_map(char **n)
{
	int	j;
	int	len_j;
	int	len;

	j = 0;
	len_j = ft_strlen(n[j]);
	while (n[j] != NULL)
	{
		len = ft_strlen(n[j]);
		if (len_j != len)
		{
			write (1, "ERROR MAP", 9);
			exit(0);
		}
		j++;
	}
}
