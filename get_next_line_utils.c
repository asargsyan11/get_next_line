/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asargsya <asargsya@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 09:38:30 by asargsya          #+#    #+#             */
/*   Updated: 2024/02/16 09:38:31 by asargsya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		s2_index;
	int		index;
	char	*joined_str;

	if (!s1 || !s2)
		return (NULL);
	joined_str = (char *)malloc(sizeof(char)
			* (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (joined_str == NULL)
		return (NULL);
	index = 0;
	while (*(s1 + index) != '\0')
	{
		*(joined_str + index) = *(s1 + index);
		index++;
	}
	s2_index = 0;
	while (*(s2 + s2_index) != '\0')
	{
		*(joined_str + index) = *(s2 + s2_index);
		s2_index++;
		index++;
	}
	*(index + joined_str) = '\0';
	return (joined_str);
}

char	*ft_strcpy(char *dest, char *src)
{
	int		i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int end_of_line(const char *str)
{
    int index;

    index = 0;
    while (str + index)
    {
        if (str[index] == '\n')
            return (1);
        index++;
    }
    return (0);
}