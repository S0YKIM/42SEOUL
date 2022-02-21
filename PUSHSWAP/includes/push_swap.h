/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 20:22:04 by sokim             #+#    #+#             */
/*   Updated: 2022/02/20 20:22:04 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "deque.h"
# include "push_swap_macro.h"

/* Create deques */
t_deque	*create_deque_with_arguments(int argc, char **argv);

/* Check validation */
int	check_validate_integer(char **str);
int	check_duplicates(t_deque *deque);
int	check_deque_sorted(t_deque *deque);

/* Change integer into index and move it to A (tmp->A) */
void	add_index_and_binary(t_push_swap *data);

/* Operation (pa, pb, sa, sb, ra, rb, ...) */
void	operator(char *op, t_push_swap *data);

/* Print deque */
void	print_deque_ab(t_deque *a, t_deque *b);

/* Error handling */
void	exit_with_error_message(char *msg);
void	exit_with_memory_free(char *msg, t_deque *a, t_deque *b, char **str);

/* Memory Free */
void	free_double_char(char **str);

#endif