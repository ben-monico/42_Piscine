/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarreir <bcarreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 12:31:03 by bcarreir          #+#    #+#             */
/*   Updated: 2022/03/10 15:04:42 by bcarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int	ft_putint(int n, int cc)
{
	long	nb;

	nb = n;
	cc += ft_nbrlen(n, 10);
	if (nb < 0)
	{
		nb = -nb;
		ft_putchar('-', cc);
	}
	if (nb >= 10)
	{
		ft_putint(nb / 10, cc);
		ft_putchar("0123456789"[nb % 10], cc);
	}
	else
		ft_putchar("0123456789"[nb % 10], cc);
	return (cc);
}

/* int main(void)
{
	// ft_putint(4589, 2);
	printf("\n%d", ft_putint(4589, 2));
} */