/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deal2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimaie <gimaie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 13:15:55 by gimaie            #+#    #+#             */
/*   Updated: 2025/05/22 17:26:47 by gimaie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hex(unsigned int ui)
{
	int		ret;
	char	*s;

	s = ft_itoa_hex(ui);
	ret = print_str(s);
	free(s);
	if (ret < 0)
		return (-1);
	return (ret);
}

int	print_bhex(unsigned int ui)
{
	int		ret;
	char	*s;

	s = ft_itoa_bhex(ui);
	ret = print_str(s);
	free(s);
	if (ret < 0)
		return (-1);
	return (ret);
}

int	print_bfptr(unsigned long l)
{
	int		ret;
	char	*s;

	s = ft_itoa_ptr(l);
	ret = print_str(s);
	free(s);
	if (ret < 0)
		return (-1);
	return (ret);
}
