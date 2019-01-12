/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obtain_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesafi <mesafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 19:12:19 by mesafi            #+#    #+#             */
/*   Updated: 2019/11/20 15:54:40 by mesafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"

static int	token_dimensions(t_fill *data, int *width, int *height)
{
	char	*line;
	char	*tmp;

	if (get_next_line(0, &line) != 1)
		return (error_handler(data, data->height, 0, -1));
	tmp = line;
	while (!(ft_isdigit(*tmp)))
		tmp++;
	*height = ft_atoi(tmp);
	while (ft_isdigit(*tmp))
		tmp++;
	*width = ft_atoi(tmp);
	free(line);
	return (0);
}

static void	free_token(char **token, int units)
{
	int		i;

	i = -1;
	while (++i < units)
		free(token[i]);
	free(token);
}

static char	**stow_token(t_fill *data, int columns, int lines)
{
	char	**token;
	int		i;
	int		j;

	i = -1;
	if (!(token = (char **)malloc(lines * sizeof(char *))))
		return (NULL);
	while (++i < lines)
	{
		if (get_next_line(0, &token[i]) <= 0)
		{
			free_token(token, i);
			return (NULL);
		}
		j = -1;
		while (++j < columns)
		{
			if (token[i][j] == '*')
				data->units += 1;
		}
	}
	return (token);
}

static void	reduplicate(t_fill *data, int lines, int columns, char **token)
{
	int		i;
	int		temporal;

	i = -1;
	while (--lines >= 0)
	{
		temporal = columns;
		while (--temporal >= 0)
		{
			if (token[lines][temporal] == '*')
			{
				i += 1;
				data->token[i].line = lines;
				data->token[i].column = temporal;
			}
		}
	}
}

int			obtain_token(t_fill *data)
{
	char	**token;
	int		width;
	int		height;

	if (token_dimensions(data, &width, &height) == -1)
		return (-1);
	if (!(token = stow_token(data, width, height)))
		return (error_handler(data, data->height, 0, -1));
	if (!(data->token = (t_cord *)malloc(data->units * sizeof(t_cord))))
	{
		free_token(token, height);
		return (error_handler(data, data->height, 0, -1));
	}
	reduplicate(data, height, width, token);
	free_token(token, height);
	return (0);
}
