/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnefo <lbonnefo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 11:17:22 by lbonnefo          #+#    #+#             */
/*   Updated: 2023/02/01 17:57:23 by lbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 
en chained list il faut parcourir la liste depuis le debut avec avec l'elem que je dois inserer et le placer au bon endroit

for i = 1 to n
	key = A[i]
	j = i - 1 					//j est l'element juste avant celui qu'on va insert => la fin de la sous liste deja sorted
	while j > 0 && A[j] > key	//placer l'element A[j] dans la sous liste en allant vers la gauche
		A[j + 1] = A[j]			//on decale l'element sur lequel on se trouve vers la droite pour insere notre element a sa gauche
		j = j - 1 				//on recule le max de 1
	A[j + 1] = key 				//on reset la key au premier elem 
*/

#include <stdlib.h>
#include "../lib_includes/libft/libft.h"
#include "../lib_includes/ft_printf/ft_printf.h"

t_list	*set_list(int argc, char **argv);
void	print_list(t_list **list);
void	insertion_sort(t_list **my_list);

int main(int argc, char **argv)
{
	t_list *my_list;
	
	my_list = set_list(argc, argv);
	print_list(&my_list);
	ft_printf("--------sorting----------\n");
	insertion_sort(&my_list);
	return (0);
}


void insertion_sort(t_list **my_list)
{
	


}

t_list *set_list(int argc, char **argv)
{
	t_list	*start_list;
	int		i;

	i = 1; 	
	start_list = ft_lstnew(ft_atoi(argv[i++]));
	while (i < argc)
	{
		ft_lstadd_back(&start_list, ft_lstnew(ft_atoi(argv[i]))); 
		i++;
	}
	return (start_list);
}

void	print_list(t_list **list)
{
	t_list *tmp;

	tmp = *list;
	while (tmp)
	{
		ft_printf("%d ", tmp->content);
		tmp = tmp->next;
	}
	write(1, "\n", 1);
}
