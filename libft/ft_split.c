/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daspring <daspring@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 13:19:04 by daspring          #+#    #+#             */
/*   Updated: 2024/03/24 13:40:48 by daspring         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

static char	**go_through_string(t_container *cont, char **return_array);
static char	*extract_substring(t_container *cont);
static char	**populate_array(char **return_array, char *substr);
static void	kill_old_array(char **array);

char	**ft_split(const char *s, char c)
{
	char		**return_array;
	t_container	cont;
	int			all_delim;

	cont.str = (char *)s;
	cont.delim = c;
	return_array = ft_calloc(1, sizeof(char *));
	if (!return_array)
		return (NULL);
	if (s[0] == '\0')
		return (return_array);
	all_delim = 1;
	while (*s)
		if (*s++ != c)
			all_delim = 0;
	if (all_delim)
		return (return_array);
	return_array = go_through_string(&cont, return_array);
	return (return_array);
}

static char	**go_through_string(t_container *cont, char **return_array)
{
	char		*substr;

	while (*(cont->str) != '\0')
	{
		substr = extract_substring(cont);
		if (substr == NULL)
		{
			kill_old_array(return_array);
			return (NULL);
		}
		if (substr[0] == '\0')
			break ;
		return_array = populate_array(return_array, substr);
		if (return_array == NULL)
			return (NULL);
	}
	return (return_array);
}

static char	*extract_substring(t_container *cont)
{
	const char	*start_address;
	size_t		counter;
	char		*substring;

	while (*(cont->str) == cont->delim && *(cont->str) != '\0')
		(cont->str)++;
	start_address = cont->str;
	counter = 0;
	while (*(cont->str) != cont->delim && *(cont->str) != '\0')
	{
		counter++;
		(cont->str)++;
	}
	while (*(cont->str) == cont->delim && *(cont->str) != '\0')
		(cont->str)++;
	substring = ft_substr(start_address, 0, counter);
	if (substring == NULL)
		return (NULL);
	return (substring);
}

static char	**populate_array(char **return_array, char *substr)
{
	size_t	array_size;
	size_t	pos;
	char	**new_array;

	array_size = 0;
	while (return_array[array_size++])
		;
	new_array = ft_calloc(array_size + 1, sizeof(char *));
	if (new_array == NULL)
	{
		kill_old_array(return_array);
		return (NULL);
	}
	if (array_size == 1)
	{
		new_array[0] = substr;
		free(return_array);
		return (new_array);
	}
	pos = 0;
	while (pos++ < array_size - 1)
		new_array[pos - 1] = return_array[pos - 1];
	new_array[--pos] = substr;
	free(return_array);
	return (new_array);
}

static void	kill_old_array(char **array)
{
	size_t	array_size;
	size_t	pos;

	pos = 0;
	array_size = 0;
	while (array[array_size++])
		;
	while (pos < array_size)
		free(array[pos++]);
	free(array);
}
