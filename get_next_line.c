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
        
    }
}

char    *ft_get_whats_left(int fd, const char *str)
{
    // RETURNS THE REMAINING PART OF THE LINE
}

char *get_next_line(int fd)
{
    static char *current_line;

}
