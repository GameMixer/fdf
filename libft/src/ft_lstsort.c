/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gderenzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 13:24:36 by gderenzi          #+#    #+#             */
/*   Updated: 2017/03/21 18:19:21 by gderenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_checkcontent(t_list *lst, t_list *temp,
		int (*cmp)(void *, void *))
{
	t_list	*iter;

	iter = lst;
	while ((iter->next) && ((*cmp)(temp->content, iter->next->content)) >= 0)
		iter = iter->next;
	return (iter);
}

static void		ft_elsesub(t_list **lst, t_list **temp, t_list *val)
{
	(*temp)->next = val;
	*lst = *temp;
}

t_list			*ft_lstsort(t_list *lst, int (*cmp)(void *, void *))
{
	t_list	*head;
	t_list	*iter;
	t_list	*temp;

	head = lst;
	lst = NULL;
	while (head != NULL)
	{
		temp = head;
		head = head->next;
		if (lst != NULL)
		{
			if ((*cmp)(temp->content, lst->content) >= 0)
			{
				iter = ft_checkcontent(lst, temp, (*cmp));
				temp->next = iter->next;
				iter->next = temp;
			}
			else
				ft_elsesub(&lst, &temp, lst);
		}
		else
			ft_elsesub(&lst, &temp, NULL);
	}
	return (lst);
}
