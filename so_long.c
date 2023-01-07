/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hajj <yel-hajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 10:33:07 by yel-hajj          #+#    #+#             */
/*   Updated: 2023/01/07 13:54:39 by yel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"

int	exitwin(t_allvar *allvar)
{
	destroy_all(allvar);
	exit(0);
}

int	main(int ac, char **av)
{
	t_allvar	allvar;

	allvar.tab = NULL;
	allvar.z = 0;
	allvar.moves_num = 0;
	allvar.moves_count = 0;
	allvar.bonus = 0;
	allvar.mlx = mlx_init();
	parsing(ac, av, &allvar);
	allvar.tab = get_linee(allvar.choosed_map);
	checkmap(av[1], &allvar);
	set_mlx_win(av[1], &allvar);
	display_themap(&allvar);
	mlx_hook(allvar.mlx_win, 2, 0, &checkkey, &allvar);
	mlx_hook(allvar.mlx_win, 17, 0, &exitwin, &allvar);
	allvar.moves_count = 0;
	mlx_loop_hook(allvar.mlx, &move_enemy, &allvar);
	mlx_loop(allvar.mlx);
	destroy_all(&allvar);
	mlx_destroy_window(allvar.mlx, allvar.mlx_win);
	return (0);
}
