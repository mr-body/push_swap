/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 06:04:38 by waalexan          #+#    #+#             */
/*   Updated: 2024/07/29 13:13:23 by waalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define INT_MIN -2147483648

# define INT_MAX 4294967296

typedef struct s_data
{
	int				data;
	struct s_data	*next;
}					t_data;

typedef struct s_alvo
{
	int				a_valor;
	int				b_valor;
	int				a_index;
	int				b_index;
	int				a_sentido;
	int				b_sentido;
}					t_alvo;

void				ft_init_list(t_data **list, int value);
void				ft_print_list(t_data *list);

int					ft_isvalid(long n);
int					ft_verif_repeat(t_data *list, int n);
int					ft_verif_sequence(t_data *list);
int					ft_validar_data_one(char **av, int i, t_data **list);
int					ft_validar_data_two(char **av, int i, t_data **list);
int					ft_global_valid(int ac, char **av, t_data **pilha1);

int					ft_pilha_get_max(t_data *list);
int					ft_pilha_get_min(t_data *list);
int					ft_count_list(t_data *list);

t_data				*ft_pilha_get_top(t_data *list);
t_data				*ft_pilha_get_last(t_data *list);

void				ft_free_list(t_data *list);
void				ft_free_mariz(char **matriz);

void				ft_push_b(t_data **a, t_data **b);
void				ft_push_a(t_data **a, t_data **b);

void				ft_swap_a(t_data **a);
void				ft_swap_b(t_data **a);
void				ft_swap_swap(t_data **a, t_data **b);

void				ft_rotate_a(t_data **a);
void				ft_rotate_b(t_data **b);
void				ft_reverse_rotate_a(t_data **a);
void				ft_reverse_rotate_b(t_data **b);
void				ft_rotate_rotate(t_data **a, t_data **b);
void				ft_reverse_rotate_rotate(t_data **a, t_data **b);

void				ft_case_two(t_data **a);
void				ft_case_three(t_data **a);
void				ft_case_more(t_data **a, t_data **b);

#endif
