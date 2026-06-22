/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_display.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 14:35:53 by yuknakas          #+#    #+#             */
/*   Updated: 2026/06/22 00:07:43 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

/**
 * Sets up mlx display
 * @param display pointer to t_display struct that 
 * will hold all relavant information
 */
bool	setup_display(t_display *display)
{
	display->mlx = mlx_init();
	display->window = mlx_new_window(display->mlx, HEIGHT, WIDTH, "miniRT");
	display->image = mlx_new_image(display->mlx, HEIGHT, WIDTH);
	display->ptr_to_image = mlx_get_data_addr(display->image,
			&display->bits_per_pixel,
			&display->size_line,
			&display->endian);
	if (!display->mlx || !display->window
		|| !display->image || !display->ptr_to_image)
	{
		perror("Error: Failed to setup window");
		return (true);
	}
	return (false);
}

