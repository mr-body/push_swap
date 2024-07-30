/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algoritmo2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 07:53:53 by waalexan          #+#    #+#             */
/*   Updated: 2024/07/30 12:21:15 by waalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_best_option(t_data **a, int b)
{
	long int	value;
	t_data		*tmp;

    value = INT_MAX;
    
	if(b > ft_pilha_get_max(*a) || b < ft_pilha_get_min(*a))
        return (ft_pilha_get_min(*a));
    else
    {
        tmp = *a;
        while (tmp)
        {
            if (tmp->data > b)
            {
                if(tmp->data < value)
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
    // printf("%d <- %d\n", value, a->data);
	return (i);
}

t_alvo	ft_get_nplusb(t_data **a, t_data **b)
{
	t_data		*tmp;
	t_alvo		dados;
	int			i;
	int			value;
	int			index;
	long int	n_plus_b;
	int			pilha_a;
	int			pilha_b;
	int			sentido_a;
	int			sentido_b;

	i = 0;
	n_plus_b = INT_MAX;
	tmp = (*b);
	while ((tmp))
	{
		value = ft_get_best_option(a, tmp->data);
		index = ft_get_index(*a, value);
		if (index <= ft_count_list(*a) / 2)
		{
			pilha_a = index;
			sentido_a = -1;
		}
		else if (index > ft_count_list(*a) / 2)
		{
			pilha_a = ft_count_list(*a) - index;
			sentido_a = 1;
		}
		if (i <= ft_count_list(*a) / 2)
		{
			pilha_b = i + 1;
			sentido_b = -1;
		}
		else if (i > ft_count_list(*a) / 2)
		{
			pilha_b = ft_count_list(*a) - i + 1;
			sentido_b = 1;
		}
		if (pilha_a + pilha_b < n_plus_b)
		{
			n_plus_b = pilha_a + pilha_b;
			dados.a_index = index;
			dados.a_valor = value;
			dados.a_sentido = sentido_a;
			dados.b_index = i;
			dados.b_valor = tmp->data;
			dados.b_sentido = sentido_b;
		}
		tmp = tmp->next;
		i++;
	}

    // printf("[%d] %d <- [%d]%d\n", dados.a_index, dados.a_valor, dados.b_index, dados.b_valor);
	return (dados);
}

void	ft_put_min_top(t_data **a)
{
	int	min;
	int	sentido;
	int	index;

	min = ft_pilha_get_min(*a);
	index = ft_get_index(*a, min);
	if (index <= ft_count_list(*a) / 2)
	{
		sentido = -1;
	}
	else if (index > ft_count_list(*a) / 2)
	{
		sentido = 1;
	}
	while ((*a)->data != min)
	{
		if (sentido == -1)
			ft_rotate_a(a, 1);
		else if (sentido == 1)
			ft_reverse_rotate_a(a, 1);
	}
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
                {
					ft_reverse_rotate_a(a, 1);
                    // ft_printf("\n\n==========A==========\n");
                    // ft_print_list(*a);
                    // ft_printf("\n\n==========B==========\n");
                    // ft_print_list(*b);
                    // ft_printf("\n\n========================\n");
                    // printf("valor: %d -> alvo: %d\n",dados_alvos.b_valor, dados_alvos.a_valor);
                    // ft_print_list(*a);
                    // sleep(10);
                }
			}
			ft_push_a(a, b);
		}
	}
	while (!ft_verif_sequence(*a))
	{
		if (ft_pilha_get_min(*a) <= ft_count_list(*a) / 2)
			ft_rotate_a(a, 1);
		else
			ft_reverse_rotate_a(a, 1);
	}
}
