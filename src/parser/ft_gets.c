/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gets.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlamonic <jlamonic@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 18:08:18 by jlamonic          #+#    #+#             */
/*   Updated: 2022/06/01 19:30:11 by jlamonic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	check_rgb(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		if (!ft_digits(arr[i]))
			return (0);
		i++;
	}
	i = 0;
	while (arr[i])
	{
		if (ft_strlen(arr[i]) > 3 || ft_strlen(arr[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

static int	check_rec_color(int transpar, int red, int green, int black)
{
	return (transpar << 24 | red << 16 | green << 8 | black);
}

static void	fc_save(t_p *p, int *color, bool is_floor)
{
	if (is_floor)
	{
		if (p->floor != -1)
			ft_print_error("Floor color is already set\n");
		p->floor = check_rec_color(0, color[0], color[1], color[2]);
	}
	else
	{
		if (p->ceiling != -1)
			ft_print_error("Ceiling color is already set\n");
		p->ceiling = check_rec_color(0, color[0], color[1], color[2]);
	}
}

void	ft_get_fc(t_p *p, char *line, bool is_floor)
{
	char	**arr;
	char	*cutted;
	int		i;
	int		color[3];

	cutted = ft_strtrim(line, " ");
	arr = ft_split(cutted, ',');
	i = 0;
	while (arr[i])
		i++;
	if (i != 3 || !check_rgb(arr) || ft_count_chars(line, ",") != 2)
		ft_print_error("Invalid setting for the floor or the ceiling\n");
	i = -1;
	while (++i < 3)
		color[i] = ft_atoi(arr[i]);
	if (color[0] > 255 || color[1] > 255 || color[2] > 255)
		ft_print_error("Color code should be between 0 and 255\n");
	fc_save(p, color, is_floor);
	free(cutted);
	ft_free_split(arr);
}
