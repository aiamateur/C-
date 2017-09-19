#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
    int a = 101;
    int *ap = &a; //When you dereference ap, you get the contents of a, which is 101, Therefore ***appp = 101;
    int **app = &ap;    //When you dereference app, you get the contents of ap, which is address of a
    int ***appp = &app; //When you  dereference appp, you get the contents of app, which is address of ap
    
    printf("a : %d \n", a);
    printf("*ap : %d \n", *ap);
    printf("*&*ap : %d \n", *&*ap);   
    printf("*&*&*ap : %d \n", *&*&*ap);       
    
    printf("a : %d \n", a);
    printf("*ap : %d \n", *ap);
    printf("**app : %d \n", **app);   
    printf("***appp : %d \n", ***appp);      


     
}

/*Results
a : 101 
*ap : 101 
*&*ap : 101 
*&*&*ap : 101 
a : 101 
*ap : 101 
**app : 101 
***appp : 101 
*/

/* 2-d array*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
    int *a = malloc(3*sizeof(int)); //malloc allocates memory on heap and returns a pointer to that address
    int **ap = &a;
    a[0] = 33;
    a[1] = 66;
    a[2] = 99;
    
    printf("sizeof(int): %lu \n", sizeof(int));
    
    printf("&a[0]: On heap, element 0 %p \n", &a[0]);
    printf("&a[1]: On heap, element 1 %p \n", &a[1]);
    printf("&a[2]: On heap, element 2 %p \n", &a[2]);
    
    printf("&a: a is a variable on stack the address of a is, %p \n", &a);
    printf("*a: Contents of a, should be the memory location/address of a[0] on heap %p \n", *ap);  
    
    //Pointer arithmetic. a is a pointer to integer, a+1 is the pointer to next integer and so on.
    printf("a: %p \n", a);
    printf("a+1: %p \n", a+1);
    printf("a+2: %p \n", a+2);
    
    //Dereferencing the addresses

    printf("*a: %d \n", *a);
    printf("*(a+1): %d \n", *(a+1));
    printf("*(a+2): %d \n", *(a+2));
}
