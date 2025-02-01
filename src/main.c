/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plesukja <plesukja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 08:37:12 by plesukja          #+#    #+#             */
/*   Updated: 2025/02/01 18:47:46 by plesukja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**get_env_arr(char **arr)
{
	char	**new_arr;
	int		i;

	i = 0;
	while (arr[i])
		i++;
	new_arr = malloc(sizeof(char *) * (i + 1));
	if (!new_arr)
		return (NULL);
	i = 0;
	while (arr[i])
	{
		new_arr[i] = ft_strdup(arr[i]);
		if (!new_arr[i])
		{
			free_array(new_arr);
			return (NULL);
		}
		i++;
	}
	new_arr[i] = NULL;
	return (new_arr);
}

static void	create_env_linked_list(t_env **env, char **envp)
{
	t_env	*env_node;
	t_env	*last;
	int		i;

	last = NULL;
	i = 0;
	while (envp[i])
	{
		env_node = malloc(sizeof(t_env));
		if (!env_node)
		{
			free_env(env);
			return ;
		}
		env_node->key = ft_strndup(envp[i], ft_strchr(envp[i], '=') - envp[i]);
		env_node->value = ft_strdup(ft_strchr(envp[i], '=') + 1);
		env_node->next = NULL;
		if (!(*env))
			*env = env_node;
		else
			last->next = env_node;
		last = env_node;
		i++;
	}
}

static void	init_shell(t_shell **shell, char **envp)
{
	*shell = ft_calloc(1, sizeof(t_shell));
	if (!(*shell))
		exit(EXIT_FAILURE);
	(*shell)->env_arr = get_env_arr(envp);
	create_env_linked_list(&(*shell)->env, envp);
	(*shell)->has_pipe = 0;
	(*shell)->exit_status = 0;
	(*shell)->default_stdin = STDIN_FILENO;
	(*shell)->default_stdout = STDOUT_FILENO;
	(*shell)->in_fd = STDIN_FILENO;
	(*shell)->out_fd = STDOUT_FILENO;
}

int	main(int ac, char **av, char **envp)
{
	t_shell	*shell;
	char	*input;

	(void)ac;
	(void)av;
	shell = NULL;
	input = NULL;
	init_shell(&shell, envp);
	run_signals(1, shell);
	while (get_input(&input, shell) != -1)
	{
		process_input(shell, input);
		restore_fd(shell);
		set_exit_status(shell, g_signal);
		if (!shell->current_cmd)
			free_tree(shell->current_cmd);
		// free_tree(shell->current_cmd);
		shell->current_cmd = NULL;
	}
	if (input)
		free(input);
	clean_and_exit(shell);
	return (0);
}
