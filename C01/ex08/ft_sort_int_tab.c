/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaborsk <itaborsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 20:19:57 by itaborsk          #+#    #+#             */
/*   Updated: 2025/08/06 15:15:07 by itaborsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	b;
	int	temp;

	b = 0;
	while (b <= size)
	{
		i = 0;
		while (i <= size)
		{
			if (tab[b] < tab[i])
			{
				temp = tab[b];
				tab[b] = tab[i];
				tab[i] = temp;
			}
			i++;
		}
		b++;
	}
}
