/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsonmez <dsonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 17:58:36 by dsonmez           #+#    #+#             */
/*   Updated: 2024/10/26 18:23:37 by dsonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*mover(char *s, char c)
{
	while (*s == c)
		s++;
	return (s);
}

static int	count_words(char *str, char c)
{
	int	count;

	count = 0;
	while (*str != '\0')
	{
		while (*str == c)
			str++;
		if (*str)
			count += 1;
		while (*str != c && *str)
			str++;
	}
	return (count);
}

static char	**ft_free(char **str, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**new_str;
	int		i;
	int		index;
	int		count;

	i = 0;
	if (!s)
		return (NULL);
	count = count_words((char *)s, c);
	new_str = malloc(sizeof(char *) * (count + 1));
	if (new_str == NULL)
		return (NULL);
	while (i < count)
	{
		s = mover((char *)s, c);
		index = 0;
		while (s[index] != c && s[index])
			index++;
		new_str[i++] = ft_substr(s, 0, index);
		if (new_str[i - 1] == NULL)
			return (ft_free(new_str, i - 1));
		s += index;
	}
	new_str[i] = NULL;
	return (new_str);
}
