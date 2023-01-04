/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hajj <yel-hajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 10:07:16 by yel-hajj          #+#    #+#             */
/*   Updated: 2023/01/04 14:23:52 by yel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	help_check_u_d(t_allvar *allvar, int sign)
{
	allvar->moves_count++;
	allvar->tab[allvar->pos_py][allvar->pos_px] = '0';
	allvar->tab[allvar->pos_py + sign][allvar->pos_px] = 'P';
	mlx_put_image_to_window(allvar->mlx, allvar->mlx_win,
		allvar->mlx_image_wall, 0, 0);
	mlx_string_put(allvar->mlx, allvar->mlx_win, 10, 5, 255,
		ft_itoa(allvar->moves_count));
	mlx_put_image_to_window(allvar->mlx, allvar->mlx_win,
		allvar->mlx_image_ground, allvar->pos_px * 32, allvar->pos_py * 32);
	mlx_put_image_to_window(allvar->mlx, allvar->mlx_win,
		allvar->mlx_image_ground, allvar->pos_px * 32,
		(allvar->pos_py + sign) * 32);
	mlx_put_image_to_window(allvar->mlx, allvar->mlx_win,
		allvar->mlx_image_hero,
		allvar->pos_px * 32, (allvar->pos_py + sign) * 32);
}

void	check_won(t_allvar *allvar, int sign)
{
	if (allvar->tab[allvar->pos_py + sign][allvar->pos_px] == 'E'
	&& allvar->count_c == 0)
	{
		write(1, "YOU WON\n", 8);
		exit(0);
	}
}

void	check_up(t_allvar *allvar)
{
	if (allvar->tab[allvar->pos_py - 1][allvar->pos_px] != '1')
	{
		if (allvar->tab[allvar->pos_py - 1][allvar->pos_px] == 'C')
		{
			mlx_put_image_to_window(allvar->mlx, allvar->mlx_win,
				allvar->mlx_image_wall, 0, 0);
			mlx_string_put(allvar->mlx, allvar->mlx_win, 10, 5, 255,
				ft_itoa(allvar->moves_count));
			allvar->count_c-- ;
			allvar->tab[allvar->pos_py - 1][allvar->pos_px] = '0';
		}
		if (allvar->tab[allvar->pos_py - 1][allvar->pos_px] == 'A')
		{
			write(1, "YOU LOSE\n", 9);
			exit(0);
		}
		check_won(allvar, -1);
		if (allvar->tab[allvar->pos_py - 1][allvar->pos_px] != 'E')
			help_check_u_d(allvar, -1);
		else
			return ;
		allvar->pos_py -= 1;
	}
}

void	check_down(t_allvar *allvar)
{
	if (allvar->tab[allvar->pos_py + 1][allvar->pos_px] != '1')
	{
		if (allvar->tab[allvar->pos_py + 1][allvar->pos_px] == 'C')
		{
			mlx_put_image_to_window(allvar->mlx, allvar->mlx_win,
				allvar->mlx_image_wall, 0, 0);
			mlx_string_put(allvar->mlx, allvar->mlx_win, 10, 5, 255,
				ft_itoa(allvar->moves_count));
			allvar->count_c--;
			allvar->tab[allvar->pos_py + 1][allvar->pos_px] = '0';
		}
		if (allvar->tab[allvar->pos_py + 1][allvar->pos_px] == 'A')
		{
			write(1, "YOU LOSE\n", 9);
			exit(0);
		}
		check_won(allvar, 1);
		if (allvar->tab[allvar->pos_py + 1][allvar->pos_px] != 'E')
			help_check_u_d(allvar, 1);
		else
			return ;
		allvar->pos_py += 1;
	}
}

int	checkkey(int keycode, t_allvar *allvar)
{
	if (keycode == 53 || keycode == 17)
		exit(0);
	if (keycode == 13)
		check_up(allvar);
	if (keycode == 1)
		check_down(allvar);
	if (keycode == 0)
		check_left(allvar);
	if (keycode == 2)
		check_right(allvar);
	return (0);
}
