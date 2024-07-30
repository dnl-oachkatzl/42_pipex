/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daspring <daspring@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 13:12:23 by daspring          #+#    #+#             */
/*   Updated: 2024/03/08 16:55:15 by daspring         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_isupper(int s);
static int	ft_islower(int s);

int	ft_isalpha(int s)
{
	if (ft_isupper(s) || ft_islower(s))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

static int	ft_isupper(int s)
{
	if (s >= 'A' && s <= 'Z')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

static int	ft_islower(int s)
{
	if (s >= 'a' && s <= 'z')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
