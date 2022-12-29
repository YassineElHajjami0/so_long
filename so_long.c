/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hajj <yel-hajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 10:33:07 by yel-hajj          #+#    #+#             */
/*   Updated: 2022/12/29 19:22:05 by yel-hajj         ###   ########.fr       */
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
    line = get_next_line(fd);
    while(line)
    {
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
                mlx_put_image_to_window(allvar->mlx, allvar->mlx_win, allvar->mlx_image_hero, allvar->x, allvar->y);
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



void    parsing(int ac, char **str, t_allvar *allvar)
{
    if (ac != 2)
    {
        write(2, "Eroor\n", 6);
        exit(1);
    }
    if(ft_strncmp(str[1],"map.ber",7) != 0 && ft_strncmp(str[1],"map1.ber",8) != 0 
    && ft_strncmp(str[1],"map2.ber",8) != 0 && ft_strncmp(str[1],"map3.ber",8) != 0)
    {
        write(2, "Eroor\n", 6);
        exit(1);
    }
    allvar->choosed_map = str[1];
}

int main(int ac, char **av)
{
    t_allvar allvar;

    allvar.tab = NULL;
    allvar.mlx = mlx_init();
    parsing(ac, av, &allvar);
    allvar.tab = get_line(allvar.choosed_map);
    checkmap(&allvar);
    set_mlx_win("map.ber" ,&allvar);
    display_themap(&allvar);
    mlx_loop(allvar.mlx);
    return 0;
}