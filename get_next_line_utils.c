/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhgoncal <jhgoncal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 20:05:47 by jhgoncal          #+#    #+#             */
/*   Updated: 2022/04/06 20:02:17 by jhgoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *str, int c)
{
	int	i;

	i = -1;
	if (!str)
		return (0);
	while (str[++i] != '\0')
		if (str[i] == (char) c)
			return ((char *)&str[i]);
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*new;
	int		s_free;

	i = -1;
	j = -1;
	s_free = 0;
	if (!s1)
	{
		s1 = malloc(sizeof(char) * 1);
		s1[0] = '\0';
		s_free = 1;
	}
	new = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (new == NULL)
		return (NULL);
	while (s1[++i] != '\0')
		new[i] = s1[i];
	while (s2[++j] != '\0')
		new[i++] = s2[j];
	new[i] = '\0';
	if (s_free == 1)
		free(s1);
	return (new);
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