/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaborsk <itaborsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 13:19:12 by itaborsk          #+#    #+#             */
/*   Updated: 2025/08/10 17:06:17 by itaborsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	show(char mat[6][6]);
void	converte(char *tab, char mat[6][6]);
void	create(char mat[6][6]);
void	change_4hor(char mat[6][6]);
void	change_4ver(char mat[6][6]);
void	change_2_3(char mat[6][6]);
void	change_1(char mat[6][6]);
void	checking_hor(char mat[6][6]);
void	checking_ver(char mat[6][6]);
void	searching_last(char mat[6][6]);
void	change_3_2(char mat[6][6]);
void	change_2_2(char mat[6][6]);

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	error(void)
{
	ft_putchar('E');
	ft_putchar('r');
	ft_putchar('r');
	ft_putchar('o');
	ft_putchar('r');
	ft_putchar('\n');
}

int	size(char *argv)
{
	int	i;
	int	size;
	int	space;

	size = 0;
	i = 0;
	space = 0;
	while (argv[i])
	{
		if (argv[i] >= '1' && argv[i] <= '4')
			size++;
		if (argv[i] == ' ')
			space++;
		i++;
	}
	if (size == 16 && space == 15)
	{
		return (0);
	}
	else
	{
		return (1);
	}
}

int	check(int a, char **argv)
{
	int	i;

	i = 0;
	if (a != 2)
	{
		error();
		return (0);
	}
	while (argv[1][i])
	{
		if (argv[1][i] != ' ' && !(argv[1][i] >= '1' && argv[1][i] <= '4'))
		{
			error();
			return (0);
		}
		i++;
	}
	if (size(argv[1]))
	{
		error();
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	char	mat[6][6];

	while (check(argc, argv))
	{
		converte(argv[1], mat);
		change_4ver(mat);
		change_4hor(mat);
		change_2_3(mat);
		change_1(mat);
		checking_hor(mat);
		checking_ver(mat);
		searching_last(mat);
		change_3_2(mat);
		checking_hor(mat);
		checking_ver(mat);
		searching_last(mat);
		change_2_2(mat);
		show(mat);
		break ;
	}
}
