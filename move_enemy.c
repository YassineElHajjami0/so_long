/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hajj <yel-hajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 13:21:51 by yel-hajj          #+#    #+#             */
/*   Updated: 2023/01/06 15:51:30 by yel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_right(t_allvar *allvar)
{
	if (allvar->tab[allvar->pos_enemyy][allvar->pos_enemyx + 1] == 'P')
	{
		write(1, "YOU LOSE\n", 9);
		exit(0);
	}
	allvar->tab[allvar->pos_enemyy][allvar->pos_enemyx] = '0';
	allvar->tab[allvar->pos_enemyy][allvar->pos_enemyx + 1] = 'A';
	allvar->pos_enemyx++;
	display_themap(allvar);
}

int	move_left(t_allvar *allvar)
{
	allvar->move_l = 1;
	if (allvar->tab[allvar->pos_enemyy][allvar->pos_enemyx - 1] == 'P')
	{
		write(1, "YOU LOSE\n", 9);
		exit(0);
	}
	if (allvar->tab[allvar->pos_enemyy][allvar->pos_enemyx - 1] != '0'
		&& allvar->tab[allvar->pos_enemyy][allvar->pos_enemyx - 1] != 'P')
	{
		allvar->i = 1000;
		allvar->move_l = 0;
		return (0);
	}
	allvar->tab[allvar->pos_enemyy][allvar->pos_enemyx] = '0';
	allvar->tab[allvar->pos_enemyy][allvar->pos_enemyx - 1] = 'A';
	display_themap(allvar);
	allvar->pos_enemyx--;
	return (1);
}

int	move_enemy(t_allvar *allvar)
{
	if (allvar->bonus == 0)
		return (0);
	if (allvar->i == 5000)
	{
		if (allvar->move_l == 0
			&& (allvar->tab[allvar->pos_enemyy][allvar->pos_enemyx + 1] == '0'
			|| allvar->tab[allvar->pos_enemyy][allvar->pos_enemyx + 1] == 'P'))
		{
			move_right(allvar);
			mlx_destroy_image(allvar->mlx, allvar->mlx_image_enemy);
			mlx_destroy_image(allvar->mlx, allvar->mlx_image_enemyy);
		}	
		else
		{
			if (!move_left(allvar))
				return (0);
		}
		allvar->i = 0;
	}
	allvar->i++;
	return (0);
}
