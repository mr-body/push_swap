/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 06:59:15 by waalexan          #+#    #+#             */
/*   Updated: 2024/07/26 09:26:34 by waalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_a(t_data **a)
{
	t_data	*top;
	t_data	*base;

	if (*a == NULL)
		return ;
	top = ft_pilha_get_top(*a);
	base = ft_pilha_get_last(*a);
	*a = (*a)->next;
	base->next = top;
	top->next = NULL;
}

void	ft_rotate_b(t_data **b)
{
	t_data	*top;
	t_data	*base;

	if (*b == NULL)
		return ;
	top = ft_pilha_get_top(*b);
	base = ft_pilha_get_last(*b);
	*b = (*b)->next;
	base->next = top;
	top->next = NULL;
}

void	ft_rotate_rotate(t_data **a, t_data **b)
{
	ft_rotate_a(a);
	ft_rotate_b(b);
}

void	ft_reverse_rotate_a(t_data **a)
{
	t_data	*top;
	t_data	*base;

	if (*a == NULL)
		return ;
	top = ft_pilha_get_top(*a);
	base = ft_pilha_get_last(*a);
	while (top->next != base)
		top = top->next;
	top->next = NULL;
	base->next = *a;
	*a = base;
}

void	ft_reverse_rotate_b(t_data **b)
{
	t_data	*top;
	t_data	*base;

	if (*b == NULL)
		return ;
	top = ft_pilha_get_top(*b);
	base = ft_pilha_get_last(*b);
	while (top->next != base)
		top = top->next;
	top->next = NULL;
	base->next = *b;
	*b = base;
}

void	ft_reverse_rotate_rotate(t_data **a, t_data **b)
{
	ft_reverse_rotate_a(a);
	ft_reverse_rotate_b(b);
}
