#include <iostream>

using namespace std;

//Abstract Base Class
class Shapes{
    public:
    //Version 1: virtual void draw() = 0; //Pure Virtual Function
    //Version 2:
    virtual void draw() = 0;
    {
        cout << "Shape: Init Brush" << endl;
    }
};

//Concrete Class
class Polygon: public Shapes{
    public:
    void draw(){
        cout << "Polygon: Draw by Triangulation"<< endl;
    }
};

//Abstract Base Class
class ClosedConics: public Shapes{
     //draw inherited -- Pure Virtual
};

//Concrete Class
class Triangle: public Polygon{
    public:
    void draw(){
        cout << "Triangle: Draw by Lines"<< endl;
    }
};

//Concrete Class
class Quadrilateral: public Polygon{
    public:
    void draw(){
        cout << "Quadrilateral: Draw by Lines"<< endl;
    }
};

//Concrete Class
class Circle: public ClosedConics{
    public:
    void draw(){
        cout << "Circle: Draw by Breshenham Algorithm"<< endl;
    }
};

//Concrete Class
class Ellipse: public ClosedConics{
    public:
    void draw(){
        cout << "Circle: Draw by ..."<< endl;
    }
};

int main()
{
   Shapes *arry[] = {new Triangle, new Quadrilateral, new Circle, new Ellipse};
   //for (int i=0; i < sizeof(arry)/sizeof(Shapes *); i++)
   for (int i=0; i < 4; ++i)
   {
       arry[i]->draw();
       //cout << i << endl;
   }
   
   return 0;
}

