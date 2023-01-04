/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_win.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hajj <yel-hajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 13:18:27 by yel-hajj          #+#    #+#             */
/*   Updated: 2023/01/04 14:37:23 by yel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"

char	**get_linee(char *choosedmap)
{
	int		fd;
	char	*line;
	char	*str;

	line = NULL;
	str = ft_strdup("");
	fd = open(choosedmap, O_RDWR);
	if (fd == -1)
	{
		write(2, "Eroor\n", 6);
		exit(1);
	}
	line = get_next_line(fd);
	while (line)
	{
		if (line[0] == '\n')
		{
			write(2, "Eroor\n", 6);
			exit(1);
		}
		str = ft_strjoinn(str, line);
		free(line);
		line = get_next_line(fd);
	}
	return (ft_split(str, '\n'));
}

void	set_mlx_win(char *map, t_allvar *allvar)
{
	int		fd;
	char	*line;
	char	*str;

	allvar->i = 0;
	allvar->len = 0;
	line = NULL;
	str = ft_strdup("");
	fd = open(map, O_RDWR);
	line = get_next_line(fd);
	if (line)
		allvar->len = ft_strlen(line) - 1;
	while (line)
	{
		allvar->i++;
		free(line);
		line = get_next_line(fd);
	}
	allvar->mlx_win = mlx_new_window(allvar->mlx,
			(int)allvar->len * 32, allvar->i * 32, "so_long");
}

int	checkpoints(char **str, t_allvar *allvar)
{
	allvar->j = 0;
	allvar->len = 0;
	while (str[1][allvar->j])
	{
		if (str[1][allvar->j] == '.')
		allvar->len++;
		allvar->j++;
	}
	if (allvar->len != 1)
		return (0);
	return (1);
}

void	parsing(int ac, char **str, t_allvar *allvar)
{
	if (ac != 2 || !checkpoints(str, allvar))
	{
		write(2, "Eroor\n", 6);
		exit(1);
	}
	allvar->j = 0;
	allvar->i = 0;
	allvar->len = 4;
	while (str[1][allvar->j])
		allvar->j++;
	if (allvar->j < 5)
	{
		write(2, "Eroor\n", 6);
		exit(1);
	}
	allvar->j--;
	if (str[1][allvar->j] != 'r' || str[1][allvar->j - 1] != 'e'
	|| str[1][allvar->j - 2] != 'b' || str[1][allvar->j - 3] != '.')
	{
		write(2, "Eroor\n", 6);
		exit(1);
	}
	allvar->choosed_map = str[1];
}
