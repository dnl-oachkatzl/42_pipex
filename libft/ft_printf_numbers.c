/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_numbers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daspring <daspring@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:25:57 by daspring          #+#    #+#             */
/*   Updated: 2024/07/30 21:45:46 by daspring         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

#define MAX_INT_DIGITS 10
/*	
 *	int and uint (4byte) is max ten digits wide
 */

static int	process_number(long number, int *counter);
static int	check_signum(long *number, int *counter);

int	ft_putnbr(int n)
{
	long	number;
	int		counter;

	number = (long)n;
	counter = 0;
	if (check_signum(&number, &counter) == -1)
		return (-1);
	if (process_number(number, &counter) == -1)
		return (-1);
	return (counter);
}

int	ft_putuint(unsigned int n)
{
	long	number;
	int		counter;

	counter = 0;
	number = n;
	if (process_number(number, &counter) == -1)
		return (-1);
	return (counter);
}

static int	process_number(long number, int *counter)
{
	int		pos;
	int		has_leading_zero;
	char	digit;

	has_leading_zero = 1;
	pos = MAX_INT_DIGITS + 1;
	while (--pos > 0)
	{
		digit = (number / power_of_ten(pos - 1)) + '0';
		number = number % power_of_ten(pos - 1);
		if (digit == '0')
		{
			if (!has_leading_zero || (number == 0 && pos == 1))
				if (put_to_screen(&digit, counter) == -1)
					return (-1);
		}
		else
		{
			if (put_to_screen(&digit, counter) == -1)
				return (-1);
			has_leading_zero = 0;
		}
	}
	return (0);
}

static int	check_signum(long *number, int *counter)
{
	if (*number < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		(*counter)++;
		*number *= -1;
	}
	return (0);
}
