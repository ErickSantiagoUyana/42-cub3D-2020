/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euyana-b <euyana-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 22:37:35 by erick             #+#    #+#             */
/*   Updated: 2019/12/18 15:28:08 by euyana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content)
{
	t_list *newlist;

	if (!(newlist = malloc(sizeof(t_list))))
		return (0);
	if (!(newlist->content = malloc(sizeof(content))))
		return (0);
	newlist->content = (void *)content;
	newlist->next = NULL;
	return (newlist);
}
