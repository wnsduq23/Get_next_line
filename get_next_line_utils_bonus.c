/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 17:19:37 by junykim           #+#    #+#             */
/*   Updated: 2022/04/02 17:27:57 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

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

char	*ft_strjoin(char const *s1, char const *s2)

{
	char	*total;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 || !s2)
		return (0);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	total = malloc(s1_len + s2_len + 1);
	if (!total)
		return (0);
	ft_memcpy(total, s1, s1_len);
	ft_memcpy(total + s1_len, s2, s2_len);
	total[s1_len + s2_len] = 0;
	return (total);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*(s + i))
		i++;
	return (i);
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

size_t	ft_strlcpy(char *dst, const char *src, size_t n)
{
	size_t	srclen;

	srclen = ft_strlen(src);
	if (srclen + 1 < n)
		ft_memcpy(dst, src, srclen + 1);
	else if (n != 0)
	{
		ft_memcpy(dst, src, n - 1);
		dst[n - 1] = 0;
	}
	return (srclen);
}
