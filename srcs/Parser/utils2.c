/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 19:06:15 by yuknakas          #+#    #+#             */
/*   Updated: 2026/07/09 11:04:38 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

bool	set_fov_d(unsigned char *fov, char *str);
bool	parse_brigtness(float *brightness, char *str);

/**
 * Sets the field of view for the camera struct
 * @param fov pointer to the fov_d in the camera struct
 * @param str char string to convert to fov
 * @return boolean-true (1) if error, 0 if no error
 * 
 * Error: FOV can only be within 1 ~ 179
 */
bool	set_fov_d(unsigned char *fov_d, char *str)
{
	int	val;

	val = rt_atoi(str);
	if (val < 1 || 179 < val)
	{
		ft_putstr_fd(ERR_FOV, 2);
		return (true);
	}
	*fov_d = (char)val;
	return (false);
}

/**
 * Sets the brightnesss of lights
 * @param brightness pointer to the brightness
 * @param str char string to convert to brightness
 * @return boolean-true (1) if error, 0 if no error
 * 
 * Error: FOV can only be within 0.0F ~ 1.0F
 */
bool	parse_brigtness(float *brightness, char *str)
{
	float	val;

	val = ft_atof(str);
	if (val < 0.0F || 1.0F < val)
	{
		ft_putstr_fd(ERR_BRIGHT, 2);
		return (true);
	}
	*brightness = val;
	return (false);
}
