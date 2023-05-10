/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygurma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:12:30 by ygurma            #+#    #+#             */
/*   Updated: 2023/04/22 07:25:17 by ygurma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
*	---------
*	GET_LINE
*	---------
*	Extracts the line (ending in either line 
*	break and `\0` or only `\0` in EOF)from static variable.
*	PARAMETERS
*	#1. The pointer to the cumulative static 
*	variable from previous runs of get_next_line.
*	RETURN VALUES
*	The string with the full line ending in a line break (`\n`) + (`\0`).
*	-------------
*	NEW_LEFTOVER_STR
*	-------------
*	Stores in the cumulative static variable the new updated variable 
*	with whatever is left from the original, minus the line extracted.
*	PARAMETERS
*	#1. The pointer to the cumulative static 
*	variable from previous runs of get_next_line.
*	RETURN VALUES
*	The new updated string with whatever is left from 
*	the original static, minus the line extracted.
*/

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

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
