/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_print_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soubella <soubella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 18:56:55 by soubella          #+#    #+#             */
/*   Updated: 2022/10/10 20:07:01 by soubella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	put_char(char character)
{
	write(1, &character, 1);
	return (1);
}

size_t	put_string(char *string)
{
	size_t		string_size;

	if (string == 0)
		string = "(null)";
	string_size = ft_strlen(string);
	write(1, string, string_size);
	return (string_size);
}
