/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pkatsaro <pkatsaro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/06 12:44:05 by pkatsaro      #+#    #+#                 */
/*   Updated: 2022/12/20 14:59:18 by pkatsaro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stddef.h> // for size_t and others...
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 200
# endif

/* get_next_line_utils.c */
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(const char *s1, const char *s2);
/* get_next_line.c */
char	*get_next_line(int fd);
char	*ft_read_and_save(int fd, char *save);
char	*ft_save(char *save);
//char	*ft_get_line(char *save);

#endif