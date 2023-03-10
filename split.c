/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hajj <yel-hajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 10:21:40 by yel-hajj          #+#    #+#             */
/*   Updated: 2023/01/07 10:04:17 by yel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	int	countwords(char *s, char c)
{
	int	words;
	int	i;

	i = 0;
	words = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
			words++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (words);
}

static	char	*bringarray(char *s1, int cp)
{
	int		i;
	char	*p;

	p = (char *)malloc(sizeof(char) * cp + 1);
	if (!p)
		show_error(2);
	i = 0;
	while (i < cp)
	{
		p[i] = s1[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

static	void	freearr(char **pp)
{
	int	i;

	i = 0;
	while (pp[i])
		free(pp[i++]);
	free(pp);
}

static	void	fillarrays(char **pp, char *s, int l, char c)
{
	int	i;
	int	j;
	int	cp;

	i = -1;
	j = 0;
	while (++i < l)
	{
		cp = 0;
		while (s[j] && s[j] == c)
			j++;
		while (s[j] && s[j] != c)
		{
			j++;
			cp++;
		}
		pp[i] = bringarray(&s[j - cp], cp);
		if (!pp[i])
		{
			freearr(pp);
			return ;
		}
		j++;
	}
	pp[i] = NULL;
}

char	**ft_split(char const *s, char c)
{
	int		l;
	char	**pp;

	if (!s)
		return (NULL);
	l = countwords((char *)s, c);
	pp = (char **)malloc(sizeof(char *) * (l + 1));
	if (!pp)
		show_error(2);
	fillarrays(pp, (char *)s, l, c);
	free((char *)s);
	return (pp);
}
