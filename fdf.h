/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vklaouse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 16:38:16 by vklaouse          #+#    #+#             */
/*   Updated: 2016/01/29 18:52:12 by vklaouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include "libft/includes/libft.h"
# include <math.h>

typedef struct	s_env
{
	void		*win;
	void		*mlx;
	int			line;
	int			collum;
	int			**tab;
	int			base_x;
	int			base_y;
	int			color;
	int			size;
	int			change;
}				t_env;

typedef struct	s_data
{
	int	i;
	int	j;
	int base_y_tmp;
	int base_x_tmp;
	int **tab_y;
	int **tab_x;
	int k;
	int l;
}				t_data;

typedef struct	s_tmp
{
	int	start_x;
	int	start_y;
	int	x_0;
	int	y_0;
	int	k;
	int	collum_x;
	int	collum_y;
}				t_tmp;

typedef struct	s_trace
{
	int	dx;
	int	sx;
	int	dy;
	int	sy;
	int	err;
	int	e2;
}				t_trace;

void			ft_end(char *error);
int				main(int ac, char **av);
void			ft_end(char *error);
void			stock_fd(char *av, t_env *yolo);
void			aff(t_env *win);
void			aff_map(int **tab, int line, int collum);
int				draw(t_env *yolo);
int				color(int i);
int				**create_tab(t_env *yolo);
int				keyboard(int key_code, t_env *yolo);
int				draw_black(t_env *yolo);
void			draw_transition(t_env *yolo, t_data *d, t_trace *t, t_tmp *e);
void			data_collum(t_env *yolo, t_data *d, t_trace *t, t_tmp *e);
void			collum(t_env *yolo, t_data *d, t_trace *t, t_tmp *e);
void			set_overlay(t_env *yolo);

# define BLUE 0x0000FF
# define RED 0xFF0000
# define YELLOW 0xFFFF00
# define GREEN 0x00FF00
# define TURQ 0x33CCFF
# define BROWN 0x993300
# define WHITE 0xFFFFFF

# define ESC 53
# define RIGHT 124
# define LEFT 123
# define TOP 126
# define BOT 125
# define ZOOM 69
# define DEZOOM 78
# define ENLARGE 67
# define REDUCE 75

#endif
