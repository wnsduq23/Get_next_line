/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 17:19:25 by junykim           #+#    #+#             */
/*   Updated: 2022/04/11 16:51:22 by junykim          ###   ########.fr       */
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
char		*get_next_line(int fd);
t_list		*get_node(t_list *head, int fd);
void		*del_node(t_list **node);
char		*ft_strchr(const char *s, int c);
size_t		ft_strlen(const char *s);
char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlcpy(char *dst, const char *src, size_t n);
#endif
