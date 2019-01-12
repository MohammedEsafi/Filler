/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesafi <mesafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 19:26:43 by mesafi            #+#    #+#             */
/*   Updated: 2019/11/20 15:06:12 by mesafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"

int		error_handler(t_fill *data, int map_opt, int token_opt, int respond)
{
	int		i;

	free_stack(&(data->scope));
	free_queue(&(data->queue));
	if (map_opt != 0)
	{
		i = -1;
		while (++i < map_opt)
		{
			free(data->map[i]);
		}
		free(data->map);
	}
	if (token_opt != 0)
	{
		free(data->token);
	}
	return (respond);
}
