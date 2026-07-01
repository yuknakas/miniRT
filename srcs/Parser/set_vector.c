/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_vector.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 10:49:19 by yuknakas          #+#    #+#             */
/*   Updated: 2026/07/01 10:33:27 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

bool			ato3f(char *str, float target[3]);
bool			parse_colors(char *str, float rgb[3]);
static bool		_is_valid_3p(char **arr);

/**
 * Converts a string with three numerical values separated by commas to numbers
 *  and stores them in a pointer to 3 values
 * @param str pointer to string in form num1,num2,num3
 * @param target pointer to hold three float values
 * @return boolean-true (1) if error happens with memory allocation,
 *  false if good
 */
bool	ato3f(char *str, float target[3])
{
	char	**arr;
	int		i;

	arr = ft_split(str, ',');
	if (!_is_valid_3p(arr))
		return (true);
	i = 0;
	while (i < 3)
	{
		target[i] = ft_atof(arr[i]);
		i++;
	}
	free_char_dp(arr);
	return (false);
}

/**
 * Converts a string with three numerical values separated by commas to
 *  rgb values that are represented by a float ranging from 0.0 ~ 1.0
 * @param str pointer to string in form num1,num2,num3
 * @param target pointer to hold three float values in rgb format
 * @return boolean-true (1) if error happens with memory allocation,
 *  false if good
 */
bool	parse_colors(char *str, float rgb[3])
{
	char			**arr;
	unsigned char	val;
	int				i;

	arr = ft_split(str, ',');
	if (!_is_valid_3p(arr))
		return (true);
	i = 0;
	while (i < 3)
	{
		val = ft_atouc(arr[i]);
		rgb[i] = (float)val / 255.0F;
	}
	return (false);
}

/**
 * Checks if an char double pointer array is valid for ectracting 3 nbr
 * @param arr array to char double pointer
 * @return boolean-true if valid, false if not
 * 
 * This also handles frees
 */
static bool	_is_valid_3p(char **arr)
{
	if (arr == NULL)
	{
		free(arr);
		return (false);
	}
	if (arr_len(arr) < 3)
	{
		free_char_dp(arr);
		return (false);
	}
	return (true);
}
