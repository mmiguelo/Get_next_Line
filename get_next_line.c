/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiguelo <mmiguelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 11:02:46 by mmiguelo          #+#    #+#             */
/*   Updated: 2024/11/20 19:15:22 by mmiguelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_text(int fd, char *storage)
{
	char	*buffer;
	int		nbytes;
	
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	nbytes = 1;
	while (nbytes != 0)
	{
		nbytes = read(fd, buffer, BUFFER_SIZE);
		if (nbytes == 0 || nbytes == -1)
		{
			return (NULL);
			free (buffer);
		}
		storage = ft_strjoin(storage, buffer);
		buffer[nbytes] = '\0';
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
	size_t	j;

	i = 0;
	j = 0;
	if (!storage[i] || !storage)
		return (NULL);
	while (storage[i] != '\n' && storage[i])
		i++;
	new = malloc(sizeof(char) * i + 2);
	while (j < i + 1)
	{
		new[j] = storage[j];
		j++;
	}
	new[j] = '\0';
	// while (storage[i] && storage[i] != '\n')
	// {
		// new[i] = storage[i];
		// i++;
	// }
	// if (storage[i] && storage[i] == '\n')
		// new[i++] = '\n';
	// new[i] = '\0';
	return (new);
}

char	*save_remaining(char *storage)
{
	char		*temp;
	size_t		i;
	size_t		j;
	
	i = ft_strlen(storage, '\n');
	j = ft_strlen(storage, '\0');
	temp = malloc(sizeof(char) * (j - i));
	j = 0;
	while (storage[++i] != '\0')
	{
		temp[j] = storage[i];
		i++;
		j++;
	}
	temp[j] = '\0';
	return (temp);
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

int	main(void)
{
	char *line;
	int fd = open("test.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	line = get_next_line(fd);
	return (0);
}