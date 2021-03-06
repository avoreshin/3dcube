/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_0.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlamonic <jlamonic@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 18:08:58 by jlamonic          #+#    #+#             */
/*   Updated: 2022/06/01 19:25:43 by jlamonic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	init_player(t_data *img, t_p *p, t_player *plr)
{
	img->plr = plr;
	plr->x = p->pers_x + 0.5;
	plr->y = p->pers_y + 0.5;
	plr->z = 0;
	plr->rotate_speed = p->cnt_v * PLR_ROTATE_SPEED / 180;
	plr->speed = PLR_SPEED;
	if (p->map[p->pers_y][p->pers_x] == 'E')
		plr->ind_v = 0;
	else if (p->map[p->pers_y][p->pers_x] == 'S')
		plr->ind_v = p->cnt_v / 4;
	else if (p->map[p->pers_y][p->pers_x] == 'W')
		plr->ind_v = p->cnt_v / 2;
	else
		plr->ind_v = p->cnt_v * 3 / 4;
	plr->vx = img->v[plr->ind_v].x;
	plr->vy = img->v[plr->ind_v].y;
}

void	ft_rotate(t_data *img, double sin_step, double cos_step, int i)
{
	double	copy_x;

	img->v[i].x = img->v[i - 1].x;
	img->v[i].y = img->v[i - 1].y;
	copy_x = img->v[i].x;
	img->v[i].x = copy_x * cos_step - img->v[i].y * sin_step;
	img->v[i].y = copy_x * sin_step + img->v[i].y * cos_step;
	img->v[i].cx = 1 - 2 * (img->v[i].x < 0);
	img->v[i].cy = img->v[i].y / img->v[i].x * img->v[i].cx;
	img->v[i].ry = 1 - 2 * (img->v[i].y < 0);
	img->v[i].rx = img->v[i].x / img->v[i].y * img->v[i].ry;
}

void	vector_create(t_data *img, t_p *p)
{
	int		i;
	double	sin_step;
	double	cos_step;

	p->cnt_v = ft_max(360, p->res_x * 6);
	sin_step = sin(M_PI * 2 / p->cnt_v);
	cos_step = cos(M_PI * 2 / p->cnt_v);
	img->v = malloc(sizeof(*img->v) * p->cnt_v * 1.21);
	if (!img->v)
		ft_print_error("Allocation error\n");
	i = 0;
	img->v[i].x = 1;
	img->v[i].y = 0;
	while (i < p->cnt_v * 1.2)
	{
		ft_rotate(img, sin_step, cos_step, i);
		i++;
	}
}

void	textures_create(t_data *img, t_texture *xpm, t_p *p, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		if (!ft_strncmp(p->xpm[i], p->xpm[j], ft_strlen(p->xpm[i]) + 1))
		{
			xpm[i] = xpm[j];
			continue ;
		}
		j++;
	}
	if (!ft_strncmp(p->xpm[i] + ft_strlen(p->xpm[i]) - 4, ".png", 4))
		ft_print_error("png textures not supported\n");
	xpm[i].img = mlx_xpm_file_to_image(img->mlx, p->xpm[i],
			&xpm[i].w, &xpm[i].h);
	if (!xpm[i].img)
		ft_print_error("Cannot read texture file\n");
	xpm[i].addr = mlx_get_data_addr(xpm[i].img, &xpm[i].bpp,
			&xpm[i].llen, &xpm[i].end);
}
