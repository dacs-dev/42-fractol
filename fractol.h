#ifndef FRACTOL_H
#define FRACTOL_H

#include "libft/libft.h"
#include "minilibx-linux/mlx.h"
#include <X11/X.h>
#include <X11/Xutil.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define COLOR_BLACK 0x000000 /* Negro */
#define COLOR_WHITE 0xFFFFFF /* Blanco */
#define COLOR_RED 0xFF0000
#define COLOR_GREEN 0x00FF00
#define COLOR_BLUE 0x0000FF
#define COLOR_YELLOW 0xFFFF00
#define COLOR_CYAN 0x00FFFF
#define COLOR_MAGENTA 0xFF00FF
#define COLOR_ORANGE 0xFFA500
#define COLOR_PURPLE 0x800080
#define COLOR_PINK 0xFFC0CB
#define COLOR_LIME 0xBFFF00
#define COLOR_TEAL 0x008080
#define COLOR_INDIGO 0x4B0082
#define COLOR_VIOLET 0xEE82EE
#define COLOR_GOLD 0xFFD700
#define COLOR_SILVER 0xC0C0C0
#define COLOR_BROWN 0xA52A2A
#define COLOR_MAROON 0x800000
#define COLOR_OLIVE 0x808000
#define COLOR_NAVY 0x000080
#define COLOR_GRAY 0x808080
#define COLOR_CHOCOLATE 0xD2691E
#define COLOR_CORAL 0xFF7F50
#define COLOR_CRIMSON 0xDC143C
#define COLOR_FIREBRICK 0xB22222
#define COLOR_DARKGREEN 0x006400
#define COLOR_DARKORCHID 0x9932CC

#define QUALITY 100
#define WIDTH 800
#define HEIGHT 800
#define TITLE "Fractol dcid-san"
#define JULIA 0
#define MANDELBROT 1
#define MANDELBROT_STR "mandelbrot"
#define JULIA_STR "julia"
/*
** Estructura para la imagen, contiene la referencia a la imagen,
** su dirección en memoria y los parámetros de la imagen.
*/
typedef struct s_img
{
	void *img;
	char *addr;
	int   bits_per_pixel;
	int   line_length;
	int   endian;
} t_img;

/*
** Estructura principal de fractol.
** Aquí se almacenan los punteros de la miniLibX, la imagen, y
** parámetros para el zoom, desplazamiento y opciones del fractal.
*/
typedef struct s_coord
{
	double real;
	double imaginary;
} t_coord;

typedef struct s_f_data
{
	void  *mlx_ptr;
	void  *window_ptr;
	char  *name;
	int    num;
	t_img *img;
	double hypotenuse_max;
	double added_x;
	double added_y;
	double quality;
	double zoom;

} t_f_data;
/*
** Prototipos de funciones
*/
void init_data(t_f_data *data);
void print_fractal(t_f_data *data);
int  keyboard_handler(int keysym, t_f_data *data);
void pixel_put(t_img *img, int x, int y, int color);
double scale_range(double unscaled, double min_val, double max_val, double curr_min, double curr_max);
t_coord square_coord(t_coord current);
t_coord sum_coord(t_coord coord1, t_coord coord2);
int     keyboard_handler(int keysym, t_f_data *data);
int     mouse_handler(int button, int x, int y, t_f_data *data);
int     close_handler(t_f_data *data);
void exit_with_error(char *msg, int code, t_f_data *data, void (*callback)(t_f_data *));
void exit_with_msg(char *msg, int code, t_f_data *data, void (*callback)(t_f_data *));
void free_data(t_f_data *data);

#endif
