/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luribero <luribero@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 00:02:02 by luribero          #+#    #+#             */
/*   Updated: 2024/05/03 14:14:38 by luribero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
// Include Libraries:
# include <stdlib.h>					//malloc, free
# include <unistd.h>					//write
# include <limits.h>					//LONG_MIN, INT_MAX, ULONG_MAX, etc
# include <fcntl.h>						//open
# include <stdio.h>						//testing
//# define BUFFER_SIZE 1000 		 	// buffer size
# define GET_NEXT_LINE_H

//STRUCTS:
struct s_remember
{
	char	*txt; //text
	int		e; //end
};
//FUNCTION PROTOTYPES:

void	*ft_memcpy(void *dst, const void *src, size_t n);

int		ft_strlen(char *txt);

size_t	ft_strlcpy(char *dst, const char *src, size_t n);

char	*ft_strjoin(char const *s1, char const *s2);

char	*ft_strchr(const char *s, int c);

char	*ft_substr(char const *s, unsigned int start, size_t len);

void	ft_error(char **remain, int *finish, char **line);

void	reader(int fd, char **line, int *finish);

void	trimmer(char **remain, char **n_line);

char	*get_next_line(int fd);

#endif
