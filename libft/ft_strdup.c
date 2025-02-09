/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsonmez <dsonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 19:08:31 by dsonmez           #+#    #+#             */
/*   Updated: 2024/10/18 17:20:01 by dsonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dup;
	char	*s2;
	size_t	i;
	size_t	k;

	s2 = (char *)s1;
	i = ft_strlen(s2);
	k = 0;
	dup = (char *)malloc(sizeof(char) * (i + 1));
	if (dup == NULL)
	{
		return (NULL);
	}
	while (k <= i && s2[k])
	{
		dup[k] = s2[k];
		k++;
	}
	dup[k] = '\0';
	return (dup);
}
