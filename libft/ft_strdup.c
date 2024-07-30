/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daspring <daspring@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:17:19 by daspring          #+#    #+#             */
/*   Updated: 2024/03/13 16:57:54 by daspring         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s;
	size_t	len;
	size_t	pos;

	len = ft_strlen(s1);
	s = malloc((len + 1) * sizeof(char));
	if (!s)
	{
		return (NULL);
	}
	pos = 0;
	while (pos <= len)
	{
		s[pos] = s1[pos];
		pos++;
	}
	return (s);
}
