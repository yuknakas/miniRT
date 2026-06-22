/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 09:41:00 by yuknakas          #+#    #+#             */
/*   Updated: 2026/06/22 16:25:35 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "elements.h"

float	ray_cylinder(float origin[3], float ray[3], t_cylinder *cyl, float min);
float	_cyl_surface(float origin[3], float ray[3], t_cylinder *cyl, float min);
float	_det_cyl(float origin[3], float ray[3], t_cylinder *cyl, float b[3]);
void	_set_dist(float dist[2], float det, float n_crs_a[3], float b_crs_a[3]);
bool	_t_cyl(float origin[3], float ray[3], t_cylinder *cyl, float dist);

/**
 * Finds the intersection of the ray and cylinder if there is one, 
 * returns the minimum distance.
 * @param origin pointer float[3] that represents the origin of ray
 * @param ray pointer to float[3] vector ray from camera to pixel
 * @param cyl pointer to t_cylinder struct that is tested intersection
 * @param min the length to screen, aka the minimum distance to appear
 * @return the distance from camera to intersecting point.
 * If not intersection set to -1.0F
 * 
 * Intersection with a cylinder must be calculated for both side and ends
 */
float	ray_cylinder(float origin[3], float ray[3], t_cylinder *cyl, float min)
{
	float	dist[2];

	dist[0] = _cyl_surface(origin, ray, cyl, min);
	dist[1] = cylinder_end(origin, ray, cyl, min);
	if (dist[0] < dist[1] && dist[0] >= min)
		return (dist[0]);
	if (dist[1] >= min)
		return (dist[1]);
	return (-1.0F);
}

/**
 * Finds the distance to intersect the surface of a cylinder
 * @param origin pointer float[3] that represents the origin of ray
 * @param ray pointer to float[3] vector ray from camera to pixel
 * @param cyl pointer to t_cylinder struct that is tested intersection
 * @param min the length to screen, aka the minimum distance to appear
 * @return the distance from camera to intersecting point on side surface
 * If no intersection, return -1.0F
 */
float	_cyl_surface(float origin[3], float ray[3], t_cylinder *cyl, float min)
{
	float	det;
	float	n_cross_a[3];
	float	b_cross_a[3];
	float	dist[2];

	cyl->center[0] = cyl->coords[0] + -(cyl->height / 2) * cyl->normal[0];
	cyl->center[1] = cyl->coords[1] + -(cyl->height / 2) * cyl->normal[1];
	cyl->center[2] = cyl->coords[2] + -(cyl->height / 2) * cyl->normal[2];
	det = _det_cyl(origin, ray, cyl, cyl->center);
	if (det < 0.0F)
		return (-1.0F);
	if (det < EPSILON)
		det = 0.0F;
	cross(ray, cyl->normal, n_cross_a);
	cross(cyl->center, cyl->normal, b_cross_a);
	_set_dist(dist, det, n_cross_a, b_cross_a);
	if (dist[0] >= min && _t_cyl(cyl->normal, ray, cyl, dist[0]) < cyl->height)
		return (dist[0]);
	if (dist[1] >= min && _t_cyl(cyl->normal, ray, cyl, dist[1]) < cyl->height)
		return (dist[1]);
	return (-1.0F);
}

/**
 * Finds the determinant of a line-cylinder intersection
 * @param origin pointer float[3] that represents the origin of ray
 * @param ray pointer to float[3] vector ray from camera to pixel
 * @param cyl pointer to t_cylinder struct that is tested intersection
 * @param b the center of the end circle
 * @return float value of the determinant
 */
float	_det_cyl(float origin[3], float ray[3], t_cylinder *cyl, float b[3])
{
	float	n_cross_a[3];

	cross(ray, cyl->normal, n_cross_a);
	if (v_len(n_cross_a) < EPSILON)
		return (-1.0F);
	return (dot(n_cross_a, n_cross_a) * (cyl->diameter / 2)
		* (cyl->diameter / 2) - dot(cyl->normal, cyl->normal)
		* dot(b, n_cross_a) * dot(b, n_cross_a));
}

/**
 * Helper function to set dist values within 25 lines for norminette
 * @param dist pointer to where to store dist
 */
void	_set_dist(float dist[2], float det, float n_crs_a[3], float b_crs_a[3])
{
	dist[0] = (dot(n_crs_a, b_crs_a)
			- sqrtf(det)) / dot(n_crs_a, n_crs_a);
	dist[1] = (dot(n_crs_a, b_crs_a)
			+ sqrtf(det)) / dot(n_crs_a, n_crs_a);
}

/**
 * Finds the height of where the intersecting point lies on the cylinder,
 *  used to check infinite cylinder
 * @param origin the origin of the ray
 * @param ray the ray
 * @param cyl pointer to t_cylinder struct
 * @param dist the dist from origin
 * @return boolean-true if point is on cylinder, false if not
 */
bool	_t_cyl(float origin[3], float ray[3], t_cylinder *cyl, float dist)
{
	float	o_min_b[3];
	float	x_min_b[3];
	float	t;

	v_subtract(origin, cyl->center, o_min_b);
	x_min_b[0] = o_min_b[0] + cyl->normal[0] * dist;
	x_min_b[1] = o_min_b[1] + cyl->normal[1] * dist;
	x_min_b[2] = o_min_b[2] + cyl->normal[2] * dist;
	t = dot(cyl->normal, x_min_b);
	return (0.0F <= t && t <= cyl->height);
}
