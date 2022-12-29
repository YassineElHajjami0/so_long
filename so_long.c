/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hajj <yel-hajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 10:33:07 by yel-hajj          #+#    #+#             */
/*   Updated: 2022/12/28 17:06:14 by yel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"

int get_line()
{
    int fd;
    char *line;
    line = NULL;
    int i;

    i = 0;
    fd = open("map.ber", O_RDWR);
    line = get_next_line(fd);
    while(line)
    {
        i++;
        free(line);
        line = get_next_line(fd);
    }
    return i;
}

char    **allocate(int i, t_allvar *allvar)
{
    char **str;
    
    str = (char **)malloc(sizeof(char *) * i);
    allvar->i = 0;
    while (str[i])
    {
        while(str[i][j])
            j++;
    }
    
    return str ;
}

int main()
{
    t_allvar allvar;
    
    allvar.tab = NULL;
    allvar.mlx = mlx_init();
    allvar.i = get_line();
    printf("i => %d\n", allvar.i);
    allvar.tab = allocate(allvar.i, &allvar);
    allvar.mlx_win = mlx_new_window(allvar.mlx,1000,500,"alae");
    allvar.mlx_image = mlx_xpm_file_to_image(allvar.mlx, "wall.xpm", &allvar.x, &allvar.y);
    mlx_put_image_to_window(allvar.mlx, allvar.mlx_win, allvar.mlx_image, 0, 0);
    mlx_loop(allvar.mlx);
    return 0;
}