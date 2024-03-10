/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfafouri <hfafouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 18:02:14 by hfafouri          #+#    #+#             */
/*   Updated: 2024/03/09 02:51:15 by hfafouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void ra(t_list **stack_a)
{
	rotate(stack_a);
}
void rb(t_list **stack_b)
{
	rotate(stack_b);
}
void rr(t_list **stack_a, t_list **stack_b)
{
	rotate(stack_b);
	rotate(stack_a);
}
