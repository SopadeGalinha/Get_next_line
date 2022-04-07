/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhgoncal <jhgoncal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 21:05:49 by jhgoncal          #+#    #+#             */
/*   Updated: 2022/04/07 21:05:49 by jhgoncal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif
/*
** \______________________________HEADERS_____________________________________/
*/

# include <fcntl.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

/*
** \_____________________________FUNCTIONS_____________________________________/
*/

size_t	ft_strlen(char *str);
char	*ft_strchr(char *str, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *s, int c);
char	*ft_strdup(const char *src);
char	*get_next_line_bonus(int fd);

#endif
