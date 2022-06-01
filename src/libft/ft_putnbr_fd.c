/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlamonic <jlamonic@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 18:03:10 by jlamonic          #+#    #+#             */
/*   Updated: 2022/06/01 18:03:12 by jlamonic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		i;

	i = n;
	if (i == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else
	{
		if (i < 0 && i > -2147483648)
		{
			ft_putchar_fd('-', fd);
			i *= -1;
		}
		if (i > 9)
			ft_putnbr_fd(i / 10, fd);
		ft_putchar_fd(i % 10 + '0', fd);
	}
}
