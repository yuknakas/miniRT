/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 14:26:06 by yuknakas          #+#    #+#             */
/*   Updated: 2026/07/01 10:16:02 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdio.h>
# include <stdlib.h>
# include "../minilibx-linux/mlx.h"
# include "Display/display.h"
# include "Elements/elements.h"
# include "Color/color.h"
# include "Parser/parser.h"
# include "minirt_struct.h"

void		color_image(t_minirt *minirt);
t_element	*get_close_elem(t_minirt *minirt);

#endif