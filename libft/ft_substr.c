/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsonmez <dsonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 20:36:35 by dsonmez           #+#    #+#             */
/*   Updated: 2024/10/18 17:24:06 by dsonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*s2;
	size_t	size;
	size_t	i;

	size = ft_strlen(s);
	i = 0;
	if (start >= size)
		return (ft_strdup(""));
	if (start + len > size)
		len = size - start;
	s2 = (char *)malloc(sizeof(char) * (len + 1));
	if (s2 == NULL)
	{
		return (NULL);
	}
	if (start < size)
	{
		while (i < len)
		{
			s2[i] = s[start + i];
			i++;
		}
		s2[i] = '\0';
	}
	return (s2);
}
