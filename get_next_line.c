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
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"

char	*ft_read_and_save(int fd); // char *save
char	*ft_save(char *save);

char *get_next_line(int fd, char *save)
{
	char		*line;
	static char	*save;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	save = ft_read_and_save(fd); //, save
	if (!save)
		return (NULL);
	// line = ft_get_line(save);
	// save = ft_save(save);
	return (save); // line
}

char	*ft_read_and_save(int fd, char *save)
{
	char	*buff;
	int		read_bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	// read_bytes = 1;
	// while (!ft_strchr(save, '\n') && read_bytes != 0)
	// {
		read_bytes = read(fd, buff, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[read_bytes] = '\0';
	// 	save = ft_strjoin(save, buff);
	// }
	// free(buff);
	return (buff); // save
}

char	*ft_save(char *save)
{
	int		i;
	int		c;
	char	*str;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_str_len(save) - i + 1));
	if (!str)
		return (NULL);
	i++;
	c = 0;
	while (save[i])
		str[c++] = save[i++];
	str[c] = '\n';
	free(save);
	return (str);
}

int	main(void)
{
	int 	fd;
	
	fd = open("tests/test.txt", O_RDONLY);
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
