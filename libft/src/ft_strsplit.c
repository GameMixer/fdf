/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gderenzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 16:23:41 by gderenzi          #+#    #+#             */
/*   Updated: 2017/03/06 15:48:51 by gderenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*strdup_plus(char *start, char *end)
{
	char *res;
	char *iter;

	if ((res = (char *)malloc(end - start + 1)) == NULL)
		return (NULL);
	iter = res;
	while (start < end)
		*iter++ = *start++;
	*iter = '\0';
	return (res);
}

static char	*skip_past_delim(char *s, char c)
{
	while (*s != '\0' && *s == c)
		s++;
	return (s);
}

static char	*skip_to_delim(char *s, char c)
{
	while (*s != '\0' && *s != c)
		s++;
	return (s);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**result;
	int		i;
	char	*iter;

	i = 0;
	if (!s)
		return (NULL);
	iter = skip_past_delim((char *)s, c);
	while (*iter != '\0')
	{
		iter = skip_past_delim(skip_to_delim(iter, c), c);
		i++;
	}
	if ((result = (char **)malloc(sizeof(char *) * i + 1)) == NULL)
		return (NULL);
	i = 0;
	iter = skip_past_delim((char *)s, c);
	while (*iter != '\0')
	{
		result[i++] = strdup_plus(iter, skip_to_delim(iter, c));
		iter = skip_to_delim(iter, c);
		iter = skip_past_delim(iter, c);
	}
	result[i] = NULL;
	return (result);
}
