/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsonmez <dsonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 18:51:51 by dsonmez           #+#    #+#             */
/*   Updated: 2024/10/18 17:14:47 by dsonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	k;

	i = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0')
	{
		k = 0;
		while (haystack[i + k] == needle[k] && (i + k) < len)
		{
			if (haystack[i + k] == '\0' && needle[k] == '\0')
				return ((char *)&haystack[i]);
			k++;
		}
		if (needle[k] == '\0')
			return ((char *)haystack + i);
		i++;
	}
	return (0);
}
