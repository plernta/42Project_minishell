/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plesukja <plesukja@42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 17:14:35 by plesukja          #+#    #+#             */
/*   Updated: 2024/12/31 13:27:26 by plesukja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_word(char *ptr, char c);
static void	add_word(char **result, char *str, char sep);
static char	*copy_word(char *src, int len);

char	**ft_split(char const *s, char c)
{
	char	*ptr;
	int		word_count;
	char	**result;

	ptr = (char *)s;
	word_count = count_word(ptr, c);
	result = (char **)malloc((word_count + 1) * (sizeof(char *)));
	if (!result)
		return (NULL);
	add_word(result, ptr, c);
	return (result);
}

static int	count_word(char *str, char sep)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != sep && (str[i + 1] == '\0' || str[i + 1] == sep))
			count++;
		i++;
	}
	return (count);
}

static void	add_word(char **result, char *str, char sep)
{
	int	i;
	int	word_index;
	int	word_len;

	i = 0;
	word_index = 0;
	while (str[i])
	{
		if (str[i] != sep)
		{
			word_len = 0;
			while (str[i + word_len] && str[i + word_len] != sep)
				word_len++;
			result[word_index] = copy_word(&str[i], word_len);
			i += word_len;
			word_index++;
		}
		else
			i++;
	}
	result[word_index] = NULL;
}

static char	*copy_word(char *src, int len)
{
	int		i;
	char	*word;

	i = 0;
	word = (char *)malloc((len + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (i < len)
	{
		word[i] = src[i];
		i++;
	}
	word[len] = '\0';
	return (word);
}

// int main(void)
// {
//     char **result = ft_split("0123,4", ',');

//     if (!result)
//     {
//         printf("Error in ft_split\n");
//         return 1;
//     }
//     for (int i = 0; result[i] != NULL; i++)
//     {
//         printf("Result[%d]: %s\n", i, result[i]);
//     }
//     for (int i = 0; result[i] != NULL; i++)
//     {
//         free(result[i]);
//     }
//     free(result);
//     return 0;
// }
