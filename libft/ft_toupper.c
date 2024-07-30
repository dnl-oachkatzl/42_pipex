/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daspring <daspring@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 18:23:12 by daspring          #+#    #+#             */
/*   Updated: 2024/03/09 19:31:00 by daspring         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static	int	ft_islower(int c);

int	ft_toupper(int c)
{
	if (ft_islower(c))
	{
		return (c + ('A' - 'a'));
	}
	return (c);
}

static	int	ft_islower(int c)
{
	return (c >= 'a' && c <= 'z');
}
