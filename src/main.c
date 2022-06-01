/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlamonic <jlamonic@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 18:50:32 by jbasmati          #+#    #+#             */
/*   Updated: 2022/06/01 19:28:29 by jlamonic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	main(int argc, char **argv)
{
	t_p			p;
	t_data		img;
	t_player	plr;
	t_button	btn;

	ft_parser(&p, argc, argv);
	window_buttons(&img, &btn, &p);
	textures_creation(&img, &p);
	check_resol(&p, &img);
	create_vectors(&img, &p);
	init_player(&img, &p, &plr);
	mlx_hook(img.win, 2, 1L << 0, ft_button, &img);
	mlx_hook(img.win, 3, 1L << 1, ft_release_button, &img);
	mlx_hook(img.win, 17, 1L << 1, ft_win_close, &img);
	mlx_loop_hook(img.mlx, ft_game, &img);
	mlx_loop(img.mlx);
}
