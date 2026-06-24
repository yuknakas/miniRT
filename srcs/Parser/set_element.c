/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_element.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakashibay <nakashibay@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 14:37:34 by nakashibay        #+#    #+#             */
/*   Updated: 2026/06/23 16:57:39 by nakashibay       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

bool	set_element(t_minirt *minirt, char *line);

/**
 * Sets the element struct
 * @param minirt pointer to t_minirt struct holding all info
 * @param line line to from a element from
 * @return boolean-true if line is ok, false if line containes an error
 */
bool	set_element(t_minirt *minirt, char *line)
{
	char		**info;

	info = ft_split(line, " ");
	if (info == NULL || info[0] == NULL)
	{
		free(info);
		return (true);
	}
	if (ft_strlen(info[0]) == 1)
		_set_acl(minirt, info)
	_free_char_dp(info);
}

bool	_set_acl(t_minirt *minirt, char **info)
{
	if (info[0][0] == 'A')
	{
		minirt->amb_light = malloc(sizeof(t_amb_light));
		if (!minirt->amb_light)
		{
			perror(ERR_MALLOC);
			return (false);
		}
		
	}
}
