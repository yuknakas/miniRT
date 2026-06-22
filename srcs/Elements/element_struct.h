/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_struct.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 20:40:36 by yuknakas          #+#    #+#             */
/*   Updated: 2026/06/21 23:53:34 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ELEMENT_STRUCT_H
# define ELEMENT_STRUCT_H

# include <stdbool.h>

// ==================== Struct Ambient Lighting ===============================
typedef struct s_ambient_lighting
{
	float			ratio;
	unsigned char	rgb[3];
}	t_ambient_lighting;

// ==================== Struct Camera =========================================
/**
 * @brief Stores information about camera and screen (display in 3D world)
 */
typedef struct s_camera
{
	float			coords[3]; //> coordinates of the camera itself
	float			orientation[3]; //> orientation (view direction) of camera
	unsigned char	fov_d; //> degrees of field of view (as input)
	unsigned char	fov; // field of view in radients (converted)
	float			center[3]; // center of the screen
	float			width; // width of the screen
	float			height; // height of the screen
	float			v_hori[3]; // horizontal (right) component of the screen
	float			v_vert[3]; // vertical (down) component of the screen
}	t_camera;
/* standard distance is set to 16 */

// ==================== Struct Sphere =========================================
/**
 * @brief Stores information about a sphere
 */
typedef struct s_sphere
{
	float			coords[3]; //> coordinate of the center of sphere
	float			diameter; //> diameter of sphere
	unsigned char	rgb[3]; //> rgb value of sphere
}	t_sphere;

// ==================== Struct Plane ==========================================
typedef struct s_plane
{
	float			coords[3]; //> coordinates of a point on plane
	float			normal[3]; //> normal vector of the plane
	unsigned char	rgb[3]; //> rgb value of plane
}	t_plane;

// ==================== Struct Cylinder =======================================
typedef struct s_cylinder
{
	float			coords[3];
	float			normal[3];
	float			diameter;
	float			height;
	unsigned char	rgb[3];
}	t_cylinder;

#endif