/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hajj <yel-hajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 10:07:16 by yel-hajj          #+#    #+#             */
/*   Updated: 2023/01/01 10:07:35 by yel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    check_up(t_allvar *allvar)
{
    if (allvar->tab[allvar->pos_py - 1][allvar->pos_px] != '1')
    {
        if (allvar->tab[allvar->pos_py - 1][allvar->pos_px] == 'C')
        {
            allvar->count_c--;
            allvar->tab[allvar->pos_py - 1][allvar->pos_px] = '0';
        }
        if (allvar->tab[allvar->pos_py - 1][allvar->pos_px] == 'E' && allvar->count_c == 0)
        {
            write(1, "YOU WON\n", 8);
            exit(0);
        }
        else if (allvar->tab[allvar->pos_py - 1][allvar->pos_px] != 'E')
        {
            mlx_put_image_to_window(allvar->mlx, allvar->mlx_win, allvar->mlx_image_ground, allvar->pos_px*32, allvar->pos_py*32);
            mlx_put_image_to_window(allvar->mlx, allvar->mlx_win, allvar->mlx_image_ground, allvar->pos_px*32, (allvar->pos_py -1)*32);
            mlx_put_image_to_window(allvar->mlx, allvar->mlx_win, allvar->mlx_image_hero, allvar->pos_px*32, (allvar->pos_py -1)*32);
            allvar->pos_py -= 1;
        }
        else   
            return ;
    }
}

void    check_down(t_allvar *allvar)
{
    if (allvar->tab[allvar->pos_py + 1][allvar->pos_px] != '1')
    {
        if (allvar->tab[allvar->pos_py + 1][allvar->pos_px] == 'C')
        {
            allvar->count_c--;
            allvar->tab[allvar->pos_py + 1][allvar->pos_px] = '0';
        }  
        if (allvar->tab[allvar->pos_py + 1][allvar->pos_px] == 'E' && allvar->count_c == 0)
        {
            write(1, "YOU WON\n", 8);
            exit(0);
        }
        else if (allvar->tab[allvar->pos_py + 1][allvar->pos_px] != 'E')
        {
            mlx_put_image_to_window(allvar->mlx, allvar->mlx_win, allvar->mlx_image_ground, allvar->pos_px*32, allvar->pos_py*32);
            mlx_put_image_to_window(allvar->mlx, allvar->mlx_win, allvar->mlx_image_ground, allvar->pos_px*32, (allvar->pos_py + 1)*32);
            mlx_put_image_to_window(allvar->mlx, allvar->mlx_win, allvar->mlx_image_hero, allvar->pos_px*32, (allvar->pos_py + 1)*32);
        }
        else
            return ;
        allvar->pos_py += 1;
    }
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
        if (allvar->tab[allvar->pos_py][allvar->pos_px - 1] == 'E' && allvar->count_c == 0)
        {
            write(1, "YOU WON\n", 8);
            exit(0);
        }
        else if (allvar->tab[allvar->pos_py][allvar->pos_px - 1] != 'E')
        {
            mlx_put_image_to_window(allvar->mlx, allvar->mlx_win, allvar->mlx_image_ground, allvar->pos_px*32, allvar->pos_py*32);
            mlx_put_image_to_window(allvar->mlx, allvar->mlx_win, allvar->mlx_image_ground, (allvar->pos_px - 1)*32, allvar->pos_py *32);
            mlx_put_image_to_window(allvar->mlx, allvar->mlx_win, allvar->mlx_image_hero, (allvar->pos_px - 1)*32, allvar->pos_py*32);
        }
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
            allvar->count_c--;
            allvar->tab[allvar->pos_py][allvar->pos_px + 1] = '0';
        }
        if (allvar->tab[allvar->pos_py][allvar->pos_px + 1] == 'E' && allvar->count_c == 0)
        {
            write(1, "YOU WON\n", 8);
            exit(0);
        }
        else if (allvar->tab[allvar->pos_py][allvar->pos_px + 1] != 'E')
        {
            mlx_put_image_to_window(allvar->mlx, allvar->mlx_win, allvar->mlx_image_ground, allvar->pos_px*32, allvar->pos_py*32);
            mlx_put_image_to_window(allvar->mlx, allvar->mlx_win, allvar->mlx_image_ground, (allvar->pos_px + 1)*32, allvar->pos_py *32);
            mlx_put_image_to_window(allvar->mlx, allvar->mlx_win, allvar->mlx_image_hero, (allvar->pos_px + 1)*32, allvar->pos_py*32);
        }
        else
            return ;
        allvar->pos_px += 1;
    }
}

int checkkey(int keycode, t_allvar *allvar)
{
    printf("count l9ess =>%d\n", allvar->count_c);
    allvar->i = 0;
    if (keycode == 53)
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