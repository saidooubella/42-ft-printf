/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number_print_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soubella <soubella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 18:57:02 by soubella          #+#    #+#             */
/*   Updated: 2022/10/10 19:45:35 by soubella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	put_u64(unsigned long long number, char *base, size_t base_size)
{
	size_t	length;

	length = 0;
	if (number >= base_size)
		length = put_u64(number / base_size, base, base_size);
	write(1, &base[number % base_size], 1);
	return (length + 1);
}

size_t	put_i32_prefix(char *prefix, unsigned int number, char *base)
{
	size_t		prefix_size;

	prefix_size = ft_strlen(prefix);
	write(1, prefix, prefix_size);
	return (prefix_size + put_u64(number, base, ft_strlen(base)));
}

size_t	put_i32(int number, int leading_space, int enforce_sign, char *base)
{
	if (number < 0)
		return (put_i32_prefix("-", -number, base));
	if (enforce_sign)
		return (put_i32_prefix("+", number, base));
	if (leading_space)
		return (put_i32_prefix(" ", number, base));
	return (put_i32_prefix("", number, base));
}

size_t	put_u32(char *prefix, unsigned int number, char *base)
{
	size_t		prefix_size;

	prefix_size = ft_strlen(prefix);
	write(1, prefix, prefix_size);
	return (prefix_size + put_u64(number, base, ft_strlen(base)));
}

size_t	put_address(void *pointer)
{
	write(1, "0x", 2);
	return (2 + put_u64((unsigned long long) pointer, BASE_16_LOWER, 16));
}
