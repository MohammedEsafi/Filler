/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesafi <mesafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 13:31:43 by mesafi            #+#    #+#             */
/*   Updated: 2019/11/22 20:14:13 by mesafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"

static int	map_dimensions(t_fill *data)
{
	char	*line;
	char	*tmp;

	if (get_next_line(0, &line) != 1)
		return (-1);
	tmp = line;
	while (!(ft_isdigit(*tmp)))
		tmp++;
	data->height = ft_atoi(tmp);
	while (ft_isdigit(*tmp))
		tmp++;
	data->width = ft_atoi(tmp);
	free(line);
	return (0);
}

static void	screening(t_fill *data, int line, int column, char value)
{
	t_cord		finger;

	data->map[line][column].value = value;
	if (ft_toupper(data->map[line][column].value) == S_SIGN(data->player))
	{
		data->map[line][column].score = 0;
		finger.line = line;
		finger.column = column;
		enqueue(&(data->queue), ft_lstnew(&finger, sizeof(t_cord)));
		return ;
	}
	if (ft_toupper(data->map[line][column].value) == data->player)
	{
		finger.line = line;
		finger.column = column;
		push(&(data->scope), ft_lstnew(&finger, sizeof(t_cord)));
	}
	data->map[line][column].score = -1;
}

int			map_reader(t_fill *data)
{
	int		i;
	int		j;
	char	*line;

	i = -1;
	if (map_dimensions(data) == -1)
		return (-1);
	if (!(data->map = (t_plot **)malloc(data->height * sizeof(t_plot *))))
		return (error_handler(data, 0, 0, -1));
	while (++i < data->height + 1)
	{
		if (get_next_line(0, &line) != 1)
			return (error_handler(data, i - 1, 0, -1));
		if (i != 0)
		{
			data->map[i - 1] = (t_plot *)malloc(data->width * sizeof(t_plot));
			if (!(data->map[i - 1]))
				return (error_handler(data, i - 1, 0, -1));
			j = 3;
			while (++j < data->width + 4)
				screening(data, i - 1, j - 4, line[j]);
		}
		ft_strdel(&line);
	}
	return (0);
}
