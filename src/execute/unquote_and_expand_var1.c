/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unquote_and_expand_var1.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plesukja <plesukja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 20:41:27 by plesukja          #+#    #+#             */
/*   Updated: 2025/02/04 14:55:11 by plesukja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*unquote_and_expand_var(char *s, t_shell *shell)
{
	char	*result;

	result = ft_calloc(1, sizeof(char));
	if (!result)
		return (NULL);
	while (*s)
	{
		if (*s == '\'')
			single_quote_handler(&s, &result);
		else if (*s == '"')
			double_quote_handler(&s, &result, shell);
		else if (*s == '$')
			dollar_sign_handler(&s, &result, shell);
		else
			character_handler(&s, &result);
	}
	return (result);
}

static char	*var_expansion_cont(char **s, t_shell *shell, int var_name_len)
{
	char	*var_value;
	char	*var_name;
	char	*result;

	result = NULL;
	var_name = ft_substr(*s, 0, var_name_len);
	var_value = ft_getenv(shell->env, var_name);
	free (var_name);
	if (!var_value)
	{
		*s += var_name_len;
		return (ft_strdup(""));
	}
	*s += var_name_len;
	result = ft_strdup(var_value);
	free(var_value);
	return (result);
}

char	*var_expansion(char **s, t_shell *shell)
{
	int		var_name_len;

	*s += 1;
	if (ft_strchr("\'\"$ \0", (*s)[0]))
		return (ft_strdup("$"));
	if ((*s)[0] == '?')
	{
		*s += 1;
		return (ft_itoa(shell->exit_status));
	}
	var_name_len = 0;
	while (!ft_strchr("'\"$ ", (*s)[var_name_len]) && (*s)[var_name_len])
		var_name_len++;
	return (var_expansion_cont(s, shell, var_name_len));
}

//edited
// char	*var_expansion(char **s, t_shell *shell)
// {
// 	char	*var_value;
// 	char	*var_name;
// 	int		var_name_len;
// 	char	*result;

// 	*s += 1;
// 	result = NULL;
// 	if (ft_strchr("\'\"$ \0", (*s)[0]))
// 		return (ft_strdup("$"));
// 	if ((*s)[0] == '?')
// 	{
// 		*s += 1;
// 		return (ft_itoa(shell->exit_status));
// 	}
// 	var_name_len = 0;
// 	while (!ft_strchr("'\"$ ", (*s)[var_name_len]) && (*s)[var_name_len])
// 		var_name_len++;
// 	var_name = ft_substr(*s, 0, var_name_len);
// 	var_value = ft_getenv(shell->env, var_name);
// 	free (var_name);
// 	if (!var_value)
// 	{
// 		*s += var_name_len;
// 		return (ft_strdup(""));
// 	}
// 	*s += var_name_len;
// 	result = ft_strdup(var_value);
// 	free(var_value);
// 	return (result);
// }

//original
// char	*var_expansion(char **s, t_shell *shell)
// {
// 	char	*var_value;
// 	char	*var_name;
// 	int		var_name_len;

// 	*s += 1;
// 	if (ft_strchr("\'\"$ \0", (*s)[0]))
// 		return (ft_strdup("$"));
// 	if ((*s)[0] == '?')
// 	{
// 		*s += 1;
// 		return (ft_itoa(shell->exit_status));
// 	}
// 	var_name_len = 0;
// 	while (!ft_strchr("'\"$ ", (*s)[var_name_len]) && (*s)[var_name_len])
// 		var_name_len++;
// 	var_name = ft_substr(*s, 0, var_name_len);
// 	var_value = ft_getenv(shell->env, var_name);
// 	free (var_name);
// 	if (!var_value)
// 	{
// 		*s += var_name_len;
// 		return (ft_strdup(""));
// 	}
// 	*s += var_name_len;
// 	return (ft_strdup(var_value));
// }