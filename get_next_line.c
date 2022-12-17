/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pkatsaro <pkatsaro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/02 13:21:44 by pkatsaro      #+#    #+#                 */
/*   Updated: 2022/12/17 17:00:02 by pkatsaro      ########   odam.nl         */
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
char	*ft_select(char *buf, int *ret);

char	*get_next_line(int fd, char **line)
{
	char		buf[BUFFER_SIZE + 1];
	int			ret;
	static char	*str = NULL;
	char		*temp;

	ret = BUFFER_SIZE;
	if (fd < 0 || fd > 1023 || !line || BUFFER_SIZE <= 0)
		return (NULL);
	while (ret > 0)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret == -1)
			retrun (NULL);
		buf[ret] = 0;
		temp = str;
		str = ft_strjoin(temp, buf);
		free(temp);
		if (ft_strchr (str, '\n'))
			break;
	}
	// *line = ft_select(str, &ret);
	// temp = str;
	// //str = ft_select2(temp);
	// free(temp);
	// if (ret == 0 && (*str)[0] == 0)
	// {
	// 	free (*str);
	// 	*str = NULL;
	// }
	// return (ret);
	return (str);
}


int	main(void)
{
	int 	fd;
	//int		ret;
	
	fd = open("tests/test.txt", O_RDONLY);
	// get_next_line(fd);
	// get_next_line(fd);
	// get_next_line(fd);
	printf("%s\n-----------------\n", get_next_line(fd));
	printf("%s\n-----------------\n", get_next_line(fd));
	printf("%s\n-----------------\n", get_next_line(fd));
	printf("%s\n-----------------\n", get_next_line(fd));
	if (close(fd) == -1) // checks
	{
		printf("close() err");
		return (-1);
	}
	return (0);
}

char	*ft_select(char *buf, int *ret)
{
	int		i;
	char	*dest;

	i = 0;
	while (buf && buf[i] && buf[i] != '\n')
		i++;
	dest = malloc (i + 1);
	if (!dest)
		return (NULL);
	if (ft_strchr(buf, '\n' != 0))
		*ret = 1;
	i = 0;
	while (buf && buf[i] && buf[i] != '\n')
	{
		dest[i] = buf[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

// void	free_null(char **ptr)
// {
// 	if (*ptr != NULL)
// 	{
// 		free(*ptr);
// 		ptr = NULL;
// 	}
// }

// char	*join_line(int nl_position, char **buffer)
// {
// 	char	*res;
// 	char	*temp;

// 	temp = NULL;
// 	if (nl_position <= 0)
// 	{
// 		if (**buffer == '\0')
// 		{
// 			free(*buffer);
// 			*buffer = NULL;
// 			return (NULL);
// 		}
// 		res = *buffer;
// 		*buffer = NULL;
// 		return (res);
// 	}
// 	temp = ft_substr(*buffer, nl_position, BUFFER_SIZE);
// 	res = *buffer;
// 	res[nl_position] = 0;
// 	return (res);
// }

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