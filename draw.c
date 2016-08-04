/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vklaouse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 17:12:11 by vklaouse          #+#    #+#             */
/*   Updated: 2016/01/29 19:09:59 by vklaouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	data_x(t_env *yolo, t_data *d)
{
	d->tab_x = create_tab(yolo);
	d->i = 0;
	while (yolo->line > d->i)
	{
		d->j = 0;
		d->base_x_tmp = yolo->base_x;
		while (d->j != d->i)
		{
			d->base_x_tmp = d->base_x_tmp + yolo->size;
			d->j++;
		}
		d->j = 0;
		while (yolo->collum > d->j)
		{
			d->tab_x[d->i][d->j] = d->base_x_tmp;
			d->base_x_tmp = yolo->size + d->base_x_tmp;
			d->j++;
		}
		d->i++;
	}
}

static void	data_y(t_env *yolo, t_data *d)
{
	d->tab_y = create_tab(yolo);
	d->i = 0;
	d->base_y_tmp = yolo->base_y;
	while (yolo->line > d->i)
	{
		d->j = 0;
		while (yolo->collum > d->j)
		{
			d->tab_y[d->i][d->j] = d->base_y_tmp - yolo->tab[d->i][d->j];
			d->j++;
		}
		d->base_y_tmp = d->base_y_tmp + yolo->size;
		d->i++;
	}
	d->i = 0;
}

void		data_collum(t_env *yolo, t_data *d, t_trace *t, t_tmp *e)
{
	e->start_x = d->tab_x[d->i][d->j];
	e->start_y = d->tab_y[d->i][d->j];
	e->collum_x = d->tab_x[e->k][d->j];
	e->collum_y = d->tab_y[e->k][d->j];
	collum(yolo, d, t, e);
}

int			draw(t_env *yolo)
{
	t_data	d;
	t_trace	t;
	t_tmp	e;

	data_x(yolo, &d);
	data_y(yolo, &d);
	e.k = 1;
	while (d.i < yolo->line)
	{
		d.j = 0;
		while (d.j < yolo->collum)
		{
			yolo->color = color(yolo->tab[d.i][d.j]);
			mlx_pixel_put(yolo->mlx, yolo->win, d.tab_x[d.i][d.j],\
					d.tab_y[d.i][d.j], yolo->color);
			draw_transition(yolo, &d, &t, &e);
			e.x_0 = d.tab_x[d.i][d.j];
			e.y_0 = d.tab_y[d.i][d.j];
			d.j++;
		}
		d.i++;
		e.k++;
	}
	set_overlay(yolo);
	return (0);
}

int			draw_black(t_env *yolo)
{
	t_data	d;
	t_trace	t;
	t_tmp	e;

	data_x(yolo, &d);
	data_y(yolo, &d);
	e.k = 1;
	while (d.i < yolo->line)
	{
		d.j = 0;
		while (d.j < yolo->collum)
		{
			yolo->color = 0x000000;
			mlx_pixel_put(yolo->mlx, yolo->win, d.tab_x[d.i][d.j],\
			d.tab_y[d.i][d.j], yolo->color);
			draw_transition(yolo, &d, &t, &e);
			e.x_0 = d.tab_x[d.i][d.j];
			e.y_0 = d.tab_y[d.i][d.j];
			d.j++;
		}
		d.i++;
		e.k++;
	}
	return (0);
}
