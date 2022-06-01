/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlamonic <jlamonic@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 18:09:11 by jlamonic          #+#    #+#             */
/*   Updated: 2022/06/01 19:26:53 by jlamonic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	next_fun(t_vector *vector, t_dot *dot, t_dot *dot_row)
{
	dot->y = dot_row->y;
	dot->x = dot_row->x;
	if (1)
	{
		dot_row->x = (int)dot->x + vector->cx;
		dot_row->y = dot->y + (dot_row->x - dot->x) * vector->cy * vector->cx;
	}
	else
	{
		dot_row->y = (int)dot->y + vector->ry;
		dot_row->x = dot->x + (dot_row->y - dot->y) * vector->rx * vector->ry;
	}
}

void	window_buttons(t_data *img, t_button *btn, t_p *p)
{
	btn->w = false;
	btn->a = false;
	btn->s = false;
	btn->d = false;
	btn->q = false;
	btn->e = false;
	img->p = p;
	img->btn = btn;
	img->mlx = mlx_init();
	if (!img->mlx)
		ft_print_error("Cannot initialize mlx\n");
}
