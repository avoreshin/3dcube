/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlamonic <jlamonic@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 18:09:38 by jlamonic          #+#    #+#             */
/*   Updated: 2022/06/01 19:29:10 by jlamonic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_col_make(t_data *img, int i)
{
	int			row_sp;
	int			down;
	t_texture	*xpm;

	while (i)
	{
		xpm = img->plr->sprite[img->plr->cnt_s].xpm;
		down = (img->p->res_y - img->plr->sprite[img->plr->cnt_s].h) / 2;
		row_sp = 0;
		while (row_sp < xpm->h)
		{
			create_pix(img, down, xpm, row_sp);
				row_sp++;
		}
		i--;
	}
}

void	ft_draw(t_p *p, t_data *img)
{
	int	i;
	int	col;
	int	start_ind;

	i = 0;
	col = 0;
	while (i < p->res_y / 2)
		ft_put_row(img, i++, p->ceiling);
	while (i < p->res_y)
		ft_put_row(img, i++, p->floor);
	start_ind = img->plr->ind_v - p->res_x / 2;
	if (start_ind < 0)
		start_ind += p->cnt_v;
	while (col < p->res_x)
	{
		create_line2(img, img->v[start_ind + col], p);
		ft_col_make(img, img->plr->cnt_s);
		col++;
	}
}
