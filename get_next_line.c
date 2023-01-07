/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pkatsaro <pkatsaro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/02 13:21:44 by pkatsaro      #+#    #+#                 */
/*   Updated: 2022/12/20 15:00:03 by pkatsaro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// read, malloc, free, ret NULL if there is nth else to read
//read() r nbytes of data from the obj of reference by the fildes into
// the buffer pointed to by buf:re num of bites read adn place in the buf

#include <fcntl.h>
#include "get_next_line.h"

void	free_ptr(char **ptr);
char	*join_line(int start, char **buff);
char	*read_line(int fd, char **buff, char *read_return);

char	*get_next_line(int fd)
{
	static char	*buff[MAX_FD + 1];
	char		*text;
	char		*res;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > MAX_FD)
		return (NULL);
	text = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (text == NULL)
		return (NULL);
	if (!buff[fd])
		buff[fd] = ft_strdup("");
	res = read_line(fd, &buff[fd], text);
	free_ptr(&text);
	return (res);
}

void	free_ptr(char **ptr)
{
	if (*ptr != NULL)
	{
		free(*ptr);
		ptr = NULL;
	}
}

char	*join_line(int start, char **buff)
{
	char	*result;
	char	*temp;

	temp = NULL;
	if (start <= 0)
	{
		if (**buff == '\0')
		{
			free(*buff);
			*buff = NULL;
			return (NULL);
		}
		result = *buff;
		*buff = NULL;
		return (result);
	}
	// wtf happens here:
	/*
	1: buff e pointer to str; temp e substr of buff
	*/
	temp = ft_substr(*buff, start, BUFFER_SIZE);
	result = *buff;
	result[start] = 0;
	*buff = temp;
	return (result);
}

char	*read_line(int fd, char **buff, char *text)
{
	ssize_t	bytes_read;
	char	*temp;
	char	*nl;

	nl = ft_strchr(*buff, '\n');
	temp = NULL;
	bytes_read = 0;
	while (nl == NULL)
	{
		bytes_read = read(fd, text, BUFFER_SIZE);
		if (bytes_read <= 0)
			return (join_line(bytes_read, buff));
		text[bytes_read] = 0;
		temp = ft_strjoin(*buff, text);
		free_ptr(buff);
		*buff = temp;
		nl = ft_strchr(*buff, '\n');
	}
	return (join_line(nl - *buff + 1, buff));
}

/*
	Make sure that your function works as expected both when reading a file and when
reading from the standard input.
*/
int	main(void)
{
	int 	fd, count = 0;
	
	fd = open("tests/test.txt", O_RDONLY);

	for (int i = 0; i < 5; i++)
	{
		char	*line;
		
		line = get_next_line(fd);
		printf("[%i] %s", ++count, line);
		free (line);
	}
	if (close(fd) == -1) // checks
	{
		printf("close() err");
		return (-1);
	}
	// !! there is no \n at the end of the text!!!
	return (0);
}