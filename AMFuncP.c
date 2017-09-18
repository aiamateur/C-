#include <stdio.h>
#include <string.h>

#define VAR1 "String1"

//Going to be accessible to every single function in the file/program, deefined outside main
//variable = box in memory

int globalVar = 100;

typedef int (* arith_func)(int, int);

int add(int a, int b)
    {
        return (a+b);
    }

int subtract(int a, int b)
    {
        return (a-b);
    }

int multiply(int a, int b)
    {
        return (a*b);
    }

void blend(int *a, int *b, int len, arith_func f)
    {
        for(int i=0; i < len; i++)
        {
           printf("%d \n", f(a[i], b[i]));
        }
    }




int main(){
    printf("%d\n", 10);

    long int x = -32767000;

    printf("add(3+4), %d\n", add(3,4));

    int (* plus)(int, int) = add;

    printf("plus(3+4), %d\n", plus(3,4));

    //Typedef to define a new type
    //typedef int (* arith_func)(int, int);

    arith_func minus = subtract;

    printf("subtract(10-9), %d\n", subtract(10,9));

    int a[3] = {10, 20, 30};
    int b[3] = {5, 6, 7};

    arith_func funcs[3] = {add, subtract, multiply};

    for(int i=0; i<3; i++)
    {
        blend(a, b, 3, funcs[i]);
    }



    return 0;
}

