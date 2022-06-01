/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlamonic <jlamonic@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 18:06:27 by jlamonic          #+#    #+#             */
/*   Updated: 2022/06/01 18:07:00 by jlamonic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	ft_game(t_data *img)
{
	ft_view(img->p, img->plr, img->btn);
	ft_pos(img->p->map, img->plr, img->btn, img->v);
	draw_floor_and_cel(img->p, img);
	ft_draw_walls(img->p, img);
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
	mlx_do_sync(img->mlx);
	return (0);
}
