/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlamonic <jlamonic@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 18:09:26 by jlamonic          #+#    #+#             */
/*   Updated: 2022/06/01 19:29:10 by jlamonic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	create_line1(t_data *img, t_dot *dot_row, t_dot *dot_col, \
						t_vector *vect)
{
	int		max_cross;
	t_dot	dot;

	max_cross = 256;
	while (max_cross && img->plr->cnt_s < 200)
	{
		if (ft_dist(dot_row->x - img->plr->x, dot_row->y - img->plr->y)
			< ft_dist(dot_col->x - img->plr->x, dot_col->y - img->plr->y))
		{
			next_fun(vect, &dot, dot_row);
			if (ft_sell_x(img, vect, &dot, &img->plr->cnt_s))
				break ;
		}
		else
		{
			next_fun(vect, &dot, dot_row);
			if (ft_cell_y(img, vect, &dot, &img->plr->cnt_s))
				break ;
			max_cross--;
		}
	}
}

void	create_line2(t_data *img, t_vector vect, t_p *p)
{
	int		col;
	float	k;
	int		i;
	t_dot	dot_row;
	t_dot	dot_col;

	col = 0;
	img->plr->cnt_s = 0;
	dot_row.x = (int)img->plr->x + (vect.cx > 0);
	dot_row.y = img->plr->y + (dot_row.x - img->plr->x)
		* vect.cy * vect.cx;
	dot_col.y = (int)img->plr->y + (vect.ry > 0);
	dot_col.x = img->plr->x + (dot_col.y - img->plr->y)
		* vect.rx * vect.ry;
	create_line1(img, &dot_row, &dot_col, &vect);
	k = img->v[ft_abs(p->res_x / 2 - col)].x;
	i = img->plr->cnt_s;
	img->plr->sprite[i - 1].h /= k;
}

void	create_pixel(t_data *img, int row, int col, int color)
{
	char	*dst;

	dst = img->addr + (row * img->llen + col * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

void	create_pix(t_data *img, int down, t_texture *xpm, int row_sp)
{
	int	i;
	int	up;
	int	col;
	int	color;

	i = 0;
	up = ft_max(0, down);
	col = 0;
	color = ft_get_pixel(xpm, row_sp, img->plr->sprite[img->plr->cnt_s].diff);
	down = ft_min(img->p->res_y, (img->p->res_y - \
		img->plr->sprite[img->plr->cnt_s].h) / 2
			+ (row_sp + 1) * img->plr->sprite[img->plr->cnt_s].h / xpm->h);
	if (down >= 0 && up < img->p->res_y
		&& (i + 1 == img->plr->cnt_s
			|| img->plr->sprite[img->plr->cnt_s].h / 2 < img->p->res_y)
		&& (color != TRNS))
	{
		while (up < down)
		{
			create_pixel(img, up++, col, color);
			up++;
		}
	}
}
