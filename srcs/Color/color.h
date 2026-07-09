/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 07:04:17 by yuknakas          #+#    #+#             */
/*   Updated: 2026/07/09 17:11:41 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include "../Elements/elements.h"
# include "../minirt_struct.h"
# include <limits.h>

int		get_color(t_minirt *minirt, t_element *close_elem);
void	get_normal(float target[3], t_pixel *pixel, t_element *gelement, t_camera *camera);
float	get_brightness(t_minirt *minirt, t_element *gelement);
int		get_color(t_minirt *minirt, t_element *close_elem);

#endif
