/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utilities.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daspring <daspring@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 15:18:44 by daspring          #+#    #+#             */
/*   Updated: 2024/07/30 21:53:55 by daspring         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	power_of_ten(int pow)
{
	int	result;

	if (pow == 0)
		return (1);
	result = 1;
	while (pow-- > 0)
		result *= 10;
	return (result);
}

int	put_to_screen(char *digit, int *counter)
{
	(*counter)++;
	return (write(1, digit, 1));
}
