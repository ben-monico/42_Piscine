/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_push_swap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarreir <bcarreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 17:10:26 by bcarreir          #+#    #+#             */
/*   Updated: 2022/04/05 17:28:40 by bcarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	t_ps	pushswap;

	pushswap.a = initstack(0);
	if (!pushswap.a)
	{
		ft_putstr("initstackError\n");
		return (0);
	}	
	if (argc == 1 || !(pushswap.a->head = ft_parse_args(argc, argv)))
	{
		ft_putstr("parseargError\n");
		return (0);
	}
	
	/* int c;
	int i = -1;
	int arr[] = {3, 4, 0, 6, 2, 1 , 90, 89, 27, 10};



	t_node *head;
	t_node *tmp;
	t_node *tmp2;
	
	c = 10;
	tmp2 = NULL;
	while(++i < c)
	{
		tmp = initnode(arr[i]);
		if (tmp2 != NULL)
			tmp2->next = tmp;
		tmp->prev = tmp2;
		printf("cpy:%d \n", tmp->nb);
		tmp2 = tmp;
	}
	head = ft_find_head(tmp);
	printf("Tmp point to nb (%d)\n", tmp->nb);
	printf("Tmp2 point to nb (%d)\n", tmp2->nb);
	printf("head nb = (%d)\n", head->nb); */
	

}