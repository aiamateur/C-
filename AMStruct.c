#include <stdio.h>

struct pixel{
        unsigned char r;
        unsigned char g;
        unsigned char b;
        unsigned char a[1024];
    };

void print_pixel(struct pixel p)
{
    printf("%u %u %u \n", p.r, p.g, p.b);
    p.r = 0;
    p.g = 128;
    p.b = 0;
}

int main()
{

    
    struct pixel p;
    p.r = 0;
    p.g = 255;
    p.b = 0;
    
    print_pixel(p);
    print_pixel(p);
    
    printf("sizeof(struct pixel) %lu \n", sizeof(struct pixel));
    
    return 0;
}



/*typedef*/

#include <stdio.h>

typedef struct {
        unsigned char r;
        unsigned char g;
        unsigned char b;
        unsigned char a[1024];
    } pixel;

void print_pixel(pixel p)
{
    printf("%u %u %u \n", p.r, p.g, p.b);
    p.r = 0;
    p.g = 128;
    p.b = 0;
}

int main()
{

    
    pixel p;
    p.r = 0;
    p.g = 255;
    p.b = 0;
    
    print_pixel(p);
    print_pixel(p);
    
    printf("sizeof(pixel) %lu \n", sizeof(pixel));
    
    return 0;
}

/*
#include <stdio.h>
#include <stdlib.h>

typedef struct {
        unsigned char r;
        unsigned char g;
        unsigned char b;
        //unsigned char a[1024];
    } pixel;

void print_pixel(pixel p)
{
    printf("%u %u %u \n", p.r, p.g, p.b);
    p.r = 0;
    p.g = 128;
    p.b = 0;
}

void make_redder(pixel *p)
{
    p->r = 255;
}

int main()
{

    
    pixel p = {0, 12, 21};


    print_pixel(p);
    make_redder(&p);
    print_pixel(p);
    
    printf("sizeof(pixel) %lu \n", sizeof(pixel));
    
    pixel *screen =  malloc(1000*sizeof(pixel));
    
    for (int i = 0; i < 1000; i++)
    {
        screen[i].r = (i+1)%256;
        screen[i].g = (i+20)%256;
        screen[i].b = (i+200)%256;
    }
    
    for (int i = 0; i < 10; i++)
    {
        print_pixel(screen[i]);
    }
    
    for (int i = 0; i < 1000; i++)
    {
        make_redder(&screen[i]);
    }
    
    for (int i = 0; i < 10; i++)
    {
        print_pixel(screen[i]);
    }
    
    return 0;
}

/*Nested structures Example*/
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    unsigned char r;
    unsigned char g;
    unsigned char b;
}pixel;

typedef struct{
    int width;
    int height;
    pixel *data;
}screen;

screen *screen_new(int width, int height)
{
    screen *s = malloc(sizeof(screen));
    s->width = width;
    s->height = height;
    s->data = malloc(width*height*sizeof(pixel));
    //The following segment needs to be uncommented
    //Commented it out as it is causing a segmentation fault (core dumped)
    //for(int i=0; i < (s->height); i++)
    //{
        //for(int j=0; j < s->width; j++)
        //{
            //int index = (i*(s->width))+j;
            //s->data[index].r = i;
            //s->data[index].g = j;
            //s->data[index].b = 0;
        //}
    //}
    
}

void screen_free(screen *s)
{
    free(s->data);
    free(s);
}

void screen_print(screen *s)
{
    for (int i = 0; i < s->height; i++)
    {
        for(int j=0; j < s->width; j++)
        {
            int index = (i*(s->width))+j;
            printf("(%u, %u, %u) ", s->data[index].r, s->data[index].g, s->data[index].b);
        }
        printf("\n");
    }
}

int main()
{
    screen *s = screen_new(5,5);
    screen_print(s);
    screen_free(s);
    
    return 0;
}













