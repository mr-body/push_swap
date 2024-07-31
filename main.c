/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 04:50:14 by waalexan          #+#    #+#             */
/*   Updated: 2024/07/31 12:06:33 by waalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	ft_init_list(t_data **list, int value)
{
	t_data	*new;

	new = (t_data *)malloc(sizeof(t_data));
	if (new == NULL)
		return ;
	new->data = value;
	new->next = *list;
	*list = new;
}

void	ft_print_list(t_data *list)
{
	while (list)
	{
		ft_printf("%d\n", list->data);
		list = list->next;
	}
}

int	main(int ac, char **av)
{
	t_data	*pilha1;
	t_data	*pilha2;

	pilha1 = NULL;
	pilha2 = NULL;
	if (!ft_global_valid(ac, av, &pilha1))
		return (0);
	if (ft_count_list(pilha1) == 2)
		ft_case_two(&pilha1);
	else if (ft_count_list(pilha1) == 3)
		ft_case_three(&pilha1);
	else
		ft_case_more(&pilha1, &pilha2);
	ft_free_list(pilha1);
	ft_free_list(pilha2);
	return (0);
}
