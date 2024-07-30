/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daspring <daspring@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 18:26:42 by daspring          #+#    #+#             */
/*   Updated: 2024/03/15 15:41:51 by daspring         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*haystack;
	unsigned char	needle;
	unsigned int	pos;

	haystack = (unsigned char *)s;
	needle = (unsigned char)c;
	pos = 0;
	while (pos < n)
	{
		if (haystack[pos] == needle)
		{
			return ((void *)(haystack + pos));
		}
		pos++;
	}
	return (NULL);
}
