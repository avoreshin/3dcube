/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_img_helpers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlamonic <jlamonic@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 18:07:07 by jlamonic          #+#    #+#             */
/*   Updated: 2022/06/01 18:07:08 by jlamonic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_put_pixel(t_data *img, int row, int col, int color)
{
	char	*dst;

	dst = img->addr + (row * img->llen + col * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

void	ft_put_row(t_data *img, int row, int color)
{
	unsigned int	*dst;
	int				i;

	i = 0;
	dst = (unsigned int *)(img->addr + row * img->llen);
	while (i < img->p->res_x)
		dst[i++] = color;
}

int	ft_get_pixel(t_texture *xpm, int row_sp, float diff)
{
	int	*color;

	color = (int *)(xpm->addr + xpm->llen * row_sp
			+ (xpm->bpp / 8) * (int)(xpm->w * diff));
	return (*color);
}
