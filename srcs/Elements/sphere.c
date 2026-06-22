/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 22:34:48 by yuknakas          #+#    #+#             */
/*   Updated: 2026/06/22 15:25:04 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "elements.h"

float	ray_sphere(float origin[3], float ray[3], t_sphere *sphere, float min);
float	_det_sphere(float origin[3], float ray[3], t_sphere *sphere);

/**
 * Finds the intersection of the ray and sphere if there is one, 
 * returns the distance.
 * @param origin pointer float[3] that represents the origin of ray
 * @param ray pointer to float[3] vector ray from camera to pixel
 * @param sphere pointer to t_sphere struct that is tested intersection
 * @param min the length to screen, aka the minimum distance to appear
 * @return the distance from camera to intersecting point.
 * If not intersection set to -1.0F
 * 
 * For sphere: || x - c ||² = r² and ray: x = o + du
 * 
 * distance = -[u•(o - c)] ± sqrt(det)
 */
float	ray_sphere(float origin[3], float ray[3], t_sphere *sphere, float min)
{
	float	det;
	float	o_min_c[3];
	float	dist[2];

	det = _det_sphere(origin, ray, sphere);
	v_subtract(origin, sphere->coords, o_min_c);
	if (det < 0.0F)
		return (-1.0F);
	if (det < EPSILON)
		det = 0.0F;
	dist[0] = -dot(ray, o_min_c) - sqrtf(det);
	dist[1] = -dot(ray, o_min_c) + sqrtf(det);
	if (dist[0] >= min)
		return (dist[0]);
	if (dist[1] >= min)
		return (dist[1]);
	return (-1.0F);
}

/**
 * Finds the determinant of the quadratic equation used to find the intersection 
 * between the sphere and ray
 * @param origin pointer float[3] that represents the origin of ray
 * @param ray pointer to float[3] vector ray from camera to pixel
 * @param sphere pointer to t_sphere struct that is tested intersection
 * @return float value of determinant
 * 
 * For sphere: || x - c ||² = r² and ray: x = o + du
 * 
 * det = [u • (o - c)]² - ( || o - c ||² - r²)
 * 
 * where || o - c ||² = (o - c) • (o - c)
 */
float	_det_sphere(float origin[3], float ray[3], t_sphere *sphere)
{
	float	det;
	float	o_min_c[3];

	v_subtract(origin, sphere->coords, o_min_c);
	det = dot(ray, o_min_c) * dot(ray, o_min_c) - (dot(o_min_c, o_min_c)
			- (sphere->diameter / 2) * (sphere->diameter / 2));
	return (det);
}
