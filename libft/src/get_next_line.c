/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gderenzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 18:47:18 by gderenzi          #+#    #+#             */
/*   Updated: 2017/03/24 16:25:50 by gderenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*get_correct_file(t_list **file, int fd)
{
	t_list	*tmp;

	tmp = *file;
	while (tmp)
	{
		if ((int)tmp->content_size == fd)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = ft_lstnew("\0", fd);
	ft_lstadd(file, tmp);
	tmp = *file;
	return (tmp);
}

int		get_next_line(const int fd, char **line)
{
	char			buff[BUFF_SIZE + 1];
	static t_list	*file;
	int				ret;
	t_list			*curr;

	if ((fd < 0 || line == NULL || read(fd, buff, 0) < 0))
		return (-1);
	curr = get_correct_file(&file, fd);
	MALLCHECK((*line = ft_strnew(1)));
	while ((ret = read(fd, buff, BUFF_SIZE)))
	{
		buff[ret] = '\0';
		MALLCHECK((curr->content = ft_strjoin(curr->content, buff)));
		if (ft_strchr(buff, '\n'))
			break ;
	}
	if (ret < BUFF_SIZE && !ft_strlen(curr->content))
		return (0);
	*line = ft_strsub(curr->content, 0, ft_strpos(curr->content, '\n'));
	if (ft_strpos(curr->content, '\n') < ft_strlen(curr->content))
		curr->content += (ft_strpos(curr->content, '\n') + 1);
	else
		ft_strclr(curr->content);
	return (1);
}
