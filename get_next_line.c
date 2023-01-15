/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pkatsaro <pkatsaro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/02 13:21:44 by pkatsaro      #+#    #+#                 */
/*   Updated: 2023/01/15 17:28:06 by pkatsaro      ########   odam.nl         */
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
	if (!buff[fd]) // ??? what r we doing here?
		buff[fd] = ft_strdup("");
	// if (!buff[fd]) // ??? what r we doing here?
	// 	buff[fd] = NULL;
	res = read_line(fd, &buff[fd], text);
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
        result = ft_strdup(*buff); // create a copy of *buff
        free(*buff); // free the memory allocated to *buff
        *buff = NULL;
        return (result);
    }
    temp = ft_substr(*buff, start, BUFFER_SIZE);
    result = ft_strndup(*buff, start); // create a copy of *buff up to start position
    free(*buff); // free the memory allocated to *buff
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
		if (bytes_read == -1)
		{
			free(*buff);
			*buff = NULL;
			return (NULL);
		}
		else if (bytes_read <= 0)
		{
			// if (!*buff)
			// 	return (NULL);
			return (join_line(bytes_read, buff));
		}
						
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

Error in test 3: get_next_line(5: "read_error.txt"): expected: <NULL>, got: "cccccccc"
Probable reason: You should clear the static buffer when a call to read returns -1

To see the tests open: /Users/pkatsaro/francinette/tests/get_next_line/fsoares/tester.c

*/
// int	main(void)
// {
// 	int 	fd, count = 0;
	
// 	fd = open("tests/test.txt", O_RDONLY);

// 	for (int i = 0; i < 5; i++)
// 	{
// 		char	*line;
		
// 		line = get_next_line(fd);
// 		printf("[%i] %s", ++count, line);
// 		free (line);
// 	}
// 	if (close(fd) == -1) // checks
// 	{
// 		printf("close() err");
// 		return (-1);
// 	}
// 	// !! there is no \n at the end of the text!!!
// 	return (0);
// }