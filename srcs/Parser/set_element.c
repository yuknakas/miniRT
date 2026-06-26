/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_element.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakashibay <nakashibay@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 14:37:34 by nakashibay        #+#    #+#             */
/*   Updated: 2026/06/26 09:21:04 by nakashibay       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

bool		set_element(t_minirt *minirt, char *line);
static bool	_set_amb_light(t_minirt *minirt, char **info);
static bool	_set_camera(t_minirt *minirt, char **info);
static bool	_set_light(t_minirt *minirt, char **info);

/**
 * Sets the element struct
 * @param minirt pointer to t_minirt struct holding all info
 * @param line line to from a element from
 * @return boolean-true if line containes an error, false if line is ok
 */
bool	set_element(t_minirt *minirt, char *line)
{
	char		**info;
	bool		success;

	info = ft_split(line, " ");
	if (info == NULL || info[0] == NULL)
	{
		free(info);
		return (false);
	}
	if (ft_strlen(info[0]) == 1)
		success = _set_acl(minirt, info);
	else
		success = set_spc(minirt, info);
	_free_char_dp(info);
	return (success);
}

/**
 * Sets ambient light, camera, or light objects
 * @param minirt pointer to t_minirt struct
 * @param info char double pointer to info of obj to handle
 * @return 1-fail 2-success
 */
static bool	_set_acl(t_minirt *minirt, char **info)
{

	if (info[0][0] == 'A')
		return (_set_amb_light(minirt, info));
	if (info[0][0] == 'C')
	{
		if (minirt->camera)
		{
			perror("Error: Cannot have two or more Cameras");
			return (1);
		}
		return (_set_camera(minirt, info));
	}
	if (info[0][0] == 'L')
	{
		if (minirt->light)
		{
			perror("Error: Cannot have two or more Lights");
			return (1);
		}
		return (_set_light(minirt, info));
	}
	perror(ERR_INV_ELEM);
	return (1);
}

/**
 * Sets info of ambient light object
 * @param minirt pointer to t_minirt struct
 * @param info char double pointer to info to be processed
 * @return 1-error, 0-success
 * 
 * Ignores additional arguments, but throws error if insufficient argument
 */
static bool	_set_amb_light(t_minirt *minirt, char **info)
{
	if (minirt->amb_light)
	{
		perror("Error: Cannot have two or more Ambient Lights");
		return (1);
	}
	if (sizeof(info) / sizeof(char *) <= 3)
	{
		perror("Error: Insufficient arguments for Ambient Light");
		return (1);
	}
	minirt->amb_light = malloc(sizeof(t_amb_light));
	if (!minirt->amb_light)
	{
		perror(ERR_MALLOC);
		return (1);
	}
	minirt->amb_light->ratio = ft_atof(info[1]);
	if (ato3(info[2], minirt->amb_light->rgb, UCHAR))
	{
		free(minirt->amb_light);
		minirt->amb_light = NULL;
		return (1);
	}
	return (0);
}

/**
 * Sets info of camera object
 * @param minirt pointer to t_minirt struct
 * @param info char double pointer to info to be processed
 * @return 1-error, 0-success
 * 
 * Ignores additional arguments, but throws error if insufficient argument
 */
static bool	_set_camera(t_minirt *minirt, char **info)
{
	if (sizeof(info) / sizeof(char *) <= 4)
	{
		perror("Error: Insufficient arguments for Camera");
		return (1);
	}
	minirt->camera = malloc(sizeof(t_camera));
	if (!minirt->camera)
	{
		perror(ERR_MALLOC);
		return (1);
	}
	if (ato3(info[1], minirt->camera->coords, FLOAT)
			|| ato3(info[2], minirt->camera->orientation, FLOAT)
			|| normalize(minirt->camera->orientation,
					minirt->camera->orientation))
	{
		free(minirt->camera);
		minirt->camera = NULL;
		perror(ERR_INV_NBR);
		return (1);
	}
	minirt->camera->fov_d = ft_atouc(info[3]);
	setup_screen(minirt->camera);
	return (0);
}

/**
 * Sets info of light object
 * @param minirt pointer to t_minirt struct
 * @param info char double pointer to info to be processed
 * @return 1-error, 0-success
 * 
 * Ignores additional arguments, but throws error if insufficient argument
 */
static bool	_set_light(t_minirt *minirt, char **info)
{
	if (sizeof(info) / sizeof(char *) <= 3)
	{
		perror("Error: Insufficient arguments for Light");
		return (1);
	}
	if (sizeof(info) / sizeof(char *) == 4)
		if (ato3(info[3], minirt->light->rgb, FLOAT))
			return (1);
	minirt->light = malloc(sizeof(t_light));
	if (!minirt->light)
	{
		perror(ERR_MALLOC);
		return (1);
	}
	if (ato3(info[1], minirt->light->coords, FLOAT))
	{
		free(minirt->light);
		minirt->light = NULL;
		return (1);
	}
	minirt->light->brightness = ft_atof(info[2]);
	return (0);
}
