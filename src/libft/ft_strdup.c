/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlamonic <jlamonic@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 18:03:50 by jlamonic          #+#    #+#             */
/*   Updated: 2022/06/01 18:03:51 by jlamonic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dst;
	size_t	dstsize;
	size_t	i;

	i = 0;
	dstsize = (ft_strlen(s1) + 1) * (sizeof(const char));
	dst = malloc(dstsize);
	if (dst == NULL)
		return (NULL);
	while (i < dstsize)
	{
		dst[i] = s1[i];
		i++;
	}
	return ((char *)dst);
}
