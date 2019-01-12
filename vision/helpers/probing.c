/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   probing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesafi <mesafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 19:38:49 by mesafi            #+#    #+#             */
/*   Updated: 2019/11/22 20:12:04 by mesafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vision.h"

static void	dimensions(t_vision *vision, char **line)
{
	char	*tmp;

	tmp = *line;
	while (!(ft_isdigit(*tmp)))
		tmp++;
	vision->height = ft_atoi(tmp);
	while (ft_isdigit(*tmp))
		tmp++;
	vision->width = ft_atoi(tmp);
	ft_strdel(line);
}

static void	init_finger(t_scp *finger, int x, int y)
{
	finger->x = x;
	finger->y = y;
}

static void	map_reader(t_vision *vision, int *score_p1, int *score_p2)
{
	int		i;
	int		j;
	char	*l;
	t_scp	finger;

	i = -1;
	while (++i < vision->height + 1 && get_next_line(0, &l))
	{
		if (i != 0)
		{
			j = 3;
			while (++j < vision->width + 4)
			{
				init_finger(&finger, i - 1, j - 4);
				finger.p = l[j];
				if (l[j] == 'X' || l[j] == 'x' || l[j] == 'O' || l[j] == 'o')
					push(&(vision->stack), ft_lstnew(&finger, sizeof(t_scp)));
				if (l[j] == 'o')
					*score_p1 = 1;
				if (l[j] == 'x')
					*score_p2 = 1;
			}
		}
		ft_strdel(&l);
	}
}

static void	inc_score(t_vision *vision, int score_p1, int score_p2)
{
	if (score_p1 == 1)
		vision->score_p1 += 1;
	if (score_p2 == 1)
		vision->score_p2 += 1;
}

int			probing(t_vision *vision)
{
	char	*line;
	int		score_p1;
	int		score_p2;

	score_p1 = 0;
	score_p2 = 0;
	while (get_next_line(0, &line) == 1)
	{
		if (ft_strstr(line, "fin"))
			vision->exit = 0;
		else if (ft_strstr(line, "Plateau"))
		{
			dimensions(vision, &line);
			vision->zoom = 1080 / vision->width;
			vision->pad = 30;
			vision->win_w = vision->width * vision->zoom + 2;
			vision->win_h = vision->height * vision->zoom + 2;
			map_reader(vision, &score_p1, &score_p2);
			inc_score(vision, score_p1, score_p2);
			return (1);
		}
		free(line);
	}
	return (0);
}
