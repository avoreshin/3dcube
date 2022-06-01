/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_indexsrch.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlamonic <jlamonic@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 17:41:03 by jlamonic          #+#    #+#             */
/*   Updated: 2022/06/01 17:44:52 by jlamonic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_indexsrch(const char *s, int c)
{
	const char	*tmp;
	int			index;

	tmp = s;
	index = 0;
	while (*tmp != '\0')
	{
		if (tmp[index] == (unsigned char)c)
			return (index);
		index++;
	}
	return (0);
}
