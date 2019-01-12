/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   top_bar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesafi <mesafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 23:07:32 by mesafi            #+#    #+#             */
/*   Updated: 2019/11/22 23:35:06 by mesafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vision.h"

void	top_bar(t_vision *vision)
{
	char	*p;
	char	*n;

	n = ft_itoa(vision->score_p1);
	p = ft_strjoin(vision->p1, n);
	mlx_string_put(vision->mlx_ptr, vision->win_ptr, 15, 4, WH, p);
	free(n);
	free(p);
	n = ft_itoa(vision->score_p2);
	p = ft_strjoin(vision->p2, n);
	mlx_string_put(vision->mlx_ptr, vision->win_ptr, vision->win_w -
				(15 + (ft_strlen(p) * 10)), 4, WH, p);
	free(n);
	free(p);
}
