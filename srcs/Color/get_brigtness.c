/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_brigtness.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 16:00:41 by yuknakas          #+#    #+#             */
/*   Updated: 2026/07/09 14:29:38 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

float			get_brightness(t_minirt *minirt, t_element *gelement);
static float	_intensity_light(t_minirt *minirt, float poi_to_light[3]);
static bool		_intercepts(float poi[3], float ray[3], t_element *gelement);
static float	_get_frac(t_minirt *minirt, t_element *gelement, float ray[3]);

/**
 * Gets the brightness applied on the point of intersection by the
 *  ambient light and the light source
 * @param minirt minirt struct that holds all relavant information
 */
float	get_brightness(t_minirt *minirt, t_element *gelement)
{
	float	brightness;
	float	intensity;
	float	diffuse_frac;
	float	poi_to_light[3];

	brightness = minirt->amb_light->ratio;
	v_subtract(minirt->light->coords, minirt->pixel.poi, poi_to_light);
	intensity = _intensity_light(minirt, poi_to_light);
	diffuse_frac = _get_frac(minirt, gelement, poi_to_light);
	if (intensity < 0.0F || diffuse_frac < 0.0F)
		return (brightness);
	return (brightness + intensity * diffuse_frac);
}

/**
 * Finds the intensity from the light source that reaches the point
 *  of intersection
 * @param minirt minirt struct containing all relavant info
 * @return float value of distance to light, -1.0F if light is intercepted
 */
static float	_intensity_light(t_minirt *minirt, float poi_to_light[3])
{
	t_element	*gelement;
	float		dist;

	gelement = minirt->elements;
	while (gelement)
	{
		if (_intercepts(minirt->pixel.poi, poi_to_light, gelement))
			return (-1.0F);
		gelement = gelement->next;
	}
	dist = v_len(poi_to_light) / 100.0F;
	return (minirt->light->brightness / (1.0F + 4.0F * PI * dist * dist));
}

/**
 * Examines if an elements itercepts the light from the Light struct
 *  to the object that is showing on the pixel
 * @param poi point of intersection, this case acts as the origin of the ray
 * @param ray ray from point of intersection to the light source
 * @param gelement gerenal element struct used
 * @return boolean-true if element intecepts with the light, false if not.
 * 
 * temp is used to store the hit type for the cylinder object, which is
 *  used later on to calculate the normal. This is needed as ray_cylinder
 *  updates the hit_type, which may cause errors later.
 */
static bool	_intercepts(float poi[3], float ray[3], t_element *gelement)
{
	float		dist;
	t_cylinder	*cyl;
	t_hit_type	temp;
	float		unitv[3];

	dist = -1.0F;
	normalize(ray, unitv);
	if (gelement->type == SPHERE)
		dist = ray_sphere(poi, unitv, gelement->element, EPSILON);
	else if (gelement->type == PLANE)
		dist = ray_plane(poi, unitv, gelement->element, EPSILON);
	else if (gelement->type == CYL)
	{
		cyl = gelement->element;
		temp = cyl->hit_type;
		dist = ray_cylinder(poi, unitv, cyl, EPSILON);
		cyl->hit_type = temp;
	}
	if (0.0 < dist && dist < v_len(ray))
		return (true);
	return (false);
}

/**
 * Calculates the fraction of light that is diffused and directed towards the camera
 * @param minirt minirt struct
 * @param gelement general element struct that holds the information
 *  about the element which the point of intersection lies on
 * @return float value of the fraction directed to the camera
 * 
 * the ray (camera->poi) is the opposite of poi->camera so the
 *  return value is multiplied with -1
 */
static float	_get_frac(t_minirt *minirt, t_element *gelement, float ray[3])
{
	float	surface_normal[3];
	float	diffuse_frac;

	get_normal(surface_normal, &minirt->pixel, gelement);
	diffuse_frac = dot(surface_normal, ray)
			/ (v_len(surface_normal) * v_len(ray));
	return (diffuse_frac);
}
