/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soubella <soubella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 18:57:15 by soubella          #+#    #+#             */
/*   Updated: 2022/10/10 18:58:54 by soubella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <sys/types.h>
# include <stdarg.h>
# include <unistd.h>

# define BASE_16_UPPER	"0123456789ABCDEF"
# define BASE_16_LOWER	"0123456789abcdef"
# define BASE_10		"0123456789"

typedef struct s_flags
{
	int	ox_prefix;
	int	space_prefix;
	int	sign_prefix;
	int	width;
}	t_flags;

size_t	put_i32(int number, int leading_space, int enforce_sign, char *base);
size_t	put_u64(unsigned long long number, char *base, size_t base_size);
size_t	put_i32_prefix(char *prefix, unsigned int number, char *base);
size_t	get_number_size(unsigned long long number, size_t base);
size_t	put_u32(char *prefix, unsigned int number, char *base);
size_t	put_string(char *string, int padding);
void	flags_zero_init(t_flags *flags);
size_t	put_address(void *pointer);
size_t	put_char(char character);
size_t	ft_strlen(char *string);
int		ft_atoi(char **str_ptr);
int		ft_isdigit(int ch);
int		ft_printf(const char *format, ...);

#endif
