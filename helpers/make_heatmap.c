/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_heatmap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesafi <mesafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 10:29:15 by mesafi            #+#    #+#             */
/*   Updated: 2019/11/19 15:10:01 by mesafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"

static void	unit(t_fill *data, int line, int column, int value)
{
	t_cord		finger;

	if (line < 0 || line >= data->height || column < 0 || column >= data->width)
		return ;
	if (data->map[line][column].score == -1 &&
		ft_toupper(data->map[line][column].value) != data->player)
	{
		finger.line = line;
		finger.column = column;
		enqueue(&(data->queue), ft_lstnew(&finger, sizeof(t_cord)));
		data->map[line][column].score = value;
	}
}

static void	ft_init(t_fill *data)
{
	t_list	*node;
	int		column;
	int		line;
	int		value;

	node = dequeue(&(data->queue));
	line = ((t_cord *)(node->content))->line;
	column = ((t_cord *)(node->content))->column;
	value = data->map[line][column].score + 1;
	unit(data, line + 1, column, value);
	unit(data, line - 1, column, value);
	unit(data, line, column + 1, value);
	unit(data, line, column - 1, value);
	unit(data, line + 1, column + 1, value);
	unit(data, line + 1, column - 1, value);
	unit(data, line - 1, column + 1, value);
	unit(data, line - 1, column - 1, value);
	free(node->content);
	free(node);
}

void		make_heatmap(t_fill *data)
{
	while (data->queue.size != 0)
		ft_init(data);
}
