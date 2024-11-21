/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiguelo <mmiguelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 11:03:04 by mmiguelo          #+#    #+#             */
/*   Updated: 2024/11/21 11:55:44 by mmiguelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str, char c)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != c)
		i++;
	return (i);
}
char	*ft_strlcpy(char *dst, char *src, size_t size)
{
	size_t	i;
	size_t	length;

	(void)length;
	if (!dst || !src)
		return (0);
	length = ft_strlen(src, '\0');
	if (size == 0)
		return (NULL);
	i = 0;
	while (src[i] && (i < size - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new;
	size_t		s1_length;
	size_t		s2_length;	
	
	if (!s1 || !s2)
		return (NULL);
	s1_length = ft_strlen(s1, '\0');
	s2_length = ft_strlen(s2, '\0');
	new = malloc(sizeof(char) * (s1_length + s2_length +1));
	if (!new)
		return (NULL);
	ft_strlcpy(new, s1, s1_length + 1);
	ft_strlcpy(new + s1_length, s2, s2_length + 1);
	return (new);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*cpy;

	i = 0;
	cpy = (char *)s;
	if (!s)
		return (NULL);
	while (s[i] && s[i] != (char)c)
		i++;
	if (s[i] == (char)c)
		return (cpy + i);
	return (NULL);
}
