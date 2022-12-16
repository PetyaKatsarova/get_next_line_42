/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pkatsaro <pkatsaro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/02 13:21:44 by pkatsaro      #+#    #+#                 */
/*   Updated: 2022/12/16 18:40:20 by pkatsaro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// read, malloc, free, ret NULL if there is nth else to read
//read() r nbytes of data from the obj of reference by the fildes into
// the buffer pointed to by buf:re num of bites read adn place in the buf
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"
// #include "j12.j"

char	*get_next_line(int fd)
{
	static char		buf[BUFFER_SIZE + 1];
	int				buf_len;
	int				i;
	int				j;
	static char		*storage[BUFFER_SIZE + 1];
	
	buf_len = read(fd, buf, BUFFER_SIZE);
	i = 0;
	j = 0;
	if (!buf_len)
		return (NULL);
	//printf("%s, %i\n", buf, buf_len);
	while (buf[i] != '\0' && buf[i] != '\n')
		i++;
	while (i < buf_len && i != '\n')
	{
		storage[j] = &buf[i];
		j++;
		i++;
	}
	printf("%s bla\n", storage);
	return (buf);  // add dif if end of file and + \n
}

int	main(void)
{
	int 	fp;
	//int		ret;
	
	fp = open("tests/test.txt", O_RDONLY);
	
	printf("%s\n-----------------\n", get_next_line(fp));
	printf("%s\n-----------------\n", get_next_line(fp));
	printf("%s\n-----------------\n", get_next_line(fp));
	
	
	if (close(fp) == -1) // checks
	{
		printf("close() err");
		return (-1);
	}
	return (0);
}
/*
Description Write a function that returns a line read from a
file descriptor
• Repeated calls (e.g., using a loop) to your get_next_line() function should let
you read the text file pointed to by the file descriptor, one line at a time.
• Your function should return the line that was read.
If there is nothing else to read or if an error occurred, it should return NULL.
• Make sure that your function works as expected both when reading a file and when
reading from the standard input.
• Please note that the returned line should include the terminating \n character,
except if the end of file was reached and does not end with a \n character.
• Your header file get_next_line.h must at least contain the prototype of the
get_next_line() function.
• Add all the helper functions you need in the get_next_line_utils.c file.
*/