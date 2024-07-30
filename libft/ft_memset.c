/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daspring <daspring@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 17:22:44 by daspring          #+#    #+#             */
/*   Updated: 2024/03/15 16:03:22 by daspring         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*u_char_string;

	u_char_string = (unsigned char *)b;
	while (len > 0)
	{
		*u_char_string = (unsigned char)c;
		u_char_string++;
		len--;
	}
	return (b);
}
