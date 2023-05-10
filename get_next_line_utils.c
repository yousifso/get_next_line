/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygurma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 20:16:38 by ygurma            #+#    #+#             */
/*   Updated: 2023/05/04 23:32:23 by ygurma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//This function calculates the length 
//of a string by iterating over the characters 
//of the string until it encounters the null terminator 
//character ('\0'). If the string is null, it returns 0.
size_t	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

//This function searches for the first occurrence 
//of a character (c) in a string (s) and returns 
//a pointer to that character. If the character 
//is not found, it returns null. If the character 
//is null, it returns a pointer to the end of the string.
char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

//This function concatenates two strings 
//(leftover and buff) and returns a new 
//string that contains the result. If either 
//of the input strings is null, it returns null. 
//It first allocates memory for the new string 
//based on the sum of the lengths of the two 
//input strings plus one for the null terminator. 
//Then, it copies the characters of the leftover 
//string to the new string and then the characters of the buff string.
char	*ft_strjoin(char *leftover_str, char *buff)
{
	size_t	i;
	size_t	j;
	char	*str;	

	if (!leftover_str)
	{
		leftover_str = (char *)malloc(1 * sizeof(char));
		leftover_str[0] = '\0';
	}
	if (!leftover_str || !buff)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(leftover_str)
					+ ft_strlen(buff)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (leftover_str)
		while (leftover_str[++i] != '\0')
			str[i] = leftover_str[i];
	while (buff[j] != '\0')
		str[i++] = buff[j++];
	str[ft_strlen(leftover_str) + ft_strlen(buff)] = '\0';
	free(leftover_str);
	return (str);
}

//This function extracts a line from the input 
//string (leftover) up to the first newline 
//character ('\n') and returns it as a new string. 
//If the input string is null or does not contain 
//a newline character, it returns null. It first finds 
//the position of the newline character (if it exists) 
//by iterating over the input string. Then, it allocates 
//memory for the new string based on the length of the 
//extracted line plus one for the null terminator. Finally, 
//it copies the characters of the input string 
//up to the newline character to the new string.
char	*ft_get_line(char *leftover_str)
{
	int		i;
	char	*str;

	i = 0;
	if (!leftover_str[i])
		return (NULL);
	while (leftover_str[i] && leftover_str[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (leftover_str[i] && leftover_str[i] != '\n')
	{
		str[i] = leftover_str[i];
		i++;
	}
	if (leftover_str[i] == '\n')
	{
		str[i] = leftover_str[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

//This function extracts the remaining characters 
//after the newline character ('\n') in the input 
//string (leftover) and returns them as a new string. 
//If the input string does not contain a newline character, 
//it frees the input string and returns null. 
//It first finds the position of the newline character by 
//iterating over the input string. Then, 
//it allocates memory for the new string based on the length 
//of the remaining characters plus one for the null terminator. 
//Finally, it copies the remaining characters 
//after the newline character to the new string.
char	*ft_new_leftover_str(char *leftover_str)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (leftover_str[i] && leftover_str[i] != '\n')
		i++;
	if (!leftover_str[i])
	{
		free(leftover_str);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(leftover_str) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (leftover_str[i])
		str[j++] = leftover_str[i++];
	str[j] = '\0';
	free(leftover_str);
	return (str);
}
