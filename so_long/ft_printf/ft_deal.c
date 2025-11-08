/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimaie <gimaie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 20:38:47 by gimaie            #+#    #+#             */
/*   Updated: 2025/05/22 17:28:53 by gimaie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

int	print_char(int c)
{
	char	cc;

	cc = (char)c;
	if ((write(1, &cc, 1)) < 0)
		return (-1);
	return (1);
}

int	print_str(char *s)
{
	const char	*p;
	size_t		len;

	if (s == NULL)
		return (write(1, "(null)", 6));
	p = s;
	while (*p)
		p++;
	len = p - s;
	if (write(1, s, len) < 0)
		return (-1);
	return ((int) len);
}

int	print_ptr(void *p)
{
	unsigned long	lp;
	int				wr;
	int				pr;

	if (p == NULL)
		return (write (1, "(nil)", 5));
	lp = (unsigned long)p;
	wr = write(1, "0x", 2);
	pr = print_bfptr(lp);
	if (wr < 0 || pr < 0)
		return (-1);
	return (wr + pr);
}

int	print_dec(int i)
{
	int		p;
	char	*s;

	s = ft_itoa(i);
	p = print_str(s);
	free(s);
	if (p < 0)
		return (-1);
	return (p);
}

int	print_ui(unsigned int ui)
{
	int		p;
	char	*s;

	s = ft_uitoa(ui);
	p = print_str(s);
	free(s);
	if (p < 0)
		return (-1);
	return (p);
}
