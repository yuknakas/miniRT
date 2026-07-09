/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_normal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 07:05:30 by yuknakas          #+#    #+#             */
/*   Updated: 2026/07/09 14:45:29 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

void		get_normal(float target[3], t_pixel *pixel, t_element *gelement);
static void	_normal_sphere(float target[3], float poi[3], t_sphere *sphere);
static void	_normal_plane(float target[3], float ray[3], t_plane *plane);
static void	_normal_cylinder_side(float t[3], float poi[3], t_cylinder *cyl);
static void _normal_cylinder_end(float t[3], float ray[3], t_cylinder *cyl);

/**
 * Sets the normal vector of a surface into a target pointer of float[3]
 * @param target target pointer of float[3]
 * @param pixel pixel struct holding relavant information
 * @param gelement general element struct
 */
void	get_normal(float target[3], t_pixel *pixel, t_element *gelement)
{
	t_cylinder *cyl;

	if (gelement->type == SPHERE)
		_normal_sphere(target, pixel->poi, gelement->element);
	else if (gelement->type == PLANE)
		_normal_plane(target, pixel->ray, gelement->element);
	else if (gelement->type == CYL)
	{
		cyl = gelement->element;
		if (cyl->hit_type == SIDE)
			_normal_cylinder_side(target, pixel->poi, cyl);
		if (cyl->hit_type == END)
			_normal_cylinder_end(target, pixel->ray, cyl);
	}
	else
		return ;
	normalize(target, target);
}

/**
 * Sets the normal for a point on the surface of a sphere
 * @param target pointer to float[3] that will hold the nromal
 * @param poi point of intersection for the sphere and ray
 * @param sphere pointer to sphere struct
 * 
 * normal for a point on the surface of sphere can be calculated as
 *  P - O
 */
static void	_normal_sphere(float target[3], float poi[3], t_sphere *sphere)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		target[i] = poi[i] - sphere->coords[i];
		i++;
	}
}

/**
 * Sets the normal for a point on the surface of a sphere
 * @param target pointer to float[3] that will hold the nromal
 * @param ray ray that is being traced, used to determine side
 * @param plane pointer to t_plane sturuct
 * 
 * If dot product is positive, plane->normal would be facing to the other side
 *  of the camera
 */
static void	_normal_plane(float target[3], float ray[3], t_plane *plane)
{
	int	i;

	i = 0;
	if (dot(ray, plane->normal) > 0.0F)
	{
		while (i < 3)
		{
			target[i] = - plane->normal[i];
			i++;
		}
	}
	else
	{
		while (i < 3)
		{
			target[i] = plane->normal[i];
			i++;
		}
	}
}

/**
 * Sets the normal for a point of intersection on the side of cylinder
 * @param target pointer to float[3] that holds the normal
 * @param poi point of intersection
 * @param cyl pointer to cylinder struct
 * 
 * The normal for a point on the side can be found by P - C where C is the center
 *  of the cross-sectional circle of the cylidner
 */
static void	_normal_cylinder_side(float target[3], float poi[3], t_cylinder *cyl)
{
	float	poi_height;
	float	poi_min_base[3];
	float	poi_center[3];
	int		i;

	v_subtract(cyl->coords, poi, poi_min_base);
	poi_height = dot(cyl->normal, poi_min_base) / v_len(cyl->normal);
	i = 0;
	while (i < 3)
	{
		poi_center[i] = cyl->coords[i] + cyl->normal[i] * poi_height;
		i++;
	}
	i = 0;
	while (i < 3)
	{
		target[i] = poi[i] - poi_center[i];
		i++;
	}
}

/**
 * Sets the normal for a point of intersection lying on the end of a cylinder
 * @param target pointer to float[3] that will hold the normal
 * @param ray ray that is being traced, used to determine side
 * @param cyl pointer to cylinder struct
 * 
 * Same idea as _normal_plane, if the dot product of ray and normal is positive,
 *  then the normal is facing the other direction.
 */
static void _normal_cylinder_end(float target[3], float ray[3], t_cylinder *cyl)
{
	int	i;

	i = 0;
	if (dot(ray, cyl->normal) > 0.0F)
	{
		while (i < 3)
		{
			target[i] = - cyl->normal[i];
			i++;
		}
	}
	else
	{
		while (i < 3)
		{
			target[i] = cyl->normal[i];
			i++;
		}
	}
}