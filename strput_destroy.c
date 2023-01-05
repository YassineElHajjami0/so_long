/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strput_destroy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hajj <yel-hajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 12:09:10 by yel-hajj          #+#    #+#             */
/*   Updated: 2023/01/05 12:13:32 by yel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_vars(t_allvar *allvar)
{
	if (!allvar->mlx_image_door || !allvar->mlx_image_wall
		|| !allvar->mlx_image_hero || !allvar->mlx_image_ground
		|| !allvar->mlx_image_diamond)
	{
		destroy_all(allvar);
		if (allvar->tab)
			freemap(allvar->tab);
		write(2, "Invalid Path !!!\n", 17);
		exit(1);
	}
}

void	print_str_put(t_allvar *allvar)
{
	char	*p;

	p = ft_itoa(allvar->moves_count);
	mlx_string_put(allvar->mlx, allvar->mlx_win, 10, 5, 255, p);
	free(p);
}

void	destroy_all(t_allvar *allvar)
{
	if (allvar->mlx_image_hero)
		mlx_destroy_image(allvar->mlx, allvar->mlx_image_hero);
	if (allvar->mlx_image_diamond)
		mlx_destroy_image(allvar->mlx, allvar->mlx_image_diamond);
	if (allvar->mlx_image_door)
		mlx_destroy_image(allvar->mlx, allvar->mlx_image_door);
	if (allvar->mlx_image_enemy)
		mlx_destroy_image(allvar->mlx, allvar->mlx_image_enemy);
	if (allvar->mlx_image_enemyy)
		mlx_destroy_image(allvar->mlx, allvar->mlx_image_enemyy);
	if (allvar->mlx_image_ground)
		mlx_destroy_image(allvar->mlx, allvar->mlx_image_ground);
	if (allvar->mlx_image_wall)
		mlx_destroy_image(allvar->mlx, allvar->mlx_image_wall);
}
