/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcollong <lcollong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:57:25 by lcollong          #+#    #+#             */
/*   Updated: 2024/11/04 20:29:54 by lcollong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# define MAX_FILE 1024

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n);
char	*add_buff(char *big, char *small);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(const char *s, int c);
char	*read_file(char	*str, int fd);
char	*ft_get_line(char *str);
char	*get_next_line(int fd);
char	*remain(char *str);
void	*ft_calloc(size_t nmemb, size_t size);
size_t	ft_strlen(const char *s);

#endif
