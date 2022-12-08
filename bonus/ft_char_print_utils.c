/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_print_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soubella <soubella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 18:56:55 by soubella          #+#    #+#             */
/*   Updated: 2022/10/11 16:30:14 by soubella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	put_char(char character)
{
	write(1, &character, 1);
	return (1);
}

size_t	put_string(char *string, int padding)
{
	size_t		string_size;
	size_t		index;

	if (string == 0)
		string = "(null)";
	string_size = ft_strlen(string);
	if (string_size < (size_t) padding)
	{
		padding = padding - string_size;
		index = -1;
		while (++index < (size_t) padding)
			write(1, " ", 1);
	}
	else
		padding = 0;
	write(1, string, string_size);
	return (string_size + padding);
}
