/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plesukja <plesukja@42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 17:24:26 by plesukja          #+#    #+#             */
/*   Updated: 2025/01/29 17:33:54 by plesukja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_find_new_line(int fd, char *file_read)
{
	int		num_read;
	char	*buffer;

	if (!file_read)
		file_read = ft_gnl_calloc(sizeof(char), 1);
	buffer = ft_gnl_calloc(sizeof(char), BUFFER_SIZE + 1);
	if (!buffer)
		return (free(buffer), free(file_read), (NULL));
	num_read = 1;
	while (num_read > 0)
	{
		num_read = read(fd, buffer, BUFFER_SIZE);
		if (num_read == 0)
			break ;
		if (num_read == -1)
			return (free(buffer), free(file_read), (NULL));
		buffer[num_read] = '\0';
		file_read = ft_gnl_strjoin_free(file_read, buffer);
		if (ft_gnl_strchr(buffer, '\n'))
			break ;
	}
	return (free(buffer), file_read);
}

static char	*ft_extract_line(char *file_read)
{
	char	*result;
	int		index;

	index = 0;
	if (!file_read[index])
		return (NULL);
	while (file_read[index] && file_read[index] != '\n')
		index++;
	result = ft_gnl_calloc(sizeof(char), index + 2);
	if (!result)
		return (NULL);
	index = 0;
	while (file_read[index] && file_read[index] != '\n')
	{
		result[index] = file_read[index];
		index++;
	}
	if (file_read[index] && file_read[index] == '\n')
	{
		result[index] = file_read[index];
		index++;
	}
	return (result);
}

static char	*ft_get_remain(char *file_read)
{
	int		index;
	int		result_index;
	char	*result;

	index = 0;
	while (file_read[index] && file_read[index] != '\n')
		index++;
	if (!file_read[index])
		return (free(file_read), (NULL));
	result = ft_gnl_calloc(sizeof(char), ft_gnl_strlen(file_read) - index + 1);
	if (!result)
		return (free(file_read), (NULL));
	index++;
	result_index = 0;
	while (file_read[index])
	{
		result[result_index] = file_read[index];
		result_index++;
		index++;
	}
	free(file_read);
	return (result);
}

char	*get_next_line(int fd)
{
	static char	*file_read;
	char		*extract_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	file_read = ft_find_new_line(fd, file_read);
	if (!file_read)
		return (NULL);
	extract_line = ft_extract_line(file_read);
	file_read = ft_get_remain(file_read);
	return (extract_line);
}

// #include <fcntl.h>
// #include <stdio.h>
// int	main(void)
// {
// 	int	fd;
// 	fd = open ("/get_next_line_github/test.txt", O_RDONLY);
// 	if (fd == -1)
// 	{
//         perror("Error opening file");
//         return 1;
//     }
// 	printf("%s", get_next_line(fd));
// }
