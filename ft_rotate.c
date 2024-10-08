/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 06:59:15 by waalexan          #+#    #+#             */
/*   Updated: 2024/07/30 08:13:48 by waalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_a(t_data **a, int flg)
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
	if (flg == 1)
		ft_printf("ra\n");
}

void	ft_rotate_b(t_data **b, int flg)
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
	if (flg == 1)
		ft_printf("rb\n");
}

void	ft_reverse_rotate_a(t_data **a, int flg)
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
	if (flg == 1)
		ft_printf("rra\n");
}

void	ft_reverse_rotate_b(t_data **b, int flg)
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
	if (flg == 1)
		ft_printf("rrb\n");
}
