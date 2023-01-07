#include "get_next_line.h"
#include <string.h>
#include <fcntl.h>

void	free_ptr(char **ptr);
char    *read_line(int fd, char **buff, char *text);
char	*join_line(int start, char **buff);

char    *get_next_line(int fd)
{
    static char *buff[MAX_FD + 1];
    char *text, *res;

    text = (char *)malloc(BUFFER_SIZE + 1);
    if (!buff[fd])
        buff[fd] = ft_strdup("");
    //&buff is the address ptr to static char **buff
    res = read_line(fd, &buff[fd], text);
    free_ptr(&text);
    return (res);
}

int main(void)
{
    int  fd, read_bytes, count = 0;
    char    *text;
    char    **buff;

    fd = open("tests/test.txt", O_RDONLY);
    text = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
    read_bytes = read(fd, text, BUFFER_SIZE + 1);
    text[read_bytes] = '\0';
    for (int i = 0; i < 5; i++)
    {
        char *line = get_next_line(fd);
        printf("[%i] %s\n ---------------- \n", ++count, line);
        free(line);
    }

    return (0);
}

void	free_ptr(char **ptr)
{
	if (*ptr != NULL)
	{
		free(*ptr);
		ptr = NULL;
	}
}

// **buff is the pointer to static char *buff position
char    *read_line(int fd, char **buff, char *text)
{
    int bytes_read = 0;
    char *temp, *nl;

    nl = ft_strchr(*buff, '\n');
    temp = NULL;
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
    // why????
    return (join_line (nl - *buff + 1, buff));
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
