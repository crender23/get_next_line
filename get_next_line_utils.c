/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crender <crender@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 02:01:11 by crender           #+#    #+#             */
/*   Updated: 2021/12/03 06:05:51 by crender          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char	*str)
{
	size_t	i;

	i = 0;
	while (*(str + i) != '\0')
		i++;
	return (i);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*a;
	char	*z;

	a = (char *) dst;
	z = (char *) src;
	if (!a || !z)
		return (0);
	while (n--)
		*a++ = *z++;
	*a = '\0';
	return (dst);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*a;
	char	*b;

	a = (char *) src;
	b = (char *) dst;
	if (!a && !b)
		return (0);
	if (b < a)
		ft_memcpy(dst, src, len);
	else
	{
		while (len--)
			*(b + len) = *(a + len);
	}
	return (dst);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	len1;
	size_t	len2;

	if (!s1)
	{
		s1 = (char *) malloc(sizeof(char));
		*s1 = '\0';
	}
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	str = (char *) malloc((len1 + len2 + 1) * sizeof(char));
	if (str)
	{
		ft_memcpy(str, s1, len1);
		ft_memmove(str + len1, s2, len2);
		*(str + len1 + len2) = '\0';
	}
	free((char *) s1);
	return (str);
}
