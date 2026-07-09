/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 14:31:38 by yuknakas          #+#    #+#             */
/*   Updated: 2026/07/09 12:23:19 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_H
# define DISPLAY_H

# include <stdio.h>
# include <stdbool.h>
# include <stdlib.h>
# include "../../minilibx-linux/mlx.h"
# include "../Elements/element_struct.h"
# include "../minirt_struct.h"
# include "display_struct.h"

# ifndef WIDTH
#  define WIDTH 1280
# endif

# ifndef HEIGHT
#  define HEIGHT 720
# endif

// =========================== Functions =====================================
bool		setup_display(t_display *display);
void		destroy_display(t_display *display);
t_element	*get_close_elem(t_minirt *minirt, t_pixel *pixel);
void		color_image(t_minirt *minirt);
int			close_setup(t_minirt *minirt);
int			rt_key_hook(int keycode, t_minirt *minirt);
int			key_move(int keycode, t_minirt *minirt);
int			rt_mouse_hook(int mouse_code, int x, int y, t_minirt *minirt);
int			rt_key_hook(int keycode, t_minirt *minirt);

// MOUSECODES
# define MOUSE_LEFT 1
# define MOUSE_MIDDLE 2
# define MOUSE_RIGHT 3
# define SCROLL_UP 4
# define SCROLL_DOWN 5

#endif