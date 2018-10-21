/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidabdes <ussef.id@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 14:50:09 by yidabdes          #+#    #+#             */
/*   Updated: 2018/10/21 14:54:06 by yidabdes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	if (n >= 0 && n < 10)
		ft_putchar(n + '0');
	else if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putchar(n % 10 + '0');
	}
	else if (n > -10)
	{
		ft_putchar('-');
		ft_putchar(n * -1 + '0');
	}
	else
	{
		ft_putchar('-');
		ft_putnbr(-1 * (n / 10));
		ft_putchar(-1 * (n % 10) + '0');
	}
}
