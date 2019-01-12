/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesafi <mesafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 14:25:01 by mesafi            #+#    #+#             */
/*   Updated: 2019/11/22 20:15:14 by mesafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	init(t_fill *data)
{
	init_queue(&(data->queue));
	init_stack(&(data->scope));
	data->units = 0;
	data->score = -1;
	data->result.line = 0;
	data->result.column = 0;
}

int			main(void)
{
	t_fill		data;

	if (player_concerned(&data) == -1)
		return (0);
	while (1)
	{
		init(&data);
		if (map_reader(&data) == -1)
			return (0);
		if (obtain_token(&data) == -1)
			return (0);
		make_heatmap(&data);
		find_out(&data);
		ft_putnbr(data.result.line);
		ft_putchar(' ');
		ft_putnbr(data.result.column);
		ft_putchar('\n');
		error_handler(&data, data.height, 1, 0);
	}
	return (0);
}
