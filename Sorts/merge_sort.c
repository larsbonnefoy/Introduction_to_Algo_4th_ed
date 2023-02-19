/*
 * Merge sort divides recursively one array into left and right array
 * where Values_L < Values_R. It stops when the base case len_array = 1 is reached
 * 	-> An array with one value is always sorted
 * It then merges the arrays back together
 * 
 
 Merge copies the two tempo arrays A[p : q] and A[q + 1, r] back into array A[p, r]

 MERGE(A, p, q, r)
 nL = q - p + 1 			//length of A[q : p]
 nR = r -  q 				//length of A[q + 1 : r]
 let L[0 : nl - 1] and R[0 : nR - 1] be new arrays
 for i = 0 to nL - 1 		//copy A[p : q] into L[0 : nL - 1]
 	L[i] = A[p + i]
 for j = 0 to nR - 1 		//copy A[q + 1 : r] into R[0 : nR - 1] 
 	R[j] = A[q + j + 1]
 i = 0; 					//i indexes the smalles remaining element in L
 j = 0; 					//j indexes the smalles remaining element in R
 k = p 					//k indexes the location in A to fill
//As long as eacg if the arrays L and R contains an unmerged elenent,
// 	copy the smallest unmerged element back into A[p : r]
 while i < nL and j < nR
	if L[i] <= R[j]
 		A[k] = L[i]
		i = i + 1;
	else A[k] = R[j]
		j = j + 1
	k = k + 1
//As we have gone through L or R entirelym copy to remainder
// 	of the other to the end of A[p : r]
 while i < nL
 	A[k] = L[i]
	i = i + 1
	k = k + 1
 while j < nR
 	A[k] = R[j]
	j = j + 1
	k = k + 1

 * Source :
 * Introduction to Algorithms, Fourth Edition
 * Thomas H. Cormen;Charles E. Leiserson;Ronald L. Rivest;Clifford Stein;
 *
 */
#include <stdlib.h>
#include "../lib_includes/ft_printf/ft_printf.h"
#include "../lib_includes/libft/libft.h"

void 	print_array(int *array, int len);
int 	*init_array(int argc, char **argv);

int main(int argc, char **argv)
{
	int *array;

	array = init_array(argc, argv);
	print_array(array, argc - 1);
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
