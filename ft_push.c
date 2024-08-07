/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 06:59:15 by waalexan          #+#    #+#             */
/*   Updated: 2024/07/31 10:16:41 by waalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_b(t_data **a, t_data **b)
{
	t_data	*top;

	if (*a == NULL)
		return ;
	top = ft_pilha_get_top(*a);
	*a = (*a)->next;
	top->next = *b;
	*b = top;
	ft_printf("pb\n");
}

void	ft_push_a(t_data **a, t_data **b)
{
	t_data	*top;

	if (*b == NULL)
		return ;
	top = ft_pilha_get_top(*b);
	*b = (*b)->next;
	top->next = *a;
	*a = top;
	ft_printf("pa\n");
}
