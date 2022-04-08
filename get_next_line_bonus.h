/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 17:19:25 by junykim           #+#    #+#             */
/*   Updated: 2022/04/08 12:55:38 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				fd;
	char			*save;
	struct s_node	*prev;
	struct s_node	*next;
}t_list;
static char	*read_iter(char **s_save, int fd);
static char	*get_line(char const *save);
static char	*append_buf(char const *save, char const *buf);
char		*get_next_line(int fd);
t_list		*get_node(t_list *head, int fd);
void		del_node(t_list **node);
char		*ft_strchr(const char *s, int c);
size_t		ft_strlen(const char *s);
void		*ft_memcpy(void *dst, const void *src, size_t n);
char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlcpy(char *dst, const char *src, size_t n);
static char	*set_remains(char **s_save, size_t offset);
#endif
