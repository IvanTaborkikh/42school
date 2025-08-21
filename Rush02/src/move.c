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

int	move_to(t_obj *unit, t_pos target_pos)
{
	int	step;
	int	next_x;
	int	next_y;
	int	dx;
	int	dy;
	t_obj	*next_pos_obj;

	dx = target_pos.x - unit->pos.x;
	dy = target_pos.y - unit->pos.y;
	t_pos	next_pos = {unit->pos.x, unit->pos.y};
	if (abs(dx) > abs(dy))
	{
		if (dx > 0)
			step = 1;
		else
			step = -1;
		next_pos.x += step;
		next_x = 1;
	}
	else
	{
		if (dy > 0)
			step = 1;
		else
			step = -1;
		next_pos.y += step;
		next_y = 1;
	}
	next_pos_obj = core_get_obj_from_pos(next_pos);
	if (next_pos_obj)
	{
		if (next_pos_obj->type == OBJ_RESOURCE
			&& (int)unit->s_unit.unit_type == UNIT_MINER)
			return (core_action_attack(unit, next_pos), 0);
		if ((next_pos_obj->type == OBJ_UNIT || next_pos_obj->type == OBJ_CORE)
			&& (int)unit->s_unit.unit_type == UNIT_WARRIOR
			&& next_pos_obj->s_unit.team_id != game.my_team_id)
			return(core_action_attack(unit, next_pos), 0);
		if (next_pos_obj->type == OBJ_MONEY
			&& (int)unit->s_unit.unit_type == UNIT_CARRIER)
			core_action_move(unit, next_pos);
		else
		{
			if (next_y == 1)
			{
				next_pos.y -= step;
				if (unit->pos.x == 0)
					next_pos.x += 1;
				else if (unit->pos.x == 19)
					next_pos.x -= 1;
				else
				{
					if (abs(target_pos.x - unit->pos.x - 1) >= abs(target_pos.x - unit->pos.x))
						next_pos.x -= 1;
					else
						next_pos.x += 1;
				}
			}
			else if (next_x == 1)
			{
				next_pos.x -= step;
				if (unit->pos.y == 0)
					next_pos.y += 1;
				else if (unit->pos.y == 19)
					next_pos.y -= 1;
				else
				{
					if (abs(target_pos.y - unit->pos.y - 1) > abs(target_pos.y - unit->pos.y))
						next_pos.y -= 1;
					else
						next_pos.y += 1;
				}
			}
			core_action_move(unit, next_pos);
		}
	}
	else
		core_action_move(unit, next_pos);
	return (0);
}
