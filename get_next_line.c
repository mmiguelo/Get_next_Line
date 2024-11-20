/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiguelo <mmiguelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 11:02:46 by mmiguelo          #+#    #+#             */
/*   Updated: 2024/11/20 14:16:20 by mmiguelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>

char	*read_text(int fd, char *storage)
{
	char	*buffer;
	int		temp;
	
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	temp = 1;
	while (temp != 0)
	{
		temp = read(fd, buffer, BUFFER_SIZE);
		if (temp < 0)
		{
			free (buffer);
			return (NULL);
		}
		storage = ft_strjoin(storage, buffer);
		free (buffer);
		if (strchr(buffer, '\n'))
			break;
	}
	free (buffer);
	return (storage);
}

char	*cut_string(char *storage)
{
	char 	*new;
	size_t	i;

	i = 0;
	if (!storage[i] || !storage)
		return (NULL);
	while (storage[i] && storage[i] != '\n')
		i++;
	new = malloc(sizeof(char) * (i + 2));
	i = 0;
	while (storage[i] && storage[i] != '\n')
	{
		new[i] = storage[i];
		i++;
	}
	if (storage[i] && storage[i] == '\n')
		new[i++] = '\n';
	new[i] = '\0';
	return (new);
}

char	*get_next_line(int fd)
{
	static char	*storage;
	char	*result;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!storage)
	{
		storage = malloc(sizeof(char) * 1);
		storage[0] = '\0';
	}
	storage = read_text(fd, storage);
	if (!storage)
		return (NULL);
	result = cut_string(storage);
	storage = save_remaining(storage);
	return (result);
}

char	*save_remaining(char *storage)
{
	char	*temp;
	int		i;
	int		j;
	
	temp = malloc()
}

int	main(void)
{
	char *line;
	int fd = open("test.txt", O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		printf("%s\n", line);
		free(line);
		line = get_next_line(fd);
	}
	return (0);
}