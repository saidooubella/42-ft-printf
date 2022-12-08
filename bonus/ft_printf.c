/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soubella <soubella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 18:57:09 by soubella          #+#    #+#             */
/*   Updated: 2022/11/12 14:43:03 by soubella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

#include "ft_printf.h"

t_flags	parse_flags(char **format_ptr)
{
	char	*format;
	t_flags	flags;

	flags_zero_init(&flags);
	format = *format_ptr;
	while (*format)
	{
		if (*format == '#')
			flags.ox_prefix = 1;
		else if (*format == ' ')
			flags.space_prefix = 1;
		else if (*format == '+')
			flags.sign_prefix = 1;
		else
		{
			if (ft_isdigit(*format))
				flags.width = ft_atoi(&format);
			break ;
		}
		format++;
	}
	*format_ptr = format;
	return (flags);
}

size_t	put_hex_arg(va_list args, t_flags *flags, char *prefix, char *base)
{
	unsigned int	temp;

	temp = va_arg(args, unsigned int);
	if (flags->ox_prefix && temp != 0)
		return (put_u32(prefix, temp, base));
	return (put_u32("", temp, base));
}

size_t	put_argument(char **format, va_list args)
{
	size_t			length;
	t_flags			flags;

	if (**format == 0)
		return (0);
	flags = parse_flags(format);
	if (**format == 'd' || **format == 'i')
		length = put_i32(va_arg(args, int), flags.space_prefix,
				flags.sign_prefix, BASE_10);
	else if (**format == 'c')
		length = put_char((char) va_arg(args, int));
	else if (**format == 's')
		length = put_string(va_arg(args, char *), flags.width);
	else if (**format == 'p')
		length = put_address(va_arg(args, void *));
	else if (**format == 'u')
		length = put_u32("", va_arg(args, unsigned int), BASE_10);
	else if (**format == 'x')
		length = put_hex_arg(args, &flags, "0x", BASE_16_LOWER);
	else if (**format == 'X')
		length = put_hex_arg(args, &flags, "0X", BASE_16_UPPER);
	else
		length = put_char(**format);
	*format += 1;
	return (length);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		size;

	va_start(args, format);
	size = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			size += put_argument((char **) &format, args);
		}
		else
		{
			put_char(*format++);
			size += 1;
		}
	}
	va_end(args);
	return (size);
}

int main()
{
	printf("% +d", 12);
}
