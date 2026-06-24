/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakashibay <nakashibay@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 14:26:08 by nakashibay        #+#    #+#             */
/*   Updated: 2026/06/24 14:34:12 by nakashibay       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAESER_H
# define PARSER_H

# include "../minirt.h"
# include "../../libft/libft.h"
# include "../../gnl/get_next_line.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <limits.h>

// =================== ENUM NUM_TYPE ========================================
typedef enum s_num_type
{
    UCHAR,
    FLOAT
} t_num_type;

bool			set_element(t_minirt *minirt, char *line);
bool			set_spc(t_minirt *minirt, char **info);

float			ft_atof(char *str);
unsigned char	ft_atouc(char *str);
bool			ato3(char *str, void *target, t_num_type type);
void			free_char_dp(char **cdp);

t_element		*elem_new(void *in_element, t_elem_type type);
bool			elem_append(t_element *elem_list, t_element *new_element);
t_element		*elem_last_id(t_element *elem_list, int *id);

# define ERR_NULL_IN "Error: Infile cannot be NULL"
# define ERR_FILETYPE "Error: Wrong infile type. Must be .rt"
# define ERR_INV_ELEM "Error: Invalid element identifier found"
# define ERR_INV_NBR "Error: Invalid number, vectors cannot be zero-vectors \
and 3 number arrays must be separated with only commas."

#endif