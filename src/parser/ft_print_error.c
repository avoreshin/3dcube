/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlamonic <jlamonic@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 18:08:37 by jlamonic          #+#    #+#             */
/*   Updated: 2022/06/01 18:08:40 by jlamonic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_print_error(char *s)
{
	ft_putstr_fd("Error\n", 2);
	if (s)
		ft_putstr_fd(s, 2);
	else
		perror(NULL);
	exit (1);
}
