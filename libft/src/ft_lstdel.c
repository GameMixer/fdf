/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gderenzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 18:20:50 by gderenzi          #+#    #+#             */
/*   Updated: 2017/03/02 12:44:45 by gderenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *list;
	t_list *temp;

	list = *alst;
	while (list)
	{
		temp = list->next;
		(*del)(list->content, list->content_size);
		free(list);
		list = temp;
	}
	*alst = NULL;
}
