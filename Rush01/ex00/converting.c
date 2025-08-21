/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaborsk <itaborsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 16:12:19 by itaborsk          #+#    #+#             */
/*   Updated: 2025/08/09 18:14:35 by itaborsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	create(char mat[6][6])
{
	int	x;
	int	y;

	y = 0;
	while (y < 6)
	{
		x = 0;
		while (x < 6)
		{
			mat[x][y] = ' ';
			x++;
		}
		y++;
	}
}

void	converte(char *tab, char mat[6][6])
{
	int	i;

	i = 0;
	create(mat);
	while (tab[i])
	{
		if (i % 2 == 0 && i >= 0 && i <= 8)
		{
			mat[0][(i / 2) + 1] = tab[i];
			mat[5][(i / 2) + 1] = tab[i + 8];
		}
		else if (i % 2 == 0 && i >= 16 && i <= 22)
		{
			mat[(i / 2) - 7][0] = tab[i];
			mat[(i / 2) - 7][5] = tab[i + 8];
		}
		i++;
	}
	mat[0][0] = 'X';
	mat[0][5] = 'X';
	mat[5][0] = 'X';
	mat[5][5] = 'X';
}

void	show(char mat[6][6])
{
	int	x;
	int	y;

	y = 0;
	while (y < 6)
	{
		x = 0;
		while (x < 6)
		{
			ft_putchar(mat[y][x]);
			x++;
		}
		ft_putchar('\n');
		y++;
	}
}
