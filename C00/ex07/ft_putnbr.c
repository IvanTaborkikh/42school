/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaborsk <itaborsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 12:45:02 by itaborsk          #+#    #+#             */
/*   Updated: 2025/08/15 10:56:24 by itaborsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	checking(int nb, int *nbb)
{
	if (nb < 0)
	{
		ft_putchar('-');
		if (nb == -2147483648)
		{
			ft_putchar('2');
			ft_putchar('1');
			ft_putchar('4');
			ft_putchar('7');
			ft_putchar('4');
			ft_putchar('8');
			ft_putchar('3');
			ft_putchar('6');
			ft_putchar('4');
			ft_putchar('8');
		}
		*nbb = *nbb * -1;
	}
	if (nb == 0)
	{
		ft_putchar('0');
		return (0);
	}
	return (1);
}

void	ft_putnbr(int nb)
{	
	int	num;
	int	size;
	int	check;

	num = 1000000000;
	size = 0;
	check = checking(nb, &nb);
	while (nb != 0 && nb != -2147483648)
	{
		if (nb / num != 0)
		{
			break ;
		}
		size++;
		num = num / 10;
	}
	size = 10 - size;
	while (size != 0 && nb != -2147483648 && check)
	{
		ft_putchar((nb / num) + 48);
		nb = nb % num;
		num = num / 10;
		size--;
	}
}

int	main(void)
{
	ft_putnbr(5555);
}
