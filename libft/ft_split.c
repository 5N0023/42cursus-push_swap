/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlektaib <mlektaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 19:39:07 by mlektaib          #+#    #+#             */
/*   Updated: 2022/10/24 18:08:54 by mlektaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_countwords(char const *str, char c)
{
	int	i;
	int	count;

	if (!str)
		return (0);
	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i] != c && str[i])
			count++;
		while (str[i] != c && str[i])
			i++;
	}
	return (count);
}

static size_t	ft_wordlen(char const *str, char c)
{
	size_t	count;

	count = 0;
	while (str[count] && str[count] != c)
		count++;
	return (count);
}

static void	ft_freeall(char **ptr, size_t i)
{
	size_t	j;

	j = 0;
	while (j <= i)
	{
		free(ptr[j]);
		j++;
	}
	free(ptr);
}

char	**ft_split(char const *s, char c)
{
	char			**res;
	size_t			i;
	unsigned int	pos;

	if (!s)
		return (0);
	i = -1;
	pos = 0;
	res = malloc(sizeof(char *) * ft_countwords(s, c) + 1);
	if (!res)
		return (0);
	while (++i < ft_countwords(s, c))
	{
		while (s[pos] == c && s[pos])
			pos++;
		res[i] = ft_substr(s, pos, ft_wordlen((s + pos), c));
		if (!(res[i]))
		{
			ft_freeall(res, i);
			return (0);
		}
		pos += ft_wordlen(s + pos, c);
	}
	res[i] = NULL;
	return (res);
}
