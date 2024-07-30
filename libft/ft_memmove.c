/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daspring <daspring@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 15:43:32 by daspring          #+#    #+#             */
/*   Updated: 2024/03/15 15:29:01 by daspring         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

static void	*ft_memcpy_reverse(void *dst, const void *src, size_t n);

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	if (dst > src)
	{
		return (ft_memcpy_reverse(dst, src, n));
	}
	else
	{
		return (ft_memcpy(dst, src, n));
	}
}

static void	*ft_memcpy_reverse(void *dst, const void *src, size_t n)
{
	unsigned char	*to;
	unsigned char	*from;
	size_t			steps;

	if (dst == 0 && src == 0)
	{
		return (dst);
	}
	to = (unsigned char *)dst;
	from = (unsigned char *)src;
	steps = 1;
	while (!(steps > n))
	{
		to[n - steps] = from[n - steps];
		steps++;
	}
	return (dst);
}
