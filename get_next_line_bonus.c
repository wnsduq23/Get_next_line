/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 17:16:40 by junykim           #+#    #+#             */
/*   Updated: 2022/04/02 17:19:11 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

char	*get_next_line(int fd) /* fd: 3이라고 가정해봅시다 */
{
/* heap에 할당되어 줄줄이 연결되어 있는 연결리스트의 첫 주소를 보관하기 위한 노드
** 멤버는 모두 0으로 초기화되고 그중 next만 사용하게 된다.
** t_list *로 선언할 수도 있겠으나, 리스트관련함수를 쓰려면 얘도 노드인 게 편하다. */
	static t_list	head;
	t_list			*node; /* fd: 3인 node를 저장 */
	char			*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);

/* fd: 3인 노드를 찾고, 없으면 새로 만들어서 연결 후 반환한다. 
** &head로 넘겨주어야 하는 이유: 
** 새로운 노드를 할당했을 경우 연결작업을 하는데, 이 때 해당 멤버의 값을 수정하려고 */
	node = get_node(&head, fd);
	if (node == NULL)
		return (NULL);

	node->save = read_iter(&(node->save), fd);
	if (node->save == NULL || *(node->save) == '\0')
	{
/* get_next_line(3)은 더이상 main에서 사용할 일이 없다고 판단하고,
** 1. fd : 3인 노드의 멤버와 노드 자체를 프리시키는 작업
** 2. 앞뒤 노드를 연결시켜두는 작업을 진행한다. */
		del_node(&node);
		return (NULL);
	}
	line = get_line(node->save);
	if (line == NULL)
	{
		del_node(&node);
		return (NULL);
	}
	node->save = set_remains(&(node->save), ft_strlen(line));
	if (node->save == NULL)
	{
		del_node(&node);
		return (NULL);
	}
	return (line);
}

t_list	*get_node(t_list *head, int fd)
{
	t_list	*node;

/* fd: 3인 노드가 있을 때 */
	node = head->next;
	while (node)
	{
		if (node->fd == fd)
			return (node); /* 그 노드 리턴 */
		else
			node = node->next;
	}

/* fd:3인 노드가 없거나 아예 연결리스트가 없을 때 */
	node = malloc(sizeof(t_list));
	if (node == NULL)
		return (NULL);

/* 새로 만든 노드에는 쓰레기값이 들어있다. 초기화시킨다. */
	node->fd = fd;
	node->save = NULL;
	node->prev = head;
	node->next = head->next;

/* 앞뒤 노드에 나를 넣어준다. */
	if (head->next) /* head->next가 NULL이면 할 필요가 없음 */
		head->next->prev = node;
	head->next = node;

	return (node);
}

/**************************************************************************/

void	del_node(t_list **node)
{
	free((*node)->save); /* 1. save 프리 */
	(*node)->prev->next = (*node)->next; /* 2. 앞 노드에 다음 노드 정보 넣기 */
	if ((*node)->next)
	{
		(*node)->next->prev = (*node)->prev; /* 3. 뒷 노드에 앞 노드 정보 넣기 */
	}
	free(*node); /* 4. node 프리 */
	*node = NULL; /* (댕글링 포인터 방지) */
}
