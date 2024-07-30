/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daspring <daspring@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 16:39:29 by daspring          #+#    #+#             */
/*   Updated: 2024/07/30 21:45:23 by daspring         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

#include "libft.h"

static int	process_specifier(char specifier, va_list *arg_list, int *counter);

int	ft_printf(const char *format, ...)
{
	va_list	arg_list;
	int		counter;

	counter = 0;
	va_start(arg_list, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			if (process_specifier(*(++format), &arg_list, &counter) == -1)
				return (-1);
		}
		else
		{
			if (ft_putchar(*format) == -1)
				return (-1);
			counter++;
		}
		format++;
	}
	if (*format == '\0')
		return (counter);
	return (-1);
}

static int	process_specifier(char specifier, va_list *arg_list, int *counter)
{
	int	ret_value;

	if (specifier == '%')
		ret_value = ft_putchar('%');
	else if (specifier == 'c')
		ret_value = ft_putchar(va_arg(*arg_list, int));
	else if (specifier == 's')
		ret_value = ft_putstr(va_arg(*arg_list, char *));
	else if (specifier == 'p')
		ret_value = ft_putpointer(va_arg(*arg_list, unsigned long));
	else if (specifier == 'd' || specifier == 'i')
		ret_value = ft_putnbr(va_arg(*arg_list, int));
	else if (specifier == 'u')
		ret_value = ft_putuint(va_arg(*arg_list, unsigned int));
	else if (specifier == 'x')
		ret_value = ft_puthexa(va_arg(*arg_list, unsigned int));
	else if (specifier == 'X')
		ret_value = ft_puthexa_upper_case(va_arg(*arg_list, unsigned int));
	else
		return (0);
	if (ret_value == -1)
		return (-1);
	*counter += ret_value;
	return (0);
}
