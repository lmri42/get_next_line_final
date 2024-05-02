/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luribero <luribero@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 14:10:16 by luribero          #+#    #+#             */
/*   Updated: 2024/05/02 16:04:50 by luribero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*tmp_dst;
	unsigned char	*tmp_src;

	if (dst == (void *)0 && src == (void *)0)
		return (dst);
	tmp_dst = (unsigned char *) dst;
	tmp_src = (unsigned char *) src;
	while (n > 0)
	{
		*(tmp_dst++) = *(tmp_src++);
		n--;
	}
	return (dst);
}

int	ft_strlen(char *txt)
{
	int	count;

	count = 0;
	if (txt == NULL)
		return (0);
	while (*txt != '\0')
	{
		count++;
		txt++;
	}
	return (count);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;

	src_len = ft_strlen((char *)src);
	if (src_len + 1 < dstsize)
		ft_memcpy(dst, src, src_len + 1);
	else if (dstsize != 0)
	{
		ft_memcpy(dst, src, dstsize - 1);
		dst[dstsize - 1] = 0;
	}
	return (src_len);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*res;
	int		i;
	int		j;
	int		s_s1;
	int		s_s2;

	s_s1 = ft_strlen((char *)s1);
	s_s2 = ft_strlen((char *)s2);
	i = 0;
	j = 0;
	res = (char *) malloc((s_s1 + s_s2 + 1) * sizeof(char));
	if (!res)
		return (NULL);
	while ((s_s1) && (s1[i]))
	{
		res[j++] = s1[i++];
	}
	i = 0;
	while (s2[i])
	{
		res[j++] = s2[i++];
	}
	res[j] = '\0';
	return (res);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;
	char			cc;

	if (!s)
		return (NULL);
	cc = (char)c;
	i = 0;
	while (s[i])
	{
		if (s[i] == cc)
			return ((char *) &s[i]);
		i++;
	}
	if (s[i] == cc)
		return ((char *) &s[i]);
	return (NULL);
}
