/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 23:39:33 by yuknakas          #+#    #+#             */
/*   Updated: 2026/06/22 00:06:34 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "elements.h"

float	ray_plane(t_camera *camera, float ray[3], t_plane *plane, float min);
bool	_is_parallel(float ray[3], t_plane *plane);
bool	_is_overlapping(t_camera *camera, float ray[3], t_plane *plane);

/**
 * Finds the intersection of the ray and plane if there is one, 
 * returns the minimum distance.
 * @param camera pointer to t_camera struct
 * @param ray pointer to float[3] vector ray from camera to pixel
 * @param plane pointer to t_plane struct that is tested intersection
 * @param min the length to screen, aka the minimum distance to appear
 * @return the distance from camera to intersecting point.
 * If not intersection set to -1.0F
 * 
 * For plane: (x - p₀) • n = 0 and line: x = l₀ + dl
 * 
 * distance = ((p₀ - l₀) • n) / (l • n)
 */
float	ray_plane(t_camera *camera, float ray[3], t_plane *plane, float min)
{
	float	p0_min_l0[3];

	if (_is_parallel(ray, plane))
	{
		if (_is_overlapping(camera, ray, plane))
			return (min);
		return (-1.0F);
	}
	v_subtract(plane->coords, ray, p0_min_l0);
	return (dot(p0_min_l0, plane->normal) / dot(ray, plane->normal));
}

/**
 * Tests if the ray and plane are parallel.
 * If so, there is either no or all intersections.
 * @param ray pointer to float[3] vector ray from camera to pixel
 * @param plane pointer to t_plane struct that is tested intersection
 * @return boolean-true if parallel, false if not
 */
bool	_is_parallel(float ray[3], t_plane *plane)
{
	return (is_perpendicular(ray, plane->normal));
}

/**
 * Tests if the ray and plane are overlapping, when they are parallel
 * @param camera pointer to t_camera struct
 * @param ray pointer to float[3] vector ray from camera to pixel
 * @param plane pointer to t_plane struct that is tested intersection
 * @return boolean-true if overlaps, false if not
 * 
 * Use: for normal vector n: xn1 + yn2 + zn3 = d
 */
bool	_is_overlapping(t_camera *camera, float ray[3], t_plane *plane)
{
	float	d1;
	float	d2;
	int		idx;

	idx = 0;
	d1 = 0.0F;
	d2 = 0.0F;
	while (idx < 3)
	{
		d1 += camera->coords[idx] * plane->normal[idx];
		d2 += plane->coords[idx] * plane->normal[idx];
	}
	if (d1 - d2 < EPSILON)
		return (true);
	return (false);
}