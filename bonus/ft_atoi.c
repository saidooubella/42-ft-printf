/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soubella <soubella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 18:50:57 by soubella          #+#    #+#             */
/*   Updated: 2022/10/11 16:26:52 by soubella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_atoi(char **str_ptr)
{
	unsigned long	res;
	char			*str;
	int				sign;

	str = *str_ptr;
	sign = 1;
	res = 0;
	while (ft_isdigit(*str))
	{
		res *= 10;
		res += *str - '0';
		str++;
	}
	*str_ptr = str;
	return (res * sign);
}
