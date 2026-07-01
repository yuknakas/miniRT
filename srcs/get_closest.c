/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_closest.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 20:34:32 by yuknakas          #+#    #+#             */
/*   Updated: 2026/07/01 11:53:04 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_element		*get_close_elem(t_minirt *minirt);
static float	_get_dist(t_minirt *minirt, t_element *gelement);
static void		_set_poi(t_minirt *minirt, float dist, float poi[3]);

/**
 * Finds the closest element that intersects with the ray and returns the
 *  general element structure for it while setting variables in pixel struct
 * @param minirt minirt struct holding all relarvant info
 */
t_element	*get_close_elem(t_minirt *minirt)
{
	t_pixel		*pixel;
	t_element	*gelement;
	t_element	*close_elem;
	float		dist_min;
	float		dist;

	pixel = &minirt->pixel;
	pixel->min = ray_to_pixel(minirt->camera, pixel->x, pixel->y, pixel->ray);
	dist_min = -1.0F;
	close_elem = NULL;
	gelement = minirt->elements;
	while (gelement)
	{
		dist = _get_dist(minirt, gelement);
		if (dist > 0.0F && (dist < dist_min || dist_min < 0.0F))
		{
			dist_min = dist;
			close_elem = gelement;
		}
		gelement = gelement->next;
	}
	_set_poi(minirt, dist_min, pixel->poi);
	return (close_elem);
}

/**
 * Calculates the shortest distance to an intersecting point of the ray
 *  and the element
 * @param minirt minirt struct holding relavant info
 * @param gelement general element struct to find intersection with
 * @return float distance to intersecting point. -1.0F if error or no
 *  intersection.
 */
static float	_get_dist(t_minirt *minirt, t_element *gelement)
{
	float	*origin;
	float	*ray;
	float	min;

	origin = minirt->camera->coords;
	ray = minirt->pixel.ray;
	min = minirt->pixel.min;
	if (gelement->type == SPHERE)
		return (ray_sphere(origin, ray, gelement->element, min));
	if (gelement->type == PLANE)
		return (ray_plane(origin, ray, gelement->element, min));
	if (gelement->type == CYL)
		return (ray_cylinder(origin, ray, gelement->element, min));
	return (-1.0F);
}

/**
 * Sets point of intersection from origin of ray (camera), ray, and dist
 * @param minirt minirt struct holding relavant information
 * @param dist distance of the ray. -1.0F if error
 * @param poi pointer to float[3] value that stores the
 *  point of intersection
 */
static void	_set_poi(t_minirt *minirt, float dist, float poi[3])
{
	int	i;

	if (dist < 0.0F)
		return ;
	i = 0;
	while (i < 3)
	{
		poi[i] = minirt->camera->coords[i] + minirt->pixel.ray[i] * dist;
		i++;
	}
}
