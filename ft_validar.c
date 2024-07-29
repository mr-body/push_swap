/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 04:57:54 by waalexan          #+#    #+#             */
/*   Updated: 2024/07/27 08:15:10 by waalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_verif_repeat(t_data *list, int n)
{
	while (list)
	{
		if (list->data == n)
			return (0);
		list = list->next;
	}
	return (1);
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

int	ft_validar_data_one(char **av, int i, t_data **list)
{
	while (--i > 0)
	{
		if (!ft_isbigdigit(av[i]))
			return (0);
		if (!ft_isvalid(atoi(av[i])))
			return (0);
		if (!ft_verif_repeat(*list, atoi(av[i])))
			return (0);
		ft_init_list(list, atoi(av[i]));
	}
	return (1);
}

int	ft_validar_data_two(char **av, int i, t_data **list)
{
	while (i-- > 0)
	{
		if (!ft_isbigdigit(av[i]))
			return (0);
		if (!ft_isvalid(atoi(av[i])))
			return (0);
		if (!ft_verif_repeat(*list, atoi(av[i])))
			return (0);
		ft_init_list(list, atoi(av[i]));
	}
	return (1);
}

int	ft_global_valid(int ac, char **av, t_data **pilha1)
{
	char	**rede;
	int		i;

	if (ac == 2)
	{
		rede = ft_split(av[1], ' ');
		i = 0;
		while (rede[i])
			i++;
		if (i == 1)
		{
			if (!ft_isbigdigit(rede[0]))
				return (ft_free_mariz(rede), ft_printf("Error\n"), 0);
			if (!ft_isvalid(atoi(rede[0])))
				return (ft_free_mariz(rede), ft_printf("Error\n"), 0);
		}
		else if (!ft_validar_data_two(rede, i, pilha1))
			return (ft_free_mariz(rede), ft_free_list(*pilha1),
				ft_printf("Error\n"), 0);
		ft_free_mariz(rede);
	}
	else if (ac > 2)
		if (!ft_validar_data_one(av, ac, pilha1))
			return (ft_free_list(*pilha1), ft_printf("Error\n"), 0);
	if (ft_verif_sequence(*pilha1))
		return (ft_free_list(*pilha1), 0);
	return (1);
}