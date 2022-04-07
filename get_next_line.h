/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhgoncal <jhgoncal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 12:59:25 by jhgoncal          #+#    #+#             */
/*   Updated: 2022/04/07 15:50:11 by jhgoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef	GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
/*
** \______________________________HEADERS_____________________________________/
*/

#include <fcntl.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif

/*
** \_____________________________FUNCTIONS_____________________________________/
*/

//* UTILS *
size_t	ft_strlen(char *str);
char	*ft_strchr(char *str, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);
char	*ft_strchr(char *s, int c);


#endif
