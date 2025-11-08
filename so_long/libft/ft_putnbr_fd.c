/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimaie <gimaie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 18:43:29 by gimaie            #+#    #+#             */
/*   Updated: 2025/05/08 19:29:43 by gimaie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	u;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		u = (unsigned int)(-n);
	}
	else
		u = (unsigned int)n;
	if (u >= 10)
		ft_putnbr_fd(u / 10, fd);
	ft_putchar_fd((u % 10) + '0', fd);
}

// int	main(void)
// {
// 	int	a = -1234567;
// 	ft_putnbr_fd(a, 1);
// }
