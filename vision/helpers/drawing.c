/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesafi <mesafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 19:34:49 by mesafi            #+#    #+#             */
/*   Updated: 2019/11/22 18:38:05 by mesafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vision.h"

static void	init_d(t_draw *d, t_point start, t_point end)
{
	d->delta_x = abs(end.x - start.x);
	d->step_x = start.x < end.x ? 1 : -1;
	d->delta_y = abs(end.y - start.y);
	d->step_y = start.y < end.y ? 1 : -1;
	d->slope_error = (d->delta_x > d->delta_y ? d->delta_x : -d->delta_y) / 2;
}

static void	draw_line(t_vision *vision, t_point start, t_point end)
{
	t_draw	d;
	t_point	index;

	init_d(&d, start, end);
	index = start;
	while (1)
	{
		if (index.x < vision->win_w && index.x >= 0 &&
				index.y < vision->win_h && index.y >= 0)
			vision->data[index.y * vision->win_w + index.x] = LN;
		if (index.x == end.x && index.y == end.y)
			return ;
		d.tmp = d.slope_error;
		if (d.tmp > -d.delta_x)
		{
			d.slope_error -= d.delta_y;
			index.x += d.step_x;
		}
		if (d.tmp < d.delta_y)
		{
			d.slope_error += d.delta_x;
			index.y += d.step_y;
		}
	}
}

void		drawing(t_vision *vision)
{
	int		i;
	int		j;
	t_point	start;
	t_point	end;

	i = -1;
	while (++i <= vision->height)
	{
		j = -1;
		while (++j <= vision->width)
		{
			start.x = j * vision->zoom;
			start.y = i * vision->zoom;
			end.x = (j + 1) * vision->zoom;
			end.y = i * vision->zoom;
			if (j + 1 <= vision->width)
				draw_line(vision, start, end);
			end.x = j * vision->zoom;
			end.y = (i + 1) * vision->zoom;
			if (i + 1 <= vision->height)
				draw_line(vision, start, end);
		}
	}
}
