/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daspring <daspring@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 17:54:59 by daspring          #+#    #+#             */
/*   Updated: 2024/03/10 13:03:24 by daspring         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

/* accordign to its man-page bzero returns void.
the implemented function does return the given pointer, though.*/
void	ft_bzero(void *s, size_t n)
{
	char	*char_s;

	char_s = (char *)s;
	while (n > 0)
	{
		*char_s = 0;
		char_s++;
		n--;
	}
}
