#include<stdlib.h>
#include<stdio.h>

int main() {
    int a_size = 10;
    int *a = NULL;
    
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
    
    free(a);
    
    return 0;

}
