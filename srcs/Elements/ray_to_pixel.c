/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_to_pixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 20:50:35 by yuknakas          #+#    #+#             */
/*   Updated: 2026/07/01 12:35:06 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "elements.h"

float		ray_to_pixel(t_camera *camera, int x, int y, float v_target[3]);
static void	_pixel_to_screen(t_camera *camera, int x, int y, float target[3]);

/**
 * Finds vector from the coordinates of the camera to the coordinates of 
 * where the pixel would be in the 3D world.
 * @param camera pointer to t_camera struct, holding important info
 * @param x x coordinate of pixel on the display
 * @param y y coordinate of pixel on the display
 * @param target pointer to where the vector should be stored
 * @return distance to pixel on screen
 */
float	ray_to_pixel(t_camera *camera, int x, int y, float v_target[3])
{
	float	coord_pixel[3];
	float	dist;

	_pixel_to_screen(camera, x, y, coord_pixel);
	v_subtract(coord_pixel, camera->center, v_target);
	dist = v_len(v_target);
	normalize(v_target, v_target);
	return (dist);
}

/**
 * Finds the coordinate of the pixel on the screen in the 3D world
 * @param camera pointer to t_camera struct, holding important info
 * @param x x coordinate of pixel on the display
 * @param y y coordinate of pixel on the display
 * @param target pointer to where the coordinate should be stored
 */
static void	_pixel_to_screen(t_camera *camera, int x, int y, float target[3])
{
	float	vert_dist;
	float	hori_dist;
	int		idx;

	vert_dist = (float)(x - HEIGHT / 2) / camera->height;
	hori_dist = (float)(y - WIDTH / 2) / camera->width;
	idx = 0;
	while (idx < 3)
	{
		target[idx] = camera->center[idx] + vert_dist * camera->v_vert[idx]
			+ hori_dist * camera->v_hori[idx];
		idx++;
	}
}
