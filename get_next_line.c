/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhgoncal <jhgoncal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 14:15:06 by jhgoncal          #+#    #+#             */
/*   Updated: 2022/04/06 20:02:19 by jhgoncal         ###   ########.fr       */
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
#include <fcntl.h>
#include <unistd.h>
#include<stdlib.h>
#include <string.h>
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10000000
#endif

size_t	ft_strlen(char *str);
int		check_line(char *buffer);
char	*ft_strchr(char *str, int c);
char	*ft_get_the_line(char *save);
char	*ft_strjoin(char *s1, char *s2);

char	*ft_save(char *save)
{
	int		i;
	int		c;
	char	*s;

	i = 0;
	if (!save[i])
		return (NULL);
	while (save[i] != '\0' && save[i] != '\n')
		i++;
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

char	*ft_read_and_save(int fd, char *save)
{
	int		readed;
	char	*buf;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	readed = 1;
	while (!check_line(buf) && readed != 0)
	{
		readed = read(fd, buf, BUFFER_SIZE);
		if (readed == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[readed] = '\0';
		save = ft_strjoin(save, buf);
	}
	free(buf);
	return (save);
}

char *get_next_line(int fd)
{
	static char	*save;
	char		*line;
	
	if(fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	save = ft_read_and_save(fd, save);
	if (!save)
		return (NULL);
	line = ft_get_the_line(save);
	save = ft_save(save);
	return (line);
}

int main(void)
{
	int fd;
	int i;
	char *str;
	
	i = -1;
	fd = open("leiame.txt", O_RDONLY);
	if (fd == -1)
		return 0;
	while (fd >= 0 &&  ++i < 14)
	{
		str = get_next_line(fd);
		if (str)
		{
			printf("%s", str);
			free(str);
		}
	}
	close(fd);
}

size_t ft_strlen(char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	const size_t	s1_len = ft_strlen(s1);
	const size_t	s2_len = ft_strlen(s2);
	char			*new;
	char			*o_new;

	new = malloc(sizeof(char) * (s1_len + s2_len) + 1);
	if (new == NULL)
		return (NULL);
	o_new = new;
	if (s1)
		while (*s1 != '\0')
		{
			*new++ = *s1;
			s1++;
		}
	if (s2)
		while (*s2 != '\0')
		{
			*new = *s2;
			new++;
			s2++;
		}
	*new = '\0';
	return (o_new);
}

char	*ft_get_the_line(char *save)
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

int	check_line(char *buffer)
{
	int i;

	i = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	return (buffer[i]);
}