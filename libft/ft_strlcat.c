/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daspring <daspring@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:35:51 by daspring          #+#    #+#             */
/*   Updated: 2024/03/20 13:46:34 by daspring         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <string.h>
#include "libft.h"

#include <stdio.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dstsize <= dst_len)
		return (dstsize + src_len);
	if (dst_len + src_len + 1 <= dstsize)
	{
		ft_memmove(dst + dst_len, src, src_len + 1);
	}
	else
	{
		ft_memmove(dst + dst_len, src, (dstsize - dst_len - 1));
		dst[dstsize - 1] = '\0';
	}
	return (dst_len + src_len);
}
