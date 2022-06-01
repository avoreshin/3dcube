/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlamonic <jlamonic@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 18:01:14 by jlamonic          #+#    #+#             */
/*   Updated: 2022/06/01 18:01:23 by jlamonic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*шагает по листу и применяет функцию f к каждому элементу списка.
Из результата применения функции создает новый список.
Применяет функцию del, если необходимо*/

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*first_element;
	t_list	*new_lst;

	if (!f)
		return (NULL);
	first_element = NULL;
	while (lst)
	{
		new_lst = ft_lstnew((*f)(lst -> content));
		if (!(new_lst))
		{
			while (first_element)
			{
				new_lst = first_element -> next;
				(*del)(first_element -> content);
				free(first_element);
				first_element = new_lst;
			}
			lst = NULL;
			return (NULL);
		}
		ft_lstadd_back(&first_element, new_lst);
		lst = lst -> next;
	}
	return (first_element);
}
