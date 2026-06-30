/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 15:06:27 by nakashibay        #+#    #+#             */
/*   Updated: 2026/06/29 20:14:08 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

float			ft_atof(char *str);
unsigned char	ft_atouc(char *str);
void			free_char_dp(char **cdp);

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
		if ((255 - (str[i] - '0')) / 10 < nbr)
			return (255);
		nbr += nbr * 10 + (str[i] - '0');
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
	while (cdp[i])
	{
		free(cdp[i]);
		i++;
	}
	free(cdp);
}
