/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algoritmo2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 07:53:53 by waalexan          #+#    #+#             */
/*   Updated: 2024/07/31 11:49:03 by waalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_best_option(t_data **a, int b)
{
	long int	value;
	t_data		*tmp;

	value = INT_MAX;
	if (b > ft_pilha_get_max(*a) || b < ft_pilha_get_min(*a))
		return (ft_pilha_get_min(*a));
	else
	{
		tmp = *a;
		while (tmp)
		{
			if (tmp->data > b)
			{
				if (tmp->data < value)
					value = tmp->data;
			}
			tmp = tmp->next;
		}
	}
	return (value);
}

int	ft_get_index(t_data *a, int value)
{
	int	i;

	i = 0;
	while (a)
	{
		if (a->data == value)
			break ;
		a = a->next;
		i++;
	}
	return (i);
}

void	ft_order_b_in_a(t_data **a, t_data **b, t_alvo dados_alvos)
{
	if (dados_alvos.a_sentido == dados_alvos.b_sentido)
	{
		ft_rrr_rr(a, b, dados_alvos);
	}
	while ((*b)->data != dados_alvos.b_valor)
	{
		if (dados_alvos.b_sentido == -1)
			ft_rotate_b(b, 1);
		else if (dados_alvos.b_sentido == 1)
			ft_reverse_rotate_b(b, 1);
	}
	while ((*a)->data != dados_alvos.a_valor)
	{
		if (dados_alvos.a_sentido == -1)
			ft_rotate_a(a, 1);
		else if (dados_alvos.a_sentido == 1)
			ft_reverse_rotate_a(a, 1);
	}
	ft_push_a(a, b);
}

void	ft_case_more(t_data **a, t_data **b)
{
	t_alvo	dados_alvos;

	while (ft_count_list(*a) > 3)
		ft_push_b(a, b);
	if (!ft_verif_sequence(*a))
		ft_case_three(a);
	while (ft_count_list(*b) > 0)
	{
		dados_alvos = ft_get_nplusb(a, b);
		if ((*b)->data > ft_pilha_get_max(*a)
			|| (*b)->data < ft_pilha_get_min(*a))
		{
			ft_put_min_top(a);
			ft_push_a(a, b);
		}
		else
			ft_order_b_in_a(a, b, dados_alvos);
	}
	while (!ft_verif_sequence(*a))
	{
		if (ft_get_index(*a, ft_pilha_get_max(*a)) <= ft_count_list(*a) / 2)
			ft_rotate_a(a, 1);
		else
			ft_reverse_rotate_a(a, 1);
	}
}
