/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhgoncal <jhgoncal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 12:13:03 by jhgoncal          #+#    #+#             */
/*   Updated: 2022/04/07 20:14:42 by jhgoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
		while (*s1)
			*new++ = *s1++;
	if (s2)
		while (*s2)
			*new++ = *s2++;
	*new = '\0';
	return (o_new);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_strdup(const char *src)
{
	char	*cpy;
	size_t	i;

	i = 0;
	while (src[i])
		i++;
	cpy = (char *)malloc(sizeof(char) * i + 1);
	if (!(cpy))
		return (NULL);
	i = 0;
	while (*src)
		cpy[i++] = *src++;
	cpy[i] = '\0';
	return (cpy);
}
