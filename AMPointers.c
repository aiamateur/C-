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
