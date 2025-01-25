/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plesukja <plesukja@42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 00:17:49 by plesukja          #+#    #+#             */
/*   Updated: 2025/01/24 22:43:11 by plesukja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static bool	has_too_many_arguments(char **args)
{
	return (args[1] && args[2]);
}

static void	handle_cd_error(t_shell *shell, char *msg, char *old_pwd)
{
	if (msg)
	{
		ft_putstr_fd("minishell: cd: ", STDERR_FILENO);
		ft_putendl_fd(msg, STDERR_FILENO);
	}
	else
		perror("minishell: cd");
	if (old_pwd)
		free (old_pwd);
	shell->exit_status = EXIT_FAILURE;
}

//getenv returns a pointer to the value in the env
//getenv returns NULL if there is no match
// chdir: success, zero is returned
// chdir: error, -1 is returned
static int	change_directory(t_shell *shell, char **args, char *old_pwd)
{
	char	*home_dir;

	if (!args[1])
	{
		home_dir = getenv("HOME");
		if (!home_dir || chdir(home_dir) == -1)
		{
			handle_cd_error(shell, NULL, old_pwd);
			return (EXIT_FAILURE);
		}
	}
	else if (chdir(args[1]) == -1)
	{
		handle_cd_error(shell, NULL, old_pwd);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static void	update_path_var(t_env *env, char *old_pwd, char *new_pwd)
{
	char	*node_old_pwd;
	char	*node_new_pwd;

	if (!old_pwd || !new_pwd)
		return ;
	node_old_pwd = ft_strjoin("OLDPWD=", old_pwd);
	node_new_pwd = ft_strjoin("PWD=", new_pwd);
	if (!node_old_pwd || !node_new_pwd)
	{
		free(node_old_pwd);
		free(node_new_pwd);
		return ;
	}
	add_or_update_env_var(&env, node_old_pwd);
	add_or_update_env_var(&env, node_new_pwd);
	free(node_old_pwd);
	free(node_new_pwd);
}

void	run_builtin_cd(t_shell *shell, char **args)
{
	char	*old_pwd;
	char	*new_pwd;

	old_pwd = getcwd(NULL, 0);
	if (!old_pwd)
		return (handle_cd_error(shell, NULL, NULL));
	if (has_too_many_arguments(args))
		return (handle_cd_error(shell, "too many arguments", old_pwd));
	if (change_directory(shell, args, old_pwd) == EXIT_FAILURE)
	{
		shell->exit_status = EXIT_FAILURE;
		return ;
	}
	new_pwd = getcwd(NULL, 0);
	if (!new_pwd)
		return (handle_cd_error(shell, NULL, old_pwd));
	update_path_var(shell->env, old_pwd, new_pwd);
	free(old_pwd);
	free(new_pwd);
	shell->env_arr = env_to_arr(shell->env, shell->env_arr);
	shell->exit_status = EXIT_SUCCESS;
}
