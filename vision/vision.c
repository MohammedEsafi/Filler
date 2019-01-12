/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vision.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesafi <mesafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 16:15:43 by mesafi            #+#    #+#             */
/*   Updated: 2019/11/22 23:30:42 by mesafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vision.h"

static void	player_concerned(t_vision *vision)
{
	char	*line;
	int		stop;
	int		i;

	vision->p1 = (char *)malloc(100);
	vision->p2 = (char *)malloc(100);
	stop = 0;
	while (stop != 2 && get_next_line(0, &line) == 1)
	{
		if (ft_strstr(line, "$$$"))
		{
			i = ft_strlen(line);
			while (line[--i] != '/')
				;
			++i;
			if (stop == 0)
				ft_memcpy(vision->p1, &line[i], ft_strlen(line) - i - 1);
			else if (stop == 1)
				ft_memcpy(vision->p2, &line[i], ft_strlen(line) - i - 1);
			stop++;
			free(line);
			continue ;
		}
		free(line);
	}
}

static void	player_stow(t_vision *vision)
{
	char	*p;

	player_concerned(vision);
	p = vision->p1;
	vision->p1 = ft_strjoin(vision->p1, " ");
	free(p);
	p = vision->p2;
	vision->p2 = ft_strjoin(vision->p2, " ");
	free(p);
}

static int	key_press(int key, t_vision *vision)
{
	if (key == 53 && vision->exit == 0)
	{
		free(vision->p1);
		free(vision->p2);
		exit(0);
	}
	return (0);
}

static int	exit_hook(t_vision *vision)
{
	if (vision->exit == 0)
	{
		free(vision->p1);
		free(vision->p2);
		exit(0);
	}
	return (0);
}

int			main(void)
{
	t_vision	vision;

	vision.score_p1 = 0;
	vision.score_p2 = 0;
	player_stow(&vision);
	init_stack(&(vision.stack));
	probing(&vision);
	vision.mlx_ptr = mlx_init();
	vision.win_ptr = mlx_new_window(vision.mlx_ptr, vision.win_w,
					(vision.win_h + vision.pad + PAD), "Filler ViSion");
	vision.img_ptr = NULL;
	vision.exit = 1;
	vision.pad -= 1;
	gang(&vision);
	mlx_hook(vision.win_ptr, 2, 0, key_press, &vision);
	mlx_hook(vision.win_ptr, 17, 0, exit_hook, &vision);
	mlx_loop_hook(vision.mlx_ptr, reader, &vision);
	mlx_loop(vision.mlx_ptr);
	return (0);
}
