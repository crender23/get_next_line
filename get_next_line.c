/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crender <crender@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 01:50:05 by crender           #+#    #+#             */
/*   Updated: 2021/12/04 19:13:29 by crender          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*end_of_line(char *line)
{
	char	*result;
	size_t	i;

	i = 0;
	while (*(line + i) != '\n' && *(line + i) != '\0')
		i++;
	if (*(line + i) != '\0')
	{	
		result = (char *) malloc(ft_strlen(line) - i + 1);
		if (!result)
			return (NULL);
		ft_memcpy(result, &line[i + 1], ft_strlen(line) - i);
		free (line);
		return (result);
	}
	free (line);
	return (NULL);
}

static char	*start_of_line(char *line)
{
	size_t	i;
	char	*result;

	i = 0;
	while (*(line + i) != '\n' && (*(line + i) != '\0'))
		i++;
	result = (char *) malloc(i + 1 + 1);
	if (!result)
		return (NULL);
	ft_memcpy(result, line, i + 1);
	return (result);
}

static int	whole_line(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (0);
	while (*(line + i) != '\n' && (*(line + i) != '\0'))
		i++;
	if (!(*(line + i)))
		return (0);
	return (1);
}

char	*get_next_line(int fd)
{
	static char	*result;
	char		*str;
	int			j;
	char		buffer[BUFFER_SIZE + 1];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	j = 1;
	while (j && !whole_line(result))
	{
		j = read(fd, buffer, BUFFER_SIZE);
		if (j < 0 || (!j && !result))
			return (NULL);
		if (!j && !*result)
		{
			free(result);
			return (NULL);
		}
		*(buffer + j) = '\0';
		result = ft_strjoin(result, buffer);
	}
	str = start_of_line(result);
	result = end_of_line(result);
	return (str);
}

// #include <stdio.h>
// #include <fcntl.h>

// int main (void)
// {
// 	int fd;
// 	char *line;

// 	fd = open("text.txt", O_RDONLY);

// 	line = get_next_line(fd);
// 	printf("%s\n", line);
// 	free (line);

// }
