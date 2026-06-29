/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 21:18:08 by yuknakas          #+#    #+#             */
/*   Updated: 2026/06/29 07:36:08 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"

float	v_len(float v[3]);
void	v_add(float v1[3], float v2[3], float v_target[3]);
void	v_subtract(float v1[3], float v2[3], float v_target[3]);

/**
 * Finds the length of a vector
 * @param v vector which length is to be calculated for
 * @return length of vector
 */
float	v_len(float v[3])
{
	return (sqrtf(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]));
}

/**
 * Add v1 and v2. Sets v_target as result
 * @param v1 first vector to add
 * @param v2 second vector to add
 * @param v_target pointer to float[3] which stores the result.
 */
void	v_add(float v1[3], float v2[3], float v_target[3])
{
	int	idx;

	idx = 0;
	while (idx < 3)
	{
		v_target[idx] = v1[idx] + v2[idx];
		idx++;
	}
}

/**
 * Subtract v2 from v1, resulting in v2->v1. Sets v_target as result
 * @param v1 destination vector. subtracted from v1
 * @param v2 start vector. subtract with v2
 * @param v_target pointer to float[3] which stores the result.
 */
void	v_subtract(float v1[3], float v2[3], float v_target[3])
{
	int	idx;

	idx = 0;
	while (idx < 3)
	{
		v_target[idx] = v1[idx] - v2[idx];
		idx++;
	}
}
