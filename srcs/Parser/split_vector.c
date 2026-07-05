/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_vector.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 12:14:48 by yuknakas          #+#    #+#             */
/*   Updated: 2026/07/05 12:21:26 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char		**split_vector(char const *str, char c);
static int	_countsegment(const char *str, char c);
static char	**_freeall(char **arr);

char	**split_vector(char const *str, char c)
{
	int		seglen;
	char	**arr;
	char	**start;

	arr = malloc((_countsegment(str, c) + 1) * sizeof(char *));
	if (arr == NULL)
		return (NULL);
	start = arr;
	while (*str != '\0')
	{
		seglen = 0;
		while (str[seglen] != c && str[seglen] != '\0')
			seglen++;
		*arr = ft_substr(str, 0, seglen);
		if (*arr == NULL)
			return (_freeall(start));
		str += seglen;
		arr++;
		if (*str == c)
			str++;
	}
	*arr = NULL;
	return (start);
}

static int	_countsegment(const char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 1;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			count++;
		i++;
	}
	return (count);
}

static char	**_freeall(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}
