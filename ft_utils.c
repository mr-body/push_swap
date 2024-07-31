/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 09:25:39 by waalexan          #+#    #+#             */
/*   Updated: 2024/07/31 12:03:03 by waalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isvalid(long n)
{
	if (n == INT_MIN)
		return (0);
	return (1);
}

int	ft_pilha_get_max(t_data *list)
{
	int	tmp;

	tmp = list->data;
	while (list)
	{
		if (list->data > tmp)
			tmp = list->data;
		list = list->next;
	}
	return (tmp);
}

int	ft_pilha_get_min(t_data *list)
{
	int	tmp;
	int	max;

	max = ft_pilha_get_max(list);
	tmp = max;
	while (list)
	{
		if (!(list->data > tmp))
			tmp = list->data;
		list = list->next;
	}
	return (tmp);
}

int	ft_count_list(t_data *list)
{
	int	i;

	i = 0;
	while (list)
	{
		i++;
		list = list->next;
	}
	return (i);
}

int	ft_verif_sequence(t_data *list)
{
	int	tmp;

	tmp = list->data;
	while (list)
	{
		if (list->data >= tmp)
			tmp = list->data;
		else
			return (0);
		list = list->next;
	}
	return (1);
}
