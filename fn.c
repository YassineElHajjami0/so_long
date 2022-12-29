/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hajj <yel-hajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 18:49:12 by yel-hajj          #+#    #+#             */
/*   Updated: 2022/12/29 18:50:47 by yel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strjoinn(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*l;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	while (s1[i])
		i++;
	j = 0;
	while (s2[j])
		j++;
	l = (char *)malloc(sizeof(char) * (i + j + 1));
	if (!l)
		return (NULL);
	i = -1;
	j = -1;
	while (s1[++i])
		l[++j] = s1[i];
	i = -1;
	while (s2[++i])
		l[++j] = s2[i];
	l[++j] = '\0';
	return (l);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*p;

	i = 0;
	while (s1[i])
		i++;
	p = (char *)malloc(sizeof(char) * i + 1);
	if (!p)
		return (NULL);
	i = -1;
	while (s1[++i])
		p[i] = s1[i];
	p[i] = '\0';
	return (p);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		r;

	if (!n)
		return (0);
	i = 0;
	r = 0;
	while ((s1[i] || s2[i]) && i < n - 1)
	{
		if (s1[i] != s2[i])
			return (r = (unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}