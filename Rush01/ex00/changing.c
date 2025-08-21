/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   changing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaborsk <itaborsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 17:07:35 by itaborsk          #+#    #+#             */
/*   Updated: 2025/08/10 15:59:50 by itaborsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	change_4hor(char mat[6][6])
{
	int	i;

	i = 0;
	while (i < 5)
	{
		if (mat[5][i] == '4')
		{
			mat[1][i] = '4';
			mat[2][i] = '3';
			mat[3][i] = '2';
			mat[4][i] = '1';
		}
		else if (mat[0][i] == '4')
		{
			mat[1][i] = '1';
			mat[2][i] = '2';
			mat[3][i] = '3';
			mat[4][i] = '4';
		}
		i++;
	}
}

void	change_4ver(char mat[6][6])
{
	int	i;

	i = 0;
	while (i < 5)
	{
		if (mat[i][5] == '4')
		{
			mat[i][1] = '4';
			mat[i][2] = '3';
			mat[i][3] = '2';
			mat[i][4] = '1';
		}
		else if (mat[i][0] == '4')
		{
			mat[i][1] = '1';
			mat[i][2] = '2';
			mat[i][3] = '3';
			mat[i][4] = '4';
		}
		i++;
	}
}

void	change_2_3(char mat[6][6])
{
	int	i;

	i = 0;
	while (i < 5)
	{
		if (mat[5][i] == '2' && mat[0][i] == '1')
		{
			mat[4][i] = '3';
		}
		else if (mat[0][i] == '2' && mat[5][i] == '1')
		{
			mat[1][i] = '3';
		}
		else if (mat[i][5] == '2' && mat[i][0] == '1')
		{
			mat[i][4] = '3';
		}
		else if (mat[i][0] == '2' && mat[i][5] == '1')
		{
			mat[i][1] = '3';
		}
		i++;
	}
}

void	change_1(char mat[6][6])
{
	int	i;

	i = 0;
	while (i < 5)
	{
		if (mat[0][i] == '1')
		{
			mat[1][i] = '4';
		}
		else if (mat[5][i] == '1')
		{
			mat[4][i] = '4';
		}
		else if (mat[i][0] == '1')
		{
			mat[i][1] = '4';
		}
		else if (mat[i][5] == '1')
		{
			mat[i][4] = '4';
		}
		i++;
	}
}
