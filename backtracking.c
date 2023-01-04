/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hajj <yel-hajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 10:28:33 by yel-hajj          #+#    #+#             */
/*   Updated: 2023/01/04 13:43:19 by yel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	valid(t_allvar *allvar, char **map, int y, int x)
{
	if (map[y][x] == '1')
		return (0);
	if (map[y][x] == 'P')
		return (1);
	map[y][x] = '1';
	if (valid(allvar, map, y, x + 1))
		return (1);
	else if (valid(allvar, map, y + 1, x))
		return (1);
	else if (valid(allvar, map, y, x - 1))
		return (1);
	else if (valid(allvar, map, y - 1, x))
		return (1);
	else
		return (0);
}

void	show_error(int num)
{
	write(num, "Eroor\n", 6);
	exit(1);
}

void	check_backtracking(char *choosedmap, t_allvar *allvar)
{
	char	**map;
	char	**map1;

	allvar->i = 0;
	allvar->j = 0;
	map = get_linee(choosedmap);
	map1 = get_linee(choosedmap);
	while (map[allvar->i])
	{
		allvar->j = 0;
		while (map[allvar->i][allvar->j])
		{
			if (map[allvar->i][allvar->j] == 'E'
			|| map[allvar->i][allvar->j] == 'C')
			{
				if (!valid(allvar, map, allvar->i, allvar->j))
					show_error(2);
				map = map1;
			}
			allvar->j++;
		}
		allvar->i++;
	}
}
