/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gang.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesafi <mesafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 19:35:44 by mesafi            #+#    #+#             */
/*   Updated: 2019/11/22 23:13:49 by mesafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vision.h"

static void	make_background(t_vision *vision, t_point start,
			t_point end, int color)
{
	int		i;

	while (++start.y < end.y)
	{
		i = start.x;
		while (++i < end.x)
		{
			vision->data[i * vision->win_w + start.y] = color;
		}
	}
}

static void	make_sc(t_vision *vision, t_point start,
			t_point end, int color)
{
	int		i;

	while (start.y < end.y)
	{
		i = start.x;
		while (i < end.x)
		{
			mlx_pixel_put(vision->mlx_ptr, vision->win_ptr, start.y, i, color);
			++i;
		}
		++start.y;
	}
}

static void	drop_score(t_vision *vision)
{
	t_point	start;
	t_point	end;

	start.x = PAD;
	start.y = 0;
	end.x = vision->pad - 1 + PAD;
	end.y = vision->win_w;
	make_sc(vision, start, end, P2);
	if (vision->score_p1 == 0)
		end.y = vision->win_w / 2;
	else
		end.y = ((vision->win_w * vision->score_p1) /
				(vision->score_p1 + vision->score_p2));
	make_sc(vision, start, end, P1);
}

static void	drop_ch(t_vision *vision)
{
	t_list	*node;
	t_point	start;
	t_point	end;
	t_scp	finger;
	int		color;

	while (vision->stack.size != 0)
	{
		node = pop(&(vision->stack));
		finger = *((t_scp *)(node->content));
		start.x = finger.x * vision->zoom;
		start.y = finger.y * vision->zoom;
		end.x = (finger.x + 1) * vision->zoom;
		end.y = (finger.y + 1) * vision->zoom;
		if (finger.p == 'o' || finger.p == 'O')
			color = P1;
		else
			color = P2;
		make_background(vision, start, end, color);
		free(node->content);
		free(node);
	}
}

void		gang(t_vision *vision)
{
	int			bits_per_pixel;
	int			size_line;
	int			endian;

	if (vision->img_ptr != NULL)
		mlx_destroy_image(vision->mlx_ptr, vision->img_ptr);
	mlx_clear_window(vision->mlx_ptr, vision->win_ptr);
	vision->img_ptr = mlx_new_image(vision->mlx_ptr, vision->win_w,
						vision->win_h);
	vision->data = (int *)mlx_get_data_addr(vision->img_ptr,
					&bits_per_pixel, &size_line, &endian);
	drawing(vision);
	drop_ch(vision);
	drop_score(vision);
	top_bar(vision);
	mlx_put_image_to_window(vision->mlx_ptr, vision->win_ptr,
					vision->img_ptr, 0, vision->pad + PAD);
}
