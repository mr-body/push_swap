/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algoritmo1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 10:12:29 by waalexan          #+#    #+#             */
/*   Updated: 2024/07/31 10:18:34 by waalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_case_two(t_data **a)
{
	if (!ft_verif_sequence(*a))
		ft_swap_a(a, 1);
}

void	ft_case_three(t_data **a)
{
	if (ft_pilha_get_min(*a) == (*a)->data)
	{
		ft_reverse_rotate_a(a, 1);
		ft_swap_a(a, 1);
	}
	else if (ft_pilha_get_max(*a) == (*a)->data)
	{
		ft_rotate_a(a, 1);
		if (!ft_verif_sequence(*a))
			ft_swap_a(a, 1);
	}
	else
	{
		if (ft_pilha_get_min(*a) == (*a)->next->data)
			ft_swap_a(a, 1);
		else
			ft_reverse_rotate_a(a, 1);
	}
}
