/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 12:17:00 by waalexan          #+#    #+#             */
/*   Updated: 2024/07/31 10:15:51 by waalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_data	*ft_pilha_get_top(t_data *list)
{
	return (list);
}

t_data	*ft_pilha_get_last(t_data *list)
{
	t_data	*tmp;

	while (list)
	{
		tmp = list;
		list = list->next;
	}
	return (tmp);
}

void	ft_reverse_rotate_rotate(t_data **a, t_data **b)
{
	ft_reverse_rotate_a(a, 0);
	ft_reverse_rotate_b(b, 0);
	ft_printf("rrr\n");
}

void	ft_rotate_rotate(t_data **a, t_data **b)
{
	ft_rotate_a(a, 0);
	ft_rotate_b(b, 0);
	ft_printf("rr\n");
}
