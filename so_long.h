/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hajj <yel-hajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 16:22:24 by yel-hajj          #+#    #+#             */
/*   Updated: 2022/12/31 10:48:43 by yel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>
# include <unistd.h>

typedef struct s_allvar
{
    int     x;
    int     y;
    char    *choosed_map;
    void    *mlx;
    void    *mlx_win;
    void    *mlx_image_wall;
    void    *mlx_image_ground;
    void    *mlx_image_hero;
    void    *mlx_image_door;
    void    *mlx_image_enemy;
    void    *mlx_image_diamond;
    char    **tab;
    int     i;
    int     j;
    int     z;
    int     k;
    size_t  len;
    int     pos_px;
    int     pos_py;
}       t_allvar;

char	**ft_split(char const *s, char c);
void    check_walls(t_allvar *allvar);
char	*ft_strjoinn(char const *s1, char const *s2);
char	*ft_strdup(const char *s1);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
void checkmap(t_allvar *allvar);

#endif
