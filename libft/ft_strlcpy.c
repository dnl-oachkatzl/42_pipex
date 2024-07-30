/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daspring <daspring@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 19:29:53 by daspring          #+#    #+#             */
/*   Updated: 2024/03/19 20:27:44 by daspring         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;
	size_t	srcsize;

	src_len = ft_strlen(src);
	srcsize = src_len + 1;
	if (dstsize == 0)
		return (src_len);
	if (srcsize < dstsize)
	{
		ft_memmove(dst, src, srcsize - 1);
		dst[srcsize - 1] = '\0';
	}
	else
	{
		ft_memmove(dst, src, dstsize - 1);
		dst[dstsize - 1] = '\0';
	}
	return (src_len);
}
