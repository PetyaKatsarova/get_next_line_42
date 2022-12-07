/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: pkatsaro <pkatsaro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/02 15:36:10 by pkatsaro      #+#    #+#                 */
/*   Updated: 2022/12/07 18:40:13 by pkatsaro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
// #include "j12.j"

#define BUF_SIZE 4096

int	main(void)
{
	int 	fd;
	int		ret;
	char	buf[BUF_SIZE + 1];
	
	fd = open("tests/test.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("open() error");
		return (-1);
	}
	ret = read(fd, buf, BUF_SIZE);
	buf[ret] = '\0';
	printf("str_len: %i, text: %s", ret, buf);
	if (close(fd) == -1)
	{
		printf("close() err");
		return (-1);
	}
	return (0);
}
