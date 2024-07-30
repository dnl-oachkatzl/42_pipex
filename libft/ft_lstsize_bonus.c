/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daspring <daspring@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 12:54:20 by daspring          #+#    #+#             */
/*   Updated: 2024/03/20 16:09:17 by daspring         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*next_node;
	int		counter;

	next_node = lst;
	counter = 0;
	while (next_node != NULL)
	{
		counter++;
		next_node = next_node->next;
	}
	return (counter);
}
