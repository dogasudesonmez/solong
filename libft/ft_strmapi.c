/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsonmez <dsonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 23:32:22 by dsonmez           #+#    #+#             */
/*   Updated: 2024/10/20 19:52:11 by dsonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*new1;

	i = 0;
	new1 = NULL;
	if (!s || !f)
		return (NULL);
	new1 = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (new1 == NULL)
		return (NULL);
	i = 0;
	while (i < ft_strlen(s))
	{
		new1[i] = f(i, s[i]);
		i++;
	}
	new1[i] = '\0';
	return (new1);
}
