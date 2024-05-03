/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luribero <luribero@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 01:59:48 by luribero          #+#    #+#             */
/*   Updated: 2024/05/03 15:46:39 by luribero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;
	size_t	size;

	if (!s)
		return (NULL);
	size = ft_strlen((char *)s);
	if (start > (unsigned int)size)
		return (ft_strjoin(NULL, ""));
	if (len > (size + start))
		len = size + start;
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	return (str);
}

void	ft_error(char **remain, int *finish, char **line)
{
	if (*line != NULL)
	{
		free(*line);
		*line = NULL;
	}
	if (*remain != NULL)
		*remain = NULL;
	if (*finish != 1)
		*finish = 1;
}

void	reader(int fd, char **line, int *finish)
{
	int		c_read;
	char	buff[BUFFER_SIZE + 1];
	char	*temp;

	c_read = read(fd, buff, BUFFER_SIZE);
	if (c_read < 0)
		*finish = 2;
	else if (c_read < BUFFER_SIZE)
		*finish = 3;
	if (c_read > 0)
	{
		buff[c_read] = '\0';
		if (*line == NULL)
			*line = ft_strjoin(NULL, buff);
		else
		{
			temp = ft_strjoin(*line, buff);
			free(*line);
			*line = temp;
		}
	}
}

void	trimmer(char **remain, char **n_line)
{
	char	*nl;
	size_t	len;
	char	*temp;

	len = ft_strlen(*n_line);
	nl = ft_strchr(*n_line, '\n');
	*remain = ft_substr(*n_line, nl - *n_line + 1, len - (nl - *n_line));
	temp = ft_substr(*n_line, 0, (nl - *n_line + 1));
	free(*n_line);
	*n_line = temp;
}

char	*get_next_line(int fd)
{
	static struct s_remember	r;
	char						*line;

	if ((fd < 0) || (BUFFER_SIZE < 1) || (BUFFER_SIZE > INT_MAX) || (r.e == 1))
		return (NULL);
	line = NULL;
	if (r.txt != NULL)
		line = r.txt;
	r.txt = NULL;
	while ((!ft_strchr(line, '\n')) && (r.e == 0))
	{
		reader(fd, &line, &r.e);
	}
	if (r.e == 2)
		ft_error(&r.txt, &r.e, &line);
	else if (ft_strchr(line, '\n') != NULL)
		trimmer(&r.txt, &line);
	if (r.e == 3 && (!line || !(*line)))
	{
		r.e = 1;
		return (NULL);
	}
	return (line);
}
