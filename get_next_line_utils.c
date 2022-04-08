/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 15:18:27 by junykim           #+#    #+#             */
/*   Updated: 2022/04/08 12:49:23 by junykim          ###   ########.fr       */
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

	srclen = 0;
	while (src[srclen])
		srclen++;
	if (srclen + 1 < n)
		ft_memcpy(dst, src, srclen + 1);
	else if (n != 0)
	{
		ft_memcpy(dst, src, n - 1);
		dst[n - 1] = 0;
	}
	return (srclen);
}
