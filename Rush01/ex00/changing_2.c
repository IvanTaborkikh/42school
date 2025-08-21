/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   changing_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaborsk <itaborsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 15:35:39 by itaborsk          #+#    #+#             */
/*   Updated: 2025/08/10 17:05:13 by itaborsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	searching_last2(char mat[6], int cor[4], int i)
{
	int	x;

	x = 1;
	while (x < 5)
	{
		if (mat[x] == i + 48)
		{
			cor[0] -= x;
			cor[1] -= cor[2];
			cor[3]++;
		}
		x++;
	}
}

void	searching_last(char mat[6][6])
{
	int	y;
	int	cor[4];
	int	i;

	i = 1;
	while (i < 5)
	{
		cor[0] = 10;
		cor[1] = 10;
		cor[3] = 0;
		y = 1;
		while (y < 5)
		{
			cor[2] = y;
			searching_last2(mat[y], cor, i);
			y++;
		}
		if (cor[3] == 3)
		{
			mat[cor[1]][cor[0]] = i + 48;
		}
		i++;
	}
}

void	change_3_2(char mat[6][6])
{
	int	i;

	i = 0;
	while (i < 5)
	{
		if (mat[5][i] == '3' && mat[3][i] == '3' &&
			mat[0][i] == '2' && mat[4][i] == '2')
		{
			mat[2][i] = '4';
			mat[1][i] = '1';
		}
		if (mat[0][i] == '3' && mat[2][i] == '3' &&
			mat[5][i] == '2' && mat[1][i] == '2')
		{
			mat[3][i] = '4';
			mat[4][i] = '1';
		}
		if (mat[i][0] == '3' && mat[i][2] == '3' && mat[i][5] == '2' &&
			mat[i][1] == '2')
		{
			mat[i][3] = '4';
			mat[i][4] = '1';
		}
		if (mat[i][5] == '3' && mat[i][3] == '3' &&
			mat[i][0] == '2' && mat[i][1] == '2')
		{
			mat[i][2] = '4';
			mat[i][1] = '1';
		}
		i++;
	}
}

void	change_2_2(char mat[6][6])
{
	int	i;

	i = 0;
	while (i < 5)
	{
		if (mat[5][i] == '2' && mat[0][i] == '2' &&
			mat[1][i] == '3' && mat[2][i] == '4')
		{
			mat[3][i] = '1';
			mat[4][i] = '2';
		}
		if (mat[5][i] == '2' && mat[0][i] == '2' &&
			mat[4][i] == '3' && mat[3][i] == '4')
		{
			mat[2][i] = '1';
			mat[1][i] = '2';
		}
		if (mat[i][5] == '2' && mat[i][0] == '2' &&
			mat[i][1] == '3' && mat[i][2] == '4')
		{
			mat[i][3] = '1';
			mat[i][4] = '2';
		}
		if (mat[i][5] == '2' && mat[i][0] == '2' &&
			mat[i][4] == '3' && mat[i][3] == '4')
		{
			mat[i][2] = '1';
			mat[i][1] = '2';
		}
		i++;
	}
}
