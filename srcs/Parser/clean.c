/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 15:10:21 by yuknakas          #+#    #+#             */
/*   Updated: 2026/06/24 15:17:38 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void		clean_minirt(t_minirt *minirt);
static void	_clean_ptr(void **ptr);
static void	_clean_element(t_element **elements);

/**
 * Frees memory allocated for pointers in t_minirt
 * @param minirt pointer to t_minirt struct
 */
void	clean_minirt(t_minirt *minirt)
{
	_clean_ptr((void **)&minirt->amb_light);
	_clean_ptr((void **)&minirt->camera);
	_clean_ptr((void **)&minirt->light);
	_clean_element(&minirt->elements);
}

/**
 * Checks if a pointer exists, then frees and sets it to NULL
 * @param ptr address of the pointer to check, free and NULL
 */
static void	_clean_ptr(void **ptr)
{
	if (!*ptr)
		return ;
	free(*ptr);
	*ptr = NULL;
}

/**
 * Frees the general elements and the element allocated for the
 * 	pointer in the general element, then NULLs the list head
 */
static void	_clean_element(t_element **elements)
{
	t_element	*current;
	t_element	*next;

	if (!*elements)
		return ;
	current = *elements;
	while (current)
	{
		next = current->next;
		free(current->element);
		free(current);
		current = next;
	}
	*elements = NULL;
}
