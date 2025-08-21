/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaborsk <itaborsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 19:51:22 by itaborsk          #+#    #+#             */
/*   Updated: 2025/08/06 15:15:14 by itaborsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	divis;
	int	rem;
	int	temp;
	int	temp1;

	temp = *a;
	temp1 = *b;
	divis = temp / temp1;
	rem = temp % temp1;
	*a = divis;
	*b = rem;
}
