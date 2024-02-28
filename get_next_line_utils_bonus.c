/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asargsya <asargsya@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 10:58:50 by asargsya          #+#    #+#             */
/*   Updated: 2024/02/27 10:58:51 by asargsya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *s)
{
	size_t	len;

	len = 0;
	if (!s)
		return (0);
	while (*s++)
		len++;
	return (len);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res_str;
	size_t	index1;
	size_t	index2;

	index1 = 0;
	index2 = 0;
	if (!s1)
	{
		s1 = malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	res_str = malloc ((ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!res_str)
		return (0);
	while (s1[index1] != '\0')
	{
		res_str[index1] = s1[index1];
		index1++;
	}
	while (s2[index2] != '\0')
		res_str[index1++] = s2[index2++];
	res_str[index1] = '\0';
	free(s1);
	return (res_str);
}

char	*ft_strcpy(char *dest, const char *src)
{
	int		index;

	index = 0;
	while (src[index] != '\n' && src[index])
	{
		dest[index] = src[index];
		index++;
	}
	if (src[index] == '\n')
		dest[index++] = '\n';
	dest[index] = '\0';
	return (dest);
}

char	*ft_strchr(const char *s, int c)
{
	int		index;

	index = 0;
	while (s[index] != '\0')
	{
		if (s[index] == (char)c)
			return ((char *)s + index);
		index++;
	}
	if (s[index] == (char)c)
		return ((char *)s + index);
	return (0);
}
