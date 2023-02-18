/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort_array.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnefo <lbonnefo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 15:42:16 by lbonnefo          #+#    #+#             */
/*   Updated: 2023/02/03 17:06:41 by lbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Insertion sort is an inplace algo, it is better to use an array as the amount of element is fixed and we don't need to add elements.

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

void 	print_array(int *array, int len);
int 	*init_array(int argc, char **argv);
void	insertion_sort(int *array, int len);

int	main(int argc, char **argv)
{
	int *array;

	array = init_array(argc, argv);
	if (array == NULL)
		return (-1);
	print_array(array, argc - 1);
	ft_printf("--------sorting----------\n");
	insertion_sort(array, argc - 1);
	print_array(array, argc - 1);
	free(array);
	return (0);
}

void	insertion_sort(int *array, int len)
{
	int i; 											//i is the position of the element to insert (i - 1 is the beg of sorted sub array)
	int j; 											//use j to find where to insert i
	int elem_to_insert;

	i = 1; 											//dont need to insert the 1st elem of the list
	while (i < len)  								
	{
		elem_to_insert = array[i];
		j = i - 1;
		while (j >= 0 && array[i] < array[j])		//we have to insert element i in [0; array[end_of_sub_array]]
			j--;
		if (j + 1 != i) 							//if j + 1 == i the element doesnt need to move
		{
			ft_memmove(&array[j + 1], &array[j], sizeof(int) * (i - j)); 
			array[j + 1] = elem_to_insert;
		}
		i++;
	}
}

int *init_array(int argc, char **argv)
{
	int i;
	int *array;

	array = malloc(sizeof(int) * argc - 1);
	if (array == NULL)
		return (NULL);
	i = 1;
	while (i < argc)
	{
		array[i - 1] = ft_atoi(argv[i]);
		i++;
	}
	return (array);
}

void print_array(int *array, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		ft_printf("%d ", array[i]);
		i++;
	}
	write(1, "\n", 1);
 }
