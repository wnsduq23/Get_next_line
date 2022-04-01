/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 20:11:08 by junykim           #+#    #+#             */
/*   Updated: 2022/04/01 15:17:07 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
// 바이트가 0보다 크면 개행까지 읽어서 반환해주면 그 뒤에 있는 값은 어떻게 되는거?
// 개행을 찾았으면 다음 값의 주소를 반환하게?
// find memory leak
//
#define BUFFER_SIZE 32//임시용
static char	*find_LF_return_line(char *buf)
{
	char			*LF;
	unsigned int	start;

	start = 0;
	LF = ft_strchr(buf, '\n');//개행의 주소를 담기
	while (buf)
	{
		if (&buf[start++] == LF)
			break ;
	}
	return (ft_substr(buf, start, buf - LF + 1));
}

char	*get_next_line(int fd)
{
	char	*buf;
	char	*line;
	int		byte;

	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (0);
	buf[BUFFER_SIZE] = 0;
	byte = read(fd, buf, BUFFER_SIZE);
	while (1)
	{
		if (byte < 0)
			return (0);
		if (byte == 0)
			return (ft_strdup(""));
		line = find_LF_return_line(buf);
	}
	return (line);

}
