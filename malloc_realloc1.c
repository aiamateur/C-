#include<stdlib.h>
#include<stdio.h>

int main() {
    int a_size = 10;
    int *a = NULL;
    int new_a_size = 0;
    
    a = malloc(a_size*sizeof(int));
    
    if(a == NULL)
    {
        fprintf(stderr, "Error allocaing memory \n");
        exit(1);
    }
    
    for(int i =0; i < a_size; i++)
    {
        a[i] = i*10;
    }
 
     for(int i =0; i < a_size; i++)
    {
        printf("a[%d] = %d \n", i, a[i]);
    }  
    
    int *tmp = NULL;
    new_a_size = 2*a_size;
    
    printf("Rallocating a! \n");
    tmp = realloc(a, new_a_size*sizeof(int));
    
    if(tmp == NULL)
    {
        fprintf(stderr, "Error allocaing memory \n");
        exit(1);
    }
    
    printf("Done!\n");
     for(int i =0; i < new_a_size; i++)
    {
        printf("a[%d] = %d \n", i, a[i]);
    }  
    
    a = tmp;
    
    
    free(a);
    
    return 0;

}
