/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygurma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:48:53 by ygurma            #+#    #+#             */
/*   Updated: 2023/05/10 18:18:39 by ygurma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
*	GET_NEXT_LINE
*	-------------
*	DESCRIPTION
*	This function takes an opened file descriptor 
*	and returns its next line.This function has undefined 
*	behavior when reading from a binary file.
*	PARAMETERS
*	#1. A file descriptor 
*	RETURN VALUES
*	If successful, get_next_line returns a string with 
*	the full line ending in a line break (`\n`) when there 
*	is one.If an error occurs, or there's nothing more to 
*	read, it returns NULL.
*	----------------------------------------------------------------------------
*	AUXILIARY FUNCTIONS
*	-------------------
*	READ_TO_LEFTOVER
*	-----------------
*	DESCRIPTION
*	Takes the opened file descriptor and saves on a "buff" 
*	variable what readed from it. Then joins it to the cumulative 
*	static variable for the persistence of the information.
*	PARAMETERS
*	#1. A file descriptor.
*	#2. The pointer to the cumulative static variable from previous runs of
*	get_next_line.
*	RETURN VALUES
*	The new static variable value with buffer joined 
*	for the persistence of the info,or NULL if error.
*/

#include "get_next_line_bonus.h"
#include <unistd.h>
//#include <stdio.h>
//#include <fcntl.h>

char	*ft_read_to_leftover_str(int fd, char *leftover_str)
{
	char	*buff;
	int		rd_bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	rd_bytes = 1;
	while (!ft_strchr(leftover_str, '\n') && rd_bytes != 0)
	{
		rd_bytes = read(fd, buff, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(buff);
			free(leftover_str);
			return (NULL);
		}
		buff[rd_bytes] = '\0';
		leftover_str = ft_strjoin(leftover_str, buff);
	}
	free(buff);
	return (leftover_str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*leftover_str[4096];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	leftover_str[fd] = ft_read_to_leftover_str(fd, leftover_str[fd]);
	if (!leftover_str[fd])
		return (NULL);
	line = ft_get_line(leftover_str[fd]);
	leftover_str[fd] = ft_new_leftover_str(leftover_str[fd]);
	return (line);
}

/*int main(void)
{
    char    *line;
    int     i;
    int     fd1;
    int     fd2;
    int     fd3;

    fd1 = open("test1.txt", O_RDONLY);
    fd2 = open("test2.txt", O_RDONLY);
    fd3 = open("test3.txt", O_RDONLY);
    i = 1;
    while (i < 9)
    {
        line = get_next_line(fd1);
        if (line)
        {
            printf("line [%02d]: %s", i, line);
            free(line);
        }
        else
        {
            printf("Reached end of file for fd1\n");
            close(fd1);
            fd1 = -1;
        }

        line = get_next_line(fd2);
        if (line)
        {
            printf("line [%02d]: %s", i, line);
            free(line);
        }
        else
        {
            printf("Reached end of file for fd2\n");
            close(fd2);
            fd2 = -1;
        }

        line = get_next_line(fd3);
        if (line)
        {
            printf("line [%02d]: %s", i, line);
            free(line);
        }
        else
        {
            printf("Reached end of file for fd3\n");
            close(fd3);
            fd3 = -1;
        }

        if (fd1 == -1 && fd2 == -1 && fd3 == -1)
            break;

        i++;
    }

    return (0);
}*/
