/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hajj <yel-hajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 10:28:33 by yel-hajj          #+#    #+#             */
/*   Updated: 2023/01/07 11:50:06 by yel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	valid(char **map, char c, int y, int x)
{
	if (map[y][x] == '1' || (c != 'E' && map[y][x] == 'E'))
		return (0);
	if (map[y][x] == 'P')
		return (1);
	map[y][x] = '1';
	if (valid(map, c, y, x + 1))
		return (1);
	else if (valid(map, c, y + 1, x))
		return (1);
	else if (valid(map, c, y, x - 1))
		return (1);
	else if (valid(map, c, y - 1, x))
		return (1);
	else
		return (0);
}

void	show_error(int num)
{
	write(num, "Eroor\n", 6);
	exit(1);
}

void	freemap(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		free(s[i++]);
	free(s);
}

void	check_backtracking(char *choosedmap, t_allvar *allvar)
{
	char	**map;

	allvar->i = 0;
	allvar->j = 0;
	map = get_linee(choosedmap);
	while (map[allvar->i])
	{
		allvar->j = 0;
		while (map[allvar->i][allvar->j])
		{
			if (map[allvar->i][allvar->j] == 'E'
				|| map[allvar->i][allvar->j] == 'C')
			{
				if (!valid(map, map[allvar->i][allvar->j],
					allvar->i, allvar->j))
					show_error(2);
				freemap(map);
				map = get_linee(choosedmap);
			}
			allvar->j++;
		}
		allvar->i++;
	}
	freemap(map);
}
