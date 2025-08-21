/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaborsk <itaborsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 22:38:29 by itaborsk          #+#    #+#             */
/*   Updated: 2025/08/15 11:50:55 by itaborsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	checking(char *str, int *num)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '-')
		{
			*num *= -1;
		}
		i++;
	}
	if (!((str[0] >= '0' && str[0] <= '9') || str[0] == '-' || str[0] == '+'
			|| str[0] == ' '))
		*num *= 0;
}

int	ft_atoi(char *str)
{
	int	i;
	int	num;
	int	output;

	num = 1;
	i = 0;
	output = 0;
	checking(str, &num);
	while ((str[i] >= '0' && str[i] <= '9') || str[i] == '-' || str[i] == '+'
		|| str[i] == ' ')
	{
		if ((str[i] >= '0' && str[i] <= '9')
			&& !(str[i + 1] >= '0' && str[i + 1] <= '9'))
			break ;
		i++;
	}
	while (str[i] >= '1' && str[i] <= '9' && i >= 0)
	{
		output += num * (str[i] - 48);
		num = num * 10;
		i--;
	}
	return (output);
}
