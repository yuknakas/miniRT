/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 22:34:48 by yuknakas          #+#    #+#             */
/*   Updated: 2026/06/21 23:48:20 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "elements.h"

float	ray_sphere(t_camera *camera, float ray[3], t_sphere *sphere, float min);
float	_det_sphere(t_camera *camera, float ray[3], t_sphere *sphere);

/**
 * Finds the intersection of the ray and sphere if there is one, 
 * returns the distance.
 * @param camera pointer to t_camera struct
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
float	ray_sphere(t_camera *camera, float ray[3], t_sphere *sphere, float min)
{
	float	det;
	float	o_min_c[3];
	float	dist[2];

	det = _det_sphere(camera, ray, sphere);
	v_subtract(camera->orientation, sphere->coords, o_min_c);
	if (fabsf(det) < EPSILON)
		return (-dot(ray, o_min_c));
	if (det < 0.0F)
		return (-1.0F);
	dist[0] = -dot(ray, o_min_c) + sqrtf(det);
	dist[1] = -dot(ray, o_min_c) - sqrtf(det);
	if (dist[0] < dist[1] && dist[0] >= min)
		return (dist[0]);
	return (dist[1]);
}

/**
 * Finds the determinant of the quadratic equation used to find the intersection 
 * between the sphere and ray
 * @param camera pointer to t_camera struct
 * @param ray pointer to float[3] vector ray from camera to pixel
 * @param sphere pointer to t_sphere struct that is tested intersection
 * @return float value of determinant
 * 
 * For sphere: || x - c ||² = r² and ray: x = o + du
 * 
 * det = [u•(o - c)]² - ( || o - c ||² - r²)
 * 
 * where || o - c ||² = (o - c) • (o - c)
 */
float	_det_sphere(t_camera *camera, float ray[3], t_sphere *sphere)
{
	float	det;
	float	o_min_c[3];

	v_subtract(camera->orientation, sphere->coords, o_min_c);
	det = powf(dot(ray, o_min_c), 2.0F)
		- (dot(o_min_c, o_min_c) - powf(sphere->diameter, 2.0F));
	return (det);
}
