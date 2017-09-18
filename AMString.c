#include <stdlib.h>
#include <stdio.h>

int main()
{
    char a[] = "Hello";
    char b[6] = "Hello";
    char c[5] = "Halloween";
    char *d = "Hello";
    //d[0] = 'B';
    printf("%s a\n", a);
    printf("%s b\n", b);
    printf("%s c\n", c);
    printf("%s b\n", b);
    printf("%s d\n", d);
    puts(a);
    
    //printf("%d Address of a\n", int((char *)(a)));
    return 0;
}

#include <stdlib.h>
#include <stdio.h>

int main()
{
  char a[] ="hello";
  char b[] = {'h', 'e', 'l', 'l', 'o', '\0'};
  printf("%s \n", a);
  
  char c[6] = "hello";
  char d[5] = "hello";
  printf("%s \n", d);  
  char *e = "hello"; //Put the string literal "hello" into a ROM. "hello" string literal is like a constant
}

#include <stdlib.h>
#include <stdio.h>

int main()
{
    char a[] = "hello";
    char b[6] = "hello";
    char c[5] = "hello";
    char d[] = {'h', 'e', 'l', 'l', 'o', '\0'};
    char e[] = {'h', 'e', 'l', 'l', 'o'};
    
    printf("a \"%s\" \n", a);
    printf("b \"%s\" \n", b);
    printf("c \"%s\" \n", c); 
    printf("d \"%s\" \n", d); 
    printf("e \"%s\" \n", e); 
    
    //Instructor gets a 'hellohello' for this since there is no space for null terminated character in a
    //5 byte array like in "c". So, it goes on till it finds the \0 after "b" since "c" is immediaely next to(before) "b" 
    //on the function main's stack frame. That was the instructor's explanation. However, I suspect this is a function of compiler as to where exactly on the stack 
    //it allocates each of these character arrays("b" and "c")
    
    printf("%p \n", a);
    printf("%p \n", b);
    printf("%p \n", c);
    printf("%p \n", d);
    printf("%p \n", e);
    
}

//Results:
a "hello" 
b "hello" 
c "hello" 
d "hello" 
e "hello" 
0x7ffdc99109a0 
0x7ffdc99109b0 
0x7ffdc9910980 
0x7ffdc99109c0 
0x7ffdc9910990 

//Trying to change/modify/write to a string literal we are assigning to a pointer

#include <stdlib.h>
#include <stdio.h>

int main()
{
    char *a = "hello";
    char b[] = "hello";

    printf("a \"%s\" \n", a); //Prints: a "hello"
    printf("b \"%s\" \n", b); //Prints: b "hello"
    b[0] = 'b';
    printf("b \"%s\" \n", b); //Prints: b "bello"
    
    a[0] = 'c';               //Segmentation fault (core dumped)
    printf("a \"%s\" \n", a); 

        

    
}
//Segmentation fault because the string literal "hello" pointed to by "a" is in a read only memory and we cannot access it. That crashes
//the program. What happens is this:
//A string literal like "hello" is copied into an array when it is a character array, like so
// char a[] = "hello";
//Wherever else a string literal is used, that will be allocated in static memory by the compiler and then the pointer will be copied
//into "a", like so
//char *a = "hello";


 
