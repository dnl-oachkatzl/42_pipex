/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daspring <daspring@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 19:16:03 by daspring          #+#    #+#             */
/*   Updated: 2024/03/13 10:29:01 by daspring         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

static int	is_needle_here(char *hay, size_t hay_pos, const char *needle);

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*hay;
	size_t	hay_pos;
	size_t	needle_len;
	size_t	hay_len;

	hay = (char *) haystack;
	hay_len = ft_strlen(hay);
	if (*needle == '\0')
	{
		return (hay);
	}
	hay_pos = 0;
	needle_len = ft_strlen(needle);
	while ((hay_pos + needle_len) <= hay_len && (hay_pos + needle_len) <= len)
	{
		if (is_needle_here(hay, hay_pos, needle))
		{
			return (hay + hay_pos);
		}
		hay_pos++;
	}
	return (NULL);
}

static int	is_needle_here(char *hay, size_t hay_pos, const char *needle)
{
	size_t	needle_pos;

	needle_pos = 0;
	while (needle[needle_pos] != '\0')
	{
		if (hay[hay_pos + needle_pos] != needle[needle_pos])
		{
			return (0);
		}
		needle_pos++;
	}
	return (1);
}
