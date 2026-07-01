/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_display.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 09:42:35 by yuknakas          #+#    #+#             */
/*   Updated: 2026/07/01 09:47:01 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

void	destroy_display(t_display *display);

/**
 * Destroys and frees all memeory allocated in display.
 * @param display pointer to t_display struct
 * 
 * Warning: does not free display itself
 */
void	destroy_display(t_display *display)
{
	mlx_destroy_image(display->mlx, display->image);
	mlx_destroy_window(display->mlx, display->window);
	mlx_destroy_display(display->mlx);
	free(display->mlx);
}
