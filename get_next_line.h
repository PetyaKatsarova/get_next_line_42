/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pkatsaro <pkatsaro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/06 12:44:05 by pkatsaro      #+#    #+#                 */
/*   Updated: 2022/12/17 16:57:45 by pkatsaro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stddef.h> // for size_t and others...
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 200
# endif

# ifndef MAX_FD
#  define MAX_FD 256
# endif

/* get_next_line.c */
char	*get_next_line(int fd);
//int	*get_next_line(int fd);

/* get_next_line_utils.c */
char	*ft_strchr(const char *s, int c);
char	*ft_substr(const char *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strdup(const char *s1);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
void	free_null(char **ptr);
char	*join_line(int nl_position, char **buffer);
char	*read_line(int fd, char **buffer, char *read_return);
#endif