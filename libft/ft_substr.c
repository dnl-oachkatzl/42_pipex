/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daspring <daspring@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 19:17:25 by daspring          #+#    #+#             */
/*   Updated: 2024/03/15 15:36:24 by daspring         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "libft.h"

static size_t	min(size_t a, size_t b);

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	str_len;
	size_t	pos;

	str_len = min(len, ft_strlen(s) - start);
	if (ft_strlen(s) == 0 || ft_strlen(s) < start)
	{
		str_len = 0;
	}
	str = malloc((str_len + 1) * sizeof(char));
	if (!str)
	{
		return (NULL);
	}
	pos = 0;
	while (pos < str_len)
	{
		str[pos] = s[start + pos];
		pos++;
	}
	str[pos] = '\0';
	return (str);
}

static size_t	min(size_t a, size_t b)
{
	if (a > b)
	{
		return (b);
	}
	else
	{
		return (a);
	}
}
