/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 15:18:27 by junykim           #+#    #+#             */
/*   Updated: 2022/04/01 15:20:51 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char const *s, unsigned int start, size_t n)
{
	unsigned int	i;
	char			*ret;
	size_t			ret_s;
	size_t			ret_len;

	if (!s)
		return (0);
	if (ft_strlen(s) < n)
		ret_len = ft_strlen(s);
	else
		ret_len = n;
	ret = malloc(sizeof(char) *(ret_len + 1));
	if (!ret)
		return (0);
	i = 0;
	ret_s = 0;
	while (s[i])
	{
		if (start <= i && ret_s < n)
			ret[ret_s++] = s[i];
		i++;
	}
	ret[ret_s] = 0;
	return (ret);
}

char	*ft_strdup(const char *s)
{
	char	*dst;
	size_t	s_len;

	s_len = ft_strlen(s);
	dst = malloc(sizeof(char) * (s_len + 1));
	if (!dst)
		return (0);
	ft_memcpy(dst, s, s_len);
	dst[s_len] = 0;
	return (dst);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (c == 0)
		return ((char *)s);
	return (0);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (!dst && !src)
		return (dst);
	i = 0;
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dst);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*(s + i))
		i++;
	return (i);
}
