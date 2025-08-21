/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaborsk <itaborsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 15:15:52 by itaborsk          #+#    #+#             */
/*   Updated: 2025/08/05 20:06:28 by itaborsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_end(int n, int i)
{
	if ((n == 1 && i != 10) || (n == 9 && i != 10))
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
	if ((n == 2 && i != 45) || (n == 8 && i != 45))
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
	if ((n == 3 && i != 120) || (n == 7 && i != 120))
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
	if ((n == 4 && i != 210) || (n == 6 && i != 210))
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
	if (n == 5 && i != 252)
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	start(char a[], int n)
{
	int	i;
	int	b;
	int	c;

	i = 0;
	c = 0;
	b = n - 2;
	while (i <= 8)
	{
		a[i] = '0';
		i++;
	}
	while (b > -1)
	{
		a[b] = '1' + c;
		b--;
		c++;
	}
	a[0] = a[0] - 1;
}

void	print(char a[], int n)
{
	int	num;
	int	end;

	num = n;
	end = 0;
	while (a[n - 1] != '9' + 1 - n)
	{
		while (n > 0)
		{
			if (a[n - 2] == '9' + 2 - n)
			{
				a[n - 1]++;
				a[n - 2] = a[n - 1];
			}
			n--;
		}
		a[0]++;
		n = num;
		while (n > 0)
		{
			write(1, &a[--n], 1);
		}
		n = num;
		print_end(n, ++end);
	}
}

void	ft_print_combn(int n)
{
	char	a[9];

	start(a, n);
	if (n <= 0 || n >= 10)
	{
		return ;
	}
	print(a, n);
}
