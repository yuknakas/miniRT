/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elem_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakashibay <nakashibay@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 11:35:36 by nakashibay        #+#    #+#             */
/*   Updated: 2026/06/24 13:53:34 by nakashibay       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_element	*elem_new(void *in_element, t_elem_type type);
bool		elem_append(t_element *elem_list, t_element *new_element);
t_element	*elem_last_id(t_element *elem_list, int *id);

/**
 * Makes a new general element and returns the pointer
 * @param in_element pointer to element to be stores
 * @param type type of element
 * @return pointer to new general element that needs to be freed later.
 *  NULL if error allocating memory 
 */
t_element	*elem_new(void *in_element, t_elem_type type)
{
	t_element	*new_elem;

	new_elem = malloc(sizeof(t_element));
	if (!new_elem)
	{
		perror(ERR_MALLOC);
		return (NULL);
	}
	new_elem->element = in_element;
	new_elem->id = -1;
	new_elem->next = NULL;
	return (new_elem);
}

/**
 * Appends a new general element struct to the end of a list of general
 *  elements.
 * @param elem_list pointer to first general element in list
 * @param new_element the new element to be added to the list
 * @return boolean-1 if error, 0 if ok
 */
bool	elem_append(t_element *elem_list, t_element *new_element)
{
	t_element	*last_elem;
	int			last_id;

	if (!new_element)
		return (1);
	last_elem = elem_last_id(elem_list, &last_id);
	new_element->id = last_id + 1;
	if (!last_elem)
	{
		elem_list = new_element;
		return (0);
	}
	last_elem->next = new_element;
	return (0);
}

/**
 * Fetches the pointer to the last general element in a list, and
 *  sets the id for the last element in list
 * @param elem_list pointer to the first element in the list
 * @param id pointer to and int that will hold the id of the last element
 */
t_element	*elem_last_id(t_element *elem_list, int *id)
{
	t_element	*element;
	*id = 0;

	if (elem_list == NULL)
		return (NULL);
	element = elem_list;
	while (element->next)
	{
		element = element->next;
		*id++;
	}
	return (element);
}