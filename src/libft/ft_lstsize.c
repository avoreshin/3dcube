/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlamonic <jlamonic@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 18:01:48 by jlamonic          #+#    #+#             */
/*   Updated: 2022/06/01 18:01:56 by jlamonic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* считает количество элементов в листе. получает
указатель на голову и возврашает количество элементов*/

int	ft_lstsize(t_list *lst)
{
	int		counter;
	t_list	*tmp;

	counter = 0;
	if (lst == NULL)
		return (0);
	tmp = lst;
	while (tmp != NULL)
	{
		tmp = tmp -> next;
		counter++;
	}
	return (counter);
}
