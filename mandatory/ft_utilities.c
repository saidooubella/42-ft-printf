/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilities.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soubella <soubella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 18:57:21 by soubella          #+#    #+#             */
/*   Updated: 2022/10/10 20:07:38 by soubella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(char *string)
{
	size_t	size;

	size = -1;
	while (string[++size])
		;
	return (size);
}

int	ft_isdigit(int ch)
{
	return ('0' <= ch && ch <= '9');
}

size_t	get_number_size(unsigned long long number, size_t base)
{
	size_t	size;

	if (number == 0)
		return (1);
	size = 0;
	while (number > 0)
	{
		number /= base;
		size += 1;
	}
	return (size);
}
