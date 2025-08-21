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

#include "header.h"

#include <time.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	return (core_startGame("jdreissi", argc, argv, ft_on_tick, false));
}

void	unit_spawner(unsigned long tick, int miner)
{
	if (tick < 10)
	{
		core_action_createUnit(UNIT_CARRIER);
	}
	else if (miner < 3 && tick < 200)
	{
		core_action_createUnit(UNIT_MINER);
	}
	else if (ft_get_core_own()->s_core.balance > 150)
	{
		core_action_createUnit(UNIT_WARRIOR);
	}
}

void	carrier_move(int miner, t_obj *obj)
{
	t_obj	*nearest_money;
	t_obj	*closest_opponent;
	t_pos	rest_pos;
	int		dx;
	int		dy;
	int		counter;
	int		has_carrier;

	counter = 0;
	closest_opponent = ft_get_units_opponent_nearest(obj->pos);
	nearest_money = ft_get_money_nearest(obj->pos);
	if(closest_opponent != NULL)
	{
		if(closest_opponent->s_unit.unit_type == UNIT_WARRIOR)
		{
			dx = closest_opponent->pos.x - obj->pos.x;
			dy = closest_opponent->pos.y - obj->pos.y;
			if (abs(dx) <= 2 && abs(dy) <= 2)
				move_to(obj, ft_get_core_own()->pos);
		}
		if(closest_opponent->s_unit.unit_type == UNIT_CARRIER && !nearest_money)
			{
				dx = closest_opponent->pos.x - obj->pos.x;
				dy = closest_opponent->pos.y - obj->pos.y;
				if (abs(dx) <= 5 && abs(dy) <= 5)
					move_to(obj, ft_get_core_own()->pos);
			}
	}
	if(nearest_money != NULL)
	{
		dx = nearest_money->pos.x - obj->pos.x;
		dy = nearest_money->pos.y - obj->pos.y;
	}
	if (nearest_money && obj->s_unit.balance >= 100 && miner == 0)
	{
		if ((obj->pos.y == 1 && obj->pos.x == 0) || (obj->pos.y == 0 && obj->pos.x == 1)
			|| (obj->pos.y == 19 && obj->pos.x == 18) || (obj->pos.y == 18 && obj->pos.x == 19))
			core_action_transferMoney(obj, ft_get_core_own()->pos, 9999999);
		else
			move_to(obj, ft_get_core_own()->pos);
	}
	else if (nearest_money && obj->s_unit.balance >= 350 && miner == 1)
	{
		if ((obj->pos.y == 1 && obj->pos.x == 0) || (obj->pos.y == 0 && obj->pos.x == 1)
			|| (obj->pos.y == 19 && obj->pos.x == 18) || (obj->pos.y == 18 && obj->pos.x == 19))
			core_action_transferMoney(obj, ft_get_core_own()->pos, 9999999);
		else
			move_to(obj, ft_get_core_own()->pos);
	}
	else if (nearest_money && ((obj->s_unit.balance < 200) || (abs(dx) < 4 && abs(dy) < 4)))
	{
			move_to(obj, nearest_money->pos);
	}
	else
	{
		if(obj->s_unit.balance != 0)
		{
			if ((obj->pos.y == 1 && obj->pos.x == 0) || (obj->pos.y == 0 && obj->pos.x == 1)
				|| (obj->pos.y == 19 && obj->pos.x == 18) || (obj->pos.y == 18 && obj->pos.x == 19))
				core_action_transferMoney(obj, ft_get_core_own()->pos, 9999999);
			else
				move_to(obj, ft_get_core_own()->pos);
		}
		else
		{
			t_obj **units = ft_get_units_opponent();
			while(units && units[counter])
			{
				if(units[counter]->s_unit.unit_type == UNIT_CARRIER)
				{
					has_carrier = 1;
					break;
				}
				counter++;
			}
			if(has_carrier == 1)
			{
				move_to(obj, units[counter]->pos);
			}
			else
			{
				rest_pos.x = 10;
				rest_pos.y = 10;
				move_to(obj, rest_pos);
			}
		}
	}
	// free (closest_opponent);
}

void	warrior_move(t_obj *obj)
{
	t_obj *closest_opponent;
	int dx;
	int dy;
	closest_opponent = ft_get_units_opponent_nearest(obj->pos);
	if(closest_opponent != NULL)
	{
		dx = closest_opponent->pos.x - obj->pos.x;
		dy = closest_opponent->pos.y - obj->pos.y;
	}
	if (abs(dx) <= 2 && abs(dy) <= 2)
		move_to(obj, closest_opponent->pos);
	else
		move_to(obj, ft_get_core_opponent()->pos);
	// free (closest_opponent);
}

void	ft_on_tick(unsigned long tick)
{
	int		i;
	int		miner;
	int		counter;
	t_obj	*nearest_resource;

	i = -1;
	miner = 0;
	counter = 0;
	t_obj **units = ft_get_units_own();
	while(units && units[counter])
	{
		if(units[counter]->s_unit.unit_type == UNIT_MINER)
			miner++;
		counter++;
	}
	unit_spawner(tick, miner);
	while (units && units[++i])
	{
		t_obj *obj = units[i];
		if (obj->state != STATE_ALIVE)
			continue;

		
		if ((int)obj->s_unit.unit_type == UNIT_WARRIOR)
		{
			warrior_move(obj);
		}
		else if ((int)obj->s_unit.unit_type == UNIT_CARRIER)
		{
			carrier_move(miner, obj);
		}
		else if ((int)obj->s_unit.unit_type == UNIT_MINER)
		{
			nearest_resource = ft_get_resource_nearest(obj->pos);
			if (nearest_resource)
				move_to(obj, nearest_resource->pos);
			else
			{
			if ((obj->pos.y == 1 && obj->pos.x == 0) || (obj->pos.y == 0 && obj->pos.x == 1)
				|| (obj->pos.y == 19 && obj->pos.x == 18) || (obj->pos.y == 18 && obj->pos.x == 19))
				core_action_transferMoney(obj, ft_get_core_own()->pos, 9999999);
			else
				move_to(obj, ft_get_core_own()->pos);
			}
		}
	}
	free(units);
}
