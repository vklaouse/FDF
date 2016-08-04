/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_fd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vklaouse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 13:34:03 by vklaouse          #+#    #+#             */
/*   Updated: 2016/01/26 20:15:53 by vklaouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	line_nbr(char *av)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = open(av, O_RDONLY);
	if (fd < 0)
		ft_end("Fail line");
	while (get_next_line(fd, &line))
	{
		i++;
		free(line);
	}
	free(line);
	close(fd);
	return (i);
}

static int	collum_nbr(char *av)
{
	int		i;
	int		fd;
	char	*line;
	char	**tab;

	i = 0;
	fd = open(av, O_RDONLY);
	if (fd < 0)
		ft_end("Fail collum");
	get_next_line(fd, &line);
	tab = ft_strsplit(line, ' ');
	while (get_next_line(fd, &line))
		free(line);
	free(line);
	while (tab[i])
		i++;
	free(tab);
	close(fd);
	return (i);
}

static void	tab(t_env *yolo, char *av, int fd)
{
	char	*line;
	char	**change;
	int		i;
	int		j;

	yolo->tab = (int **)malloc(sizeof(int*) * yolo->line);
	fd = open(av, O_RDONLY);
	if (fd < 0)
		ft_end("Fail tab");
	i = 0;
	while (i != yolo->line)
	{
		j = 0;
		get_next_line(fd, &line);
		change = ft_strsplit(line, ' ');
		yolo->tab[i] = (int *)malloc(sizeof(int) * yolo->collum);
		j = 0;
		while (change[j])
		{
			yolo->tab[i][j] = ft_atoi(change[j]);
			j++;
		}
		i++;
	}
	close(fd);
}

void		stock_fd(char *av, t_env *yolo)
{
	int		fd;

	yolo->line = line_nbr(av);
	yolo->collum = collum_nbr(av);
	tab(&*yolo, av, fd);
}
