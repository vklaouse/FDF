/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vklaouse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 15:00:23 by vklaouse          #+#    #+#             */
/*   Updated: 2016/02/01 13:51:38 by vklaouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	change_tab(t_env *yolo, int a)
{
	int	i;
	int	j;

	i = 0;
	while (i < yolo->line)
	{
		j = 0;
		while (j < yolo->collum)
		{
			if (a == 1)
				yolo->tab[i][j] *= 1.5;
			else if (a == -1)
				yolo->tab[i][j] /= 1.5;
			j++;
		}
		i++;
	}
}

static void	key(int key_code, t_env *yolo, int a)
{
	if (key_code == ESC)
		exit(0);
	else if (key_code == RIGHT)
		yolo->base_x += 20;
	else if (key_code == LEFT)
		yolo->base_x -= 20;
	else if (key_code == TOP)
		yolo->base_y -= 20;
	else if (key_code == BOT)
		yolo->base_y += 20;
	else if (key_code == ZOOM)
		yolo->size += 5;
	else if (key_code == DEZOOM)
		yolo->size -= 5;
	else if (key_code == ENLARGE)
	{
		a = 1;
		change_tab(yolo, a);
	}
	else if (key_code == REDUCE)
	{
		a = -1;
		change_tab(yolo, a);
	}
}

int			keyboard(int key_code, t_env *yolo)
{
	int	a;

	a = 0;
	draw_black(yolo);
	key(key_code, yolo, a);
	draw(yolo);
	return (0);
}
