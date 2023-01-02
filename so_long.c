/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hajj <yel-hajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 10:33:07 by yel-hajj          #+#    #+#             */
/*   Updated: 2023/01/02 16:39:14 by yel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"

char    **get_linee(char *choosedmap)
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

// int    set_the_enemy(t_allvar *allvar)
// {
//     allvar->i = 0;
//     allvar->j = 0;
//     while(allvar->tab[allvar->i])
//     {
//         allvar->j = 0;
//         while(allvar->tab[allvar->i][allvar->j])
//         {
//             if (allvar->tab[allvar->i][allvar->j] == '0' && allvar->tab[allvar->i][allvar->j+1] == '0')
//             {
                
//                 //move_enemy(allvar, allvar->i, allvar->j);
//                 return 1;
//             }
//             allvar->j++;
//         }
//         allvar->i++;
//     }
//     return 1;
// }

int    move_enemy(t_allvar *allvar)
{
    if (allvar->tab[allvar->y][allvar->pos_enemyx+1] == '0')
    {
        allvar->tab[allvar->y][allvar->pos_enemyx+1] = 'A';
        display_themap(allvar);
    }
    if (allvar->tab[allvar->y][allvar->pos_enemyx-1] == '0')
    {
        allvar->tab[allvar->y][allvar->pos_enemyx-1] = 'A';
        display_themap(allvar);
    }
    return 0;
}


int main(int ac, char **av)
{
    t_allvar allvar;

    allvar.tab = NULL;
    allvar.mlx = mlx_init();
    parsing(ac, av, &allvar);
    allvar.tab = get_linee(allvar.choosed_map);
    checkmap(av[1], &allvar);
    set_mlx_win(av[1] ,&allvar);
    display_themap(&allvar);
    //set_the_enemy(&allvar);
    mlx_hook(allvar.mlx_win, 2, 1L<<0, &checkkey, &allvar);
    mlx_string_put(allvar.mlx, allvar.mlx_win, 10, 5,  255, "0");
    printf("posx = %d,  posy = %d\n", allvar.pos_enemyx, allvar.pos_enemyy);
    allvar.moves_count = 0;
    //mlx_loop_hook(allvar.mlx, &move_enemy, &allvar);
    mlx_loop(allvar.mlx);
    printf("-----------------\n");
    return 0;
}