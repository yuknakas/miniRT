/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 15:06:27 by nakashibay        #+#    #+#             */
/*   Updated: 2026/07/04 19:27:54 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

float			ft_atof(char *str);
int				rt_atoi(char *str);
void			free_char_dp(char **cdp);
int				arr_len(char **arr);

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
 * converts from string to int value with additional error
 *  handleing from atoi
 * @param str char string to be converted to a number
 * @return int value, -1 if error
 * 
 * Error Cases: negative (-1), multiple positives (++1),
 *  trailing letters (123a), large number (INT_MAX < )
 */
int	rt_atoi(char *str)
{
	int	result;

	result = 0;
	if (*str == '-')
		return (-1);
	if (*str == '+')
		str++;
	if (!ft_isdigit(*str))
		return (-1);
	while (ft_isdigit(*str))
	{
		if ((result > (INT_MAX - (*str - '0')) / 10))
				return (-1);
		result = result * 10 + (*str - '0');
		str++;
	}
	if (*str != '\0' && *str != '\n')
		return (-1);
	return (result);
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
