/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 20:11:08 by junykim           #+#    #+#             */
/*   Updated: 2022/04/08 12:29:32 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/* static char *line : have to return 'line include \n'  */
// find memory leak
// if func return buf , means there is no \n so have to take next line in GNL
/* fd : save pos where it's finished.*/

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

char	*get_next_line(int fd)
{
	static char	*s_save;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	s_save = read_iter(&s_save, fd);
	if (s_save == NULL || *s_save == '\0')
	{
		free(s_save);
		s_save = NULL;
		return (NULL);
	}
	line = get_line(s_save);
	if (line == NULL)
	{
		free(s_save);
		s_save = NULL;
		return (NULL);
	}
	s_save = set_remains(&s_save, ft_strlen(line));
	if (s_save == NULL)
		return (NULL);
	return (line);
}

static char	*read_iter(char **s_save, int fd)
{
	char		*buf;
	ssize_t		byte;
	char		*temp;
	char		*new;

	buf = malloc(BUFFER_SIZE + 1);
	if (buf == NULL)
		return (NULL);
	byte = 0;
	new = *s_save;
	while (new == NULL || !ft_strchr(new, '\n'))
	{	
		byte = read(fd, buf, BUFFER_SIZE);
		if (byte <= 0)
			break ;
		buf[byte] = '\0';
		temp = new;
		new = append_buf(new, buf);
		free(temp);
	}
	free(buf);
	buf = NULL;
	if (byte < 0)
		return (NULL);
	return (new);
}
