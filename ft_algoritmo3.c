/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algoritmo3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 07:58:31 by waalexan          #+#    #+#             */
/*   Updated: 2024/07/30 11:36:01 by waalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rrr_rr(t_data **a, t_data **b, t_alvo dados_alvos)
{
	while ((((*b)->data != dados_alvos.b_valor) && ((*a)->data != dados_alvos.a_valor)))
	{
            // printf("%d -> %d\n",(*b)->data, dados_alvos.b_valor);
            // printf("%d -> %d\n",(*a)->data, dados_alvos.a_valor);
            // printf("sentido :%d\n", dados_alvos.a_sentido);
		if (dados_alvos.b_sentido == -1)
        {

			    ft_rotate_rotate(a, b);
        }
		else
        {
			    ft_reverse_rotate_rotate(a, b);
        }
	}
}
