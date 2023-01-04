/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hajj <yel-hajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 10:33:07 by yel-hajj          #+#    #+#             */
/*   Updated: 2023/01/04 15:09:37 by yel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"

void	destroy_all(t_allvar *allvar)
{
	mlx_destroy_image(allvar->mlx, allvar->mlx_image_hero);
	mlx_destroy_image(allvar->mlx, allvar->mlx_image_diamond);
	mlx_destroy_image(allvar->mlx, allvar->mlx_image_door);
	mlx_destroy_image(allvar->mlx, allvar->mlx_image_enemy);
	mlx_destroy_image(allvar->mlx, allvar->mlx_image_enemyy);
	mlx_destroy_image(allvar->mlx, allvar->mlx_image_ground);
	mlx_destroy_image(allvar->mlx, allvar->mlx_image_wall);
	mlx_destroy_window(allvar->mlx, allvar->mlx_win);
}

int	main(int ac, char **av)
{
	t_allvar	allvar;

	allvar.tab = NULL;
	allvar.z = 0;
	allvar.moves_count = 0;
	allvar.mlx = mlx_init();
	parsing(ac, av, &allvar);
	allvar.tab = get_linee(allvar.choosed_map);
	checkmap(av[1], &allvar);
	set_mlx_win(av[1], &allvar);
	display_themap(&allvar);
	mlx_hook(allvar.mlx_win, 2, 1L << 0, &checkkey, &allvar);
	mlx_string_put(allvar.mlx, allvar.mlx_win, 10, 5, 255, "0");
	allvar.moves_count = 0;
	mlx_loop_hook(allvar.mlx, &move_enemy, &allvar);
	mlx_loop(allvar.mlx);
	destroy_all(&allvar);
	return (0);
	system("leaks so_long");
}
