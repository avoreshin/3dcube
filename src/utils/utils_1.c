/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlamonic <jlamonic@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 18:09:05 by jlamonic          #+#    #+#             */
/*   Updated: 2022/06/01 19:26:00 by jlamonic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	funct_cool(t_data *img, int fd, int row)
{
	int	col;
	int	color;

	col = 0;
	while (row)
	{
		while (col < img->p->res_x)
		{
			color = ft_get_pixel_img(img, row, col);
			write(fd, &color, 3);
			col++;
		}
		write(fd, "\0\0\0", col % 4);
		row--;
	}
	close(fd);
	exit(0);
}
