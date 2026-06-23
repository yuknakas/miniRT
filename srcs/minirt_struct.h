/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_struct.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakashibay <nakashibay@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 13:41:50 by yuknakas          #+#    #+#             */
/*   Updated: 2026/06/23 15:04:19 by nakashibay       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_STRUCT_H
# define MINIRT_STRUCT_H

# include "Elements/elements.h"
# include "Display/display.h"

typedef struct s_element t_element;

// ==================== MINIRT STRUCT ========================================
typedef struct s_minirt
{
	t_display	display;
	t_amb_light	*amb_light;
	t_camera	*camera;
	t_light		*light;
	t_element	*elements;
}	t_minirt;

// ==================== ENUM ELEMENT_TYPE ====================================
typedef enum
{
	SPHERE,
	PLANE,
	CYL
}   elem_type;

// ==================== ELEMENT STRUCT =======================================
typedef struct s_element
{
	void		*element;
	elem_type	type;
	t_element	*next;
}	t_element;


#endif