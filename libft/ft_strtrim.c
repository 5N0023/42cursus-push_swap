/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlektaib <mlektaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 17:35:42 by mlektaib          #+#    #+#             */
/*   Updated: 2022/11/12 21:20:11 by mlektaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static size_t	ft_trimlen(size_t len, const char *s, const char *set)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = len - 1;
	while (s[i] && ft_check(s[i], set) && len > 1)
	{
		i++;
		len--;
	}
	while (s[j] && ft_check(s[j], set) && len > 1)
	{
		j--;
		len--;
	}
	return (len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		i;
	size_t		j;
	char		*new;
	size_t		len;
	size_t		newlen;

	if (!s1)
		return (0);
	i = 0;
	j = 0;
	len = ft_strlen(s1);
	newlen = ft_trimlen(len, s1, set);
	new = malloc((newlen + 1) * sizeof(char));
	if (!new)
		return (0);
	while (s1[i] && ft_check(s1[i], set))
		i++;
	while (j < newlen)
	{
		new[j] = s1[i];
		i++;
		j++;
	}
	new[j] = '\0';
	return (new);
}
