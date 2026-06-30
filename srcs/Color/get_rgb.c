/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rgb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 19:14:29 by yuknakas          #+#    #+#             */
/*   Updated: 2026/06/29 20:30:29 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

int		get_color(t_minirt *minirt, t_element *close_elem);
int		_rgb_to_color(float rgb[3]);
float	*_get_elem_rgb(t_element *gelement);

/**
 * Calculates the color to be shown in the pixel
 * @param minirt pointer to minirt struct containing all relavant info
 * @param close_elem pointer to element struct that appears on screen
 */
int	get_color(t_minirt *minirt, t_element *close_elem)
{
	float	brightness;
	float	*elem_rgb;
	float	true_rgb[3];

	if (close_elem == NULL)
		return (_rgb_to_color(minirt->amb_light->rgb));
	brightness = get_brightness(minirt, close_elem);
	if (brightness > 1.0F)
		brightness = 1.0F;
	elem_rgb = get_elem_rgb(close_elem);
	true_rgb[0] = elem_rgb[0] * brightness;
	true_rgb[1] = elem_rgb[1] * brightness;
	true_rgb[2] = elem_rgb[2] * brightness;
	return (_rgb_to_color(true_rgb));
}

/**
 * Converts rgb scale of float[3] (0.0F ~ 1.0F) to int value holding
 *  rgb value in form 0 ~ 255 as r | g | b
 * @param rgb pointer to float[3] value with rgb scale as 0.0F ~ 1.0F
 * @return int representing rgb in form 0 ~ 255
 */
int	_rgb_to_color(float rgb[3])
{
	int	color;
	int	i;
	
	color = 0;
	i = 0;
	while (i < 3)
	{
		color = color * UCHAR_MAX + (int)roundf(rgb[i] * 255);
		i++;
	}
	return (color);
}

/**
 * Returns the pointer to float[3] that represents the rgb value of the element
 * @param gelement pointer to general element struct
 * @return pointer to float[3] that holds rgb value
 */
float	*_get_elem_rgb(t_element *gelement)
{
	t_sphere	*sphere;
	t_plane		*plane;
	t_cylinder	*cyl;

	sphere = gelement->element;
	plane = gelement->element;
	cyl = gelement->element;
	if (gelement->type == SPHERE)
		return (sphere->rgb);
	if (gelement->type == PLANE)
		return (plane->rgb);
	if (gelement->type == CYL)
		return (cyl->rgb);
	return (NULL);
}
