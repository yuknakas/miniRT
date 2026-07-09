/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 09:38:04 by yuknakas          #+#    #+#             */
/*   Updated: 2026/07/09 12:23:38 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static bool	_init_setup(t_minirt *minirt, char *infile);
int			close_setup(t_minirt *minirt);

int	main(int argc, char **argv)
{
	t_minirt	minirt;

	if (argc != 2)
	{
		ft_putstr_fd("Error\nInvalid input. Usage: ./minirt <infile.rt>\n", 2);
		return (1);
	}
	if (_init_setup(&minirt, argv[1]))
		return (1);
	color_image(&minirt);
	mlx_hook(minirt.display.window, 17, 0L, close_setup, &minirt);
	mlx_mouse_hook(minirt.display.window, rt_mouse_hook, &minirt);
	mlx_key_hook(minirt.display.window, rt_key_hook, &minirt);
	mlx_loop(minirt.display.mlx);
	return (0);
}

/**
 * Set up both display and input, in case of error with display due to minilibx,
 *  exits as undefined behavior. In case of input error, returns 1
 * @param minirt minirt struct
 * @param infile char arrary for infile name
 * @return 1 in case of fail, 0 in case of success
 */
static bool	_init_setup(t_minirt *minirt, char *infile)
{
	if (parse_input(minirt, infile))
		return (1);
	if (setup_display(&minirt->display))
	{
		ft_putstr_fd("Error\nError with minilibx. \
Undefined treatment, exiting.\n", 2);
		exit(1);
	}
	return (0);
}

/**
 * Closes setup by both destroying display and cleaning minirt
 *  allocated memory
 * @param minirt minirt struct to close
 */
int	close_setup(t_minirt *minirt)
{
	destroy_display(&minirt->display);
	clean_minirt(minirt);
	exit(0);
	return (0);
}

