/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header_fdf.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuumola <tkuumola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 11:04:41 by tkuumola          #+#    #+#             */
/*   Updated: 2019/12/20 15:24:27 by tkuumola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_FDF_H
# define HEADER_FDF_H

# include "../libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include "mlx.h"

# define WIN_WIDTH (1280)
# define WIN_HEIGHT (720)

# define TEXT_COLOR	0xFFFFFF
# define NEON_BLUE	0x00D4FF
# define NEON_GREEN	0x3FFF00
# define ORANGE		0xCC610A
# define PINK		0xCC1A99
# define WHITE		0xDBE1E7
# define GREEN		0x787D62
# define BROWN		0x333333
# define BLACK		0x000000

typedef struct	s_coord
{
	int			x;
	int			y;
	float		z;
}				t_coord;

typedef	struct	s_buff
{
	t_coord		**pixel;
}				t_buff;

typedef	struct	s_rgb
{
	int			red;
	int			green;
	int			blue;
}				t_rgb;

typedef struct	s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
}				t_mlx;

typedef	struct	s_line_param
{
	int			delta_x;
	int			delta_y;
	int			yi;
	int			xi;
	int			d;
	int			y;
	int			x;
}				t_line_param;

typedef struct	s_line
{
	int			x0;
	int			y0;
	float		z0;
	int			x1;
	int			y1;
	float		z1;
	int			c0;
	int			c1;
	int			color;
}				t_line;

typedef struct	s_point
{
	int			x;
	int			y;
	int			z;
	float		scale_x;
	float		scale_y;
	float		scale_z;
	float		proj_x;
	float		proj_y;
	float		proj_z;
	int			color;
}				t_point;

typedef struct	s_grid
{
	t_point		**point;
	int			height;
	int			width;
	int			z_max;
	int			z_min;
	float		zoom;
}				t_grid;

typedef struct	s_camera
{
	float		alpha;
	float		beta;
	float		theta;
}				t_camera;

typedef	struct	s_color
{
	int			start;
	int			end;
	int			palette;
}				t_color;

typedef	struct	s_fdf
{
	t_grid		grid;
	t_mlx		mlx;
	t_camera	angle;
	t_color		color;
	t_buff		zbuff;
}				t_fdf;

int				ft_read(char **argv, t_fdf *fdf);

void			ft_puterror(char *message, int ret);

void			ft_init_fdf(t_fdf *fdf);
void			ft_init_to_zero(t_fdf *fdf, int row, int col);

void			ft_draw(t_fdf *fdf);

void			ft_draw_grid(t_fdf *fdf, t_line *line);

void			ft_plot_line(t_fdf *fdf, t_line *line);

void			ft_instructions(t_fdf *fdf);
int				deal_key(int key, t_fdf *fdf);
void			ft_projection_iso(t_fdf *fdf);
void			ft_projection_parallel(t_fdf *fdf);

void			ft_change_palette(t_fdf *fdf);

int				ft_close(t_fdf *fdf);
void			ft_zoom(t_fdf *fdf, int i);
void			ft_flat(t_fdf *fdf, int i);
void			ft_change_projection(t_fdf *fdf, int i);
void			ft_change_projection2(t_fdf *fdf, int i);

void			ft_init_buff(t_fdf *fdf);
void			ft_clean_zbuff(t_fdf *fdf);
int				pixel_is_visible(t_fdf	*fdf, t_line_param *param,\
											t_line *line, int i);

void			ft_maxmin_z(t_fdf *fdf);
int				ft_color(int start, int end, int k);

float			ft_get_min(float num1, float num2);
int				ft_get_max(int num1, int num2);
void			ft_free_memory(t_fdf *fdf);
size_t			ft_wordnb(const char *s);
int				ft_percent(int value, int total);

#endif
