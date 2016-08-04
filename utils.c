/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vklaouse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 22:31:04 by vklaouse          #+#    #+#             */
/*   Updated: 2016/01/29 18:51:50 by vklaouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_end(char *error)
{
	ft_putendl_fd(error, 2);
	exit(0);
}

int		color(int i)
{
	if (i <= 0)
		return (BLUE);
	else if (i <= 10)
		return (RED);
	else if (i <= 20)
		return (YELLOW);
	else if (i <= 30)
		return (GREEN);
	else if (i <= 40)
		return (TURQ);
	else if (i <= 50)
		return (BROWN);
	else
		return (WHITE);
}

void	aff_map(int **tab, int line, int collum)
{
	int	i;
	int	j;

	i = 0;
	while (i < line)
	{
		j = 0;
		while (j < collum)
		{
			ft_putnbr(tab[i][j]);
			ft_putstr("  ");
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

int		**create_tab(t_env *yolo)
{
	int	**tab;
	int	i;

	i = 0;
	tab = (int **)malloc(sizeof(int*) * yolo->line);
	while (i < yolo->line)
	{
		tab[i] = (int *)malloc(sizeof(int) * yolo->collum);
		i++;
	}
	return (tab);
}

void	set_overlay(t_env *yolo)
{
	mlx_string_put(yolo->mlx, yolo->win, 10, 20, BLUE, "Project : FDF");
	mlx_string_put(yolo->mlx, yolo->win, 10, 40, BLUE, "Commands :");
	mlx_string_put(yolo->mlx, yolo->win, 10, 60, WHITE, "Arrows = Move");
	mlx_string_put(yolo->mlx, yolo->win, 10, 80, WHITE, "+/- = ZOOM/DEZOOM");
	mlx_string_put(yolo->mlx, yolo->win, 10, 100, RED, "*// = Enlarge\
			/ Reduce");
	mlx_string_put(yolo->mlx, yolo->win, 10, 120, RED, "ECS = Quit");
}
