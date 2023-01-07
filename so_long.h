/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hajj <yel-hajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 16:22:24 by yel-hajj          #+#    #+#             */
/*   Updated: 2023/01/07 10:00:39 by yel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_allvar
{
	int		x;
	int		y;
	char	*choosed_map;
	void	*mlx;
	void	*mlx_win;
	void	*mlx_image_wall;
	void	*mlx_image_ground;
	void	*mlx_image_hero;
	void	*mlx_image_door;
	void	*mlx_image_enemy;
	void	*mlx_image_enemyy;
	void	*mlx_image_diamond;
	char	**tab;
	int		i;
	int		j;
	int		z;
	int		k;
	size_t	len;
	int		pos_px;
	int		pos_py;
	int		pos_enemyx;
	int		pos_enemyy;
	int		count_c;
	int		moves_count;
	int		move_l;
	int		moves_num;
	int		bonus;
}		t_allvar;

char	**get_linee(char *choosedmap);
char	**ft_split(char const *s, char c);
void	check_walls(t_allvar *allvar);
char	*ft_strjoinn(char const *s1, char const *s2);
char	*ft_strdup(const char *s1);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	checkmap(char *choosedmap, t_allvar *allvar);
int		checkkey(int keycode, t_allvar *allvar);
char	*ft_itoa(int n);
void	check_backtracking(char *choosedmap, t_allvar *allvar);
void	check_left(t_allvar *allvar);
void	check_right(t_allvar *allvar);
void	parsing(int ac, char **str, t_allvar *allvar);
void	set_mlx_win(char *map, t_allvar *allvar);
int		move_enemy(t_allvar *allvar);
void	display_themap(t_allvar *allvar);
void	check_enemy_pos(t_allvar *allvar);
void	check_player_door(t_allvar *allvar);
void	destroy_all(t_allvar *allvar);
void	print_str_put(t_allvar *allvar, int bonus);
void	freemap(char **s);
void	check_vars(t_allvar *allvar);
void	ft_putnbr(int n);
void	print_ter(t_allvar *allvar, int bonus);
void	show_error(int num);

#endif