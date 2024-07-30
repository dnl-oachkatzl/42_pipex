/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daspring <daspring@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 19:14:50 by daspring          #+#    #+#             */
/*   Updated: 2024/03/09 19:31:25 by daspring         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static	int	ft_isupper(int c);

int	ft_tolower(int c)
{
	if (ft_isupper(c))
	{
		return (c - ('A' - 'a'));
	}
	return (c);
}

static	int	ft_isupper(int c)
{
	return (c >= 'A' && c <= 'Z');
}
