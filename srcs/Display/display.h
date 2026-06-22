/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 14:31:38 by yuknakas          #+#    #+#             */
/*   Updated: 2026/06/21 20:55:09 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_H
# define DISPLAY_H

# include <stdio.h>
# include <stdbool.h>
# include "../../minilibx-linux/mlx.h"

// =========================== Struct Display ================================
typedef struct s_display
{
	void	*mlx;
	void	*window;
	void	*image;
	void	*ptr_to_image;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}	t_display;

# ifndef WIDTH
#  define WIDTH 1280
# endif

# ifndef HEIGHT
#  define HEIGHT 720
# endif

// =========================== Functions =====================================
bool	setup_display(t_display *display);

#endif