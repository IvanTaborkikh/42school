/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaborsk <itaborsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 13:23:23 by itaborsk          #+#    #+#             */
/*   Updated: 2025/08/07 20:09:50 by itaborsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	checking(char a)
{
	if ((a >= 0 && a < 48) || (a > 57 && a < 65))
	{
		return (1);
	}
	if ((a > 90 && a < 97) || (a > 122))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (i == 0 && str[i] >= 97 && str[i] < 123)
			str[i] = str[i] - 32;
		else if (str[i] >= 97 && str[i] < 123)
		{
			if (checking(str[i - 1]))
				str[i] = str[i] - 32;
		}
		else if (str[i] >= 65 && str[i] < 91)
		{
			if (checking(str[i - 1]) == 0)
				str[i] = str[i] + 32;
		}
		i++;
	}
	return (str);
}
