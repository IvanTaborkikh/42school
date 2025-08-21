/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaborsk <itaborsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 22:14:30 by itaborsk          #+#    #+#             */
/*   Updated: 2025/08/21 00:00:51 by itaborsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	is_separ(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	count_words(char *str, char *charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (!is_separ(str[i], charset))
		{
			count++;
			while (!(!is_separ(str[i], charset)
					&& is_separ(str[i + 1], charset)))
			{
				i++;
			}
		}
		i++;
	}
	return (count);
}

char	*return_word(char *str, int i, char *charset)
{
	char	*word;
	int		num;
	int		j;

	j = 0;
	num = i;
	while (!(!is_separ(str[i], charset) && is_separ(str[i + 1], charset)))
	{
		i++;
	}
	i++;
	word = (char *)malloc(sizeof(char) * (i - num));
	while (!(!is_separ(str[num - 1], charset) && is_separ(str[num], charset)))
	{
		word[j] = str[num];
		j++;
		num++;
	}
	word[j] = '\0';
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	char	**b;
	int		i;
	int		j;

	if (str == NULL || charset == NULL)
		return (NULL);
	b = (char **)malloc (sizeof(char *) * (count_words(str, charset) + 1));
	i = 0;
	j = 0;
	while (str[i])
	{
		if (!is_separ(str[i], charset))
		{
			b[j] = return_word(str, i, charset);
			j++;
			while (!(!is_separ(str[i], charset)
					&& is_separ(str[i + 1], charset)))
			{
				i++;
			}
		}
		i++;
	}
	b[j] = '\0';
	return (b);
}
