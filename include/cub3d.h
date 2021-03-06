/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlamonic <jlamonic@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 23:18:05 by zu                #+#    #+#             */
/*   Updated: 2022/06/01 19:29:10 by jlamonic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <math.h>
# include <stdbool.h>
# include <fcntl.h>
# include <sys/errno.h>
# include "../src/mlx/mlx.h"
# include "../src/libft/libft.h"

# define KEY_W 13
# define KEY_S 1
# define KEY_A 0
# define KEY_D 2
# define KEY_UP 126
# define KEY_DW 125
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_Q 12
# define KEY_E 14
# define KEY_ESC 53
# define PLR_SPEED 0.16
# define PLR_ROTATE_SPEED 2
# define TRNS 0x980088

typedef struct s_vector
{
	double	x;
	double	y;
	double	rx;
	double	ry;
	double	cx;
	double	cy;
}	t_vector;

typedef struct s_texture
{
	void	*img;
	char	*addr;
	int		w;
	int		h;
	int		bpp;
	int		llen;
	int		end;
}	t_texture;

typedef struct s_sprite
{
	t_texture	*xpm;
	float		h;
	float		diff;
}	t_sprite;

typedef struct s_player
{
	float		x;
	float		y;
	float		z;
	double		vx;
	double		vy;
	double		vz;
	float		diff;
	int			texture_ind;
	t_sprite	sprite[200];
	int			cnt_s;
	int			ind_v;
	int			rotate_speed;
	float		speed;
}	t_player;

typedef struct s_button
{
	bool	w;
	bool	a;
	bool	s;
	bool	d;
	bool	q;
	bool	e;
}	t_button;

typedef struct s_p
{
	int		argc;
	char	**argv;
	int		res_x;
	int		res_y;
	char	*xpm[5];
	int		floor;
	int		ceiling;
	bool	got_sets;

	bool	end_map;
	int		map_height;
	int		map_width;
	t_list	*lst_map;
	char	**map;

	int		pers_x;
	int		pers_y;
	int		cnt_v;

}t_p;

typedef struct s_data {
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bpp;
	int			llen;
	int			end;
	t_texture	xpm[5];
	t_p			*p;
	t_player	*plr;
	t_button	*btn;
	t_vector	*v;
}				t_data;

typedef struct s_dot
{
	float	x;
	float	y;
	float	z;
}	t_dot;

typedef struct s_cell
{
	char	x;
	char	y;
}	t_cell;

int		ft_digits(char *line);
int		ft_count_chars(const char *line, char *chars);
void	ft_free_split(char **arr);
int		mini_strchr(char *str, char c);
int		ft_abs(int a);
int		ft_min(int a, int b);
int		ft_max(int a, int b);
float	ft_dist(float a, float b);
int		ft_parser(t_p *p, int argc, char **argv);
void	ft_print_error(char *s);
void	ft_check_map_line(t_p *p, char *line);
void	ft_parse_line(t_p *p, char *line);
void	ft_check_map_line(t_p *p, char *line);
void	ft_get_fc(t_p *p, char *line, bool is_floor);
void	ft_get_walls(t_p *p, char *line);
void	ft_create_map(t_p *p);
void	ft_check_holes(t_p *p);
int		ft_win_close(t_data *img);
void	draw_floor_and_cel(t_p *p, t_data *img);
void	ft_draw_walls(t_p *p, t_data *img);
void	ft_column(t_data *img, t_sprite *spr, int col, int i);
void	ft_ray(t_data *img, t_vector vray);
void	ft_init_dots(t_data *img, t_vector *vray, t_dot *dot_row,
			t_dot *dot_col);
void	next_fun_cross(t_vector *vray, t_dot *dot, t_dot *d, int is_row);
int		ft_sell_x(t_data *img, t_vector *vray, t_dot *dot, int *i);
int		ft_cell_y(t_data *img, t_vector *vray, t_dot *dot, int *i);
void	ft_sprite_x(t_data *img, t_vector *vray, t_dot *dot, char cell);
void	ft_sprite_y(t_data *img, t_vector *vray, t_dot *dot, char cell);
void	ft_put_pixel(t_data *img, int row, int col, int color);
void	ft_put_row(t_data *img, int row, int color);
int		ft_get_pixel(t_texture *xpm, int row_sp, float diff);
int		ft_button(int keycode, t_data *img);
int		ft_release_button(int keycode, t_data *img);
int		ft_game(t_data *img);
void	ft_pos(char **map, t_player *plr, t_button *btn, t_vector *vs);
void	ft_view(t_p *p, t_player *plr, t_button *btn);
void	ft_forward(t_vector *v, float speed, float *row, float *col);
void	ft_sideway(t_vector *v, float speed, float *row, float *col);
void	ft_change(char **map, t_player *plr, float row, float col);
void	vector_create(t_data *img, t_p *p);
void	init_player(t_data *img, t_p *p, t_player *plr);
int		ft_get_pixel_img(t_data *img, int row, int col);
void	next_fun(t_vector *vector, t_dot *dot, t_dot *dot_row);
void	window_buttons(t_data *img, t_button *btn, t_p *p);
void	check_resol(t_p *p, t_data *img);
void	create_vectors(t_data *img, t_p *p);
void	ft_vectorr(t_data *img, double cos_step, \
						double sin_step, t_p *p);
void	textures_creation(t_data *img, t_p *p);
void	create_line2(t_data *img, t_vector vect, t_p *p);
void	create_pixel(t_data *img, int row, int col, int color);
void	create_pix(t_data *img, int down, t_texture *xpm, int row_sp);
void	ft_col_make(t_data *img, int i);
void	ft_draw(t_p *p, t_data *img);
#endif
