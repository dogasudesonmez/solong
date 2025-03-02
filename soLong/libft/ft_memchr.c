/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsonmez <dsonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 17:00:49 by dsonmez           #+#    #+#             */
/*   Updated: 2024/10/23 20:19:23 by dsonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	c2;
	unsigned char	*s2;
	size_t			len;

	c2 = (unsigned char)c;
	s2 = (unsigned char *)s;
	len = 0;
	while (len < n)
	{
		if (*s2 == c2)
		{
			return (s2);
		}
		s2++;
		len++;
	}
	return (0);
}
