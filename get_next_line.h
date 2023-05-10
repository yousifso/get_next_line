/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygurma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:30:46 by ygurma            #+#    #+#             */
/*   Updated: 2023/04/12 15:05:47 by ygurma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

// These functions are used internally 
// by 'get_next_line' to implement its functionality.

// This function takes a file discriptor as an argument
// and returns a line from the file corresponding to that
// discriptor, or 'NULL' if there is an error or the end of the
// file has been reached.
char	*get_next_line(int fd);

// calculate the length of a null-terminated string.
size_t	ft_strlen(char *str);

// search a string for a specific character and returns
// a pointer to the first occurrrence of that character 
// or 'NULL' if the character is not found.
char	*ft_strchr(char *s, int c);

// concatenate two null-terminated string and return the result.
char	*ft_strjoin(char *leftover_str, char *buff);

// creates a new string containing the contents of the input
// string after the first occurrence of a newline character 
// or an empty string if no new line is found.
char	*ft_new_leftover_str(char *leftover_str);

// returns a new string containing the character 
// upto the first occurrence of a newline character in 
// the input string, or the entire input string if 
// no newline is found.
char	*ft_get_line(char *leftover);

// reads data from the file discriptor into a buffer
// and appends it to an existing letover string,
// returning the resulting string . if a newline
// character is encounterd in the input data
// the function stops reading and returns the 
// string up to the newline character.
char	*ft_read_to_leftover(int fd, char *leftover);

#endif
