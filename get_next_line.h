/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asargsya <asargsya@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 09:38:12 by asargsya          #+#    #+#             */
/*   Updated: 2024/02/16 09:38:14 by asargsya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdlib.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE  1
#endif

char    *get_next_line(int fd);
size_t  ft_strlen(const char *s);
char    *ft_strjoin(const char *s1, const char *s2);
char    *ft_strcpy(char *dest, char *src);
char    *ft_read_a_little(int fd, const char *str);
char    *ft_get_whats_left(int fd, const char *str);

#endif
