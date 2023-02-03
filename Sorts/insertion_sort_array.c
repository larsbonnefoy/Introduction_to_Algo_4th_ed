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
Insertion sort is an implace algo, it is better to use an array as the amount of element is fixed and we don't need add elements.

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

void 	print_array(int *array, int length);
int 	*init_array(int argc, char **argv);
void	insertion_sort(int *array, int length);

int	main(int argc, char **argv)
{
	int *array;

	array = init_array(argc, argv);
	if (array == NULL)
		return (-1);
	print_array(array, argc);
	insertion_sort(array, argc);
	print_array(array, argc);
	free(array);
}

void	insertion_sort(int *array, int length)
{
	int i;
	int	j;
	int end_of_sub_array; 							//position of the last element in the sorted sub_string
	int elem_to_insert;

	i = 0;
	end_of_sub_array = 0;
	while (i < length)  							//element i is the element that is going to be inserted in the sub array
	{
		elem_to_insert = array[i];
		j = end_of_sub_array;
		while (j >= 0 && array[i] >= array[j])		//we have to insert element i in [0; array[end_of_sub_array]]
		{
			//use mem_move/cpy pour bouger l'array de 1 vers la droite
			j--;
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
	i = 0;
	while (i < argc)
	{
		array[i] = ft_atoi(argv[i]);
		i++;
	}
	return (array);
}

void print_array(int *array, int length)
{
	int i;

	i = 0;
	while (i < length)
	{
		ft_printf("%d ", array[i]);
		i++;
	}
	write(1, "\n", 1);
 }
