/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_element2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 13:41:07 by nakashibay        #+#    #+#             */
/*   Updated: 2026/07/03 15:57:21 by yuknakas         ###   ########.fr       */
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
		ft_putstr_fd(ERR_INV_ELEM, 2);
		return (1);
	}
	if (!ft_strncmp(info[0], "sp", 2))
		return (_set_sphere(minirt, info));
	if (!ft_strncmp(info[0], "pl", 2))
		return (_set_plane(minirt, info));
	if (!ft_strncmp(info[0], "cy", 2))
		return (_set_cylinder(minirt, info));
	ft_putstr_fd(ERR_INV_ELEM, 2);
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
	
	if (arr_len(info) < 4)
	{
		ft_putstr_fd("Error: Insufficient arguments for Sphere\n", 2);
		return (1);
	}
	sphere = malloc(sizeof(t_sphere));
	if (!sphere)
	{
		ft_putstr_fd(ERR_MALLOC, 2);
		return (1);
	}
	if (ato3f(info[1], sphere->coords)
			|| parse_colors(info[3], sphere->rgb))
	{
		free(sphere);
		return (1);
	}
	sphere->diameter = ft_atof(info[2]);
	return (elem_append(&minirt->elements, elem_new(sphere, SPHERE)));
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
	
	if (arr_len(info) < 4)
	{
		ft_putstr_fd("Error: Insufficient arguments for Plane\n", 2);
		return (1);
	}
	plane = malloc(sizeof(t_plane));
	if (!plane)
	{
		ft_putstr_fd(ERR_MALLOC, 2);
		return (1);
	}
	if (ato3f(info[1], plane->coords)
			|| ato3f(info[2], plane->normal)
			|| parse_colors(info[3], plane->rgb)
			|| normalize(plane->normal, plane->normal))
	{
		free(plane);
		ft_putstr_fd(ERR_INV_NBR, 2);
		return (1);
	}
	return (elem_append(&minirt->elements, elem_new(plane, PLANE)));
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
	
	if (arr_len(info) < 6)
	{
		ft_putstr_fd("Error: Insufficient arguments for Cylinder\n", 2);
		return (1);
	}
	cyl = malloc(sizeof(t_cylinder));
	if (!cyl)
	{
		ft_putstr_fd(ERR_MALLOC, 2);
		return (1);
	}
	if (ato3f(info[1], cyl->coords) || ato3f(info[2], cyl->normal)
			|| parse_colors(info[5], cyl->rgb)
			|| normalize(cyl->normal, cyl->normal))
	{
		free(cyl);
		ft_putstr_fd(ERR_INV_NBR, 2);
		return (1);
	}
	cyl->diameter = ft_atof(info[3]);
	cyl->height = ft_atof(info[4]);
	return (elem_append(&minirt->elements, elem_new(cyl, CYL)));
}
