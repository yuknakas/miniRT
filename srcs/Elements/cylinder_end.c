/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_end.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 11:51:58 by yuknakas          #+#    #+#             */
/*   Updated: 2026/06/29 07:49:48 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "elements.h"

float	cylinder_end(float origin[3], float ray[3], t_cylinder *cyl, float min);
// float	_ray_oncircle(float ori[3], float ray[3], t_cylinder *cyl, float min);
float	_ray_incircle(float ori[3], float ray[3], t_cylinder *cyl, float min);
bool	_is_incircle(float c_min_o[3], float ray[3], float dist, float diam);

/**
 * Finds the intersection of the ray and end of cylinder if there is one, 
 * returns the minimum distance.
 * @param origin pointer float[3] that represents the origin of ray
 * @param ray pointer to float[3] vector ray from camera to pixel
 * @param cyl pointer to t_cylinder struct that is tested intersection
 * @param min the length to screen, aka the minimum distance to appear
 * @return the distance from camera to intersecting point.
 * If not intersection set to -1.0F
 * 
 * End circle has radius <diameter>, center <coords ± normal * height / 2>
 *  and normal <normal>.
 * This circle will be treated like a plane, then checked if intersection is
 *  within the circle
 */
float	cylinder_end(float origin[3], float ray[3], t_cylinder *cyl, float min)
{
	if (is_parallel(ray, cyl->normal))
		return (-1.0F);
	return (_ray_incircle(origin, ray, cyl, min));
}

/**
 * Finds closest point on the end circle if the ray is on the circle
 * @param origin pointer float[3] that represents the origin of ray
 * @param ray pointer to float[3] vector ray from camera to pixel
 * @param cyl pointer to t_cylinder struct that is tested intersection
 * @param min the length to screen, aka the minimum distance to appear
 * @return float value of shortest distance.
 *  -1.0F if no intersection
 * 
 * Since the ray is on the circle, the circle can use the same algorithim
 *  to find intersection with a sphere, as we know that the ray only passes
 *  through the circle region of the sphere.
 */
// float	_ray_oncircle(float origin[3], float ray[3], t_cylinder *cyl, float min)
// {
// 	t_sphere	sphere[2];
// 	int			idx;
// 	int			xyz;

// 	idx = 0;
// 	while (idx < 2)
// 	{
// 		xyz = 0;
// 		while (xyz < 3)
// 		{
// 			sphere[idx].coords[xyz] = cyl->coords[xyz]
// 				+ cyl->normal[xyz] * cyl->height / 2;
// 			sphere[idx].rgb[xyz] = 0.0F;
// 			xyz++;
// 		}
// 		sphere[idx].diameter = cyl->diameter;
// 		if (is_overlapping(origin, ray, sphere[idx].coords, cyl->normal))
// 			return (-1.0F);
// 		idx++;
// 	}
// 	return (-1.0F);
// }

/**
 * Finds intersecting point of a ray passing through the two circle ends of a
 *  cylinder, not for when ray is on circle.
 * @param origin pointer float[3] that represents the origin of ray
 * @param ray pointer to float[3] vector ray from camera to pixel
 * @param cyl pointer to t_cylinder struct that is tested intersection
 * @param min the length to screen, aka the minimum distance to appear
 * @return float value of shortest distance.
 *  -1.0F if no intersection
 * 
 * For circle with center <c>, normal <n> and radius <r>,
 *  and a ray with origin <o>, and direction <d>:
 * 
 * Circle: (x - c) • n = 0 and (x - c)² < r²
 *  and Ray: x = o + ld
 * 
 * From here we get l = ((c - o) • n / d • n)
 */
float	_ray_incircle(float origin[3], float ray[3], t_cylinder *cyl, float min)
{
	float	center[2][3];
	int		idx;
	float	dist[2];
	float	c_min_o[3];

	idx = 0;
	while (idx < 3)
	{
		center[0][idx] = cyl->coords[idx] + cyl->normal[idx] * cyl->height / 2;
		center[1][idx] = cyl->coords[idx] - cyl->normal[idx] * cyl->height / 2;
		idx++;
	}
	idx = -1;
	while (++idx < 2)
	{
		v_subtract(center[idx], origin, c_min_o);
		dist[idx] = dot(c_min_o, cyl->normal) / dot(ray, cyl->normal);
		if (!_is_incircle(c_min_o, ray, dist[idx], cyl->diameter))
			dist[idx] = -1.0F;
	}
	if (dist[0] >= min && (dist[0] < dist[1] || dist[1] < min))
		return (dist[0]);
	if (dist[1] >= min)
		return (dist[1]);
	return (-1.0F);
}

/**
 * Checks if found intersection point is within the circle
 * @param c_min_o vector representing c minus o
 * @param ray the ray that is being traced
 * @param dist the distance calculated
 * @param diameter diameter of circle
 */
bool	_is_incircle(float c_min_o[3], float ray[3], float dist, float diameter)
{
	float	v_to_center[3];
	int		idx;

	idx = 0;
	while (idx < 3)
	{
		v_to_center[idx] = -c_min_o[idx] + dist * ray[idx];
		idx++;
	}
	return (dot(v_to_center, v_to_center) < (diameter / 2) * (diameter / 2));
}
