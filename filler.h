/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesafi <mesafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 22:31:54 by mesafi            #+#    #+#             */
/*   Updated: 2019/11/20 14:56:47 by mesafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H

/*
	** Definitions
*/

# define FILLER_H

# define S_SIGN(S) (S == 'O' ? 'X' : 'O')

/*
	** Includes
*/

# include "libft/libft.h"

/*
	** Structures
*/

typedef struct	s_cord
{
	int				line;
	int				column;
}				t_cord;

typedef struct	s_plot
{
	char			value;
	int				score;
}				t_plot;

typedef struct	s_fill
{
	char			player;
	t_plot			**map;
	int				width;
	int				height;
	t_queue			queue;
	t_cord			*token;
	int				units;
	t_stack			scope;
	t_cord			result;
	int				score;
}				t_fill;

/*
	** Functions Prototypes
*/

int				map_reader(t_fill *data);
int				player_concerned(t_fill *data);
int				obtain_token(t_fill *data);
void			make_heatmap(t_fill *data);
void			find_out(t_fill *data);
int				error_handler(t_fill *data, int map_opt,
				int token_opt, int respond);

#endif
