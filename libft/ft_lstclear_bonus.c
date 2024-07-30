/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daspring <daspring@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 16:12:52 by daspring          #+#    #+#             */
/*   Updated: 2024/03/21 19:08:24 by daspring         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*node;
	t_list	*temp_node;

	if (*lst == NULL)
		return ;
	node = *lst;
	*lst = NULL;
	while (node->next != NULL)
	{
		temp_node = node->next;
		ft_lstdelone(node, del);
		node = temp_node;
	}
	ft_lstdelone(node, del);
	node = NULL;
}
