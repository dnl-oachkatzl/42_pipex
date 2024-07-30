/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daspring <daspring@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 12:07:57 by daspring          #+#    #+#             */
/*   Updated: 2024/03/11 12:53:45 by daspring         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	char	*haystack;
	char	needle;
	int		pos;

	haystack = (char *)s;
	needle = (char) c;
	pos = 0;
	while (haystack[pos])
	{
		if (haystack[pos] == needle)
		{
			return (haystack + pos);
		}
		pos++;
	}
	if (needle == '\0')
	{
		return (haystack + pos);
	}
	return (0);
}
