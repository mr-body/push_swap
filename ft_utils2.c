/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 13:53:08 by waalexan          #+#    #+#             */
/*   Updated: 2024/08/01 07:35:28 by waalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_list(t_data *list)
{
	t_data	*current;
	t_data	*next;

	current = list;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
}

void	ft_free_mariz(char **matriz)
{
	int	i;

	i = -1;
	while (matriz[++i])
		free(matriz[i]);
	free(matriz);
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

int	ft_count_array(char **rede)
{
	int	i;

	i = 0;
	while (rede[i])
		i++;
	return (i);
}
