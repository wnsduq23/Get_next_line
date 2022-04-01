/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 20:11:08 by junykim           #+#    #+#             */
/*   Updated: 2022/04/01 18:52:03 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/* if there LF is middle of the buffer, using static cause save character after LF */
/* static char *line : have to return 'line include \n'  */
// find memory leak
// if func return buf , means there is no \n so have to take next line in GNL
//할당이 안됐는데, 프리하는 경우
//free 한 후, 댕글링 포인터를 프리하는 경우
/* fd : save pos where it's finished.*/
#define BUFFER_SIZE 32//임시용
static char	*find_LF_return_line(char *buf)
{
	static char		*after_LF;
	unsigned int	start;

	start = 0;
	while (buf[start])
	{
		if (ft_strchr(buf, '\n') != NULL)
			break ;
		start++;
	}
	if (!buf[start])
		return (buf);
	after_LF = ft_substr(buf, start, ft_strlen(buf) - start);
	return (ft_substr(buf, 0, start));
}

char	*get_next_line(int fd)
{
	char		*buf;//is this static too?
	static char	*line;
	ssize_t			byte;

	if (fd < 0)
		return (NULL);
	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	byte = read(fd, buf, BUFFER_SIZE);// 이러면 fd의 값은 3으로 고정이고 가리키는 주소만 바뀌는거?
	buf[BUFFER_SIZE] = 0;
	while (byte > 0 && ft_strchr(line,'\n') == NULL)
	{
		line = find_LF_return_line(buf);
		byte = read(fd, buf, BUFFER_SIZE);
	}
	if (byte < 0)
		return (NULL);
	if (byte == 0)
		return (ft_strdup(""));
	free(buf);
	buf = NULL;
	return (line);
}
