/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 21:42:09 by sbartoul          #+#    #+#             */
/*   Updated: 2024/01/08 17:59:41 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int				ft_printf(const char *format, ...);
int				ft_format(char specifier, va_list ap);
int				print_char(int c);
int				print_str(char *str);
int				print_digit(long num);
int				print_hex(long num, int uppercase);
int				print_ptr(unsigned long long ptr);
int				ft_ptrlen(uintptr_t num);
void			ft_printptr(uintptr_t num);
int				print_udigit(unsigned int num);

#endif