/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaborsk <itaborsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 21:55:17 by itaborsk          #+#    #+#             */
/*   Updated: 2025/08/20 22:11:43 by itaborsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	count(char *argv)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (argv[i])
	{
		count += argv[i];
		i++;
	}
	return (count);
}

void	rev(int argc, char *argv[])
{
	int		i;
	int		j;
	char	*temp;

	j = 1;
	while (j < argc)
	{
		i = j + 1;
		while (argv[i])
		{
			if (count(argv[j]) > count(argv[i]))
			{
				temp = argv[j];
				argv[j] = argv[i];
				argv[i] = temp;
			}
			i++;
		}
		j++;
	}
}

int	main(int argc, char *argv[])
{
	int	i;
	int	j;

	j = 1;
	rev(argc, argv);
	while (j < argc)
	{
		i = 0;
		while (argv[j][i])
		{
			write(1, &argv[j][i], 1);
			i++;
		}
		write(1, "\n", 1);
		j++;
	}
}
