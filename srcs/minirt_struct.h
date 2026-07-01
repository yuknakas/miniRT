/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_struct.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 13:41:50 by yuknakas          #+#    #+#             */
/*   Updated: 2026/07/01 10:27:53 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_STRUCT_H
# define MINIRT_STRUCT_H

# include "Elements/elements.h"
# include "Display/display.h"

// ==================== PIXEL STRUCT ========================================
typedef struct s_pixel
{
	int			x;
	int			y;
	float		ray[3];
	float		min;
	float		poi[3];
	float		normal[3];
}	t_pixel;

// ==================== MINIRT STRUCT ========================================
typedef struct s_minirt
{
	t_display	display;
	t_pixel		pixel;
	t_amb_light	*amb_light;
	t_camera	*camera;
	t_light		*light;
	t_element	*elements;
}	t_minirt;


#endif