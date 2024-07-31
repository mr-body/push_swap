/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algoritmo3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 07:58:31 by waalexan          #+#    #+#             */
/*   Updated: 2024/07/31 11:46:30 by waalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rrr_rr(t_data **a, t_data **b, t_alvo dados_alvos)
{
	while ((((*b)->data != dados_alvos.b_valor)
			&& ((*a)->data != dados_alvos.a_valor)))
	{
		if (dados_alvos.b_sentido == -1)
			ft_rotate_rotate(a, b);
		else
			ft_reverse_rotate_rotate(a, b);
	}
}

void	ft_set_alvos(t_vars *vars, t_alvo *dados, int valor)
{
	if (vars->pilha_a + vars->pilha_b < vars->n_plus_b)
	{
		vars->n_plus_b = vars->pilha_a + vars->pilha_b;
		dados->a_valor = vars->value;
		dados->a_sentido = vars->sentido_a;
		dados->b_valor = valor;
		dados->b_sentido = vars->sentido_b;
	}
}

void	ft_set_sentidos(t_data **a, t_data **b, t_vars *vars)
{
	if (vars->index <= ft_count_list(*a) / 2)
	{
		vars->pilha_a = vars->index;
		vars->sentido_a = -1;
	}
	else if (vars->index > ft_count_list(*a) / 2)
	{
		vars->pilha_a = ft_count_list(*a) - vars->index;
		vars->sentido_a = 1;
	}
	if (vars->i <= ft_count_list(*b) / 2)
	{
		vars->pilha_b = vars->i + 1;
		vars->sentido_b = -1;
	}
	else if (vars->i > ft_count_list(*b) / 2)
	{
		vars->pilha_b = ft_count_list(*b) - vars->i + 1;
		vars->sentido_b = 1;
	}
}

t_alvo	ft_get_nplusb(t_data **a, t_data **b)
{
	t_data	*tmp;
	t_alvo	dados;
	t_vars	vars;

	vars.i = 0;
	vars.n_plus_b = INT_MAX;
	tmp = (*b);
	while ((tmp))
	{
		vars.value = ft_get_best_option(a, tmp->data);
		vars.index = ft_get_index(*a, vars.value);
		ft_set_sentidos(a, b, &vars);
		ft_set_alvos(&vars, &dados, tmp->data);
		tmp = tmp->next;
		vars.i++;
	}
	return (dados);
}
