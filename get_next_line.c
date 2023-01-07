/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hajj <yel-hajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 10:15:16 by yel-hajj          #+#    #+#             */
/*   Updated: 2023/01/07 10:03:47 by yel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "so_long.h"

char	*get_next_line(int fd)
{
	static char	*sta;
	char		*s;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	sta = putinsta(fd, sta);
	if (!sta)
		return (NULL);
	s = putins(sta);
	sta = putleftinsta(sta);
	return (s);
}

char	*putins(char *sta)
{
	int		i;
	char	*s;

	i = 0;
	if (!sta[i])
		return (NULL);
	while (sta[i] && sta[i] != '\n')
		i++;
	s = (char *)malloc(i + 2);
	if (!s)
		show_error(2);
	i = 0;
	while (sta[i] && sta[i] != '\n')
	{
		s[i] = sta[i];
		i++;
	}
	if (sta[i] == '\n')
	{
		s[i] = sta[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	*putinsta(int fd, char *sta)
{
	char	*buff;
	int		x;

	buff = (char *)malloc(BUFFER_SIZE + 1);
	if (!buff)
		show_error(2);
	x = 1;
	while (!ft_strchr(sta, '\n') && x != 0)
	{
		x = read(fd, buff, BUFFER_SIZE);
		if (x == -1)
		{
			free(buff);
			free(sta);
			return (NULL);
		}
		buff[x] = '\0';
		sta = ft_strjoin(sta, buff);
	}
	free(buff);
	return (sta);
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *sta, int c)
{
	int	i;

	i = 0;
	if (!sta)
		return (0);
	if (c == '\0')
		return ((char *)&sta[ft_strlen(sta)]);
	while (sta[i] != '\0')
	{
		if (sta[i] == (char)c)
			return ((char *)&sta[i]);
		i++;
	}
	return (0);
}
