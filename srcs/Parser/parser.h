/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 14:26:08 by yuknakas          #+#    #+#             */
/*   Updated: 2026/07/09 17:45:03 by yuknakas         ###   ########.fr       */
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

bool			ft_atopf(char *str, float *nbr);
int				rt_atoi(char *str);
bool			set_fov_d(unsigned char *fov, char *str);
bool			parse_dist(float *dist, char *str);
bool			parse_brigtness(float *brightness, char *str);
bool			ato3f(char *str, float target[3]);
bool			parse_colors(char *str, float rgb[3]);
char			**split_vector(char const *str, char c);
void			free_char_dp(char **cdp);

t_element		*elem_new(void *in_element, t_elem_type type);
bool			elem_append(t_element **elem_list, t_element *new_element);
t_element		*elem_last_id(t_element *elem_list, int *id);
int				arr_len(char **arr);
void			print_errno(char *msg);

void			clean_minirt(t_minirt *minirt);

# define ERR_NULL_IN "Error\nInfile cannot be NULL\n"
# define ERR_FILETYPE "Error\nWrong infile type. Must be .rt\n"
# define ERR_INV_ELEM "Error\nInvalid element identifier found\n"
# define ERR_INV_NBR "Error\nInvalid vector (0 vector or not CSV type)\n"

# define ERR_COLOR "Error\nRGB values must be an int between 0 ~ 255.\n"
# define ERR_3PTR "Error\nRGB/Vectors must be 3 values with commas between\n"
# define ERR_FOV "Error\nField of view must be between 1 ~ 179 degrees\n"
# define ERR_BRIGHT "Error\nBrightness must be within 0.0F~1.0F\n"
# define ERR_DIST "Error\nLength cannot be equal or less than 0\n"
# define ERR_NB_HEAD "Error\nCharacter ahead of argument expecting number\n"
# define ERR_NB_TRAIL "Error\nCharacter trailing of argument expecting number\n"

# define ERR_FLOAT_LEN "Error\nLength of Float is too long\n"

#endif