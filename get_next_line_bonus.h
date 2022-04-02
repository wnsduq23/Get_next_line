/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 17:19:25 by junykim           #+#    #+#             */
/*   Updated: 2022/04/02 17:30:19 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
typedef struct node
{
	int index;
	struct node *next;	
}t_list;
char	*read_iter(char **s_save, int fd);
char	*get_line(char const *save);
char	*append_buf(char const *save, char const *buf);
char	*get_next_line(int fd);
t_list	*get_node(t_list *head, int fd);
void	del_node(t_list **node);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcpy(char *dst, const char *src, size_t n);
#endif
