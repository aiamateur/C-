#include<stdio.h>

int compare1(int i, int j)
{
    printf("In compare1\n");
    return 1;

}

int compare2(int i, int j)
{
    printf("In compare2\n");
    return 1;

}

void whichFunction(int i, int j, int (* compare)(int, int))
{
    if(i > j)
    {
        compare(i, j);
        printf("Called compare1\n");
    }else
    {
        compare(i, j);
        printf("Called compare2\n");    
    }
}

typedef int (* compare)(int, int);


int main() {
    compare ctype1 = compare1;
    compare ctype2 = compare2;
    //compare ctype3 = compare3;     
    int (* ctype3)(int, int) = compare3;
     
       

   int x=10;
   int y=25;
   whichFunction(x, y, ctype2);
   whichFunction(x, y, ctype3);
   whichFunction(x, y, ctype1);
   
   return 0;
}
