/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhgoncal <jhgoncal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 14:55:43 by jhgoncal          #+#    #+#             */
/*   Updated: 2022/04/07 18:28:43 by jhgoncal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main(void)
{
	int fd;
	int i;
	char *str;
	
	i = 0;
	fd = open("leiame.txt", O_RDONLY);
	if (fd == -1)
		return 0;
	while (fd >= 0 &&  ++i < 20)
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
