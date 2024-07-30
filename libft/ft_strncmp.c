/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daspring <daspring@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 12:57:50 by daspring          #+#    #+#             */
/*   Updated: 2024/03/15 15:48:37 by daspring         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	pos;
	int		chars_are_different;

	pos = 0;
	while (pos < n && s1[pos] && s2[pos])
	{
		chars_are_different = (unsigned char)s1[pos] - (unsigned char)s2[pos];
		if (chars_are_different)
		{
			return (chars_are_different);
		}
		pos++;
	}
	if ((s1[pos] == '\0' || s2[pos] == '\0') && pos < n)
	{
		chars_are_different = (unsigned char)s1[pos] - (unsigned char)s2[pos];
		return (chars_are_different);
	}
	return (0);
}
