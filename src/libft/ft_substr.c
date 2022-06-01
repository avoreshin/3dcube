/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlamonic <jlamonic@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 18:04:47 by jlamonic          #+#    #+#             */
/*   Updated: 2022/06/01 18:04:48 by jlamonic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_min(int x, int y)
{
	if (x < y)
		return (x);
	return (y);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*tmp;
	size_t	return_len;
	size_t	s_len;

	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	if (s_len < start)
		return (ft_strdup(""));
	return_len = ft_min((s_len - start), len);
	tmp = (char *)malloc(sizeof(char) * (return_len + 1));
	if (tmp == NULL)
		return (NULL);
	ft_strlcpy(tmp, s + start, return_len + 1);
	return (tmp);
}
