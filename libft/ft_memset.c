/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsonmez <dsonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 21:05:30 by dsonmez           #+#    #+#             */
/*   Updated: 2024/10/18 17:17:10 by dsonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*s;
	unsigned char	m;
	size_t			i;

	i = 0;
	s = (unsigned char *)b;
	m = (unsigned char)c;
	while (i < len)
	{
		s[i] = m;
		i++;
	}
	return (s);
}
