
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
