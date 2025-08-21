/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaborsk <itaborsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 13:47:44 by itaborsk          #+#    #+#             */
/*   Updated: 2025/08/05 20:06:47 by itaborsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	check(int n1, int n2, int n3);

void	ft_print_comb(void)
{
	char	mas[5];

	mas[0] = '0';
	mas[1] = '1';
	mas[2] = '2';
	mas[3] = ',';
	mas[4] = ' ';
	while (mas[0] != 55)
	{
		if (mas[2] > 57 && mas[1] <= 56)
		{
			mas[1] = mas[1] + 1;
			mas[2] = mas[1] + 1;
		}
		if (mas[1] == 57 && mas[0] < 57)
		{
			mas[0] = mas[0] + 1;
			mas[1] = mas[0] + 1;
			mas[2] = mas[1] + 1;
		}
		write(1, mas, check(mas[0], mas[1], mas[2]));
		mas[2] = mas[2] + 1;
	}
}

int	check(int n1, int n2, int n3)
{
	if (n1 + n2 + n3 == 168)
	{
		return (3);
	}
	else
	{
		return (5);
	}
}
