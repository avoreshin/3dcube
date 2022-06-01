/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlamonic <jlamonic@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 18:02:01 by jlamonic          #+#    #+#             */
/*   Updated: 2022/06/01 18:02:03 by jlamonic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	i;
	char	*tmp_src;
	char	*tmp_dst;

	i = 0;
	tmp_src = (char *)src;
	tmp_dst = (char *)dst;
	while (i < n)
	{
		tmp_dst[i] = tmp_src[i];
		if ((unsigned char)tmp_src[i] == (unsigned char)c)
			return (dst + i + 1);
		i++;
	}
	return (0);
}
