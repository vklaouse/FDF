/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vklaouse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 22:25:40 by vklaouse          #+#    #+#             */
/*   Updated: 2016/01/29 19:06:40 by vklaouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		collum(t_env *yolo, t_data *d, t_trace *t, t_tmp *e)
{
	t->dx = ft_abs(e->collum_x - e->start_x);
	t->sx = e->start_x < e->collum_x ? 1 : -1;
	t->dy = ft_abs(e->collum_y - e->start_y);
	t->sy = e->start_y < e->collum_y ? 1 : -1;
	t->err = (t->dx > t->dy ? t->dx : -t->dy) / 2;
	while (1)
	{
		mlx_pixel_put(yolo->mlx, yolo->win, e->start_x,\
				e->start_y, yolo->color);
		if (e->start_x == e->collum_x && e->start_y == e->collum_y)
			break ;
		t->e2 = t->err;
		if (t->e2 > -t->dx)
		{
			t->err -= t->dy;
			e->start_x += t->sx;
		}
		if (t->e2 < t->dy)
		{
			t->err += t->dx;
			e->start_y += t->sy;
		}
	}
}

static void	line(t_env *yolo, t_data *d, t_trace *t, t_tmp *e)
{
	t->dx = ft_abs(d->tab_x[d->i][d->j] - e->x_0);
	t->sx = e->x_0 < d->tab_x[d->i][d->j] ? 1 : -1;
	t->dy = ft_abs(d->tab_y[d->i][d->j] - e->y_0);
	t->sy = e->y_0 < d->tab_y[d->i][d->j] ? 1 : -1;
	t->err = (t->dx > t->dy ? t->dx : -t->dy) / 2;
	while (1)
	{
		mlx_pixel_put(yolo->mlx, yolo->win, e->x_0, e->y_0, yolo->color);
		if (e->x_0 == d->tab_x[d->i][d->j] && e->y_0 == d->tab_y[d->i][d->j])
			break ;
		t->e2 = t->err;
		if (t->e2 > -t->dx)
		{
			t->err -= t->dy;
			e->x_0 += t->sx;
		}
		if (t->e2 < t->dy)
		{
			t->err += t->dx;
			e->y_0 += t->sy;
		}
	}
}

void		draw_transition(t_env *yolo, t_data *d, t_trace *t, t_tmp *e)
{
	if (d->j > 0)
		line(yolo, d, t, e);
	if (e->k < yolo->line)
		data_collum(yolo, d, t, e);
}
