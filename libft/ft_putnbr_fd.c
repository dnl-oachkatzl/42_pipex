/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daspring <daspring@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:25:57 by daspring          #+#    #+#             */
/*   Updated: 2024/03/13 21:31:42 by daspring         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static long	check_signum(int n, int fd);
static int	power_of_ten(int pow);

// int is max ten digits wide
void	ft_putnbr_fd(int n, int fd)
{
	long	number;
	int		pos;
	int		has_leading_zero;
	char	digit[1];

	number = check_signum(n, fd);
	has_leading_zero = 1;
	pos = 10 + 1;
	while (--pos > 0)
	{
		digit[0] = (number / power_of_ten(pos - 1)) + '0';
		number = number % power_of_ten(pos - 1);
		if (digit[0] == '0')
		{
			if (!has_leading_zero || (number == 0 && pos == 1))
				write(fd, digit, 1);
		}
		else
		{
			has_leading_zero = 0;
			write(fd, digit, 1);
		}
	}
}

static long	check_signum(int n, int fd)
{
	long	number;

	number = (long)n;
	if (number < 0)
	{
		write(fd, "-", 1);
		number *= -1;
	}
	return (number);
}

static int	power_of_ten(int pow)
{
	int	result;

	if (pow == 0)
	{
		return (1);
	}
	result = 1;
	while (pow > 0)
	{
		result *= 10;
		pow--;
	}
	return (result);
}
