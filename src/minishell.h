/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plesukja <plesukja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 08:36:54 by plesukja          #+#    #+#             */
/*   Updated: 2025/02/01 15:14:41 by plesukja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft/libft.h"
#include "../libft/ft_printf/ft_printf.h"
#include "../libft/get_next_line/get_next_line.h"
#include <readline/readline.h> //readline
#include <readline/history.h> //add_history
#include <unistd.h>
#include <signal.h>
#include <stdbool.h> //bool
#include <sys/fcntl.h> //open
#include <errno.h> //errno
#include <sys/stat.h>
#include <sys/types.h> //waitpid
#include <sys/wait.h> //waitpid

#define MAXARGS 10
#define WHITESPACE " \t\r\n\v"
#define SIGN "><|"

extern volatile sig_atomic_t	g_signal;

typedef enum e_cmd_oprt_type
{
	COMMAND,
	REDIR,
	PIPE
}	t_token_type;

typedef struct s_cmd_oprt
{
	t_token_type	type;
}	t_token;

typedef struct s_pipe
{
	t_token_type	type;
	t_token			*left;
	t_token			*right;
}	t_pipe;

typedef struct s_redir
{
	t_token_type	type;
	t_token			*prior_token;
	int				mode;
	char			*file;
	char			*end_file;
	char			*temp_file;
}	t_redir;

typedef struct s_cmd
{
	t_token_type		type;
	char				*av[MAXARGS + 1];
	char				*end_av[MAXARGS + 1];
}	t_cmd;

typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}	t_env;

typedef struct s_shell
{
	char			**env_arr;
	t_env			*env;
	t_token			*current_cmd;
	int				has_pipe;
	int				exit_status;
	int				default_stdin;
	int				default_stdout;
	int				in_fd;
	int				out_fd;
}	t_shell;

//****************/ main
int		get_input(char **line, t_shell *shell);
void	process_input(t_shell *shell, char *input);
bool	build_tree(t_shell *shell, char *input);
t_token	*process_token(char *s);
t_token	*null_terminate(t_token *token);

//****************/ process_token
t_token	*parse_token(char **s, t_token *token, char *end);
t_token	*parse_pipe(char **ptr, char *end);
int		go_get_token_sign(char **ptr, char *end, char **tk_start, \
		char **tk_end);
t_token	*create_pipe_token(t_token *left, t_token *right);
t_token	*create_redir_token(t_token *token, char *file_start, char *file_end, \
		int token_sign);
void	heredoc_get_input(t_redir *redir);

bool	find_next_token(char **ptr, char *end, char *charset);
void	run_input(t_token *token, t_shell *shell);

//****************/ run_input
void	run_command(t_cmd *cmd, t_shell *shell);
void	run_redir(t_redir *redir, t_shell *shell);
void	run_pipe(t_pipe *pipe, t_shell *shell);

//****************/ unquote_and_expand_var
char	*unquote_and_expand_var(char *s, t_shell *shell);
void	single_quote_handler(char **s, char **result);
void	double_quote_handler(char **s, char **result, t_shell *shell);
void	double_quote_dollar_handler(char **s, char **result, t_shell *shell);
void	dollar_sign_handler(char **s, char **result, t_shell *shell);
void	character_handler(char **result, char **s);
char	*var_expansion(char **s, t_shell *shell);
char	*ft_strjoin_free(char *s1, char *s2);
bool	is_empty(char **s);

//****************/ run_command
bool	is_builtin_cmd(char *arg);
void	run_builtin_cmd(t_shell *shell, char **arg);
void	check_args_before_execute(char **args, t_shell *shell);
void	execute(char **args, t_shell *shell);
void	fork_and_execute(char **new_args, t_shell *shell);

//****************/ run_builtin_cmd
void	run_builtin_cd(t_shell *shell, char **args);
void	run_builtin_echo(t_shell *shell, char **args);
void	run_builtin_env(t_shell *shell, t_env *env);
void	run_builtin_exit(t_shell *shell, char **args);
void	run_builtin_pwd(t_shell *shell);
void	run_builtin_unset(t_shell *shell, char **args);
void	run_builtin_export(t_shell *shell, char **args);
void	sort_env(t_env **env);
void	print_sorted_env(t_env **env);
void	add_or_update_env_var(t_env **env, char *var);

//****************/ utils
char	*ft_strndup(char *src, size_t n);
int		ft_strcmp(const char *s1, const char *s2);
int		array_len(char **array);
void	restore_fd(t_shell *shell);

//****************/ clean_and_exit
t_token	*parser_error(char *message, t_token *token);
void	close_fd(t_shell *shell);
void	clean_and_exit(t_shell *shell);
void	error_exit(char *message, t_shell *shell);

//****************/ free
void	free_array(char **array);
void	free_env(t_env **env);
void	free_tree(t_token *token);

//****************/ environment
char	**env_to_arr(t_env *env, char **old_envp);
char	*ft_getenv(t_env *env, char *key);
void	free_tree(t_token *token);

//****************/ signal
void	run_signals(int sig, t_shell *shell);
void	restore_prompt(int signum);
// void	init_signal(void);
// void	sig_handling(int signum);
void	set_exit_status(t_shell *shell, int signum);