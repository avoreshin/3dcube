/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_common_checks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlamonic <jlamonic@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 18:08:46 by jlamonic          #+#    #+#             */
/*   Updated: 2022/06/01 18:08:48 by jlamonic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	ft_digits(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!ft_isdigit(line[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_count_chars(const char *line, char *chars)
{
	int		i;
	int		count;

	count = 0;
	while (*line)
	{
		i = 0;
		while (chars[i])
		{
			if (*line == chars[i++])
			{
				count++;
				break ;
			}
		}
		line++;
	}
	return (count);
}

void	ft_free_split(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

int	mini_strchr(char *str, char c)
{
	while (*str)
		if (*str++ == c)
			return (1);
	return (0);
}
