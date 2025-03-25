#include "fractol.h"

double scale_range(double unscaled, double min_val, double max_val, double curr_min, double curr_max)
{
	return (max_val - min_val) * (unscaled - curr_min) / (curr_max - curr_min) + min_val;
}

t_coord sum_coord(t_coord coord1, t_coord coord2)
{
	t_coord sum;

	sum.real = coord1.real + coord2.real;
	sum.imaginary = coord1.imaginary + coord2.imaginary;
	return (sum);
}

t_coord square_coord(t_coord current)
{
	t_coord square;
	square.real = (current.real * current.real) - (current.imaginary * current.imaginary);
	square.imaginary = 2 * (current.real * current.imaginary);
	return (square);
}
