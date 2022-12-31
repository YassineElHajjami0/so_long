/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hajj <yel-hajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 10:33:07 by yel-hajj          #+#    #+#             */
/*   Updated: 2022/12/31 12:27:06 by yel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"

char    **get_line(char *choosedmap)
{
    int fd;
    char *line;
    char *str;

    line = NULL;
    str = ft_strdup("");
    fd = open(choosedmap, O_RDWR);
    if(fd == -1)
    {
        write(2, "Eroor\n", 6);
        exit(1);
    }
    line = get_next_line(fd);
    while(line)
    {
        if (line[0] == '\n')
        {
            write(2, "Eroor\n", 6);
            exit(1);
        }
        str = ft_strjoinn(str, line);
        free(line);
        line = get_next_line(fd);
    }
    return (ft_split(str, '\n'));
}

void    display_themap(t_allvar *allvar)
{
    allvar->mlx_image_wall = mlx_xpm_file_to_image(allvar->mlx, "wall.xpm", &allvar->x, &allvar->y);
    allvar->mlx_image_ground = mlx_xpm_file_to_image(allvar->mlx, "ground.xpm", &allvar->x, &allvar->y);
    allvar->mlx_image_hero = mlx_xpm_file_to_image(allvar->mlx, "hero.xpm", &allvar->x, &allvar->y);
    allvar->mlx_image_door = mlx_xpm_file_to_image(allvar->mlx, "door.xpm", &allvar->x, &allvar->y);
    allvar->mlx_image_diamond = mlx_xpm_file_to_image(allvar->mlx, "diamond.xpm", &allvar->x, &allvar->y);
    allvar->mlx_image_enemy = mlx_xpm_file_to_image(allvar->mlx, "enemy.xpm", &allvar->x, &allvar->y);
    allvar->i = 0;
    allvar->j = 0;
    allvar->x = 0;
    allvar->y = 0;
    while (allvar->tab[allvar->i])
    {
        allvar->j = 0;
        allvar->x = 0;
        while (allvar->tab[allvar->i][allvar->j])
        {
            if (allvar->tab[allvar->i][allvar->j] == '1')
                mlx_put_image_to_window(allvar->mlx, allvar->mlx_win, allvar->mlx_image_wall, allvar->x, allvar->y);
            else if (allvar->tab[allvar->i][allvar->j] == '0')
                mlx_put_image_to_window(allvar->mlx, allvar->mlx_win, allvar->mlx_image_ground, allvar->x, allvar->y);
            else if (allvar->tab[allvar->i][allvar->j] == 'P')
            {
                allvar->pos_px = allvar->j;
                allvar->pos_py = allvar->i;
                mlx_put_image_to_window(allvar->mlx, allvar->mlx_win, allvar->mlx_image_ground, allvar->x, allvar->y);
                mlx_put_image_to_window(allvar->mlx, allvar->mlx_win, allvar->mlx_image_hero, allvar->x, allvar->y);
            }
            else if (allvar->tab[allvar->i][allvar->j] == 'E')
            {
                mlx_put_image_to_window(allvar->mlx, allvar->mlx_win, allvar->mlx_image_ground, allvar->x, allvar->y);
                mlx_put_image_to_window(allvar->mlx, allvar->mlx_win, allvar->mlx_image_door, allvar->x, allvar->y);
            }
            else if (allvar->tab[allvar->i][allvar->j] == 'C')
            {
                mlx_put_image_to_window(allvar->mlx, allvar->mlx_win, allvar->mlx_image_ground, allvar->x, allvar->y);
                mlx_put_image_to_window(allvar->mlx, allvar->mlx_win, allvar->mlx_image_diamond, allvar->x, allvar->y);
            }
            else if (allvar->tab[allvar->i][allvar->j] == 'A')
            {
                mlx_put_image_to_window(allvar->mlx, allvar->mlx_win, allvar->mlx_image_ground, allvar->x, allvar->y);
                mlx_put_image_to_window(allvar->mlx, allvar->mlx_win, allvar->mlx_image_enemy, allvar->x, allvar->y);
            }
            allvar->j++;
            allvar->x = allvar->j * 32;
        }
        allvar->i++;
        allvar->y = allvar->i * 32;
    }
}

void    set_mlx_win(char *map, t_allvar *allvar)
{
    int fd;
    char *line;
    char *str;

    allvar->i = 0;
    allvar->len = 0;    
    line = NULL;
    str = ft_strdup("");
    fd = open(map, O_RDWR);
    line = get_next_line(fd);
    if(line)
        allvar->len = ft_strlen(line) - 1;
    while(line)
    {
        allvar->i++;
        free(line);
        line = get_next_line(fd);
    }
    allvar->mlx_win = mlx_new_window(allvar->mlx, (int)allvar->len*32, allvar->i*32, "so_long");
}

int checkpoints(char **str, t_allvar *allvar)
{
    allvar->j = 0;
    allvar->len = 0;
    while(str[1][allvar->j])
    {
        if(str[1][allvar->j] == '.')
            allvar->len++;
        allvar->j++;
    }
    if(allvar->len != 1)
        return (0);
    return (1);
}

void    parsing(int ac, char **str, t_allvar *allvar)
{
    if (ac != 2 || !checkpoints(str, allvar))
    {
        write(2, "Eroor\n", 6);
        exit(1);
    }
    allvar->j = 0;
    allvar->i = 0;
    allvar->len = 4;
    while (str[1][allvar->j])
        allvar->j++;
    if(allvar->j < 5)
    {
        write(2, "Eroor\n", 6);
        exit(1);
    }
    allvar->j--;
    if(str[1][allvar->j] != 'r' || str[1][allvar->j - 1] != 'e' 
    || str[1][allvar->j - 2] != 'b' || str[1][allvar->j - 3] != '.')
    {
        write(2, "Eroor\n", 6);
        exit(1);
    }
    allvar->choosed_map = str[1];
}

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

int main(int ac, char **av)
{
    t_allvar allvar;

    allvar.tab = NULL;
    allvar.mlx = mlx_init();
    parsing(ac, av, &allvar);
    allvar.tab = get_line(allvar.choosed_map);
    checkmap(&allvar);
    printf("count of L9ess : %d\n", allvar.count_c);
    set_mlx_win("map.ber" ,&allvar);
    display_themap(&allvar);
    mlx_hook(allvar.mlx_win, 2, 1L<<0, &checkkey, &allvar);
    mlx_loop(allvar.mlx);
    return 0;
}