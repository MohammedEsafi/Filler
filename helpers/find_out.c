/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_out.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesafi <mesafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 19:59:09 by mesafi            #+#    #+#             */
/*   Updated: 2019/11/22 23:01:50 by mesafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"

static int	probing(t_fill *data, t_plot *place, int *score, int *count)
{
	if (ft_toupper(place->value) == S_SIGN(data->player))
		return (-1);
	if (ft_toupper(place->value) == data->player)
		*count += 1;
	if (data->score == -1)
		*score = place->score;
	else if (place->score != -1 &&
		place->score <= data->score)
		*score = place->score;
	return (1);
}

static void	parser(t_fill *data, t_cord *place, int index, int score)
{
	int		line;
	int		column;
	int		i;
	int		count;

	line = place->line - data->token[index].line;
	column = place->column - data->token[index].column;
	i = -1;
	count = 0;
	while (++i < data->units)
	{
		if (data->token[i].line + line < 0 ||
			data->token[i].line + line >= data->height ||
			data->token[i].column + column < 0 ||
			data->token[i].column + column >= data->width)
			return ;
		if (probing(data, &(data->map[data->token[i].line + line]
			[data->token[i].column + column]), &score, &count) == -1)
			return ;
	}
	if (count != 1 || score == -2)
		return ;
	data->result.line = line;
	data->result.column = column;
	data->score = score;
}

void		find_out(t_fill *data)
{
	int		i;
	t_list	*node;

	while (data->scope.size != 0)
	{
		node = pop(&(data->scope));
		i = -1;
		while (++i < data->units)
		{
			parser(data, (t_cord *)(node->content), i, -2);
		}
		free(node->content);
		free(node);
	}
}
