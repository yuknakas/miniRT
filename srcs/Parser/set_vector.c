/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_vector.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 10:49:19 by yuknakas          #+#    #+#             */
/*   Updated: 2026/07/05 12:29:57 by yuknakas         ###   ########.fr       */
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

	arr = split_vector(str, ',');
	if (!_is_valid_3p(arr))
	{
		free_char_dp(arr);
		return (true);
	}
	i = 0;
	while (i < 3)
	{
		if (ft_atopf(arr[i], &target[i]))
		{
			free_char_dp(arr);
			return (true);
		}
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
	int				val;
	int				i;

	arr = split_vector(str, ',');
	if (!_is_valid_3p(arr))
	{
		free_char_dp(arr);
		return (true);
	}
	i = 0;
	while (i < 3)
	{
		val = rt_atoi(arr[i]);
		if (val < 0 || 255 < val)
		{
			write(2, ERR_COLOR, ft_strlen(ERR_COLOR));
			return (true);
		}
		rgb[i] = (float)val / 255.0F;
		i++;
	}
	free_char_dp(arr);
	return (false);
}

/**
 * Checks if an char double pointer array is valid for ectracting 3 nbr
 * @param arr array to char double pointer
 * @return boolean-true if valid, false if not
 *
 * Pure predicate: does not free arr. Freeing is the caller's job.
 */
static bool	_is_valid_3p(char **arr)
{
	int	i;
	
	if (arr == NULL)
	{
		write(2, ERR_MALLOC, ft_strlen(ERR_MALLOC));
		return (false);
	}
	if (arr_len(arr) != 3 || ft_strlen(arr[0])
			|| ft_strlen(arr[1]) || ft_strlen(arr[2]))
	{
		write(2, ERR_3PTR, ft_strlen(ERR_3PTR));
		return (false);
	}
	i = 0;
	return (true);
}
