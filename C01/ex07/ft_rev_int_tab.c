/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaborsk <itaborsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 11:20:27 by itaborsk          #+#    #+#             */
/*   Updated: 2025/08/06 15:15:06 by itaborsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	num;
	int	temp;

	num = 0;
	while (num < size / 2)
	{
		temp = tab[num];
		tab[num] = tab[size - num - 1];
		tab[size - num - 1] = temp;
		num++;
	}
	num = 0;
}
