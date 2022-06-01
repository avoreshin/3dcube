/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlamonic <jlamonic@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 13:45:20 by jlamonic          #+#    #+#             */
/*   Updated: 2022/06/01 17:44:45 by jlamonic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*k;

	k = malloc(count * size);
	if (NULL == k)
		return (NULL);
	ft_bzero((char *)k, count * size);
	return ((char *)k);
}
