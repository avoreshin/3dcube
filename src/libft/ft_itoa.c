/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlamonic <jlamonic@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 17:41:03 by jlamonic          #+#    #+#             */
/*   Updated: 2022/06/01 17:45:47 by jlamonic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	size_maker(int n)
{
	int	tmp_n;

	tmp_n = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		tmp_n++;
	}
	return (tmp_n);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		sign;
	int		len;
	int		tmp;

	sign = 0;
	if (n < 0)
		sign = 1;
	len = size_maker(n);
	result = (char *)malloc((len + sign + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	result[len + sign] = '\0';
	while (len > 0)
	{
		tmp = n % 10;
		if (tmp < 0)
			tmp = -tmp;
		result[--len + sign] = tmp + '0';
		n = n / 10;
	}
	if (sign == 1)
		result[0] = '-';
	return (result);
}
