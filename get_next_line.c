/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhgoncal <jhgoncal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 14:15:06 by jhgoncal          #+#    #+#             */
/*   Updated: 2022/04/07 18:43:00 by jhgoncal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/*
**	Write a function that returns a line read from a
**	file descriptor(fd).
**	Return value: 
**		Read line: correct behavior.
**		NULL: there is nothing else to read, or an error occurred
*/

//read a line
// return a line with the '\n' (if the end wasn't reached)
// a loop should let you read 
// the entire file (a line at a time)

#include <stdio.h>
#include "get_next_line.h"
#include <string.h>

static char	*ft_get_the_line(char *save);
static char	*ft_read_and_save(int fd, char *save);
static char	*ft_save(char *save);


char *get_next_line(int fd)
{
	static char	*save;
	char		*line;

	
	if(fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	save = ft_read_and_save(fd, save);
	if (save == NULL)
		return (NULL);
	line = ft_get_the_line(save);
	save = ft_save(save);
	return (line);
}

static char	*ft_read_and_save(int fd, char *save)
{
	char	*buf;
	int		readed;
	char	*tmp;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	readed = 1;
	while (!ft_strchr(save, '\n') && readed != 0)
	{
		readed = read(fd, buf, BUFFER_SIZE);
		if (readed == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[readed] = '\0';
		tmp = ft_strjoin(save, buf);
		free(save);
		save = strdup(tmp);
		free(tmp);
	}
	free(buf);
	return (save);
}

static char	*ft_get_the_line(char *save)
{
	char	*line;
	int		i;

	i = 0;
	if (!save[i])
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = -1;
	while (save[++i] && save[i] != '\n')
		line[i] = save[i];
	if (save[i] == '\n')
		line[i] = save[i];
	line[++i] = '\0';
	return (line);
}

static char	*ft_save(char *save)
{
	int		i;
	int		c;
	char	*s;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (NULL);
	}
	s = malloc(sizeof(char) * (ft_strlen(save) - i + 1));
	if (!s)
		return (NULL);
	i++;
	c = 0;
	while (save[i])
		s[c++] = save[i++];
	s[c] = '\0';
	free(save);
	return (s);
}
