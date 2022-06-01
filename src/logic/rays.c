/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlamonic <jlamonic@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 18:07:37 by jlamonic          #+#    #+#             */
/*   Updated: 2022/06/01 19:26:14 by jlamonic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_ray(t_data *img, t_vector vray)
{
	t_dot	dot;
	t_dot	dot_row;
	t_dot	dot_col;
	int		max_cross;

	ft_init_dots(img, &vray, &dot_row, &dot_col);
	max_cross = 256;
	while (--max_cross && img->plr->cnt_s < 200)
	{
		if (ft_dist(dot_row.x - img->plr->x, dot_row.y - img->plr->y)
			< ft_dist(dot_col.x - img->plr->x, dot_col.y - img->plr->y))
		{
			next_fun_cross(&vray, &dot, &dot_row, 1);
			if (ft_sell_x(img, &vray, &dot, &img->plr->cnt_s))
				break ;
		}
		else
		{
			next_fun_cross(&vray, &dot, &dot_col, 0);
			if (ft_cell_y(img, &vray, &dot, &img->plr->cnt_s))
				break ;
		}
	}
}

void	ft_init_dots(t_data *img, t_vector *vray,
		t_dot *dot_row, t_dot *dot_col)
{
	img->plr->cnt_s = 0;
	dot_row->x = (int)img->plr->x + (vray->cx > 0);
	dot_row->y = img->plr->y + (dot_row->x - img->plr->x)
		* vray->cy * vray->cx;
	dot_col->y = (int)img->plr->y + (vray->ry > 0);
	dot_col->x = img->plr->x + (dot_col->y - img->plr->y)
		* vray->rx * vray->ry;
}

void	next_fun_cross(t_vector *vray, t_dot *dot, t_dot *d, int is_row)
{
	dot->y = d->y;
	dot->x = d->x;
	if (is_row)
	{
		d->x = (int)dot->x + vray->cx;
		d->y = dot->y + (d->x - dot->x) * vray->cy * vray->cx;
	}
	else
	{
		d->y = (int)dot->y + vray->ry;
		d->x = dot->x + (d->y - dot->y) * vray->rx * vray->ry;
	}
}
