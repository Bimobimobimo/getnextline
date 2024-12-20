/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcollong <lcollong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:56:43 by lcollong          #+#    #+#             */
/*   Updated: 2024/11/04 21:09:30 by lcollong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	*buffer[MAX_FILE];
	char		*line;

	if (fd < 0 || fd >= MAX_FILE || BUFFER_SIZE <= 0)
		return (NULL);
	if (buffer[fd] == NULL)
		buffer[fd] = ft_calloc(1, sizeof(char));
	if (buffer[fd] == NULL)
		return (NULL);
	buffer[fd] = read_file(buffer[fd], fd);
	if (!buffer[fd] || *buffer[fd] == '\0')
	{
		free(buffer[fd]);
		buffer[fd] = NULL;
		return (NULL);
	}
	line = ft_get_line(buffer[fd]);
	buffer[fd] = remain(buffer[fd]);
	return (line);
}

char	*read_file(char *big_buf, int fd)
{
	char	*small_buf;
	int		cursor;

	small_buf = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!small_buf)
		return (free(big_buf), NULL);
	while (!ft_strchr(big_buf, '\n'))
	{
		cursor = read(fd, small_buf, BUFFER_SIZE);
		if (cursor <= 0)
		{
			free(small_buf);
			if (cursor == 0)
				return (big_buf);
			free(big_buf);
			return (NULL);
		}
		small_buf[cursor] = '\0';
		big_buf = add_buff(big_buf, small_buf);
		if (!big_buf)
			return (free(small_buf), NULL);
	}
	free(small_buf);
	return (big_buf);
}

char	*add_buff(char *big, char *small)
{
	char	*added;

	added = ft_strjoin(big, small);
	if (!added)
	{
		free(big);
		return (NULL);
	}
	free(big);
	return (added);
}

char	*ft_get_line(char *str)
{
	int		i;
	char	*line;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	line = ft_calloc((i + 2), sizeof(char));
	if (!line)
		return (NULL);
	ft_strncpy(line, str, i);
	if (str[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*remain(char *str)
{
	char	*remain;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
		return (free(str), NULL);
	i++;
	remain = ft_calloc(ft_strlen(str) - i + 1, sizeof(char));
	if (!remain)
	{
		free(str);
		return (NULL);
	}
	while (str[i])
		remain[j++] = str[i++];
	remain[j] = '\0';
	free(str);
	return (remain);
}

/* int    main(void)
{
	int		fd1;
	int		fd2;
	int		i;
	int		j;
	char	*next_line_fd1;
	char	*next_line_fd2;

	fd1 = open("text.txt", O_RDONLY);
	fd2 = open("text2.txt", O_RDONLY);
	if (fd1 < 0)
		return (printf("File text.txt error\n"), 1);
	if (fd2 < 0)
		return (printf("File text2.txt error\n"), 1);
	i = 0;
	j = 0;
	next_line_fd1 = get_next_line(fd1);
	next_line_fd2 = get_next_line(fd2);
	while (next_line_fd1 || next_line_fd2)
	{
		if (next_line_fd1)
		{
			printf("fd1, line %d: %s", i, next_line_fd1);
			i++;
			free(next_line_fd1);
			next_line_fd1 = get_next_line(fd1);
		}
		if (next_line_fd2)
		{
			printf("fd2, line %d: %s", j, next_line_fd2);
			j++;
			free(next_line_fd2);
			next_line_fd2 = get_next_line(fd2);
		}
	}
	close(fd1);
	close(fd2);
	return (0);
} */
