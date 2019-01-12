/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_concerned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesafi <mesafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 12:28:07 by mesafi            #+#    #+#             */
/*   Updated: 2019/11/20 14:50:59 by mesafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"

int		player_concerned(t_fill *data)
{
	char	*line;

	if (get_next_line(0, &line) != 1)
		return (-1);
	if (ft_strstr(line, "p1"))
		data->player = 'O';
	else if (ft_strstr(line, "p2"))
		data->player = 'X';
	free(line);
	return (0);
}
