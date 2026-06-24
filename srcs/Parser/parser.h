/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakashibay <nakashibay@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 14:26:08 by nakashibay        #+#    #+#             */
/*   Updated: 2026/06/23 16:57:33 by nakashibay       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAESER_H
# define PARSER_H

# include "../minirt.h"
# include "../../libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <limits.h>

// =================== ENUM NUM_TYPE ========================================
typedef enum s_num_type
{
    CHAR,
    FLOAT
} t_num_type;

float	atofp(char *str);
char	atouc(char *str);
void	free_char_dp(char **cdp);

# define ERR_NULL_IN "Error: Infile cannot be NULL"
# define ERR_FILETYPE "Error: Wrong infile type. Must be .rt"

#endif