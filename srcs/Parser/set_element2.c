/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_element2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakashibay <nakashibay@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 13:41:07 by nakashibay        #+#    #+#             */
/*   Updated: 2026/06/24 14:27:04 by nakashibay       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

bool		set_spc(t_minirt *minirt, char **info);
static bool	_set_sphere(t_minirt *minirt, char **info);
static bool	_set_plane(t_minirt *minirt, char **info);
static bool	_set_cylinder(t_minirt *minirt, char **info);

/**
 * Sets sphere, plane, and cylinder objects.
 * @param minirt pointer to t_minirt struct
 * @param info char double pointer to info of obj to handle
 * @return 1-fail 2-success
 */
bool	set_spc(t_minirt *minirt, char **info)
{
	if (ft_strlen(info[0]) != 2)
	{
		perror(ERR_INV_ELEM);
		return (1);
	}
	if (!ft_strncmp(info[0], "sp", 2))
		return (_set_sphere(minirt, info));
	if (!ft_strncmp(info[0], "pl", 2))
		return (_set_plane(minirt, info));
	if (!ft_strncmp(info[0], "cy", 2))
		return (_set_cylinder(minirt, info));
	perror(ERR_INV_ELEM);
	return (1);
}

/**
 * Sets info of sphere object and appends to t_minirt->elements
 * @param minirt pointer to t_minirt struct
 * @param info char double pointer to info to be processed
 * @return 1-error, 0-success
 * 
 * Ignores additional arguments, but throws error if insufficient argument
 */
static bool	_set_sphere(t_minirt *minirt, char **info)
{
	t_sphere	*sphere;
	
	if (sizeof(info) / sizeof(char *) <= 4)
	{
		perror("Error: Insufficient arguments for Sphere");
		return (1);
	}
	sphere = malloc(sizeof(t_sphere));
	if (!sphere)
	{
		perror(ERR_MALLOC);
		return (1);
	}
	if (ato3(info[1], sphere->coords, FLOAT)
			|| ato3(info[3], sphere->rgb, UCHAR))
	{
		free(sphere);
		return (1);
	}
	sphere->diameter = ft_atof(info[2]);
	return (elem_append(minirt->elements, elem_new(sphere, SPHERE)));
}

/**
 * Sets info of plane object and appends to t_minirt->elements
 * @param minirt pointer to t_minirt struct
 * @param info char double pointer to info to be processed
 * @return 1-error, 0-success
 * 
 * Ignores additional arguments, but throws error if insufficient argument
 */
static bool	_set_plane(t_minirt *minirt, char **info)
{
	t_plane	*plane;
	
	if (sizeof(info) / sizeof(char *) <= 4)
	{
		perror("Error: Insufficient arguments for Plane");
		return (1);
	}
	plane = malloc(sizeof(t_plane));
	if (!plane)
	{
		perror(ERR_MALLOC);
		return (1);
	}
	if (ato3(info[1], plane->coords, FLOAT)
			|| ato3(info[2], plane->normal, FLOAT)
			|| ato3(info[3], plane->rgb, UCHAR)
			|| normalize(plane->normal, plane->normal))
	{
		free(plane);
		perror(ERR_INV_NBR);
		return (1);
	}
	return (elem_append(minirt->elements, elem_new(plane, PLANE)));
}

/**
 * Sets info of cylinder object and appends to t_minirt->elements
 * @param minirt pointer to t_minirt struct
 * @param info char double pointer to info to be processed
 * @return 1-error, 0-success
 * 
 * Ignores additional arguments, but throws error if insufficient argument
 */
static bool	_set_cylinder(t_minirt *minirt, char **info)
{
	t_cylinder	*cyl;
	
	if (sizeof(info) / sizeof(char *) <= 6)
	{
		perror("Error: Insufficient arguments for Cylinder");
		return (1);
	}
	cyl = malloc(sizeof(t_cyl));
	if (!cyl)
	{
		perror(ERR_MALLOC);
		return (1);
	}
	if (ato3(info[1], cyl->coords, FLOAT)
			|| ato3(info[2], cyl->normal, FLOAT)
			|| ato3(info[5], cyl->rgb, UCHAR)
			|| normalize(cyl->normal, cyl->normal))
	{
		free(cyl);
		perror(ERR_INV_NBR);
		return (1);
	}
	cyl->diameter = ft_atof(info[3]);
	cyl->height = ft_atof(info[4]);
	return (elem_append(minirt->elements, elem_new(cyl, CYL)));
}
