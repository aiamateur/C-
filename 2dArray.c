#include <stdlib.h>
#include <stdio.h>

/*

int* create_int_array(int row_size, int col_size)
{
    int *ptr = malloc(row_size*col_size*sizeof(int));
    return ptr;

}

void change_int_array(int *a, int row_size, int col_size)
{
    for(int i=0; i< row_size; i++)
    {
        for (int j = 0; j < col_size; j++)
        {
            *(a + (i*row_size) + j) = (i*100 + j) ;
        }
    }
}

int main()
{
    int a[10][10];
    int row_size = 3;
    int col_size = 5;
    

    //int *ap = (int *)&a; Ashley's version
    
    int *a = create_int_array(row_size, col_size);
    //int *ap = a;
    
    
    if(a == NULL)
    {
        fprintf(stderr, "Error allocating memory \n");
        exit(1);
    }
    
    for (int i = 0; i < row_size; i++)
    {
        for (int j = 0; j < col_size; j++)
        {
           printf("a[%d][%d] = %d \n", i, j, a[i][j]);
        }
    }
    
    change_int_array(a, row_size, col_size);
    for (int i = 0; i < row_size; i++)
    {
        for (int j = 0; j < col_size; j++)
        {
           printf("a[%d][%d] = %d \n", i, j, a[i][j]);
        }
    }    

    free(a);
    
    return 0;
}

*/

int* create_int_array(int len, int multiplier)
{
    int *a = malloc(len*sizeof(int));
    for(int i = 0; i < len; i++)
    {
        a[i] = i*multiplier;
    }
    
    return a;

}

int main()
{
    int array_len = 10;
    int *a = create_int_array(array_len, 10);
    int *b = create_int_array(array_len, 100);
    int *c = create_int_array(array_len, 1000);
    
    int** array_pointer = malloc(3*sizeof(int*));
    array_pointer[0] = a;
    array_pointer[1] = b;
    array_pointer[2] = c;
    
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < array_len; j++)
        {
           printf("array_pointer[%d][%d] = %d \n", i, j, array_pointer[i][j]);
        }
    }  
    
    printf("a = %d \n", (int)a);
    printf("b = %d \n", (int)b);
    printf("c = %d \n", (int)c);
    
    printf("array pointer 0 = %d \n", (int)array_pointer[0]);
    printf("array pointer 1 = %d \n", (int)array_pointer[1]);
    printf("array pointer 2 = %d \n", (int)array_pointer[2]);
 
    for (int i = 0; i < 3; i++) 
    {
        for (int j = 0; j < array_len; j++)
        {    
            printf("array_pointer[%d][%d] = %d \n", i, j, *(*(array_pointer+i) + j));
        }
    }  

    
    free(array_pointer);
    free(a);
    free(b);
    free(c);
}

