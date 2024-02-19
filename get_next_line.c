/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asargsya <asargsya@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 09:38:22 by asargsya          #+#    #+#             */
/*   Updated: 2024/02/16 09:38:23 by asargsya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *ft_read_a_little(int fd, const char *str)
{
    /*
    mallocs buff_size + 1
    reads and copies the content to malloced str
    then gives that str to a new line 
    frees the malloced space
    */

    int     bytes_read;
    char    *buffer;
 
    buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!buffer)
        return (NULL);
    bytes_read = 1;
    while (!end_of_line(buffer))
    {
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        if (bytes_read < 0)
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

char    *ft_get_whats_left(int fd, const char *str)
{
    // RETURNS THE REMAINING PART OF THE LINE
    int index;
    int str_len;
    int new_index;
    char *string1;

    index = 0;
    new_index = 0;
    str_len = ft_strlen(str);
    while (str[index] && str[index] != '\n')
        index++;
    string1 = (char *)malloc(sizeof(char) * ((str_len - index) + 1));
    if (!string1)
        return (NULL);
    index++;
    while (str[index])
        string1[new_index++] = str[index++];
    string1[new_index] = '\0';
    free(str);
    return (string1);
}

char *get_next_line(int fd)
{
    static char *current_line;
    char *line_to_read;
    int index;

    line_to_read = NULL;
    index = 0;
    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    current_line = ft_read_a_little(fd, current_line);
    if (!current_line)
        return (NULL);
    if(*current_line)
    {
		while (current_line[index] && current_line[index] != '\n')
			index++;
		line_to_read = (char *)malloc(sizeof(char) * (index + 2));
		if (!line_to_read)
			return (NULL);
		line_to_read = ft_strcpy(line_to_read, current_line);
	}
	current_line = ft_reminder(current_line);
	return (line_to_read);
}
