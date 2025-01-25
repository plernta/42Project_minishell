/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plesukja <plesukja@42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 14:22:34 by plesukja          #+#    #+#             */
/*   Updated: 2025/01/17 14:40:49 by plesukja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// void print_error(const char *format, ...)
// {
//     va_list args;
//     va_start(args, format);
//     vfprintf(stderr, format, args);
//     va_end(args);
// }

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

int	array_len(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

void	restore_fd(t_shell *shell)
{
	if (shell->default_stdin != STDIN_FILENO)
	{
		dup2(shell->default_stdin, STDIN_FILENO);
		close(shell->default_stdin);
	}
	if (shell->default_stdout != STDOUT_FILENO)
	{
		dup2(shell->default_stdout, STDOUT_FILENO);
		close(shell->default_stdout);
	}
}

char	*ft_strndup(char *src, size_t n)
{
	char		*dest;
	size_t		len;
	size_t		i;

	if (!src)
		return (NULL);
	len = ft_strlen(src);
	if (n < len)
		len = n;
	dest = malloc(len + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
