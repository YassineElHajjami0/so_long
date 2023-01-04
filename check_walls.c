/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hajj <yel-hajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 18:41:23 by yel-hajj          #+#    #+#             */
/*   Updated: 2023/01/04 14:36:21 by yel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_firstline(t_allvar *allvar)
{
	allvar->j = 0;
	while (allvar->tab[0])
	{
		while (allvar->tab[0][allvar->j])
		{
			if (allvar->tab[0][allvar->j] != '1')
			{
				write(2, "Eroor\n", 6);
				exit(1);
			}
			allvar->j++;
		}
		return ;
	}
}

void	check_lastline(t_allvar *allvar)
{
	allvar->len = 0;
	allvar->j = 0;
	while (allvar->tab[allvar->len])
		allvar->len++;
	allvar->len--;
	while (allvar->tab[allvar->len])
	{
		while (allvar->tab[allvar->len][allvar->j])
		{
			if (allvar->tab[allvar->len][allvar->j] != '1')
			{
				write(2, "Eroor\n", 6);
				exit(1);
			}
			allvar->j++;
		}
		return ;
	}
}

void	check_leftside(t_allvar *allvar)
{
	allvar->i = 0;
	allvar->j = 0;
	while (allvar->tab[allvar->i])
	{
		while (allvar->tab[allvar->i][allvar->j])
		{
			if (allvar->tab[allvar->i][allvar->j] != '1')
			{
				write(2, "Eroor\n", 6);
				exit(1);
			}
			break ;
		}
		allvar->i++;
	}
}

void	check_rightside(t_allvar *allvar)
{
	allvar->len = 0;
	allvar->i = 0;
	allvar->j = 0;
	while (allvar->tab[allvar->i])
	{
		while (allvar->tab[allvar->i][allvar->j])
			allvar->j++;
		break ;
	}
	allvar->j--;
	while (allvar->tab[allvar->i])
	{
		while (allvar->tab[allvar->i][allvar->j])
		{
			if (allvar->tab[allvar->i][allvar->j] != '1')
			{
				write(2, "Eroor\n", 6);
				exit(1);
			}
			break ;
		}
		allvar->i++;
	}
}

void	check_walls(t_allvar *allvar)
{
	check_firstline(allvar);
	check_lastline(allvar);
	check_leftside(allvar);
	check_rightside(allvar);
}
