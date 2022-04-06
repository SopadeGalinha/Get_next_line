/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhgoncal <jhgoncal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 12:59:25 by jhgoncal          #+#    #+#             */
/*   Updated: 2022/04/01 13:48:08 by jhgoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef	GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
/*
** \______________________________HEADERS_____________________________________/
*/

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include<stdlib.h>
#include <string.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 4
#endif

/*
** \_____________________________FUNCTIONS_____________________________________/
*/

char	*get_next_line(int fd);
//* UTILS
size_t	ft_strlen(char *str);
char	*ft_strchr(char *str, int c);
char	*ft_strjoin(char *s1, char *s2);

#endif