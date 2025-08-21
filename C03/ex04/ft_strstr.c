/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaborsk <itaborsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 19:38:41 by itaborsk          #+#    #+#             */
/*   Updated: 2025/08/14 16:57:28 by itaborsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	size(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	a;
	int	b;

	a = size(to_find);
	b = 0;
	while (str[b])
	{
		if (str[b] == to_find[0])
		{
			while (a - 1 >= 0)
			{
				if (str[b + a - 1] == to_find[a - 1])
					a--;
				else
					break ;
			}
		}
		if (a == 0)
			return (&str[b]);
		else
			a = size(to_find);
		b++;
	}
	return (NULL);
}
