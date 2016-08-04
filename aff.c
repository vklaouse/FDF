/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vklaouse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 14:43:19 by vklaouse          #+#    #+#             */
/*   Updated: 2016/06/25 20:20:23 by vklaouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	aff(t_env *win)
{
	win->mlx = mlx_init();
	win->win = mlx_new_window(win->mlx, 1280, 1024, "fdf");
	win->base_x = 100;
	win->base_y = 100;
	win->size = 10;
	mlx_expose_hook(win->win, draw, &*win);
	mlx_key_hook(win->win, keyboard, &*win);
	mlx_loop(win->mlx);
}
