/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 20:20:14 by junykim           #+#    #+#             */
/*   Updated: 2022/04/08 12:33:40 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>

char		*ft_strchr(const char *s, int c);
size_t		ft_strlen(const char *s);
void		*ft_memcpy(void *dst, const void *src, size_t n);
char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlcpy(char *dst, const char *src, size_t n);
char		*get_next_line(int fd);
static char	*read_iter(char **s_save, int fd);
static char	*get_line(char const *save);
static char	*append_buf(char const *save, char const *buf);
static char	*set_remains(char **s_save, size_t offset);
#endif
