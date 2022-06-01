/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlamonic <jlamonic@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 18:02:10 by jlamonic          #+#    #+#             */
/*   Updated: 2022/06/01 18:02:13 by jlamonic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*tmp_s;
	unsigned char	target;
	size_t			i;

	i = 0;
	tmp_s = (unsigned char *)s;
	target = (unsigned char)c;
	while (i < n)
	{
		if (*tmp_s == (unsigned char)target)
			return (tmp_s);
		tmp_s++;
		i++;
	}
	return (NULL);
}
