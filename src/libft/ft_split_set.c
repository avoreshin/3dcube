/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_set.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlamonic <jlamonic@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 18:03:25 by jlamonic          #+#    #+#             */
/*   Updated: 2022/06/01 18:03:27 by jlamonic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_sep(char ch, char *charset)
{
	while (*charset)
		if (*charset++ == ch)
			return (1);
	return (0);
}

static void	ft_free_split(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

static size_t	ft_count(char *s, char *c)
{
	size_t	cnt;

	cnt = 0;
	while (*s)
	{
		if (!is_sep(*s, c) && (is_sep(*(s + 1), c) || !*(s + 1)))
			cnt++;
		s++;
	}
	return (cnt);
}

char	**ft_split_set(char const *s, char *c)
{
	char	**out;
	size_t	i;
	size_t	row;

	row = 0;
	out = (char **)malloc(sizeof(char *) * (ft_count((char *)s, c) + 1));
	if (!out)
		return (NULL);
	while (*s)
	{
		while (is_sep(*s, c))
			s++;
		if (!*s)
			break ;
		i = 0;
		while (s[i] && !is_sep(s[i], c))
			i++;
		out[row] = ft_substr(s, 0, i);
		if (!out[row++])
			ft_free_split(out);
		s += i;
	}
	out[row] = NULL;
	return (out);
}
