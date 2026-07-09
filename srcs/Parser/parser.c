/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 14:20:22 by yuknakas          #+#    #+#             */
/*   Updated: 2026/07/05 11:34:45 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

bool		parse_input(t_minirt *minirt, char *infile);
static void	_init_minirt(t_minirt *minirt);
static bool	_isfiletype(char *infile);
static bool	_readline_loop(t_minirt *minirt, int fd);
static bool	_is_invalid(t_minirt *minirt);

/**
 * Parses the input file and prepares the t_minirt struct for raytracing
 * @param minirt pointer to t_minirt struct used for raytrace
 * @param infile char pointer to name of infile
 * @return boolean-true (1) if fail, 0 if okay
 * 
 * In case of fail, frees allocated memeory as needed.
 */
bool	parse_input(t_minirt *minirt, char *infile)
{
	int		fd;
	bool	fail;

	if (!_isfiletype(infile))
		return (1);
	fd = open(infile, O_RDONLY);
	if (fd < 0)
	{
		print_errno("Error\nFailed to open infile: ");
		return (1);
	}
	_init_minirt(minirt);
	fail = _readline_loop(minirt, fd);
	if (!fail)
		fail = _is_invalid(minirt);
	if (close(fd) < 0)
	{
		clean_minirt(minirt);
		print_errno("Error\nFailed to close infile: ");
		return (1);
	}
	if (fail)
		clean_minirt(minirt);
	return (fail);
}

/**
 * Initialized t_minirt struct
 * @param minirt t_minirt struct to be initialized
 */
static void	_init_minirt(t_minirt *minirt)
{
	minirt->amb_light = NULL;
	minirt->camera = NULL;
	minirt->light = NULL;
	minirt->elements = NULL;
}

/**
 * Checks if infile is the correct .rt filetype
 * @param infile pointer to string that is the name of infile
 * @return boolean-true if infile is an .rt file, false if not
 */
static bool	_isfiletype(char *infile)
{
	int	len;

	if (infile == NULL)
	{
		ft_putstr_fd(ERR_NULL_IN, 2);
		return (false);
	}
	len = ft_strlen(infile);
	if (len >= 3 && !ft_strncmp(&infile[len - 3], ".rt", 3))
		return (true);
	ft_putstr_fd(ERR_FILETYPE, 2);
	return (false);
}

/**
 * Loops through file with descriptor fd and sets elements
 * @param minirt pointer to t_minirt struct
 * @param fd file descriptor of infile
 * @return boolean-1 on failure, 0 on success.
 */
static bool	_readline_loop(t_minirt *minirt, int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		if (set_element(minirt, line))
		{
			while (line)
			{
				free(line);
				line = get_next_line(fd);
			}
			return (1);
		}
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	return (0);
}

/**
 * Checks if the minirt has the three vital components: ambient light,
 *  camera, and light.
 * @param minirt pointer to t_minirt struct
 * @return boolean-true (1) if invalid, false if valid.
 */
static bool	_is_invalid(t_minirt *minirt)
{
	if (!minirt->amb_light || !minirt->camera || !minirt->light)
	{
		ft_putstr_fd("Error\nMissing required element (A/C/L)\n", 2);
		return (true);
	}
	if (minirt->amb_light->ratio < 0.0F)
		minirt->amb_light->ratio = 0.0F;
	if (minirt->amb_light->ratio > 1.0F)
		minirt->amb_light->ratio = 1.0F;
	if (minirt->light->brightness < 0.0F)
		minirt->light->brightness = 0.0F;
	if (minirt->light->brightness > 1.0F)
		minirt->light->brightness = 1.0F;
	return (false);
}
