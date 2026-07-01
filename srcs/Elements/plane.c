/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 23:39:33 by yuknakas          #+#    #+#             */
/*   Updated: 2026/07/01 10:17:55 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "elements.h"

float	ray_plane(float origin[3], float ray[3], t_plane *plane, float min);
bool	is_parallel(float ray[3], float n[3]);
// bool	is_overlapping(float origin[3], float a[3], float n[3]);

/**
 * Finds the intersection of the ray and plane if there is one, 
 * returns the minimum distance.
 * @param origin pointer float[3] that represents the origin of ray
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
float	ray_plane(float origin[3], float ray[3], t_plane *plane, float min)
{
	float	p0_min_l0[3];
	float	dist;

	if (is_parallel(ray, plane->normal))
		return (-1.0F);
	v_subtract(plane->coords, origin, p0_min_l0);
	dist = dot(p0_min_l0, plane->normal) / dot(ray, plane->normal);
	if (dist < min)
		return (-1.0F);
	return (dist);
}

/**
 * Tests if the ray and plane are parallel.
 * If so, there is either no or all intersections.
 * @param ray pointer to float[3] vector ray from camera to pixel
 * @param n the normal vector to plane
 * @return boolean-true if parallel, false if not
 */
bool	is_parallel(float ray[3], float n[3])
{
	return (is_perpendicular(ray, n));
}

// /**
//  * Tests if the ray and plane are overlapping, when they are parallel
//  * @param origin pointer float[3] that represents the origin of ray
//  * @param a a point on the plane
//  * @param n the normal vector to plane
//  * @return boolean-true if overlaps, false if not
//  * 
//  * Use: for normal vector n: xn1 + yn2 + zn3 = d
//  */
// bool	is_overlapping(float origin[3], float a[3], float n[3])
// {
// 	float	d1;
// 	float	d2;
// 	int		idx;

// 	idx = 0;
// 	d1 = 0.0F;
// 	d2 = 0.0F;
// 	while (idx < 3)
// 	{
// 		d1 += origin[idx] * n[idx];
// 		d2 += a[idx] * n[idx];
// 		idx++;
// 	}
// 	if (d1 - d2 < EPSILON)
// 		return (true);
// 	return (false);
// }
