/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_chars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hajj <yel-hajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 18:52:53 by yel-hajj          #+#    #+#             */
/*   Updated: 2022/12/29 19:22:26 by yel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    check_ckaracters(t_allvar *allvar)
{
    allvar->i = 0;
    allvar->j = 0;
    while (allvar->tab[allvar->i])
    {
        allvar->j = 0;
        while (allvar->tab[allvar->i][allvar->j])
        {
            if (allvar->tab[allvar->i][allvar->j] != '1' && allvar->tab[allvar->i][allvar->j] != '0'
            && allvar->tab[allvar->i][allvar->j] != 'P' && allvar->tab[allvar->i][allvar->j] != 'C'
            && allvar->tab[allvar->i][allvar->j] != 'E')
            {
                write(2, "Eroor\n", 6);
                exit(1);
            }
            allvar->j++;
        }
        allvar->i++;
    }
}

void    is_rect(t_allvar *allvar)
{
    allvar->i = 0;
    allvar->j = 0;
    allvar->z = 0;
    while (allvar->tab[allvar->i][allvar->j++])
        allvar->z++;
    while (allvar->tab[allvar->i])
    {
        allvar->j = 0;
        while (allvar->tab[allvar->i][allvar->j])
            allvar->j++;
        if(allvar->j != allvar->z)
        {
            write(2, "Eroor\n", 6);
            exit(1);
        }
        allvar->i++;
    }
}

void checkmap(t_allvar *allvar)
{
    check_ckaracters(allvar);
    is_rect(allvar);
    check_walls(allvar);
}