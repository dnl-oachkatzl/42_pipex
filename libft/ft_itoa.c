/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daspring <daspring@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 20:39:36 by daspring          #+#    #+#             */
/*   Updated: 2024/03/19 20:27:25 by daspring         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdlib.h>
#include "libft.h"

#include <stdio.h>

static char	*create_string(char *temp_num, int digit_counter, int is_negative);

/*	an integer has a maximum of 10 digits plus a possible signum */
char	*ft_itoa(int n)
{
	long	number;
	int		is_negative;
	int		digit_counter;
	char	temp_num[12];

	number = n;
	if (number == 0)
		return (create_string("0", 1, 0));
	is_negative = 0;
	if (number < 0)
	{
		number = -number;
		is_negative = 1;
	}
	digit_counter = 0;
	while (number > 0)
	{
		temp_num[digit_counter++] = (number % 10) + '0';
		number /= 10;
	}
	return (create_string(temp_num, digit_counter, is_negative));
}

static char	*create_string(char *temp_num, int digit_counter, int is_negative)
{
	char	*str;
	char	*start_address;

	str = ft_calloc(digit_counter + 1 + is_negative, sizeof(char));
	start_address = str;
	if (!str)
		return (NULL);
	if (is_negative)
	{
		*str = '-';
		str++;
	}
	while ((digit_counter - 1) >= 0)
	{
		*str = temp_num[digit_counter - 1];
		digit_counter--;
		str++;
	}
	return (start_address);
}
