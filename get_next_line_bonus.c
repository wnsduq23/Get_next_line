/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 17:16:40 by junykim           #+#    #+#             */
/*   Updated: 2022/04/11 16:51:12 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

static char	*get_line(char const *save)
{
	size_t	len;
	char	*line;

	if (ft_strchr(save, '\n'))
		len = ft_strchr(save, '\n') - save + 1;
	else
		len = ft_strchr(save, '\0') - save;
	line = malloc(len + 1);
	if (line == NULL)
		return (NULL);
	ft_strlcpy(line, save, len + 1);
	return (line);
}

static char	*set_remains(char **s_save, size_t offset)
{
	char	*new;

	new = malloc(ft_strlen(*s_save + offset) + 1);
	if (new == NULL)
		return (NULL);
	ft_strlcpy(new, *s_save + offset, ft_strlen(*s_save + offset) + 1);
	free(*s_save);
	*s_save = NULL;
	return (new);
}

static char	*append_buf(char const *save, char const *buf)
{
	char	*new;

	if (buf == NULL)
		return (NULL);
	else if (save == NULL && buf)
	{
		new = malloc(ft_strlen(buf) + 1);
		if (new == NULL)
			return (NULL);
		ft_strlcpy(new, buf, ft_strlen(buf) + 1);
		return (new);
	}
	new = malloc(ft_strlen(save) + ft_strlen(buf) + 1);
	if (new == NULL)
		return (NULL);
	ft_strlcpy(new, save, ft_strlen(save) + 1);
	ft_strlcpy(new + ft_strlen(save), buf, ft_strlen(buf) + 1);
	return (new);
}

static char	*read_iter(char **s_save, int fd)
{
	char		*buf;
	ssize_t		nread;
	char		*temp;
	char		*new;

	buf = malloc(BUFFER_SIZE + 1);
	if (buf == NULL)
		return (NULL);
	nread = 0;
	new = *s_save;
	while (new == NULL || !ft_strchr(new, '\n'))
	{	
		nread = read(fd, buf, BUFFER_SIZE);
		if (nread <= 0)
			break ;
		buf[nread] = '\0';
		temp = new;
		new = append_buf(new, buf);
		free(temp);
	}
	free(buf);
	buf = NULL;
	if (nread < 0)
		return (NULL);
	return (new);
}

char	*get_next_line(int fd)
{
	static t_list	head;
	t_list			*node;
	char			*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	node = get_node(&head, fd);
	if (node == NULL)
		return (NULL);
	node->save = read_iter(&(node->save), fd);
	if (node->save == NULL || *(node->save) == '\0')
		return (del_node(&node));
	line = get_line(node->save);
	if (line == NULL)
		return (del_node(&node));
	node->save = set_remains(&(node->save), ft_strlen(line));
	if (node->save == NULL)
		return (del_node(&node));
	return (line);
}
