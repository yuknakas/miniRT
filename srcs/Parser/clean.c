/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakashibay <nakashibay@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 15:10:21 by nakashibay        #+#    #+#             */
/*   Updated: 2026/06/24 15:17:38 by nakashibay       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void		clean_minirt(t_minirt *minirt);
static void	_clean_ptr(void *ptr);
static void	_clean_element(t_element *elements);

/**
 * Frees memory allocated for pointers in t_minirt
 * @param minirt pointer to t_minirt struct
 */
void		clean_minirt(t_minirt *minirt)
{
	_clean_ptr(minirt->amb_light);
	_clean_ptr(minirt->camera);
	_clean_ptr(minirt->light);
	_clean_element(minirt->elements);
}

/**
 * Checks if a pointer exists, then frees
 * @param ptr ptr to check and free
 * 
 * after freeing set ptr to NULL for this to work
 */
static void	_clean_ptr(void *ptr)
{
	if (!ptr)
		return ;
	free(ptr);
}

/**
 * Frees the general elements and the element allocated for the
 * 	pointer in the general element
 */
static void	_clean_element(t_element *elements)
{
	t_element	*next;

	if (!elements)
		return ;
	while (elements)
	{
		next = elements->next;
		free(elements->element);
		free(elements);
		elements = next;
	}
}
