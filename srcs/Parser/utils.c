/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakashibay <nakashibay@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 15:06:27 by nakashibay        #+#    #+#             */
/*   Updated: 2026/06/23 15:21:27 by nakashibay       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

float	atof(char *str)
{
	size_t	i;
	int		decimal;
	float	nbr;

	i = 0;
	nbr = 0.0F;
	while (ft_isdigit(str[i]))
	{
		nbr = nbr * 10 + (str[i] - '0');
		i++;
	}
	if (str[i] != '.')
		return (nbr);
	decimal = 1;
	while (ft_isdigit(str[i]))
	{
		nbr += (str[i] - '0') / powf(10.0F, (float)decimal);
	}
	return (nbr);
}

char	atouc(char *str)
{
	size_t			i;
	unsigned char	nbr;

	i = 0;
	nbr = 0;
	while (ft_isdigit(str[i]))
	{
		if ((CHAR_MAX - (str[i] - '0')) / 10 < nbr)
			return (UCHAR_MAX);
		nbr += nbr * 10 + str[i] - '0'
	}
	return (nbr);
}
