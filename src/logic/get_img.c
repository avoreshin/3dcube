/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlamonic <jlamonic@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 18:07:13 by jlamonic          #+#    #+#             */
/*   Updated: 2022/06/01 18:07:15 by jlamonic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_draw_walls(t_p *p, t_data *img)
{
	int		col;
	int		start_ind;
	float	k;
	int		i;

	col = 0;
	start_ind = img->plr->ind_v - p->res_x / 2;
	if (start_ind < 0)
		start_ind += p->cnt_v;
	while (col < p->res_x)
	{
		ft_ray(img, img->v[start_ind + col]);
		k = img->v[ft_abs(p->res_x / 2 - col)].x;
		i = img->plr->cnt_s;
		img->plr->sprite[i - 1].h /= k;
		ft_column(img, img->plr->sprite, col, img->plr->cnt_s);
		col++;
	}
}

void	draw_floor_and_cel(t_p *p, t_data *img)
{
	int	i;

	i = 0;
	while (i < p->res_y / 2)
		ft_put_row(img, i++, p->ceiling);
	while (i < p->res_y)
		ft_put_row(img, i++, p->floor);
}

void	ft_column(t_data *img, t_sprite *spr, int col, int i)
{
	int			row_sp;
	int			up;
	int			down;
	t_texture	*xpm;
	int			color;

	while (i--)
	{
		xpm = spr[i].xpm;
		down = (img->p->res_y - spr[i].h) / 2;
		row_sp = -1;
		while (++row_sp < xpm->h)
		{
			up = ft_max(0, down);
			down = ft_min(img->p->res_y, (img->p->res_y - spr[i].h) / 2
					+ (row_sp + 1) * spr[i].h / xpm->h);
			color = ft_get_pixel(xpm, row_sp, spr[i].diff);
			if (down >= 0 && up < img->p->res_y
				&& (i + 1 == img->plr->cnt_s
					|| spr[i].h / 2 < img->p->res_y)
				&& color != TRNS)
				while (up < down)
					ft_put_pixel(img, up++, col, color);
		}
	}
}
