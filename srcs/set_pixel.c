/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 09:25:04 by yuknakas          #+#    #+#             */
/*   Updated: 2026/07/09 16:15:09 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		color_image(t_minirt *minirt);
static void	set_pixel(t_minirt *minirt);

void	color_image(t_minirt *minirt)
{
	setup_screen(minirt->camera);
	minirt->pixel.x = 0;
	while (minirt->pixel.x < HEIGHT)
	{
		minirt->pixel.y = 0;
		while (minirt->pixel.y < WIDTH)
		{
			set_pixel(minirt);
			minirt->pixel.y++;
		}
		minirt->pixel.x++;
	}
	mlx_put_image_to_window(minirt->display.mlx, minirt->display.window,
			minirt->display.image, 0, 0);
	return ;
}

/**
 * Sets the color of a pixel by calculating the closest element and the color
 * @param minirt t_minirt struct, must have updated minirt->pixel.x and y values
 */
static void	set_pixel(t_minirt *minirt)
{
	int	*buf;
	int	color;

	color = get_color(minirt, get_close_elem(minirt));
	buf = minirt->display.ptr_to_image;
	buf[(minirt->pixel.x * minirt->display.size_line / sizeof(int))
			+ minirt->pixel.y] = color;
}
