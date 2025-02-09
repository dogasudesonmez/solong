/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsonmez <dsonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 20:32:23 by dsonmez           #+#    #+#             */
/*   Updated: 2024/10/26 18:27:54 by dsonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*dst2;
	char		*src2;

	i = 0;
	dst2 = (char *)dst;
	src2 = (char *)src;
	if (!dst && !src)
		return (NULL);
	if (dst == src)
		return (dst);
	while (i < n)
	{
		dst2[i] = src2[i];
		i++;
	}
	return (dst2);
}
