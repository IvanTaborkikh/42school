/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaborsk <itaborsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 11:31:17 by itaborsk          #+#    #+#             */
/*   Updated: 2025/08/05 12:44:09 by itaborsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);
void	checking(char a[]);
void	check_end(char a, char b, char c, char d);

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	check_end(char a, char b, char c, char d)
{
	if (a != '9' || b != '8' || c != '9' || d != '9')
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	checking(char a[])
{
	while (a[0] != '9' || a[1] != '8' || a[3] != '9' || a[4] != '9')
	{
		a[4]++;
		if (a[1] == '9' && a[3] == '9' && a[4] == '9' + 1)
		{
			a[0]++;
			a[1] = '0';
			a[3] = a[0];
			a[4] = a[1] + 1;
		}
		if (a[3] == '9' && a[4] == '9' + 1)
		{
			a[1]++;
			a[3] = a[0];
			a[4] = a[1] + 1;
		}
		if (a[4] == '9' + 1)
		{
			a[3]++;
			a[4] = '0';
		}
		write(1, a, 5);
		check_end(a[0], a[1], a[3], a[4]);
	}
}

void	ft_print_comb2(void)
{
	char	a[5];

	a[0] = '0';
	a[1] = '0';
	a[2] = ' ';
	a[3] = '0';
	a[4] = '0';
	checking(a);
}
