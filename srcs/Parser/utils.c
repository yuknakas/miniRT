/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakashibay <nakashibay@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 15:06:27 by nakashibay        #+#    #+#             */
/*   Updated: 2026/06/23 17:02:35 by nakashibay       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

bool	ato3(char *str, void *target, t_num_type type)
{
	char	**arr;
	int		i;
	char	*c_target;
	float	*f_target;

	arr = ft_split(str, ',');
	if (arr == NULL || arr[0] == NULL)
	{
		free(arr);
		return (true);
	}
	c_target = target;
	f_target = target;
	i = 0;
	while (i < 3)
	[
		if (type == CHAR)
			c_target[i] = atoc(arr[i]);
		if (type == FLOAT)
			f_target[i] = atof(arr[i]);
		i++;
	]
	return (false);
}

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
