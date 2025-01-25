/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plesukja <plesukja@42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 16:46:03 by plesukja          #+#    #+#             */
/*   Updated: 2025/01/24 23:07:17 by plesukja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_signal;

void	restore_prompt(int signum)
{
	if (signum == SIGINT)
	{
		g_signal = 130;
		write(STDOUT_FILENO, "\n", 1);
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
}

static void	ctrl_c(int signum)
{
	(void)signum;
	g_signal = 130;
	write(STDOUT_FILENO, "\n", 1);
}

static void	back_slash(int signum)
{
	(void)signum;
	g_signal = 131;
	write(STDERR_FILENO, "Quit: 3\n", 8);
}

// run_signals(1) For restoring prompt behavior // before command is executed
// run_signals(2) For normal signal handling // while executing command
// run_signals(3) For exit handling
// SIGINT ^C
// SIGQUIT ^\
// EOF ^D

void	run_signals(int sig, t_shell *shell)
{
	(void)shell;
	if (sig == 1)
	{
		signal(SIGINT, restore_prompt);
		signal(SIGQUIT, SIG_IGN);
	}
	else if (sig == 2)
	{
		signal(SIGINT, ctrl_c);
		signal(SIGQUIT, back_slash);
	}
}
