/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaborsk <itaborsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 20:24:00 by itaborsk          #+#    #+#             */
/*   Updated: 2025/08/19 23:51:10 by itaborsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	rev(char *tab, int size, int nbr)
{
	int		num;
	char	temp;

	num = 0;
	while (num < size / 2 && nbr != -2147483648)
	{
		temp = tab[num];
		tab[num] = tab[size - num - 1];
		tab[size - num - 1] = temp;
		num++;
	}
	num = 0;
	tab[size] = '\0';
	while (*tab != '\0')
	{
		write(1, tab, 1);
		tab++;
	}
}

int	check_base(char *base, int *nbr)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		j = i + 1;
		if (base[i] == '+' || base[i] == '-')
			return (0);
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	if (i == 0 || i == 1)
		return (0);
	if (*nbr < 0)
		*nbr = *nbr * -1;
	return (i);
}

void	ft_putnbr_base(int nbr, char *base)
{	
	char	arr[33];
	int		size_b;
	int		i;
	char	check;

	i = 0;
	check = '-';
	if (nbr < 0)
		write(1, &check, 1);
	size_b = check_base(base, &nbr);
	while (nbr == -2147483648 && i != 32)
	{
		arr[0] = base[size_b - 1];
		arr[i++] = base[0];
	}
	if (nbr == 0)
		write(1, &base[0], 1);
	while (nbr != 0 && size_b != 0 && nbr != -2147483648)
	{
		arr[i++] = base[nbr % size_b];
		nbr /= size_b;
	}
	rev(arr, i, nbr);
}
