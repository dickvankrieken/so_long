/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kri <dvan-kri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/23 20:18:59 by dvan-kri      #+#    #+#                 */
/*   Updated: 2021/08/13 10:45:40 by dvan-kri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlist;
	t_list	*element;

	if (!f || !lst)
		return (NULL);
	newlist = ft_lstnew((*f)(lst->content));
	if (newlist == NULL)
		return (NULL);
	lst = lst->next;
	while (lst)
	{
		element = ft_lstnew((*f)(lst->content));
		if (!element)
		{
			ft_lstclear(&newlist, del);
			newlist = NULL;
			return (NULL);
		}
		ft_lstadd_back(&newlist, element);
		lst = lst->next;
	}
	return (newlist);
}
