/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimaie <gimaie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 15:48:46 by gimaie            #+#    #+#             */
/*   Updated: 2025/05/18 10:42:09 by gimaie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

int		ft_printf(const char *fmt, ...);
int		deal_per(char fmt, va_list *ap);
int		print_char(int c);
int		print_str(char *s);
int		print_ptr(void *p);
int		print_dec(int i);
int		print_ui(unsigned int ui);
int		print_hex(unsigned int ui);
int		print_bhex(unsigned int ui);
int		print_bfptr(unsigned long l);

size_t	count_digits(unsigned int n);
char	*ft_itoa(int n);
char	*ft_uitoa(unsigned int u);
size_t	count_16(unsigned int n);
char	*ft_itoa_hex(unsigned int u);
char	*ft_itoa_bhex(unsigned int u);
char	*ft_itoa_ptr(unsigned long l);
size_t	count_16_forptr(unsigned long l);

#endif/* FT_PRINTF_H */
