/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 12:01:29 by yuknakas          #+#    #+#             */
/*   Updated: 2026/07/09 12:24:55 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"
#include <X11/keysym.h>

int	key_move(int keycode, t_minirt *minirt);
int	_move_sph_pl_cyl(int keycode, t_minirt *minirt);
int	_move(int keycode, t_camera *camera, float target[3]);

int	key_move(int keycode, t_minirt *minirt)
{
	t_camera	*camera;
	t_light		*light;

	if (minirt->display.type == CAM)
	{
		camera = minirt->display.element;
		_move(keycode, minirt->camera, camera->coords);
	}
	else if (minirt->display.type == LIT)
	{
		light = minirt->display.element;
		_move(keycode, minirt->camera, light->coords);
	}
	return (_move_sph_pl_cyl(keycode, minirt));
}

int	_move_sph_pl_cyl(int keycode, t_minirt *minirt)
{
	t_sphere	*sphere;
	t_plane		*plane;
	t_cylinder	*cyl;

	if (minirt->display.type == SPHERE)
	{
		sphere = minirt->display.element;
		_move(keycode, minirt->camera, sphere->coords);
	}
	if (minirt->display.type == PLANE)
	{
		plane = minirt->display.element;
		_move(keycode, minirt->camera, plane->coords);
	}
	if (minirt->display.type == CYL)
	{
		cyl = minirt->display.element;
		_move(keycode, minirt->camera, cyl->coords);
	}
	color_image(minirt);
	return (0);
}

int	_move(int keycode, t_camera *camera, float target[3])
{
	if (keycode == XK_w)
		v_subtract(target, camera->v_vert, target);
	if (keycode == XK_s)
		v_add(target, camera->v_vert, target);
	if (keycode == XK_a)
		v_subtract(target, camera->v_hori, target);
	if (keycode == XK_d)
		v_add(target, camera->v_hori, target);
	return (0);
}
