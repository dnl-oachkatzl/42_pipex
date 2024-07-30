/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexadecimals.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daspring <daspring@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 15:14:13 by daspring          #+#    #+#             */
/*   Updated: 2024/07/30 21:45:04 by daspring         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#define MAX_HEXA_DIGITS 8
#define MAX_POINTER_DIGITS 16

/*
 * MAX_POINTER_DIGITS = 16 enables a converted ulong of 64 bit length,
 *															i.e. 8 byte
 * MAX_HEXA_DIGITS = 8 enables a converted uint of 32 bit length, i.e. 4 byte
 */

static char	convert_to_hexa_digit(int num);
static char	convert_to_upper_hexa_digit(int num);

int	ft_puthexa(unsigned int n)
{
	int		counter;
	char	digits[MAX_HEXA_DIGITS];

	counter = 1;
	if (n == 0)
		return (write(1, "0", 1));
	while (MAX_HEXA_DIGITS - counter >= 0 && n > 0)
	{
		digits[MAX_HEXA_DIGITS - counter] = convert_to_hexa_digit(n % 16);
		counter++;
		n /= 16;
	}
	counter--;
	return (write(1, digits + (MAX_HEXA_DIGITS - counter), counter));
}

int	ft_puthexa_upper_case(unsigned int n)
{
	int		counter;
	char	digits[MAX_HEXA_DIGITS];

	counter = 1;
	if (n == 0)
		return (write(1, "0", 1));
	while (MAX_HEXA_DIGITS - counter >= 0 && n > 0)
	{
		digits[MAX_HEXA_DIGITS - counter] = convert_to_upper_hexa_digit(n % 16);
		counter++;
		n /= 16;
	}
	counter--;
	return (write(1, digits + (MAX_HEXA_DIGITS - counter), counter));
}

int	ft_putpointer(unsigned long n)
{
	int		counter;
	char	digits[MAX_POINTER_DIGITS];

	counter = 1;
	if (n == 0)
		return (write(1, "0x0", 3));
	while (MAX_POINTER_DIGITS - counter >= 0 && n > 0)
	{
		digits[MAX_POINTER_DIGITS - counter] = convert_to_hexa_digit(n % 16);
		counter++;
		n /= 16;
	}
	counter--;
	if (write(1, "0x", 2) == -1)
		return (-1);
	if (write(1, digits + (MAX_POINTER_DIGITS - counter), counter) == -1)
		return (-1);
	return (counter + 2);
}

static char	convert_to_hexa_digit(int num)
{
	if (num >= 0 && num <= 9)
		return (num + '0');
	else if (num == 10)
		return ('a');
	else if (num == 11)
		return ('b');
	else if (num == 12)
		return ('c');
	else if (num == 13)
		return ('d');
	else if (num == 14)
		return ('e');
	else if (num == 15)
		return ('f');
	else
		return (0);
}

static char	convert_to_upper_hexa_digit(int num)
{
	if (num >= 0 && num <= 9)
		return (num + '0');
	else if (num == 10)
		return ('A');
	else if (num == 11)
		return ('B');
	else if (num == 12)
		return ('C');
	else if (num == 13)
		return ('D');
	else if (num == 14)
		return ('E');
	else if (num == 15)
		return ('F');
	else
		return (0);
}
