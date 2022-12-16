/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pkatsaro <pkatsaro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/06 12:44:05 by pkatsaro      #+#    #+#                 */
/*   Updated: 2022/12/14 13:34:12 by pkatsaro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1042
# endif

# include <stddef.h> // for size_t and others...

/* get_next_line.c */
char	*get_next_line(int fd);

/* get_next_line_utils.c */
char	*ft_strchr(const char *s, int c);
char	*ft_substr(const char *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(const char *s1, const char *s2);

#endif