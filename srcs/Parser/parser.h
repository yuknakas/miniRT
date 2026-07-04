/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 14:26:08 by nakashibay        #+#    #+#             */
/*   Updated: 2026/07/04 19:16:37 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "../minirt_struct.h"
# include "../../libft/libft.h"
# include "../../libft/gnl/get_next_line.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <limits.h>
# include <stdlib.h>

// // =================== ENUM NUM_TYPE ========================================
// typedef enum s_num_type
// {
//     UCHAR,
//     FLOAT
// } t_num_type;

bool			parse_input(t_minirt *minirt, char *infile);

bool			set_element(t_minirt *minirt, char *line);
bool			set_spc(t_minirt *minirt, char **info);

float			ft_atof(char *str);
int				rt_atoi(char *str);
bool			set_fov_d(unsigned char *fov, char *str);
bool			parse_brigtness(float *brightness, char *str);
bool			ato3f(char *str, float target[3]);
bool			parse_colors(char *str, float rgb[3]);
void			free_char_dp(char **cdp);

t_element		*elem_new(void *in_element, t_elem_type type);
bool			elem_append(t_element **elem_list, t_element *new_element);
t_element		*elem_last_id(t_element *elem_list, int *id);
int				arr_len(char **arr);

void			clean_minirt(t_minirt *minirt);

# define ERR_NULL_IN "Error: Infile cannot be NULL"
# define ERR_FILETYPE "Error: Wrong infile type. Must be .rt"
# define ERR_INV_ELEM "Error: Invalid element identifier found"
# define ERR_INV_NBR "Error\n Invalid vector (0 vector or not CSV type)\n"

# define ERR_COLOR "Error\nRGB values must be an int between 0 ~ 255.\n"
# define ERR_3PTR "Error\nRGB/Vectors must be 3 values with commas between\n"
# define ERR_FOV "Error\nField of view must be between 1 ~ 179 degrees\n"
# define ERR_BRIGHT "Error\nBrightness must be within 0.0F~1.0F\n"

#endif