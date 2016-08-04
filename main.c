/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vklaouse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 14:38:15 by vklaouse          #+#    #+#             */
/*   Updated: 2016/01/25 18:53:49 by vklaouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	t_env	yolo;

	if (ac == 2)
	{
		stock_fd(av[1], &yolo);
		aff_map(yolo.tab, yolo.line, yolo.collum);
		aff(&yolo);
	}
	else
		ft_end("fail");
	return (0);
}
