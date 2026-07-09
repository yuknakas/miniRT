/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 09:55:24 by yuknakas          #+#    #+#             */
/*   Updated: 2026/07/09 13:17:51 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTORS_H
# define VECTORS_H

# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <math.h>

# define EPSILON 1.0E-5F
# define ERR_MALLOC "Error: Memory allocation failed\n"

float	dot(float v1[3], float v2[3]);
void	cross(float v1[3], float v2[3], float target[3]);
bool	is_perpendicular(float v1[3], float v2[3]);
bool	normalize(float v[3], float target[3]);

float	v_len(float v[3]);
void	v_add(float v1[3], float v2[3], float v_target[3]);
void	v_subtract(float v1[3], float v2[3], float v_target[3]);

#endif