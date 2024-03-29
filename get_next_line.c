/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asargsya <asargsya@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 09:38:22 by asargsya          #+#    #+#             */
/*   Updated: 2024/02/27 10:37:31 by asargsya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	static char	*current_line;
	char		*line_to_read;
	int			index;

	line_to_read = NULL;
	index = 0;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(current_line);
		current_line = NULL;
		return (NULL);
	}
	current_line = ft_read_a_little(fd, current_line);
	null_check(current_line);
	if (*current_line)
	{
		while (current_line[index] && current_line[index] != '\n')
			index++;
		line_to_read = malloc(sizeof(char) * (index + 2));
		null_check(line_to_read);
		line_to_read = ft_strcpy(line_to_read, current_line);
	}
	current_line = ft_get_whats_left(current_line);
	return (line_to_read);
}
