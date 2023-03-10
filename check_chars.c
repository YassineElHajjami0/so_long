/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_chars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hajj <yel-hajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 18:52:53 by yel-hajj          #+#    #+#             */
/*   Updated: 2023/01/07 13:37:20 by yel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_alpha(t_allvar *allvar)
{
	if (allvar->bonus == 1)
	{
		if (allvar->tab[allvar->i][allvar->j] != '1'
		&& allvar->tab[allvar->i][allvar->j] != '0'
		&& allvar->tab[allvar->i][allvar->j] != 'P'
		&& allvar->tab[allvar->i][allvar->j] != 'C'
		&& allvar->tab[allvar->i][allvar->j] != 'E'
		&& allvar->tab[allvar->i][allvar->j] != 'A')
		{
			write(2, "Eroor\n", 6);
			exit(1);
		}
	}
	if (allvar->tab[allvar->i][allvar->j] != '1'
	&& allvar->tab[allvar->i][allvar->j] != '0'
	&& allvar->tab[allvar->i][allvar->j] != 'P'
	&& allvar->tab[allvar->i][allvar->j] != 'C'
	&& allvar->tab[allvar->i][allvar->j] != 'E'
	&& allvar->bonus == 0)
	{
		write(2, "Eroor\n", 6);
		exit(1);
	}
}

void	check_ckaracters(t_allvar *allvar)
{
	allvar->i = 0;
	allvar->j = 0;
	allvar->count_c = 0;
	while (allvar->tab[allvar->i])
	{
		allvar->j = 0;
		while (allvar->tab[allvar->i][allvar->j])
		{
			if (allvar->tab[allvar->i][allvar->j] == 'C')
				allvar->count_c++;
			check_alpha(allvar);
			allvar->j++;
		}
		allvar->i++;
	}
}

void	is_rect(t_allvar *allvar)
{
	allvar->i = 0;
	allvar->j = 0;
	allvar->z = 0;
	while (allvar->tab[allvar->i][allvar->j++])
		allvar->z++;
	while (allvar->tab[allvar->i])
	{
		allvar->j = 0;
		while (allvar->tab[allvar->i][allvar->j])
			allvar->j++;
		if (allvar->j != allvar->z)
		{
			write(2, "Eroor\n", 6);
			exit(1);
		}
		allvar->i++;
	}
	if (allvar->i == allvar->z)
		return (write(2, "Eroor\n", 6), exit(1));
}

void	checkmap(char *choosedmap, t_allvar *allvar)
{
	if (!allvar->tab[0])
	{
		write(2, "Eroor\n", 6);
		exit(1);
	}
	check_ckaracters(allvar);
	is_rect(allvar);
	check_walls(allvar);
	check_player_door(allvar);
	check_enemy_pos(allvar);
	check_backtracking(choosedmap, allvar);
}
