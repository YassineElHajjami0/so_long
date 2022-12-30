/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_chars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hajj <yel-hajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 18:52:53 by yel-hajj          #+#    #+#             */
/*   Updated: 2022/12/30 09:52:44 by yel-hajj         ###   ########.fr       */
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
    if (allvar->i == allvar->z)
        return (write(2, "Eroor\n", 6), exit(1));
}

void    check_player_door(t_allvar *allvar)
{
    allvar->i = 0;
    allvar->j = 0;
    allvar->z = 0;
    allvar->len = 0;
    while (allvar->tab[allvar->i])
    {
        allvar->j = 0;
        while (allvar->tab[allvar->i][allvar->j])
        {
            if (allvar->tab[allvar->i][allvar->j] == 'P')
                allvar->z += 1;
            else if (allvar->tab[allvar->i][allvar->j] == 'E')
                allvar->len += 1;
            allvar->j++;
        }
        allvar->i++;
    }
    printf("p => %d\n", allvar->z);
    printf("p => %zu\n", allvar->len);
    if(allvar->z != 1 || allvar->len != 1)
    {
        write(2, "Eroor\n", 6);
        exit(1);
    }
    printf("==========\n");
}

void checkmap(t_allvar *allvar)
{
    check_ckaracters(allvar);
    is_rect(allvar);
    check_walls(allvar);
    check_player_door(allvar);
    
}
