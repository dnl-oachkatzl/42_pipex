/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daspring <daspring@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 10:12:28 by daspring          #+#    #+#             */
/*   Updated: 2024/03/18 10:32:01 by daspring         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

static void	check_leading_chars(const char *str, size_t *pos, int *signum);

/* 2**63 = 9223372036854775807, which is the largest long long*/
int	ft_atoi(const char *str)
{
	unsigned long long	number;
	size_t				pos;
	int					signum;
	int					counter;

	number = 0;
	pos = 0;
	signum = 1;
	counter = 0;
	check_leading_chars(str, &pos, &signum);
	while (str[pos] >= '0' && str[pos] <= '9')
	{
		number = (number * 10) + (str[pos] - '0');
		counter++;
		pos++;
		if (counter > 19 || number > 9223372036854775807)
		{
			return (-1);
		}
	}
	return ((int)(signum * number));
}

static void	check_leading_chars(const char *str, size_t *pos, int *signum)
{
	while (str[*pos] == ' ' || str[*pos] == '\t' || str[*pos] == '\n'\
	|| str[*pos] == '\v' || str[*pos] == '\f' || str[*pos] == '\r')
		(*pos)++;
	if (str[*pos] == '+' || str[*pos] == '-')
	{
		if (str[*pos] == '-')
		{
			*signum = -1;
		}
		(*pos)++;
	}
	while (str[*pos] == '0')
		(*pos)++;
}
