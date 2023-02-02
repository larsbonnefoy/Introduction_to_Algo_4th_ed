/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnefo <lbonnefo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 11:17:22 by lbonnefo          #+#    #+#             */
/*   Updated: 2023/02/02 11:16:55 by lbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 
en chained list il faut parcourir la liste depuis le debut avec avec l'elem que je dois inserer et le placer au bon endroit
Le 1er elem de la liste a le pointeur sur le dernier/prochain elements a inserer (to be determined)

for i = 1 to n
	key = A[i]
	j = i - 1 					//j est l'element juste avant celui qu'on va insert => la fin de la sous liste deja sorted
	while j > 0 && A[j] > key	//placer l'element A[j] dans la sous liste en allant vers la gauche
		A[j + 1] = A[j]			//on decale l'element sur lequel on se trouve vers la droite pour insere notre element a sa gauche
		j = j - 1 				//on recule le max de 1
	A[j + 1] = key 				//on reset la key au premier elem 
*/

#include <stdlib.h>
#include "../lib_includes/ft_printf/ft_printf.h"
#include "../lib_includes/libft/libft.h"

typedef struct insertion_list
{
	int						content;
	struct insertion_list	*next;
	struct insertion_list	*next_to_be_inserted;

} t_insertion_list;


t_insertion_list	*set_list(int argc, char **argv);
void				print_list(t_insertion_list **list);
void				insertion_sort(t_insertion_list **my_list, int len_list);
t_insertion_list	*i_sort_ft_lstnew(int content);
void				i_sort_ft_lstadd_back(t_insertion_list **lst, t_insertion_list *new);
void				print_next(t_insertion_list *list);

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
	return (0);
}

void insertion_sort(t_insertion_list **my_list, int len_list)
{
	//int i;
	(void) len_list;
	t_insertion_list *to_be_sorted;
	t_insertion_list *tmp;
	t_insertion_list *tmp_prev;

	tmp = *my_list;
	//while (i < len_list) //selectionner max chaque element une fois
	//{
		tmp = *my_list; //set la tmp au debut de la liste
		tmp_prev = tmp; 
	 	to_be_sorted = (*my_list)->next_to_be_inserted;
		while (tmp && tmp->content <= to_be_sorted->content)
		{
			tmp_prev = tmp; //garder l'adresse precedente en memoire aussi pour inserer au milieu;		
			tmp = tmp->next;
		}
		if (!tmp && !tmp)
			ft_printf("stopped at end\n");
		else
		{
			ft_printf("prev at %d\n", tmp_prev->content);
			ft_printf("next at %d\n", tmp->content);
		}
		//i++;
//	}	

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
		new_elem->next_to_be_inserted = NULL;
		i_sort_ft_lstadd_back(&start_list, new_elem); 
		i++;
	}
	start_list->next_to_be_inserted = start_list->next;
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
	ft_printf("next to be inserted = %d\n", list->next_to_be_inserted->content);
}
