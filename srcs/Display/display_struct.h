/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_struct.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 10:59:17 by yuknakas          #+#    #+#             */
/*   Updated: 2026/07/09 11:01:31 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_STRUCT_H
# define DISPLAY_STRUCT_H

# include "../Elements/elements.h"

// =========================== Struct Display ================================
typedef struct s_display
{
	void		*mlx;
	void		*window;
	void		*image;
	void		*ptr_to_image;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
	void		*element;
	t_elem_type	type;
}	t_display;

#endif
