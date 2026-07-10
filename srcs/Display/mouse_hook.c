/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 11:06:48 by yuknakas          #+#    #+#             */
/*   Updated: 2026/07/10 13:14:12 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

static void	_select_elem(int x, int y, t_minirt *minirt);
static void	_redirect_cam(int x, int y, t_minirt *minirt);
static void	_zoom_in(t_minirt *minirt);
static void	_zoom_out(t_minirt *minirt);

int	rt_mouse_hook(int mouse_code, int x, int y, void *arg)
{
	t_minirt	*minirt;

	minirt = arg;
	if (mouse_code == MOUSE_LEFT)
		_select_elem(x, y, minirt);
	else if (mouse_code == MOUSE_RIGHT)
		_redirect_cam(x, y, minirt);
	else if (mouse_code == SCROLL_UP)
		_zoom_in(minirt);
	else if (mouse_code == SCROLL_DOWN)
		_zoom_out(minirt);
	return (0);
}

static void	_select_elem(int x, int y, t_minirt *minirt)
{
	t_element	*close_elem;

	minirt->pixel.x = y;
	minirt->pixel.y = x;
	close_elem = get_close_elem(minirt);
	if (!close_elem)
	{
		ft_putstr_fd("Not Detected\n", 2);
		minirt->display.element = NULL;
		minirt->display.type = NO_TYPE;
		return ;
	}
	ft_putstr_fd("Detected\n", 2);
	minirt->display.element = close_elem->element;
	minirt->display.type = close_elem->type;
	return ;
}

static void	_redirect_cam(int x, int y, t_minirt *minirt)
{
	ray_to_pixel(minirt->camera, y, x, minirt->camera->orientation);
	normalize(minirt->camera->orientation, minirt->camera->orientation);
	color_image(minirt);
}

static void	_zoom_out(t_minirt *minirt)
{
	minirt->camera->fov_d += 5;
	if (179 < minirt->camera->fov_d)
		minirt->camera->fov_d = 179;
	color_image(minirt);
}

static void	_zoom_in(t_minirt *minirt)
{
	if (minirt->camera->fov_d < 5)
		minirt->camera->fov_d = 1;
	else
		minirt->camera->fov_d -= 5;
	color_image(minirt);
}
