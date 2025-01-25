/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_no_var2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plesukja <plesukja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 15:12:22 by plesukja          #+#    #+#             */
/*   Updated: 2024/12/30 15:15:31 by plesukja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static void	compare_and_swap_node(t_env	**cur, t_env **prev, bool *sorted_env)
{
	t_env	*tmp;

	if (ft_strcmp((*cur)->key, (*cur)->next->key) > 0)
	{
		tmp = (*cur)->next;
		(*cur)->next = tmp->next;
		tmp->next = *cur;
		if (*prev == *cur)
			*prev = tmp;
		else
			(*prev)->next = tmp;
		*cur = tmp;
		*sorted_env = false;
	}
}

void	sort_env(t_env **env)
{
	bool	sorted_env;
	t_env	**cur;
	t_env	**prev;

	if (!env || !*env)
		return ;
	while (1)
	{
		sorted_env = true;
		cur = env;
		prev = env;
		while (*cur && (*cur)->next)
		{
			compare_and_swap_node(prev, cur, &sorted_env);
			prev = &(*cur)->next;
			cur = &(*cur)->next;
		}
		if (sorted_env)
			break ;
	}
}
