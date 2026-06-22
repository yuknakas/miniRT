/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 09:55:22 by yuknakas          #+#    #+#             */
/*   Updated: 2026/06/21 21:22:15 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"

float	dot(float v1[3], float v2[3]);
void	cross(float v1[3], float v2[3], float target[3]);
bool	is_perpendicular(float v1[3], float v2[3]);
bool	normalize(float v[3], float target[3]);

/**
 * Calculate the dot product of two vectors
 * @param v1 first vector
 * @param v1 second vector
 * @return dot product of v1 and v2
 */
float	dot(float v1[3], float v2[3])
{
	return (v1[0] * v2[0] + v1[1] * v2[1] + v1[2] * v2[2]);
}

/**
 * Calculate the corss product of two vectors and store it in a float[3] pointer
 * @param v1 first vector
 * @param v2 second vactor
 * @param target pointer (float[3]) to store the cross product of v1 and v2
 */
void	cross(float v1[3], float v2[3], float target[3])
{
	target[0] = v1[1] * v2[2] - v1[2] * v2[1];
	target[1] = v1[2] * v2[0] - v1[0] * v2[2];
	target[2] = v1[0] * v2[1] - v1[1] * v2[0];
}

/**
 * Checks if two vectors are perpendicular to each other using dot product
 * @param v1 first vector
 * @param v2 second vector
 * @return boolean-true is perpendicular, false if not
 */
bool	is_perpendicular(float v1[3], float v2[3])
{
	if (fabsf(dot(v1, v2)) < EPSILON)
		return (true);
	return (false);
}

/**
 * Normalize a vector passed by pointer
 * @param v vector to be normalized
 * @param target pointer (float[3]) to store normalized vector. Can be the same as v
 * @return boolean-true if zero-vector (cannot be normalized), false if success
 */
bool	normalize(float v[3], float target[3])
{
	float	len;

	if (v[0] < EPSILON && v[1] < EPSILON && v[2] < EPSILON)
		return (true);
	len = v_len(v);
	target[0] /= len;
	target[1] /= len;
	target[2] /= len;
	return (false);
}
