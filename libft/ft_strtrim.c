/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsonmez <dsonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 15:34:10 by dsonmez           #+#    #+#             */
/*   Updated: 2024/10/18 20:01:01 by dsonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s2;
	int		i;
	int		end;
	int		k;

	end = (int)ft_strlen(s1);
	i = 0;
	k = 0;
	if (s1 == NULL || set == NULL)
		return (NULL);
	while (s1[i] != '\0' && ft_strchr(set, s1[i]))
		i++;
	while (end > i && ft_strchr(set, s1[end -1]))
		end--;
	s2 = malloc(sizeof(char) * (end - i + 1));
	if (s2 == NULL)
		return (NULL);
	while (i < end)
	{
		s2[k] = s1[i];
		i++;
		k++;
	}
	s2[k] = '\0';
	return (s2);
}
