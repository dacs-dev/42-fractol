/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krusty <krusty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 14:48:21 by dcid-san          #+#    #+#             */
/*   Updated: 2025/03/29 14:11:33 by krusty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	scale_color(double unscaled, double curr_max)
{
	double	min_val;
	double	max_val;

	min_val = COLOR_BLACK;
	max_val = COLOR_WHITE;
	return ((max_val - min_val) * unscaled / curr_max + min_val);
}
