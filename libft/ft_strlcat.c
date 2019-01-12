/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesafi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 22:24:10 by mesafi            #+#    #+#             */
/*   Updated: 2019/04/05 01:46:31 by mesafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		dlen;
	size_t		slen;

	dlen = ft_strlen(dst);
	slen = ft_strlen(src);
	if (size > dlen)
	{
		ft_memccpy(dst + dlen, src, 0, size - dlen - 1);
		*(dst + size - 1) = '\0';
	}
	return (size < dlen ? size + slen : slen + dlen);
}
