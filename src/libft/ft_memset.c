/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlamonic <jlamonic@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 18:02:44 by jlamonic          #+#    #+#             */
/*   Updated: 2022/06/01 18:02:46 by jlamonic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*tmp;
	unsigned char	*end;

	tmp = (unsigned char *)s;
	end = (unsigned char *)(s + n);
	while (tmp < end)
	{
		*tmp = c;
		tmp++;
	}
	return (s);
}
