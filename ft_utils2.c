/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 13:53:08 by waalexan          #+#    #+#             */
/*   Updated: 2024/07/25 05:44:10 by waalexan         ###   ########.fr       */
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
