/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 15:06:27 by nakashibay        #+#    #+#             */
/*   Updated: 2026/07/09 17:44:49 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <errno.h>
#include <string.h>

bool		ft_atopf(char *str, float *nbr);
static bool	_set_pos(int *pos, char *str, size_t *i, float *nbr);
int			rt_atoi(char *str);
static bool	_err_trail(void);
void		print_errno(char *msg);

/**
 * Converts char string to float
 * @param str pointer to string
 * @param nbr pointer to float to store float value
 * @return boolean-true if error, false if all good
 * 
 * str is considered until first non-numeric character or second '.'
 *  If error, returns 0.0F. Deals with all +- before number
 */
bool	ft_atopf(char *str, float *nbr)
{
	size_t	i;
	int		decimal;
	int		pos;

	if (_set_pos(&pos, str, &i, nbr))
		return (true);
	while (ft_isdigit(str[i]))
	{
		*nbr = *nbr * 10 + (str[i] - '0');
		i++;
	}
	if (str[i] != '.' && str[i] != '\0' && str[i] != '\n')
		return (_err_trail());
	if (str[i] != '.')
	{
		*nbr *= (float)pos;
		return (false);
	}
	decimal = 1;
	while (ft_isdigit(str[++i]))
		*nbr += (str[i] - '0') / powf(10.0F, (float)decimal);
	*nbr *= (float)pos;
	if (str[i] != '\0' && str[i] != '\n')
		return (_err_trail());
	return (false);
}

/**
 * handles +/- in front of a float number, and tests if there is
 *  any additional letters in front of number
 * @param pos pointer to int holding position (+- of the number)
 * @param str char string to handle
 * @param i float to size_t indexer for string
 * @param nbr float pointer to nbr, which to be initialized here
 * @return boolean-true if error, false if all is good.
 */
static bool	_set_pos(int *pos, char *str, size_t *i, float *nbr)
{
	char	*addr;

	*i = 0;
	*pos = 1;
	*nbr = 0.0F;
	addr = ft_strchr(str, '.');
	if (!addr)
		addr = ft_strlen(str) + str;
	if (addr - str > 18)
	{
		ft_putstr_fd(ERR_FLOAT_LEN, 2);
		return (true);
	}
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			*pos = -1;
		*i = 1;
	}
	if (!ft_isdigit(str[*i]))
	{
		ft_putstr_fd(ERR_NB_HEAD, 2);
		return (true);
	}
	return (false);
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
	if (*str == '-' && rt_atoi(str + 1) != 0)
		return (-1);
	if (*str == '+' || *str == '-')
		str++;
	if (!ft_isdigit(*str))
	{
		ft_putstr_fd(ERR_NB_HEAD, 2);
		return (-1);
	}
	while (ft_isdigit(*str))
	{
		if ((result > (INT_MAX - (*str - '0')) / 10))
				return (-1);
		result = result * 10 + (*str - '0');
		str++;
	}
	if (*str != '\0' && *str != '\n')
	{
		_err_trail();
		return (-1);
	}
	return (result);
}

/**
 * Pure helper, returns true while displaying error message
 */
static bool	_err_trail(void)
{
	ft_putstr_fd(ERR_NB_TRAIL, 2);
	return (true);
}

/**
 * Prints msg followed by strerror(errno) and a newline to stderr
 * @param msg message to print before the errno string
 */
void	print_errno(char *msg)
{
	ft_putstr_fd(msg, 2);
	ft_putstr_fd(strerror(errno), 2);
	ft_putstr_fd("\n", 2);
}
