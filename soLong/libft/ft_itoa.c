/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsonmez <dsonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 20:02:05 by dsonmez           #+#    #+#             */
/*   Updated: 2024/10/24 21:34:40 by dsonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_len(int c)
{
	int	i;

	i = 0;
	if (c <= 0)
	{
		i = 1;
		c *= -1;
	}
	while (c != 0)
	{
		c /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*ito_string;
	long	temp;
	int		i;

	i = get_len(n);
	temp = n;
	ito_string = (char *)malloc(sizeof(char) * (i + 1));
	if (ito_string == NULL)
		return (NULL);
	if (temp < 0)
		temp *= -1;
	i -= 1;
	while (i > 0 && temp > 0)
	{
		ito_string[i] = (temp % 10) + 48;
		temp /= 10;
		i--;
	}
	if (n >= 0)
		ito_string[0] = temp + 48;
	else
		ito_string[0] = '-';
	ito_string[get_len(n)] = '\0';
	return (ito_string);
}
