/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 17:19:37 by junykim           #+#    #+#             */
/*   Updated: 2022/04/11 16:29:54 by junykim          ###   ########.fr       */
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

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*(s + i))
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t n)
{
	size_t	srclen;
	size_t	i;

	if (!dst || !src)
		return (0);
	srclen = ft_strlen(src);
	i = 0;
	while (i < srclen && i + 1 < n)
	{
		dst[i] = src[i];
		i++;
	}
	if (n != 0)
		dst[i] = 0;
	return (srclen);
}

t_list	*get_node(t_list *head, int fd)
{
	t_list	*node;

	node = head->next;
	while (node)
	{
		if (node->fd == fd)
			return (node);
		else
			node = node->next;
	}
	node = malloc(sizeof(t_list));
	if (node == NULL)
		return (NULL);
	node->fd = fd;
	node->save = NULL;
	node->prev = head;
	node->next = head->next;
	if (head->next)
		head->next->prev = node;
	head->next = node;
	return (node);
}

void	*del_node(t_list **node)
{
	free((*node)->save);
	(*node)->save = NULL;
	(*node)->prev->next = (*node)->next;
	if ((*node)->next)
		(*node)->next->prev = (*node)->prev;
	free(*node);
	*node = NULL;
	return (NULL);
}
