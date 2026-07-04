/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_screen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 10:55:46 by yuknakas          #+#    #+#             */
/*   Updated: 2026/07/02 12:53:40 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "elements.h"

void		setup_screen(t_camera *camera);
static void	_find_vectors(t_camera *camera);
static void	_set_hori(t_camera *camera);
static void	_set_vert(t_camera *camera);
static void	_edge_vert_orientation(t_camera *camera);

/**
 * Sets up the screen (what will be shown in the window), stored within t_camera
 * @param camera pointer to t_camera struct, which holds all information relavant
 */
void	setup_screen(t_camera *camera)
{
	camera->center[0] = camera->coords[0] + FOCAL_DIST * camera->orientation[0];
	camera->center[1] = camera->coords[1] + FOCAL_DIST * camera->orientation[1];
	camera->center[2] = camera->coords[2] + FOCAL_DIST * camera->orientation[2];
	if (camera->fov_d < 1)
	{
		perror("Error\nField of view cannot be less than 1: Setting FOV as 1");
		camera->fov_d = 1;
	}
	if (camera->fov_d > 179)
	{
		perror("Error\nField of view cannot be greater than 179: \
					Setting FOV to 179");
		camera->fov_d = 179;
	}
	camera->fov = (float)camera->fov_d / 180.0F * PI;
	camera->width = 2.0F * FOCAL_DIST * tanf(camera->fov / 2.0F);
	camera->height = camera->width / ((float)WIDTH / (float)HEIGHT);
	_find_vectors(camera);
}

/**
 * Sets v_hori and v_vert, the component vectors for the screen
 * @param camera pointer to camera struct, also stores v_hori and v_vert
 * 
 * If orientation is up/down (ori[2] == 0.0F) then treat specially.
 * Otherwise the cross product of orientation and [0, 1, 0] will give
 * the horizontal component of the screen, to the right (positive)
 */
static void	_find_vectors(t_camera *camera)
{
	if (1.0F - fabsf(camera->orientation[1]) < EPSILON)
		return (_edge_vert_orientation(camera));
	_set_hori(camera);
	_set_vert(camera);
}

/**
 * Sets v_hori when screen has a vetical component
 * @param camera pointer to camera struct, storing v_hori that will be modified
 * 
 * The horizontal vector of the screen is found by the cross product of orientation
 * and [0,1,0], the vertical vector.
 * Then, the vector is normalized for utility.
 */
static void	_set_hori(t_camera *camera)
{
	float	v2[3]; // temporal vertical unit vector [0,1,0]

	v2[0] = 0.0F;
	v2[1] = 1.0F;
	v2[2] = 0.0F;
	cross(camera->orientation, v2, camera->v_hori);
	normalize(camera->v_hori, camera->v_hori);
}

/**
 * Sets v_vert when screen has a vertical component
 * @param camera pointer to camera struct, storing v_vert that will be modified
 * 
 * The vertical vector is found by the cross product of v_hori and orientation.
 * Then, normalization is applied to the vector.
 * Finally, the vector is corrected to point to the downward direction to maintain
 * the screen upright.
 */
static void	_set_vert(t_camera *camera)
{
	cross(camera->orientation, camera->v_hori, camera->v_vert);
	normalize(camera->v_vert, camera->v_vert);
	if (camera->v_vert[1] > 0.0F)
	{
		camera->v_vert[0] *= -1;
		camera->v_vert[1] *= -1;
		camera->v_vert[2] *= -1;
	}
}

/**
 * Treats edge case when orientation is vertical
 * @param camera pointer to camera that holds v_hori and v_vert
 * 
 * When the orientation is vertical, there is no vertical component of the screen,
 * the cross between orientation and [0,1,0] does not work, hence must be treated
 * as an edge case.
 * If screen is facing up, x+ will be v_hori and z- will be v_vert.
 * If screen is facing down, x- will be v_hori and z+ will be v_vert.
 */
static void	_edge_vert_orientation(t_camera *camera)
{
	camera->v_hori[1] = 0.0F;
	camera->v_hori[2] = 0.0F;
	camera->v_vert[0] = 0.0F;
	camera->v_vert[1] = 0.0F;
	if (camera->orientation[1] > 0)
	{
		camera->v_hori[0] = 1.0F;
		camera->v_vert[2] = -1.0F;
	}
	else
	{
		camera->v_hori[0] = -1.0F;
		camera->v_vert[2] = 1.0F;
	}
	return ;
}
