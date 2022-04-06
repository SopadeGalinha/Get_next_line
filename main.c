/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhgoncal <jhgoncal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 14:55:43 by jhgoncal          #+#    #+#             */
/*   Updated: 2022/04/06 16:27:07 by jhgoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int	main(void)
{
	char	*str;
	int		fd;
	int		i;

	i = 0;
	fd = open("leiame.txt", O_RDONLY);
	
	while ( fd >= 0 && i++ < 2)
	{
		str = get_next_line(fd);
		if (str)
		{
			printf("%s", str);
			free(str);
		}
	}
	close(fd);
	return (0);
}
