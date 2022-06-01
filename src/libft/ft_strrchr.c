/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlamonic <jlamonic@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 18:04:34 by jlamonic          #+#    #+#             */
/*   Updated: 2022/06/01 18:04:36 by jlamonic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*tmp;

	tmp = s;
	while (*tmp != '\0')
		tmp++;
	if (c == '\0')
		return ((char *)tmp);
	while (tmp-- >= s)
	{
		if (*tmp == (unsigned char)c)
			return ((char *)tmp);
		if (tmp == s)
			return (NULL);
	}
	return (NULL);
}
