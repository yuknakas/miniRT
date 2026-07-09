/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 19:06:15 by yuknakas          #+#    #+#             */
/*   Updated: 2026/07/05 11:50:17 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

bool	set_fov_d(unsigned char *fov, char *str);
bool	parse_brigtness(float *brightness, char *str);
bool	parse_dist(float *dist, char *str);
void	free_char_dp(char **cdp);
int		arr_len(char **arr);

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
		write(2, ERR_FOV, ft_strlen(ERR_FOV));
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

	if (ft_atopf(str, &val))
		return (true);
	if (val < 0.0F || 1.0F < val)
	{
		write(2, ERR_BRIGHT, ft_strlen(ERR_BRIGHT));
		return (true);
	}
	*brightness = val;
	return (false);
}

/**
 * Sets distance, with error handeling in case of a <= 0 length
 * @param dist pointer to float that holds the distance
 * @param str string to check from
 * @return boolean-true in case of error, false if all good
 */
bool	parse_dist(float *dist, char *str)
{
	if (ft_atopf(str, dist))
		return (true);
	if (*dist < EPSILON)
	{
		write(2, ERR_DIST, ft_strlen(ERR_DIST));
		return (true);
	}
	return (false);
}

/**
 * Frees a char double pointer
 * @param cdp char double pointer to free
 */
void	free_char_dp(char **cdp)
{
	int	i;

	if (!cdp)
		return ;
	i = 0;
	while (cdp[i])
	{
		free(cdp[i]);
		i++;
	}
	free(cdp);
}

/**
 * Returns the length of an char ** array
 * @param arr char ** array to find length of
 * @return int value of length of array
 */
int	arr_len(char **arr)
{
	int	len;

	if (!arr)
		return (0);
	len = 0;
	while (arr[len])
		len++;
	return (len);
}
