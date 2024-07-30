/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 07:43:20 by waalexan          #+#    #+#             */
/*   Updated: 2024/07/30 08:12:20 by waalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_a(t_data **a, int flg)
{
	t_data	*link1;
	t_data	*link2;
	t_data	*link3;

	if (*a == NULL)
		return ;
	link1 = (*a);
	link2 = link1->next;
	link3 = link2->next;
	link2->next = link1;
	link1->next = link3;
	*a = link2;
	if (flg == 1)
		ft_printf("sa\n");
}

void	ft_swap_b(t_data **b, int flg)
{
	t_data	*link1;
	t_data	*link2;
	t_data	*link3;

	if (*b == NULL)
		return ;
	link1 = (*b);
	link2 = link1->next;
	link3 = link2->next;
	link2->next = link1;
	link1->next = link3;
	*b = link2;
	if (flg == 1)
		ft_printf("sb\n");
}

void	ft_swap_swap(t_data **a, t_data **b)
{
	ft_swap_a(a, 0);
	ft_swap_b(b, 0);
	ft_printf("ss\n");
}
