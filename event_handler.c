#include "fractol.h"
#include <X11/X.h>
#include <X11/Xutil.h>
int keyboard_handler(int keysym, t_f_data *data)
{
	if (keysym == XK_Escape)
		exit_with_msg("Se presiona ESC cerramos...\n", 0, data, free_data);
	else if (keysym == XK_Left)
		data->added_x += 0.5 * data->zoom;
	else if (keysym == XK_Right)
		data->added_x -= 0.5 * data->zoom;
	else if (keysym == XK_Up)
		data->added_y += 0.5 * data->zoom;
	else if (keysym == XK_Down)
		data->added_y -= 0.5 * data->zoom;
	else if (keysym == XK_plus || keysym == XK_KP_Add)
		data->quality += 10;
	else if (keysym == XK_minus || keysym == XK_KP_Subtract)
		data->quality -= 10;
	print_fractal(data);
	return (0);
}
int mouse_handler(int button, int x, int y, t_f_data *data)
{
	(void) x;
	(void) y;
	if (button == Button5)
		data->zoom *= 1.05;
	else if (button == Button4)
		data->zoom *= 0.95;
	print_fractal(data);
	return (0);
}

int close_handler(t_f_data *data)
{
	exit_with_msg("Se presiona el botón X cerramos...\n", 0, data, free_data);

	return (0);
}
