/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoukou <ikoukou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 16:17:05 by ikoukou           #+#    #+#             */
/*   Updated: 2022/04/08 20:08:42 by ikoukou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*find_line(char *s)
{
	int		i;
	char	*s2;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		s2 = (char *)malloc(sizeof(char) * (i + 2));
	else
		s2 = (char *)malloc(sizeof(char) * (i + 1));
	if (!s2)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		s2[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
	{
		s2[i] = s[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char	*find_rest(char *ss)
{
	int		i;
	int		j;
	char	*s;

	i = 0;
	j = 0;
	while (ss[i] != '\0' && ss[i] != '\n')
		i++;
	if (ss[i] == '\0')
	{
		free(ss);
		return (NULL);
	}
	s = (char *)malloc(sizeof(char) * ft_strlen(ss) - i);
	if (!s)
		return (NULL);
	i++;
	while (ss[i])
		s[j++] = ss[i++];
	free(ss);
	s[j] = '\0';
	return (s);
}

int	ft_check(char *buf, char *s, int re)
{
	if (re < 0)
	{
		free(buf);
		if (s != NULL)
			free(s);
		return (1);
	}
	else if (re == 0 && s == NULL)
	{
		free(buf);
		return (1);
	}
	else if (s[0] == '\0')
	{
		free(s);
		free(buf);
		return (1);
	}
	free(buf);
	return (0);
}

char	*ft_read(int fd, char *s, char *buf)
{
	char	*tmp;
	int		re;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	re = read(fd, buf, BUFFER_SIZE);
	while (re > 0)
	{
		buf[re] = 0;
		if (s == 0)
			s = ft_strdup(buf);
		else
		{
			tmp = ft_strjoin(s, buf);
			free(s);
			s = tmp;
		}
		if (ft_strchr(s, '\n'))
			break ;
		re = read(fd, buf, BUFFER_SIZE);
	}
	if (ft_check(buf, s, re))
		return (0);
	return (s);
}

char	*get_next_line(int fd)
{
	static char	*s[10240];
	char		*line;
	char		*buf;

	buf = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	s[fd] = ft_read(fd, s[fd], buf);
	if (!s[fd])
		return (NULL);
	line = find_line(s[fd]);
	s[fd] = find_rest(s[fd]);
	return (line);
}
