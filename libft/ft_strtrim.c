/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daspring <daspring@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 14:44:31 by daspring          #+#    #+#             */
/*   Updated: 2024/03/21 15:09:57 by daspring         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static size_t	trimm_leading_chars(const char *s1, const char *set);
static size_t	trimm_trailing_chars(const char *s1, const char *set);

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*str;
	size_t	first_index;
	size_t	last_index;

	first_index = trimm_leading_chars(s1, set);
	last_index = trimm_trailing_chars(s1, set);
	if (first_index > last_index)
		return ("");
	str = ft_substr(s1, first_index, last_index - first_index + 1);
	return (str);
}

static size_t	trimm_leading_chars(const char *s1, const char *set)
{
	size_t	pos;
	size_t	pos_set;
	int		found_in_set;

	pos = 0;
	while (s1[pos] != '\0')
	{
		pos_set = 0;
		found_in_set = 0;
		while (set[pos_set] != '\0')
		{
			if (set[pos_set] == s1[pos])
				found_in_set = 1;
			pos_set++;
		}
		if (found_in_set != 1)
		{
			return (pos);
			break ;
		}
		pos++;
	}
	return (0);
}

static size_t	trimm_trailing_chars(const char *s1, const char *set)
{
	size_t	s1_len;
	size_t	pos_set;
	int		found_in_set;
	size_t	last_index;

	s1_len = ft_strlen(s1) - 1;
	last_index = 0;
	while (s1_len + 1 >= 1)
	{
		pos_set = 0;
		found_in_set = 0;
		while (set[pos_set] != '\0')
		{
			if (set[pos_set] == s1[s1_len])
				found_in_set = 1;
			pos_set++;
		}
		if (found_in_set != 1)
		{
			return (s1_len);
			break ;
		}
		s1_len--;
	}
	return (s1_len);
}
