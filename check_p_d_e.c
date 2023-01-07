/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_p_d_e.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hajj <yel-hajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 13:58:02 by yel-hajj          #+#    #+#             */
/*   Updated: 2023/01/07 13:39:20 by yel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	help_check_player_door(t_allvar*allvar)
{
	allvar->i = 0;
	allvar->j = 0;
	allvar->z = 0;
	allvar->len = 0;
	allvar->k = 0;
}

void	check_player_door(t_allvar *allvar)
{
	help_check_player_door(allvar);
	while (allvar->tab[allvar->i])
	{
		allvar->j = 0;
		while (allvar->tab[allvar->i][allvar->j])
		{
			if (allvar->tab[allvar->i][allvar->j] == 'P')
			{
				allvar->pos_px = allvar->j;
				allvar->pos_py = allvar->i;
				allvar->z += 1;
			}
			else if (allvar->tab[allvar->i][allvar->j] == 'E')
				allvar->len += 1;
			else if (allvar->tab[allvar->i][allvar->j] == 'C')
				allvar->k += 1;
			allvar->j++;
		}
		allvar->i++;
	}
	if (allvar->z != 1 || allvar->len != 1 || allvar->k <= 0)
	{
		write(2, "Eroor\n", 6);
		exit(1);
	}
}

void	check_enemy_pos(t_allvar *allvar)
{
	if (allvar->bonus == 0)
		return ;
	allvar->i = 0;
	allvar->j = 0;
	allvar->z = 0;
	while (allvar->tab[allvar->i])
	{
		allvar->j = 0;
		while (allvar->tab[allvar->i][allvar->j])
		{
			if (allvar->tab[allvar->i][allvar->j] == 'A')
			{
				allvar->pos_enemyx = allvar->j;
				allvar->pos_enemyy = allvar->i;
				allvar->z++;
			}
			allvar->j++;
		}
		allvar->i++;
	}
	if (allvar->z < 1)
		show_error(2);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		write(1, "-", 1);
		write(1, "2", 1);
		n = 147483648;
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
	{
		ft_putchar(n + 48);
	}
}
