/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: pkatsaro <pkatsaro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/02 15:36:10 by pkatsaro      #+#    #+#                 */
/*   Updated: 2022/12/17 11:41:11 by pkatsaro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"
// #include "j12.j"

int	main(void)
{
	int 	fd;
	
	fd = open("tests/test.txt", O_RDONLY);
	//printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	if (close(fd) == -1)
	{
		printf("close() err");
		return (-1);
	}
	return (0);
}
