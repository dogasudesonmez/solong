/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsonmez <dsonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 15:20:05 by dsonmez           #+#    #+#             */
/*   Updated: 2024/10/20 19:58:25 by dsonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	int		len_s1;
	int		len_s2;
	int		i;

	i = 0;
	len_s1 = (int)ft_strlen(s1);
	len_s2 = (int)ft_strlen(s2);
	new_str = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (new_str == NULL)
		return (NULL);
	while (*s1 != '\0')
	{
		new_str[i] = *s1;
		i++;
		s1++;
	}
	while (*s2 != '\0')
	{
		new_str[i] = *s2;
		i++;
		s2++;
	}
	new_str[i] = '\0';
	return (new_str);
}
