/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 09:38:04 by yuknakas          #+#    #+#             */
/*   Updated: 2026/07/01 12:36:38 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static bool	_init_setup(t_minirt *minirt, char *infile);
static void	_close_setup(t_minirt *minirt);

int	main(int argc, char **argv)
{
	t_minirt	minirt;

	if (argc != 2)
	{
		perror("Error\nInvalid input. Usage: ./minirt <infile.rt>");
		return (1);
	}
	if (_init_setup(&minirt, argv[1]))
		return (1);
	color_image(&minirt);
	_close_setup(&minirt);
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
	if (setup_display(&minirt->display))
	{
		perror("Error\nError with minilibx. Undefined treatment, exiting.");
		exit(1);
	}
	return (parse_input(minirt, infile));
}

/**
 * Closes setup by both destroying display and cleaning minirt
 *  allocated memory
 * @param minirt minirt struct to close
 */
static void	_close_setup(t_minirt *minirt)
{
	destroy_display(&minirt->display);
	clean_minirt(minirt);
}
