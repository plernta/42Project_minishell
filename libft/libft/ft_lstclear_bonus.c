/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plesukja <plesukja@42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 16:13:46 by plesukja          #+#    #+#             */
/*   Updated: 2024/03/06 11:18:41 by plesukja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if ((!(*lst)) || !del)
		return ;
	while (*lst)
	{
		tmp = *lst;
		*lst = tmp->next;
		(del)(tmp->content);
		free(tmp);
	}
	*lst = NULL;
}
