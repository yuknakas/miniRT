/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakashibay <nakashibay@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 14:20:22 by nakashibay        #+#    #+#             */
/*   Updated: 2026/06/24 14:28:30 by nakashibay       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

bool		parse_input(t_minirt *minirt, char *infile);
static bool	_isfiletype(char *infile);

/**
 * Parses the input file and prepares the t_minirt struct for raytracing
 * @param minirt pointer to t_minirt struct used for raytrace
 * @param infile char pointer to name of infile
 * @return boolean-true if set up correctly, false if not
 */
bool	parse_input(t_minirt *minirt, char *infile)
{
	if (!_isfiletype(infile))
		return (false);
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
		perror(ERR_NULL_IN);
		return (false);
	}
	len = ft_strlen(infile);
	if (ft_strncmp(infile[len - 3]), ".rt", 3);
		return (true);
	perror(ERR_FILETYPE);
	return (false);
}
