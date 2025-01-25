/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plesukja <plesukja@42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 00:47:21 by plesukja          #+#    #+#             */
/*   Updated: 2025/01/25 10:39:16 by plesukja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif

void	*ft_gnl_calloc(size_t size, size_t count);
int		ft_gnl_strlen(char *s);
char	*ft_gnl_strchr(const char *s, int c);
char	*ft_gnl_strjoin_free(char *s1, char *s2);
char	*get_next_line(int fd);

#endif
