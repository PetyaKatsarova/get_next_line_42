/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pkatsaro <pkatsaro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/02 13:21:44 by pkatsaro      #+#    #+#                 */
/*   Updated: 2023/01/20 16:54:39 by pkatsaro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	free_ptr(char **ptr);
char	*join_line(int start, char **buffer_holder);
char	*read_line(int fd, char **buff, char *read_return);
char	*ft_strndup(const char *str, size_t n);

char	*get_next_line(int fd)
{
	static char	*buffer_holder[MAX_FD + 1];
	char		*current_buffer;
	char		*res;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > MAX_FD)
		return (NULL);
	current_buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (current_buffer == NULL)
		return (NULL);
	if (!buffer_holder[fd])
		buffer_holder[fd] = ft_strndup("", 1);
	res = read_line(fd, &buffer_holder[fd], current_buffer);
	free_ptr(&current_buffer);
	return (res);
}

void	free_ptr(char **ptr)
{
	if (*ptr != NULL && ptr != NULL)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

char	*join_line(int start, char **buffer_holder)
{
	char	*result;
	char	*temp;

	temp = NULL;
	result = NULL;
	if (start <= 0)
	{
		if (**buffer_holder == '\0')
		{
			free(*buffer_holder);
			*buffer_holder = NULL;
			return (NULL);
		}
		result = ft_strndup(*buffer_holder, ft_strlen(*buffer_holder));
		free(*buffer_holder);
		*buffer_holder = NULL;
		return (result);
	}
	temp = ft_substr(*buffer_holder, start, BUFFER_SIZE);
	result = ft_strndup(*buffer_holder, start);
	free(*buffer_holder);
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
			return (join_line(bytes_read, buffer_holder));
		current_buff[bytes_read] = 0;
		temp = ft_strjoin(*buffer_holder, current_buff);
		free_ptr(buffer_holder);
		*buffer_holder = temp;
		 if (*buffer_holder)
			nl = ft_strchr(*buffer_holder, '\n');
	}
	return (join_line(nl - *buffer_holder + 1, buffer_holder));
}

char	*ft_strndup(const char *str, size_t n)
{
	char	*ptr;

	if (str == NULL)
		return (NULL);
	ptr = (char *)malloc((n + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	ft_strlcpy(ptr, str, n + 1);
	return (ptr);
}


/*
	Make sure that your function works as expected both when reading a file and when
reading from the standard input.
Error in test 3: get_next_line(5: "read_error.txt"): expected: <NULL>, got: "cccccccc"
Probable reason: You should clear the static buffer when a call to read returns -1
To see the tests open: /Users/pkatsaro/francinette/tests/get_next_line/fsoares/tester.c
*/
// read, malloc, free, ret NULL if there is nth else to read
//read() r nbytes of data from the obj of reference by the fildes into
// the buffer pointed to by buf:re num of bites read adn place in the buf

// -D BUFFER_SIZE=n
// cc -Wall -Wextra -Werror -D BUFFER_SIZE=1 get_next_line.c get_next_line_utils.c && ./a.out
// int	main(void)
// {
// 	char *line;
//     int fd = open("tests/test.txt", O_RDONLY);
//     if (fd < 0) {
//         printf("Error opening file\n");
//         return (-1);
//     }
//     while ((line = get_next_line(fd)) != NULL) {
//         printf("Line: %s", line);
//         free(line);
//     }
//     if (close(fd) != 0) {
//         printf("Error closing file\n");
//         return (-1);
//     }
// 	return (0);
// }