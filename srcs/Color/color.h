/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 07:04:17 by yuknakas          #+#    #+#             */
/*   Updated: 2026/06/29 16:02:50 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include "../Elements/elements.h"
# include "../minirt_struct.h"

void		get_normal(float target[3], t_pixel *pixel, t_element *gelement);

#endif