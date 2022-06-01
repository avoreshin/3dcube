/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlamonic <jlamonic@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 18:07:42 by jlamonic          #+#    #+#             */
/*   Updated: 2022/06/01 18:07:44 by jlamonic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	ft_get_pixel_img(t_data *img, int row, int col)
{
	int	*color;

	color = (int *)(img->addr + img->llen * row
			+ (img->bpp / 8) * col);
	return (*color);
}

void	ft_bmp_put_pixels(t_data *img, int fd)
{
	int	row;
	int	col;
	int	color;

	row = img->p->res_y;
	while (row--)
	{
		col = -1;
		while (++col < img->p->res_x)
		{
			color = ft_get_pixel_img(img, row, col);
			write(fd, &color, 3);
		}
		write(fd, "\0\0\0", col % 4);
	}
}
