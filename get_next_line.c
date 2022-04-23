/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 20:11:08 by junykim           #+#    #+#             */
/*   Updated: 2022/04/23 19:08:28 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/** static char *line : have to return 'line include \n'  */
/** find memory leak */
/** fd : save pos where it's finished. */

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

static char	*update_new_malloc(char const *save, char const *buf)
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

static char	*read_fd(char **p_save, int fd)
{
	char		*buf;
	ssize_t		byte;
	char		*temp;
	char		*new;

	buf = malloc(BUFFER_SIZE + 1);
	if (buf == NULL)
		return (NULL);
	new = *p_save;
	while (new == NULL || !ft_strchr(new, '\n'))
	{	
		byte = read(fd, buf, BUFFER_SIZE);
		if (byte <= 0)
			break ;
		buf[byte] = 0;
		temp = new;
		new = update_new_malloc(new, buf);
		free(temp);
		temp = NULL;
	}
	free(buf);
	buf = NULL;
	if (byte < 0)
		return (NULL);
	return (new);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	save = read_fd(&save, fd);
	if (save == NULL)
		return (NULL);
	if (*save == 0)
	{
		free(save);
		save = NULL;
		return (NULL);
	}
	line = get_line(save);
	if (line == NULL)
		return (NULL);
	save = set_remains(&save, ft_strlen(line));
	if (save == NULL)
		return (NULL);
	return (line);
}
