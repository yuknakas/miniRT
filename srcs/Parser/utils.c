/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakashibay <nakashibay@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 15:06:27 by nakashibay        #+#    #+#             */
/*   Updated: 2026/06/24 14:27:22 by nakashibay       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

bool			ato3(char *str, void *target, t_num_type type);
static bool		_is_valid_3p(char **arr);
float			ft_atof(char *str);
unsigned char	ft_atouc(char *str);
void			free_char_dp(char **cdp)

/**
 * Converts a string with three numerical values separated by commas to numbers
 *  and stores them in a pointer to 3 values
 * @param str pointer to string in form num1,num2,num3
 * @param target pointer to hold three numerical values
 * @param type type of number to extract: UCHAR or FLOAT
 * @return boolean-true (1) if error happens with memory allocation,
 *  false if good
 */
bool	ato3(char *str, void *target, t_num_type type)
{
	char	**arr;
	int		i;
	char	*c_target;
	float	*f_target;

	arr = ft_split(str, ',');
	if (!_is_valid_3p(arr))
		return (true);
	c_target = target;
	f_target = target;
	i = 0;
	while (i < 3)
	[
		if (type == UCHAR)
			c_target[i] = atoc(arr[i]);
		if (type == FLOAT)
			f_target[i] = ft_atof(arr[i]);
		i++;
	]
	free_char_dp(arr);
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
	if (sizeof(arr) / sizeof(char *) <= 3)
	{
		free_char_dp(arr);
		return (false);
	}
	return (true);
}

/**
 * Converts char string to float
 * @param str pointer to string
 * @return float value of string
 * 
 * str is considered until first non-numeric character or second '.'
 *  If error, returns 0.0F. Deals with all +- before number
 */
float	ft_atof(char *str)
{
	size_t	i;
	int		decimal;
	int		pos;
	float	nbr;

	i = 0;
	nbr = 0.0F;
	pos = 1;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			pos *= -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		nbr = nbr * 10 + (str[i] - '0');
		i++;
	}
	if (str[i] != '.')
		return (nbr * pos);
	decimal = 1;
	while (ft_isdigit(str[++i]))
		nbr += (str[i] - '0') / powf(10.0F, (float)decimal);
	return (nbr * pos);
}

/**
 * Converts char string to an unsigned int value
 * @param str pointer to string
 * @return unsigned char value of string
 * 
 * Handles string until non-numeric character. If error returns 0.
 *  Does not handle +- since format is unsigned char.
 */
unsigned char	ft_atouc(char *str)
{
	size_t			i;
	unsigned char	nbr;

	i = 0;
	nbr = 0;
	while (ft_isdigit(str[i]))
	{
		if ((UCHAR_MAX - (str[i] - '0')) / 10 < nbr)
			return (UCHAR_MAX);
		nbr += nbr * 10 + (str[i] - '0')
	}
	return (nbr);
}

/**
 * Frees a char double pointer
 * @param cdp char double pointer to free
 */
void	free_char_dp(char **cdp)
{
	int	i;

	i = 0;
	while (cpd[i])
	{
		free(cdp[i]);
		i++;
	}
	free(cdp);
}
