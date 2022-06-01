/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlamonic <jlamonic@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 18:02:35 by jlamonic          #+#    #+#             */
/*   Updated: 2022/06/01 18:02:37 by jlamonic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*tmp_dst;
	char	*tmp_src;
	size_t	i;

	i = 0;
	if (dst || src)
	{
		tmp_dst = (char *)dst;
		tmp_src = (char *)src;
		if (tmp_src > tmp_dst)
		{
			ft_memcpy(dst, src, len);
		}
		else
		{
			while (len--)
				tmp_dst[len] = tmp_src[len];
		}
	}
	return (dst);
}
