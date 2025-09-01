/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyan <jiyan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 20:24:25 by jiyan             #+#    #+#             */
/*   Updated: 2025/09/01 20:38:57 by jiyan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <ctype.h>
# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <stdarg.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <time.h>
# include <unistd.h>

typedef struct s_node
{
	int				data;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct s_deque
{
	t_node			*front;
	t_node			*rear;
	int				size;
}					t_deque;

typedef struct s_info
{
	t_deque			*a;
	t_deque			*b;
	int				*sorted_arr;
	int				size;
}					t_info;

t_deque				*create_deque(void);
t_node				*create_node(int data);
void				push_front(t_deque *deque, int data);
void				push_rear(t_deque *deque, int data);
int					pop_front(t_deque *deque);
int					pop_rear(t_deque *deque);
int					peek_front(t_deque *deque);
int					peek_rear(t_deque *deque);
bool				is_empty(t_deque *deque);
void				free_deque(t_deque *deque);