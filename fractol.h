/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krusty <krusty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 03:31:16 by dcid-san          #+#    #+#             */
/*   Updated: 2025/03/30 00:02:43 by krusty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/Xutil.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define WIDTH 600
# define HEIGHT 600
# define QUALITY 2000
# define TITLE "Fractol by dcid-san"
# define COLOR_BLACK 0x000000 
# define COLOR_WHITE 0xFFFFFF
# define COLOR_MAGENTA 0xFF00FF
# define PI 3.14159265358979323846

# define JULIA 0
# define MANDELBROT 1
# define BURNING_SHIP 2
# define MANDELBROT_STR "mandelbrot"
# define JULIA_STR "julia"
# define BURNING_SHIP_STR "burning_ship"
/*
** Estructura para la imagen, contiene la referencia a la imagen,
** su dirección en memoria y los parámetros de la imagen.
*/

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_coord
{
	double	real;
	double	imaginary;
}	t_coord;

typedef struct s_f_data
{
	void	*mlx_ptr;
	void	*window_ptr;
	char	*name;
	int		num;
	t_img	*img;
	double	hypotenuse_max;
	double	added_x;
	double	added_y;
	double	quality;
	double	zoom;
	double	scale_x;
	double	scale_y;
	double	julia_c_real;
	double	julia_c_imag;

}	t_f_data;


void init_data(t_f_data *data);
void print_fractal(t_f_data *data);
int	keyboard_handler(int keysym, t_f_data *data);
void pixel_put(t_img *img, int x, int y, int color);
t_coord square_coord(t_coord current);
t_coord sum_coord(t_coord coord1, t_coord coord2);
int			keyboard_handler(int keysym, t_f_data *data);
int			mouse_handler(int button, int x, int y, t_f_data *data);
int			close_handler(t_f_data *data);
void exit_with_error(char *msg, int code, t_f_data *data, void (*callback)(t_f_data *));
void exit_with_msg(char *msg, int code, t_f_data *data, void (*callback)(t_f_data *));
void free_data(t_f_data *data);
int get_color(int i, int quality);
double scale_range(double unscaled, double min_val, 
	double max_val, double curr_min, double curr_max);
#endif
