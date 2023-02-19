/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnefo <lbonnefo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 11:17:22 by lbonnefo          #+#    #+#             */
/*   Updated: 2023/02/03 15:40:09 by lbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Insertion sort is an inplace algo, it is better to use an array as the amount of element is fixed and we don't need add elements.

This implementation as linked lists is used as an exercice to learn about them.
To speed up the process of insertion, the first elemen has a reference to the end of the sorted sub_array
We then can remove the element that has to be inserted, link the element to his right and left together and insert the element at the right place

for i = 1 to n
	key = A[i]
	j = i - 1 					//j est l'element juste avant celui qu'on va insert => la fin de la sous liste deja sorted
	while j > 0 && A[j] > key	//placer l'element A[j] dans la sous liste en allant vers la gauche
		A[j + 1] = A[j]			//on decale l'element sur lequel on se trouve vers la droite pour insere notre element a sa gauche
		j = j - 1 				//on recule le max de 1
	A[j + 1] = key 				//on reset la key au premier elem 

 * Source :
 * Introduction to Algorithms, Fourth Edition
 * Thomas H. Cormen;Charles E. Leiserson;Ronald L. Rivest;Clifford Stein;
*/

#include <stdlib.h>
#include "../lib_includes/ft_printf/ft_printf.h"
#include "../lib_includes/libft/libft.h"

typedef struct insertion_list
{
	int						content;
	struct insertion_list	*next;
	struct insertion_list	*end_of_sorted_sub_list;

} t_insertion_list;

t_insertion_list	*set_list(int argc, char **argv);
void				print_list(t_insertion_list **list);
void				insertion_sort(t_insertion_list **my_list, int len_list);
t_insertion_list	*i_sort_ft_lstnew(int content);
void				i_sort_ft_lstadd_back(t_insertion_list **lst, t_insertion_list *new);
void				print_next(t_insertion_list *list);
void				detach_to_be_sorted(t_insertion_list *end_of_sorted_sub_list);
void				insert(t_insertion_list *to_be_sorted, t_insertion_list *left, t_insertion_list **start);
void 				i_sort_ft_lstclear(t_insertion_list **lst);

int main(int argc, char **argv)
{
	t_insertion_list *my_list;
	
	my_list = set_list(argc, argv);
	if (!my_list)
		return (-1);
	print_list(&my_list);
	ft_printf("--------sorting----------\n");
	insertion_sort(&my_list, argc - 1);
	print_list(&my_list);
	i_sort_ft_lstclear(&my_list);
	return (0);
}

void insertion_sort(t_insertion_list **my_list, int len_list)
{
	int i;
	t_insertion_list *to_be_sorted;
	t_insertion_list *tmp;
	t_insertion_list *tmp_prev;

	i = 0; 
	tmp = *my_list;
	while (i < len_list && ((*my_list)->end_of_sorted_sub_list->next != 0)) 	//end our insertion when the last element to be inserted is the end of the list
	{
		tmp = *my_list; 														//set tmp at start of the list 
		tmp_prev = NULL; 
	 	to_be_sorted = (*my_list)->end_of_sorted_sub_list->next;
		detach_to_be_sorted((*my_list)->end_of_sorted_sub_list);
		while (tmp->content <= to_be_sorted->content && tmp != (*my_list)->end_of_sorted_sub_list->next)
		{ 
			tmp_prev = tmp; 
			tmp = tmp->next;
			if (tmp == NULL) 
				break;
		}
		if (tmp == (*my_list)->end_of_sorted_sub_list->next) 					//We append the element a the end of the list, we need to change our pointer to the end of the sub_list
			(*my_list)->end_of_sorted_sub_list = to_be_sorted;
		insert(to_be_sorted, tmp_prev, my_list);
		i++;
	}	
	return ;
}

t_insertion_list *set_list(int argc, char **argv)
{
	t_insertion_list	*start_list;
	t_insertion_list	*new_elem;
	int		i;
	
	if (argc == 1)
		return (NULL);
	i = 1; 	
	start_list = i_sort_ft_lstnew(ft_atoi(argv[i++]));
	while (i < argc)
	{
		new_elem = i_sort_ft_lstnew(ft_atoi(argv[i]));
		new_elem->end_of_sorted_sub_list = NULL;
		i_sort_ft_lstadd_back(&start_list, new_elem); 
		i++;
	}
	start_list->end_of_sorted_sub_list = start_list;
	return (start_list);
}

void	print_list(t_insertion_list **list)
{
	t_insertion_list *tmp;

	tmp = *list;
	while (tmp)
	{
		ft_printf("%d ", tmp->content);
		tmp = tmp->next;
	}
	write(1, "\n", 1);
}

t_insertion_list	*i_sort_ft_lstnew(int content)
{
	t_insertion_list	*lst;

	lst = malloc(sizeof(t_insertion_list));
	if (lst == NULL)
		return (NULL);
	lst->content = content;
	lst->next = NULL;
	return (lst);
}

void	i_sort_ft_lstadd_back(t_insertion_list **lst, t_insertion_list *new)
{
	t_insertion_list *tmp;

	tmp = *lst;
	if (lst)
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
	else
		*lst = new;
}

void print_next(t_insertion_list *list)
{
	ft_printf("next to be inserted = %d\n", list->end_of_sorted_sub_list->next->content);
}

/*
	We want to remove the element that will be inserted from the linked list,
	joining the end of the sorted sub list with the element to the right of the inserted element.
	The end of the sub sorteed list doesnt change, only its pointer to the next element, that will
	be the next to be inserted.	
*/
void	detach_to_be_sorted(t_insertion_list *end_of_sorted_sub_list)
{
	t_insertion_list *inserted_elem;

	inserted_elem = end_of_sorted_sub_list->next;
	end_of_sorted_sub_list->next = inserted_elem->next; 
	inserted_elem->next = NULL;
}

/* 
	Insert the element at the right position
	We have to modify the end of the sub_list only if we insert the element at the end of the sub_Sorted list
		->check that in the colling function
 */

void insert(t_insertion_list *to_be_sorted, t_insertion_list *left, t_insertion_list **my_list)
{
	t_insertion_list *right;
	t_insertion_list *start;
	
	start = *my_list;
	if (left == NULL) 			//we insert in front of the list, we need to set the address of the first element to the end of the sublist
	{
		to_be_sorted->end_of_sorted_sub_list = start->end_of_sorted_sub_list;
		start->end_of_sorted_sub_list = NULL;
		*my_list = to_be_sorted;
		to_be_sorted->next = start;
	}		
	else if(left->next == NULL) //we insert a the end of the list 
		left->next = to_be_sorted;
	else						//we insert between 2 elements
	{
		right = left->next;
		left->next = to_be_sorted;
		to_be_sorted->next = right;
	}
}

void i_sort_ft_lstclear(t_insertion_list **lst)
{
	t_insertion_list	*buffer;

	if (lst == NULL)
		return ;
	while (*lst)
	{
		buffer = *lst;
		*lst = (*lst)->next;
		free(buffer);
	}
	lst = NULL;
}
