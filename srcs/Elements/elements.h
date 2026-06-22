/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 13:44:19 by yuknakas          #+#    #+#             */
/*   Updated: 2026/06/22 14:10:42 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ELEMENTS_H
# define ELEMENTS_H

# include <math.h>
# include <stdbool.h>
# include "../Vectors/vectors.h"
# include "element_struct.h"

bool	setup_screen(t_camera *camera);
float	ray_to_pixel(t_camera *camera, int x, int y, float v_target[3]);

float	ray_sphere(float origin[3], float ray[3], t_sphere *sphere, float min);
float	ray_plane(float origin[3], float ray[3], t_plane *plane, float min);
float	ray_cylinder(float origin[3], float ray[3], t_cylinder *cyl, float min);
float	cylinder_end(float origin[3], float ray[3], t_cylinder *cyl, float min);

bool	is_parallel(float ray[3], float n[3]);
bool	is_overlapping(float origin[3], float ray[3], float a[3], float n[3]);

# ifndef FOCAL_DIST
#  define FOCAL_DIST 16.0F
# endif

# ifndef PI
#  define PI 3.1415
# endif

# ifndef WIDTH
#  define WIDTH 1280
# endif

# ifndef HEIGHT
#  define HEIGHT 720
# endif

#endif