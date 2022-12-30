/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_chars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hajj <yel-hajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 18:52:53 by yel-hajj          #+#    #+#             */
/*   Updated: 2022/12/30 16:01:54 by yel-hajj         ###   ########.fr       */
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
            && allvar->tab[allvar->i][allvar->j] != 'E' && allvar->tab[allvar->i][allvar->j] != 'N')
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
    if(!allvar->tab[0])
    {
        write(2, "Eroor\n", 6);
        exit(1);
    }
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
    if (allvar->i == allvar->z)
        return (write(2, "Eroor\n", 6), exit(1));
}

void    check_player_door(t_allvar *allvar)
{
    allvar->i = 0;
    allvar->j = 0;
    allvar->z = 0;
    allvar->len = 0;
    allvar->k = 0;
    while (allvar->tab[allvar->i])
    {
        allvar->j = 0;
        while (allvar->tab[allvar->i][allvar->j])
        {
            if (allvar->tab[allvar->i][allvar->j] == 'P')
                allvar->z += 1;
            else if (allvar->tab[allvar->i][allvar->j] == 'E')
                allvar->len += 1;
            else if (allvar->tab[allvar->i][allvar->j] == 'C')
                allvar->k += 1;
            allvar->j++;
        }
        allvar->i++;
    }
    if(allvar->z != 1 || allvar->len != 1 || allvar->k <= 0)
    {
        write(2, "Eroor\n", 6);
        exit(1);
    }
}

void checkmap(t_allvar *allvar)
{
    check_ckaracters(allvar);
    is_rect(allvar);
    check_walls(allvar);
    check_player_door(allvar);
    
}
