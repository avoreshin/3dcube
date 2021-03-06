/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlamonic <jlamonic@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 18:09:18 by jlamonic          #+#    #+#             */
/*   Updated: 2022/06/01 19:28:29 by jlamonic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	check_resol(t_p *p, t_data *img)
{
	img->win = mlx_new_window(img->mlx, p->res_x, p->res_y, "cub3d");
	if (!img->win)
		ft_print_error("Cannot create game windows\n");
	img->img = mlx_new_image(img->mlx, p->res_x, p->res_y);
	if (!img->img)
		ft_print_error("Cannot create new mlx_img\n");
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->llen, &img->end);
}

void	ft_vectorr(t_data *img, double cos_step, \
						double sin_step, t_p *p)
{
	int		i;
	double	copy_x;

	i = 1;
	while (i < p->cnt_v * 1.2)
	{
		img->v[i].x = img->v[i - 1].x;
		img->v[i].y = img->v[i - 1].y;
		copy_x = img->v[i].x;
		img->v[i].x = copy_x * cos_step - img->v[i].y * sin_step;
		img->v[i].y = copy_x * sin_step + img->v[i].y * cos_step;
		img->v[i].cx = 1 - 2 * (img->v[i].x < 0);
		img->v[i].cy = img->v[i].y / img->v[i].x * img->v[i].cx;
		img->v[i].ry = 1 - 2 * (img->v[i].y < 0);
		img->v[i].rx = img->v[i].x / img->v[i].y * img->v[i].ry;
		i++;
	}
}

void	create_vectors(t_data *img, t_p *p)
{
	int		i;
	double	sin_step;
	double	cos_step;

	i = 0;
	p->cnt_v = ft_max(360, p->res_x * 6);
	sin_step = sin(M_PI * 2 / p->cnt_v);
	cos_step = cos(M_PI * 2 / p->cnt_v);
	img->v = malloc(sizeof(*img->v) * p->cnt_v * 1.21);
	if (!img->v)
		ft_print_error("Allocation error\n");
	img->v[i].x = 1;
	img->v[i].y = 0;
	ft_vectorr(img, cos_step, sin_step, p);
}

void	textures_creation(t_data *img, t_p *p)
{
	int	i;
	int	j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < i)
		{
			if (!ft_strncmp(p->xpm[i], p->xpm[j], ft_strlen(p->xpm[i]) + 1))
			{
				img->xpm[i] = img->xpm[j];
				continue ;
			}
		}
		if (!ft_strncmp(p->xpm[i] + ft_strlen(p->xpm[i]) - 4, ".png", 4))
			ft_print_error("png textures not supported\n");
		img->xpm[i].img = mlx_xpm_file_to_image(img->mlx, p->xpm[i],
				&img->xpm[i].w, &img->xpm[i].h);
		if (!img->xpm[i].img)
			ft_print_error("Cannot read texture file\n");
		img->xpm[i].addr = mlx_get_data_addr(img->xpm[i].img, &img->xpm[i].bpp,
				&img->xpm[i].llen, &img->xpm[i].end);
	}
}
