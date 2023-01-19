/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pkatsaro <pkatsaro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/02 13:21:44 by pkatsaro      #+#    #+#                 */
/*   Updated: 2023/01/19 11:44:49 by pkatsaro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// read, malloc, free, ret NULL if there is nth else to read
//read() r nbytes of data from the obj of reference by the fildes into
// the buffer pointed to by buf:re num of bites read adn place in the buf

// -D BUFFER_SIZE=n
// cc -Wall -Wextra -Werror -D BUFFER_SIZE=1 get_next_line.c get_next_line_utils.c && ./a.out

#include <fcntl.h>
#include "get_next_line.h"

void	free_ptr(char **ptr);
char	*join_line(int start, char **buffer_holder);
char	*read_line(int fd, char **buff, char *read_return);

char	*get_next_line(int fd)
{
	static char	*buffer_holder[MAX_FD + 1];
	char		*text;
	char		*res;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > MAX_FD)
		return (NULL);
	text = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (text == NULL)
		return (NULL);
	if (!buffer_holder[fd])
		buffer_holder[fd] = ft_strdup("");
	// if (!buffer_holder[fd]) // ??? or
	// 	buffer_holder[fd] = NULL;
	res = read_line(fd, &buffer_holder[fd], text);
	free_ptr(&text);
	return (res);
}


void	free_ptr(char **ptr)
{
	if (*ptr != NULL && ptr != NULL)
	{
		free(*ptr);
		//ptr = NULL;
		*ptr = NULL;
	}
}

/* In this version, the function is creating a copy of the memory buffer using ft_strdup
 and ft_strndup functions instead of just copying the pointer. This way, you can modify
  the original buffer without affecting the returned result. Also, the function is now 
  returning the result when start <= 0 and freeing the memory allocated to *buff.
*/

char	*join_line(int start, char **buffer_holder)
{
    char	*result;
    char	*temp;

    temp = NULL;
    if (start <= 0)
    {
        if (**buffer_holder == '\0')
        {
            free(*buffer_holder);
            *buffer_holder = NULL;
            return (NULL);
        }
        result = ft_strdup(*buffer_holder); // create a copy of *buffer_holder
        free(*buffer_holder); // free the memory allocated to *buffer_holder
        *buffer_holder = NULL;
        return (result);
    }
    temp = ft_substr(*buffer_holder, start, BUFFER_SIZE);
    result = ft_strndup(*buffer_holder, start); // create a copy of *buffer_holder up to start position
    free(*buffer_holder); // free the memory allocated to *buffer_holder
    *buffer_holder = temp;
    return (result);
}

char	*read_line(int fd, char **buffer_holder, char *current_buff)
{
	ssize_t	bytes_read;
	char	*temp;
	char	*nl;

	nl = ft_strchr(*buffer_holder, '\n');
	temp = NULL;
	bytes_read = 0;
	while (nl == NULL)
	{
		bytes_read = read(fd, current_buff, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(*buffer_holder);
			*buffer_holder = NULL;
			return (NULL);
		}
		else if (bytes_read <= 0)
		{
			return (join_line(bytes_read, buffer_holder));
		}				
		current_buff[bytes_read] = 0;
		temp = ft_strjoin(*buffer_holder, current_buff);
		free_ptr(buffer_holder);
		*buffer_holder = temp;
		nl = ft_strchr(*buffer_holder, '\n');
	}
	return (join_line(nl - *buffer_holder + 1, buffer_holder));
}




/*
	Make sure that your function works as expected both when reading a file and when
reading from the standard input.

Error in test 3: get_next_line(5: "read_error.txt"): expected: <NULL>, got: "cccccccc"
Probable reason: You should clear the static buffer when a call to read returns -1

To see the tests open: /Users/pkatsaro/francinette/tests/get_next_line/fsoares/tester.c

*/
int	main(void)
{
	int 	fd, count = 0;
	
	fd = open("tests/test.txt", O_RDONLY);

	for (int i = 0; i < 8; i++)
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