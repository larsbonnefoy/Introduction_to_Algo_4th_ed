/*
 * Merge sort divides recursively one array into left and right array
 * where Values_L < Values_R. It stops when the base case len_array = 1 is reached
 * 	-> An array with one value is always sorted
 * It then merges the arrays back together
 * 
 MERGE-SORT(A, p, r)
 if p >= r 					//0 or 1 element
 	return
 q = [(p + r)/2] 			//midpoint of A[p : r]
 MERGE-SORT(A, p, q) 		//recursively sort A[p : q]
 MERGE-SORT(A, q + 1, r) 	//recursively sort A[q + 1 : r]
 // Merge A[p : q] and A[q + 1 : r] into A[p : r]
 MERGE(A, p, q, r)
 
 Merge-sort uses Merge as its subroutine;
 Merge copies the two tempo arrays A[p : q] and A[q + 1, r] back into array A[p, r]
 MERGE(A, p, q, r)
 nL = q - p + 1 			//length of A[q : p]
 nR = r -  q 				//length of A[q + 1 : r]
 let L[0 : nl - 1] and R[0 : nR - 1] be new arrays
 for i = 0 to nL - 1 		//copy A[p : q] into L[0 : nL - 1]
 	L[i] = A[p + i]
 for j = 0 to nR - 1 		//copy A[q + 1 : r] into R[0 : nR - 1] 
 	R[j] = A[q + j + 1]
 i = 0; 					//i indexes the smallest remaining element in L
 j = 0; 					//j indexes the smallest remaining element in R
 k = p 						//k indexes the location in A to fill
//As long as each if the arrays L and R contains an unmerged elenent,
// 	copy the smallest unmerged element back into A[p : r]
 while i < nL and j < nR
	if L[i] <= R[j]
 		A[k] = L[i]
		i = i + 1;
	else A[k] = R[j]
		j = j + 1
	k = k + 1
//As we have gone through L or R entirely we can copy the remainder
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
void	merge_sort(int *array, int p, int r);
int 	merge(int *array, int p, int q, int r );

int main(int argc, char **argv)
{
	int *array;

	array = init_array(argc, argv);
	print_array(array, argc - 1);
	merge_sort(array, 0, argc - 2);
	print_array(array, argc - 1);
	free(array);
}

void merge_sort(int *array, int p, int r)
{
	int q;
	
	if (p >= r)
		return ;
	q = (p + r)/2;
	merge_sort(array, p, q);
	merge_sort(array, q + 1, r);
	merge(array, p, q, r);
}

int merge(int *array, int p, int q, int r )
{
	int nL, nR;
	int i, j, k; 
	int *L, *R;
	
	i = 0;
	j = 0;
	nL = q - p + 1;
	nR = r - q;
	L = malloc(sizeof(int) * nL);
	if (!L)
		return (1);
	R = malloc(sizeof(int) * nR); 
	{
		if (!R)
		free(L);
		return (2);
	}
	for (i = 0; i < nL; i++)
		L[i] = array[p + i];	
	for (j = 0; j < nR; j++)
		R[j] = array[q + j + 1];	
	i = 0;
	j = 0;
	k = p;
	while (i < nL && j < nR)
	{
		if (L[i] <= R[j])
		{
			array[k] = L[i];
			i++;
		}		
		else
		{
			array[k] = R[j];
			j++;
		}
		k++;
	}
	while (i < nL)
	{
		array[k] = L[i];
		i++;
		k++;
	}
	while (j < nR)
	{
		array[k] = R[j];
		j++;
		k++;
	}
	free(L);
	free(R);
	return (0);
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
