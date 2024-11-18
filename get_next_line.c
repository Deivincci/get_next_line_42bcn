/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoral-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 10:43:45 by dmoral-p          #+#    #+#             */
/*   Updated: 2024/03/14 11:57:11 by dmoral-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

static char *ft_record(char *buffer, char *line)
{
    int len;
    int i;
    int j;
    char *remind;

    if (!line)
    {
        free(buffer);
        return (NULL);
    }

    i = 0;
    while (line[i])
        ++i;
    len = ft_strlen(&buffer[i]) + 1;
    remind = (char *)malloc(sizeof(char) * len);
    if (!remind)
	{
		free(buffer);
        return (NULL);
	}
    j = 0;
    while (buffer[i])
        remind[j++] = buffer[i++];
    remind[j] = '\0';
    free(buffer);
    return (remind);
}

static char *ft_line(char *buffer)
{
    char *line;
    char *end;
    int len;
    int i;

    end = ft_strchr(buffer, '\n');
    if (!end)
        return (ft_strdup(buffer));
    len = (end - buffer) + 2;
    line = (char *)malloc(sizeof(char) * len);
    if (!line)
        return (NULL);
    i = 0;
    while (&buffer[i] != end + 1)
    {
        line[i] = buffer[i];
        ++i;
    }
    line[i] = '\0';
    if (ft_strlen(line) == 0)
        return (NULL);
    return (line);
}

static char *ft_read_file(char *buffer, int fd)
{
    char *read_buf;
    int bytes_read;

    read_buf = (char *)malloc((sizeof(char) * BUFFER_SIZE) + 1);
    if (!read_buf)
	{
		free(buffer);
        return (NULL);
	}
    ft_bzero(read_buf, BUFFER_SIZE + 1);
    bytes_read = 1;
    while (bytes_read > 0)
    {
        bytes_read = read(fd, read_buf, BUFFER_SIZE);
        if (bytes_read == -1)
        {
            free(read_buf);
            free(buffer);
            return (NULL);
        }
        buffer = ft_strjoin(buffer, read_buf);
        if (ft_strchr(buffer, '\n') || buffer == NULL)
            break;
    }
    free(read_buf);
    return (buffer);
}

char *get_next_line(int fd)
{
    static char *buffer;
    char *line;

    if (fd < 0 || BUFFER_SIZE == 0)
        return (NULL);
    if (!buffer)
    {
        buffer = (char *)malloc(sizeof(char) * 1);
        if (!buffer)
            return (NULL);
        buffer[0] = '\0';
    }
    buffer = ft_read_file(buffer, fd);
    if (!buffer)
        return (NULL);
    if (ft_strlen(buffer) == 0)
    {
        free(buffer);
        buffer = NULL;
        return (NULL);
    }
    line = ft_line(buffer);
    buffer = ft_record(buffer, line);
    return (line);
}
/*
int main(int argc, char *argv[])
{
    int		fd;
    char	*line;

    if (argc != 2)
    {
        printf("Uso: %s <archivo>\n", argv[0]);
        return (1);
    }
    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
    {
        perror("Error al abrir el archivo");
        return (1);
    }
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s\n", line);
        free(line);
    }
    close(fd);
    return (0);
}*/
