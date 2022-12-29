/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hajj <yel-hajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 16:22:24 by yel-hajj          #+#    #+#             */
/*   Updated: 2022/12/28 16:32:44 by yel-hajj         ###   ########.fr       */
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
    void    *mlx;
    void    *mlx_win;
    void    *mlx_image;
    char    **tab;
    int     i;
}       t_allvar;

#endif
