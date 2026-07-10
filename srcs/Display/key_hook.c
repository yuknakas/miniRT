/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 11:25:50 by yuknakas          #+#    #+#             */
/*   Updated: 2026/07/09 16:35:18 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"
#include <X11/keysym.h>

int			rt_key_hook(int keycode, void *arg);
static void	_change_size(int keycode, void *element, t_elem_type type);
static int	_change_height(int keycode, t_minirt *minirt);
static int	_select_unq_elem(int keycode, t_minirt *minirt);

/**
 * KeyPress hook, closes the window on ESC
 * @param keycode X11 keysym of the pressed key
 * @param minirt minirt struct to close on ESC
 */
int	rt_key_hook(int keycode, void *arg)
{
	t_minirt	*minirt;

	minirt = arg;
	if (keycode == XK_Escape)
		return (close_setup(minirt));
	if (keycode == XK_p || keycode == XK_o)
	{
		_change_size(keycode, minirt->display.element, minirt->display.type);
		color_image(minirt);
		return (0);
	}
	if (keycode == XK_l || keycode == XK_k)
		return (_change_height(keycode, minirt));
	if (keycode == XK_c || keycode == XK_v)
		return (_select_unq_elem(keycode, minirt));
	if (keycode == XK_w || keycode == XK_a
		|| keycode == XK_s || keycode == XK_d)
		return (key_move(keycode, minirt));
	return (0);
}

static void	_change_size(int keycode, void *element, t_elem_type type)
{
	t_sphere	*sphere;
	t_cylinder	*cyl;

	if (!element || type == PLANE)
		return ;
	if (type == SPHERE)
	{
		sphere = element;
		if (keycode == XK_p)
			sphere->diameter += 1.0F;
		else if (keycode == XK_o)
			sphere->diameter -= 1.0F;
		if (sphere->diameter < EPSILON)
			sphere->diameter = EPSILON;
	}
	if (type == CYL)
	{
		cyl = element;
		if (keycode == XK_p)
			cyl->diameter += 1.0F;
		else if (keycode == XK_o)
			cyl->diameter -= 1.0F;
		if (cyl->diameter < EPSILON)
			cyl->diameter = EPSILON;
	}
}

static int	_change_height(int keycode, t_minirt *minirt)
{
	t_cylinder	*cyl;

	cyl = minirt->display.element;
	if (!cyl || minirt->display.type != CYL)
		return (0);
	if (keycode == XK_l)
	{
		cyl->height += 1.0F;
	}
	else if (keycode == XK_k)
	{
		cyl->height -= 1.0F;
		if (cyl->height < EPSILON)
			cyl->height = EPSILON;
	}
	color_image(minirt);
	return (0);
}

static int	_select_unq_elem(int keycode, t_minirt *minirt)
{
	if (keycode == XK_c)
	{
		minirt->display.element = minirt->camera;
		minirt->display.type = CAM;
		return (0);
	}
	if (keycode == XK_v)
	{
		minirt->display.element = minirt->light;
		minirt->display.type = LIT;
		return (0);
	}
	return (0);
}
