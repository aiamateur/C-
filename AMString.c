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


 
#include <stdlib.h>
#include <stdio.h>

int main()
{
    char *a = malloc(6*sizeof(char));
    printf("&a before %p \n", a);
    a = "hello";
    printf("&a after %p \n", a);    
    
    printf("a: \" %s \"", a);
    a[0] = 'b';
  
}
/* Results
&a before 0x7f354198b420 
&a after 0x5607f23d482d 
Segmentation fault (core dumped) for     a[0] = 'b';
What happens is this:
char *a = malloc(6*sizeof(char)); The memory allocated to pointer "a"  will be unused because
when we do this assignment
a = "hello";
That is, we are assigning a string literal "hello" NOT to a character array, but we are assigning the string literal "hello" to
a pointer "a". So, string literal is allocated in static memory and then the pointer to "hello" will be copied into "a".
"a" will no longer point to the memory in heap that we allocated when we did the following:
char *a = malloc(6*sizeof(char)); //"a" on heap.
So, the following assignent
a = "hello"; does not change the contents of the location "a" on heap. Instead,
whenever a string literal (like "hello") is assigned to anything other than a character array, it is allocated on static memory and a
pointer is passed back (like into "a")as the thing that is being assigned.
So, if we do this:
a = "hello";
a[0] = 'b';
then we get a segmentation fault since we are trying to write into read only memory

*/

=If we want to copy a string literal into an already allocated location, say on heap, we use function, strncpy, like so

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
    char *a = malloc(6*sizeof(char));
    printf("&a before %p \n", a);
    //a = "hello";
    strncpy(a, "hello", 5);
    //What happens here is that the string literal, "hello" is allocated in static Read Only memory and the pointer
    //is passed to strncpy function which expects a pointer as the second argument
    //From the second pointer strncpy copies to the location pointed to by the first pointer
    printf("&a after %p \n", a); 
    //"a" points to the same location on heap before and after the strncpy, showing that
    //an actual copy has taken place into the original locaion "a" on heap.
    a[5] ='\0';
    
    puts(a);
    
    
    printf("a: \" %s \" \n", a);
    a[0] = 'b'; //This change does take effect as "a" points to read/write memory on heap

    printf("a: \" %s \" \n", a);    

        

    
}
/* Results
&a before 0x7f4e12ac5420 
&a after 0x7f4e12ac5420 
hello
a: " hello " 
a: " bello " 
*/

char a[] = "hello"; //a is the name of a character array, a is an array type
char *b = "hello"; //b is a pointer to a character, b is pointer to character type
//The name of an array can be passed into a function that expects a pointer to a character, it will work.
//in that case, the array type decays into a pointer type

//=Functions in string.h and functions that take string type=
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
    char a[] = "hello";
    printf("a: %p \n", a);
    printf("&a: %p \n", &a);
    char *ap = a;
    printf("ap: %p \n", ap);
}

/*Results
a: 0x7ffd80263960 
&a: 0x7ffd80263960 
ap: 0x7ffd80263960 
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
    char a[] = "hello";
    printf("a: %p \n", a);
    printf("&a: %p \n", &a);
    char *ap = &a;
    printf("ap: %p \n", ap);
}

/* Results
jdoodle.c: In function 'main':
jdoodle.c:10:16: warning: initialization from incompatible pointer type [-Wincompatible-pointer-types]
     char *ap = &a; 
                ^
a: 0x7ffea819a460 
&a: 0x7ffea819a460 
ap: 0x7ffea819a460 

MY remarks: &a will be a pointer to a char pointer, is it not? is that the source of incompatibility
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
    char a[] = "hello";
    printf("a: %p \n", a);
    printf("&a: %p \n", &a);
    char *ap = &a[0];
    printf("ap: %p \n", ap);
}

/* Results
a: 0x7ffc7c5d1bd0 
&a: 0x7ffc7c5d1bd0 
ap: 0x7ffc7c5d1bd0 
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
     char a[] = "hello world";
     
     char *ap = (char*)&a[0];
     char *bp = (char*)&a;
     char *cp = (char*)&a[6];   
     
    printf("ap: \"%s\" \n", ap);
    printf("bp: \"%s\" \n", bp);
    printf("cp: \"%s\" \n", cp);
    
    a[5] = '\0';
    
    printf("ap: \"%s\" \n", ap);
    printf("bp: \"%s\" \n", bp);
    printf("cp: \"%s\" \n", cp);
    
     
}

/*Results
ap: "hello world" 
bp: "hello world" 
cp: "world" 
ap: "hello" 
bp: "hello" 
cp: "world" 

/* Example of a function that takes a pointer to a character to manipulate  string
Purpose: Replace one character with another*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
     char a[] = "Humpty dumpty sat on a wall";
     char search_char = 'u';
     char replace_char = 'o';
     char *ap = (char*)&a[0];
     
     printf("Before \n%s \n", a);
     
     while((ap = strchr(ap, search_char)) != NULL)
     {
         ap[0] = replace_char;
     }
     printf("After \n%s \n", a);
     
}

/* The above is the same as the following*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
     char a[] = "Humpty dumpty sat on a wall";
     char search_char = 'u';
     char replace_char = 'o';
     char *ap = (char*)&a[0];
     
     printf("Before \n%s \n", a);
     
     while(ap  != NULL)
     {
         ap[0] = replace_char;
         ap = strchr(ap, search_char);
     }
     printf("After \n%s \n", a);
     
}

/* Declaring an array of (char *), that is pointers to char to declare and define a string array
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
    char *string_array[5] = {"This", "is", "a", "string", "array"};
    //Interpret the above correctly
    //What it says is that string_array contains 5 elements
    //Each of those elements is a char pointer
    //Remember a string can be created by by creating a string literal and
    //assigning a pointer to the location of spring into elements of the string array
    
    for(int i = 0; i < 5; i++)
    {
        printf("Element %d = %s \n", i, string_array[i]);
    }

     
}
*/

    

