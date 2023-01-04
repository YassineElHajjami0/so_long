/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_l_r.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hajj <yel-hajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 11:07:27 by yel-hajj          #+#    #+#             */
/*   Updated: 2023/01/04 11:07:42 by yel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    help_check_r_l(t_allvar *allvar, int sign)
{
    allvar->moves_count++;
    allvar->tab[allvar->pos_py][allvar->pos_px + sign] = 'P';
    allvar->tab[allvar->pos_py][allvar->pos_px] = '0';
    mlx_put_image_to_window(allvar->mlx, allvar->mlx_win, allvar->mlx_image_wall, 0 , 0);
    mlx_string_put(allvar->mlx, allvar->mlx_win, 10, 5,  255, ft_itoa(allvar->moves_count));
    mlx_put_image_to_window(allvar->mlx, allvar->mlx_win, allvar->mlx_image_ground, allvar->pos_px*32, allvar->pos_py*32);
    mlx_put_image_to_window(allvar->mlx, allvar->mlx_win, allvar->mlx_image_ground, (allvar->pos_px + sign)*32, allvar->pos_py *32);
    mlx_put_image_to_window(allvar->mlx, allvar->mlx_win, allvar->mlx_image_hero, (allvar->pos_px + sign)*32, allvar->pos_py*32);
}

void    check_left(t_allvar *allvar)
{
    if (allvar->tab[allvar->pos_py][allvar->pos_px - 1] != '1')
    {
        if (allvar->tab[allvar->pos_py][allvar->pos_px - 1] == 'C')
        {
            allvar->count_c--;
            allvar->tab[allvar->pos_py][allvar->pos_px - 1] = '0';
        }
        if(allvar->tab[allvar->pos_py][allvar->pos_px - 1] == 'A')
        {
            write(1, "YOU LOSE\n", 9);
            exit(0);
        }
        if (allvar->tab[allvar->pos_py][allvar->pos_px - 1] == 'E' && allvar->count_c == 0)
        {
            write(1, "YOU WON\n", 8);
            exit(0);
        }
        else if (allvar->tab[allvar->pos_py][allvar->pos_px - 1] != 'E')
            help_check_r_l(allvar, -1);
        else
            return ;
        allvar->pos_px -= 1;
    }
}

void    check_right(t_allvar *allvar)
{
    if (allvar->tab[allvar->pos_py][allvar->pos_px + 1] != '1')
    {
        if (allvar->tab[allvar->pos_py][allvar->pos_px + 1] == 'C')
        {
            mlx_put_image_to_window(allvar->mlx, allvar->mlx_win, allvar->mlx_image_wall, 0 , 0);
            mlx_string_put(allvar->mlx, allvar->mlx_win, 10, 5,  255, ft_itoa(allvar->moves_count));
            allvar->count_c--;
            allvar->tab[allvar->pos_py][allvar->pos_px + 1] = '0';
        }
        if(allvar->tab[allvar->pos_py][allvar->pos_px + 1] == 'A')
        {
            write(1, "YOU LOSE\n", 9);
            exit(0);
        }
        if (allvar->tab[allvar->pos_py][allvar->pos_px + 1] == 'E' && allvar->count_c == 0)
        {
            write(1, "YOU WON\n", 8);
            exit(0);
        }
        else if (allvar->tab[allvar->pos_py][allvar->pos_px + 1] != 'E')
            help_check_r_l(allvar, 1);
        else
            return ;
        allvar->pos_px += 1;
    }
}