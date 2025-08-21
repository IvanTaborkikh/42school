/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   changing_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaborsk <itaborsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 14:49:51 by itaborsk          #+#    #+#             */
/*   Updated: 2025/08/10 15:40:01 by itaborsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_putchar(char c);

void	searching_x(char mat[6], int find)
{
	int	x;

	x = 1;
	while (x < 5)
	{
		if (mat[x] == ' ')
		{
			mat[x] = 202 - find;
		}
		x++;
	}
}

void	searchin_y(char mat[6][6], int find, int x)
{
	int	y;

	y = 1;
	while (y < 5)
	{
		if (mat[y][x] == ' ')
		{
			mat[y][x] = 202 - find;
		}
		y++;
	}
}

void	checking_hor(char mat[6][6])
{
	int	x;
	int	y;
	int	sum;
	int	to_find;

	y = 1;
	while (y < 5)
	{
		to_find = 0;
		x = 1;
		sum = 0;
		while (x < 5)
		{
			if (mat[y][x] >= '1' && mat[y][x] <= '4')
			{
				sum++;
				to_find += mat[y][x];
			}
			x++;
		}
		if (sum == 3)
			searching_x(mat[y], to_find);
		y++;
	}
}

void	checking_ver(char mat[6][6])
{
	int	x;
	int	y;
	int	sum;
	int	to_find;

	y = 1;
	while (x < 5)
	{
		to_find = 0;
		y = 1;
		sum = 0;
		while (y < 5)
		{
			if (mat[y][x] >= '1' && mat[y][x] <= '4')
			{
				sum++;
				to_find += mat[y][x];
			}
			y++;
		}
		if (sum == 3)
			searchin_y(mat, to_find, x);
		x++;
	}
}
