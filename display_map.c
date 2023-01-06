/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hajj <yel-hajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 13:32:19 by yel-hajj          #+#    #+#             */
/*   Updated: 2023/01/06 15:45:35 by yel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_vrs(t_allvar *allvar)
{
	allvar->mlx_image_wall = mlx_xpm_file_to_image(allvar->mlx,
			"wall.xpm", &allvar->x, &allvar->y);
	allvar->mlx_image_ground = mlx_xpm_file_to_image(allvar->mlx,
			"ground.xpm", &allvar->x, &allvar->y);
	allvar->mlx_image_hero = mlx_xpm_file_to_image(allvar->mlx,
			"hero.xpm", &allvar->x, &allvar->y);
	allvar->mlx_image_door = mlx_xpm_file_to_image(allvar->mlx,
			"door.xpm", &allvar->x, &allvar->y);
	allvar->mlx_image_diamond = mlx_xpm_file_to_image(allvar->mlx,
			"diamond.xpm", &allvar->x, &allvar->y);
	allvar->mlx_image_enemy = mlx_xpm_file_to_image(allvar->mlx,
			"enemy.xpm", &allvar->x, &allvar->y);
	allvar->mlx_image_enemyy = mlx_xpm_file_to_image(allvar->mlx,
			"enemyy.xpm", &allvar->x, &allvar->y);
	allvar->i = 0;
	allvar->j = 0;
	allvar->x = 0;
	allvar->y = 0;
}

void	third_part(t_allvar *allvar)
{
	if (allvar->tab[allvar->i][allvar->j] == 'A')
	{
		mlx_put_image_to_window(allvar->mlx, allvar->mlx_win,
			allvar->mlx_image_ground, allvar->x, allvar->y);
		if (allvar->z == 0)
		{	
			mlx_put_image_to_window(allvar->mlx, allvar->mlx_win,
				allvar->mlx_image_enemy, allvar->x, allvar->y);
			allvar->z = 1;
		}
		else
		{
			mlx_put_image_to_window(allvar->mlx, allvar->mlx_win,
				allvar->mlx_image_enemyy, allvar->x, allvar->y);
			allvar->z = 0;
		}
	}
}

void	second_part(t_allvar *allvar)
{
	if (allvar->tab[allvar->i][allvar->j] == 'E')
	{
		mlx_put_image_to_window(allvar->mlx, allvar->mlx_win,
			allvar->mlx_image_ground, allvar->x, allvar->y);
		mlx_put_image_to_window(allvar->mlx, allvar->mlx_win,
			allvar->mlx_image_door, allvar->x, allvar->y);
	}
	else if (allvar->tab[allvar->i][allvar->j] == 'C')
	{
		mlx_put_image_to_window(allvar->mlx, allvar->mlx_win,
			allvar->mlx_image_ground, allvar->x, allvar->y);
		mlx_put_image_to_window(allvar->mlx, allvar->mlx_win,
			allvar->mlx_image_diamond, allvar->x, allvar->y);
	}
}

void	first_part(t_allvar *allvar)
{
	if (allvar->tab[allvar->i][allvar->j] == '1')
		mlx_put_image_to_window(allvar->mlx, allvar->mlx_win,
			allvar->mlx_image_wall, allvar->x, allvar->y);
	else if (allvar->tab[allvar->i][allvar->j] == '0')
		mlx_put_image_to_window(allvar->mlx, allvar->mlx_win,
			allvar->mlx_image_ground, allvar->x, allvar->y);
	else if (allvar->tab[allvar->i][allvar->j] == 'P')
	{
		mlx_put_image_to_window(allvar->mlx, allvar->mlx_win,
			allvar->mlx_image_ground, allvar->x, allvar->y);
		mlx_put_image_to_window(allvar->mlx, allvar->mlx_win,
			allvar->mlx_image_hero, allvar->x, allvar->y);
	}
}

void	display_themap(t_allvar *allvar)
{
	display_vrs(allvar);
	check_vars(allvar);
	while (allvar->tab[allvar->i])
	{
		allvar->j = 0;
		allvar->x = 0;
		while (allvar->tab[allvar->i][allvar->j])
		{
			first_part(allvar);
			second_part(allvar);
			third_part(allvar);
			allvar->x = ++allvar->j * 32;
		}
		allvar->y = ++allvar->i * 32;
	}
	mlx_put_image_to_window(allvar->mlx, allvar->mlx_win,
		allvar->mlx_image_wall, 0, 0);
	print_str_put(allvar, allvar->bonus);
}
