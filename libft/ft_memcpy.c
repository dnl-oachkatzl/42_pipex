/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daspring <daspring@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 14:30:08 by daspring          #+#    #+#             */
/*   Updated: 2024/03/21 19:09:18 by daspring         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*to;
	unsigned char	*from;
	unsigned int	pos;

	if (dst == 0 && src == 0)
	{
		return (dst);
	}
	to = (unsigned char *)dst;
	from = (unsigned char *)src;
	pos = 0;
	while (n > pos)
	{
		*(to + pos) = *(from + pos);
		pos++;
	}
	return (dst);
}
