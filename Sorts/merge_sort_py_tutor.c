#include<stdio.h>
#include<string.h>

void    merge_sort(int *array, int p, int r);

int main(int argc, char **argv)
{
    int array[10];
    int i;
    i = 0;
    while (i < 10)
    {
      array[i] = i;
      i++;
    }

    //array = init_array(argc, argv);
//    print_array(array, argc - 1);
    merge_sort(array, 0, 9);
}

void merge_sort(int *array, int p, int r)
{
    int q;
    int i;
    
    i = 0;
    while (i < r + 1)
    {    
      printf("%d", array[i]);
      i++;
    }
    printf("\n");
    if (p >= r)
      return ;
    q = (p + r)/2;
    merge_sort(array, p, q);
    merge_sort(array, q + 1, r);
}
