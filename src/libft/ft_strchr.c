/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlamonic <jlamonic@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 18:03:36 by jlamonic          #+#    #+#             */
/*   Updated: 2022/06/01 18:03:38 by jlamonic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	const char	*ptr;

	ptr = s;
	while (1)
	{
		if (*ptr == (unsigned char)c)
			return ((char *)ptr);
		if (*ptr == '\0')
			break ;
		ptr++;
	}
	return (NULL);
}
