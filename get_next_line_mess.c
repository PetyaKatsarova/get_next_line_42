/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pkatsaro <pkatsaro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/19 09:40:38 by pkatsaro      #+#    #+#                 */
/*   Updated: 2023/01/19 10:18:11 by pkatsaro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// read, malloc, free, ret NULL if there is nth else to read
//read() r nbytes of data from the obj of reference by the fildes into
// the buffer pointed to by buf:re num of bites read adn place in the buf

#include <fcntl.h>
#include "get_next_line.h"

// join text and free
char	*ft_free(char *text, char *buf);
char	*ft_next(char *text);
char	*ft_line(char *text);
char	*read_file(int fd, char	*text);

char	*get_next_line(int fd)
{
	static	char	*buffer;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = read_file(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_line(buffer);
	buffer = ft_next(buffer);
	return (line);	
}

char	*ft_free(char *text, char *buf)
{
	char	*temp;

	temp = ft_strjoin(text, buf);
	free(text);
	return (temp);
}

char	*ft_next(char *text)
{
	int		i;
	int		j;
	char	*reminder;
	
	i = 0;
	// find len of first line
	while (text[i] && text[i] != '\n')
		i++;
	if (!text[i]) //? if eol == \0 ret NULL
	{
		free(text);
		return (NULL);
	}
	reminder = malloc((ft_strlen(text) -i + 1) * sizeof(char));
	i++;
	j = 0;
	while (text[i])
		reminder[j++] = text[i++];
	free(text);
	return (reminder);
}

char	*ft_line(char *text)
{
	char	*line;
	int		i;

	i = 0;
	if (!text[i])
		return (NULL);
	while (text[i] && text[i] != '\n')
		i++;
	line = malloc((i + 2) * sizeof(char));
	i = 0;
	while (text[i] && text[i] != '\n')
	{
		line[i] = text[i];
		i++;
	}
	if (line[i] && line[i] == '\n')
		line[i++] = '\n';
	return (line);
}

char	*read_file(int fd, char	*text)
{
	char	*buf;
	int		bytes_read;

// malloc fi res dont exist
	if (!text)
		text = malloc(1);
	buf = malloc(BUFFER_SIZE + 1);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buf);
			return (NULL);
		}
		// 0 AT END FOR leaks
		buf[bytes_read] = 0;
		// join & free
		text = ft_free(text, buf);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	free (buf);
	return (text);
}