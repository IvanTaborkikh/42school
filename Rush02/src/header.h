/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdreissi <jdreissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 16:10:34 by jdreissi          #+#    #+#             */
/*   Updated: 2025/08/17 14:36:55 by jdreissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER
#define HEADER

#include "core_lib.h"

t_obj	*ft_get_core_own(void);
t_obj	*ft_get_core_opponent(void);
t_obj	*ft_get_resource_nearest(t_pos pos);
t_obj	*ft_get_money_nearest(t_pos pos);
t_obj	*ft_get_resource_money_nearest(t_pos pos);
t_obj	*ft_get_units_opponent_nearest(t_pos pos);
t_obj	**ft_get_units_own(void);
t_obj	**ft_get_units_opponent(void);

int move_to(t_obj *unit, t_pos target_pos);
void ft_on_tick(unsigned long tick);

#endif