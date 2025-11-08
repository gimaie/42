/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimaie <gimaie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 14:26:44 by gimaie            #+#    #+#             */
/*   Updated: 2025/05/22 20:43:21 by gimaie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

int	deal_per(char fmt, va_list *ap)
{
	if (fmt == '\0')
		return (-1);
	if (fmt == 'c')
		return (print_char(va_arg(*ap, int)));
	else if (fmt == 's')
		return (print_str(va_arg(*ap, char *)));
	else if (fmt == 'p')
		return (print_ptr(va_arg(*ap, void *)));
	else if (fmt == 'd')
		return (print_dec(va_arg(*ap, int)));
	else if (fmt == 'i')
		return (print_dec(va_arg(*ap, int)));
	else if (fmt == 'u')
		return (print_ui(va_arg(*ap, unsigned int)));
	else if (fmt == 'x')
		return (print_hex(va_arg(*ap, unsigned int)));
	else if (fmt == 'X')
		return (print_bhex(va_arg(*ap, unsigned int)));
	else if (fmt == '%')
	{
		if (write (1, "%", 1) < 0)
			return (-1);
		return (1);
	}
	return ((print_char('%')) + (print_char((int)fmt)));
}

int	ft_printf(const char *fmt, ...)
{
	va_list		ap;
	int			n;
	const char	*start;

	n = 0;
	va_start(ap, fmt);
	if (fmt == NULL)
		return (-1);
	while (n >= 0 && *fmt)
	{
		start = fmt;
		if (*start != '%')
		{
			if (write(1, fmt++, 1) < 0)
				return (-1);
			n++;
		}
		else
		{
			fmt++;
			n = n + deal_per(*fmt++, &ap);
		}
	}
	va_end(ap);
	return (n);
}

// int	main(void)
// {
// 	int len1;
// 	int len2;

// 	len1 = ft_printf("ft:%%\n");
// 	len2 = printf("or:%%\n");

// 	ft_printf("%d\n", len1);
// 	ft_printf("%d\n", len2);
// }
