/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asargsya <asargsya@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 10:58:37 by asargsya          #+#    #+#             */
/*   Updated: 2024/02/28 12:10:51 by asargsya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	null_check(char *str)
{
	if (!str)
		return (0);
	else
		return (1);
}

char	*ft_read_a_little(int fd, char *str)
{
	int		bytes_read;
	char	*buffer;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (NULL);
	buffer[0] = '\0';
	bytes_read = 1;
	while (!(ft_strchr(buffer, '\n')) && bytes_read)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		str = ft_strjoin(str, buffer);
	}
	free(buffer);
	return (str);
}

char	*ft_get_whats_left(char *str)
{
	int		index;
	int		str_len;
	int		new_index;
	char	*string1;

	index = 0;
	new_index = 0;
	str_len = ft_strlen(str);
	while (str[index] && str[index] != '\n')
		index++;
	if (!str[index])
	{
		free(str);
		return (NULL);
	}
	string1 = malloc(sizeof(char) * ((str_len - index) + 1));
	if (!string1)
		return (NULL);
	index++;
	while (str[index])
		string1[new_index++] = str[index++];
	string1[new_index] = '\0';
	free((void *)str);
	return (string1);
}

char	*get_next_line(int fd)
{
	static char	*current_line[OPEN_MAX];
	char		*line_to_read;
	int			index;

	line_to_read = NULL;
	index = 0;
	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX || read(fd, 0, 0) < 0)
	{
		free(current_line[fd]);
		current_line[fd] = NULL;
		return (NULL);
	}
	current_line[fd] = ft_read_a_little(fd, current_line[fd]);
	null_check(current_line[fd]);
	if (*current_line[fd])
	{
		while (current_line[fd][index] && current_line[fd][index] != '\n')
			index++;
		line_to_read = malloc(sizeof(char) * (index + 2));
		null_check(line_to_read);
		line_to_read = ft_strcpy(line_to_read, current_line[fd]);
	}
	current_line[fd] = ft_get_whats_left(current_line[fd]);
	return (line_to_read);
}
