/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vision.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesafi <mesafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 18:07:50 by mesafi            #+#    #+#             */
/*   Updated: 2019/11/22 23:16:28 by mesafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISION_H

/*
	** Definitions
*/

# define VISION_H
# define P1 0x2dde98
# define P2 0xffc168
# define LN 0x050f2c
# define WH 0xffffff
# define PAD 30

/*
	** Includes
*/

# include "../libft/libft.h"
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>

/*
	** Structures
*/

typedef struct	s_point
{
	int		x;
	int		y;
}				t_point;

typedef struct	s_scp
{
	int		x;
	int		y;
	char	p;
}				t_scp;

typedef struct	s_vision
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	int		*data;
	int		win_h;
	int		win_w;
	int		pad;
	t_stack	stack;
	int		height;
	int		width;
	int		zoom;
	int		exit;
	char	*p1;
	char	*p2;
	int		score_p1;
	int		score_p2;
	int		out;
}				t_vision;

typedef struct	s_draw
{
	int		delta_x;
	int		delta_y;
	int		slope_error;
	int		step_x;
	int		step_y;
	int		tmp;
}				t_draw;

/*
	** Functions Prototypes
*/

int				reader(t_vision *vision);
void			drawing(t_vision *vision);
void			gang(t_vision *vision);
int				probing(t_vision *vision);
void			top_bar(t_vision *vision);

#endif
