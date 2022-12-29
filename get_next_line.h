/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hajj <yel-hajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 11:07:13 by yel-hajj          #+#    #+#             */
/*   Updated: 2022/11/19 11:46:57 by yel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <fcntl.h>

char	*ft_strjoin(char *sta, char *buff);
char	*get_next_line(int fd);
char	*putinsta(int fd, char *sta);
char	*ft_strchr(char *sta, int c);
size_t	ft_strlen(char *s);
char	*putleftinsta(char *sta);
char	*putins(char *sta);

#endif
