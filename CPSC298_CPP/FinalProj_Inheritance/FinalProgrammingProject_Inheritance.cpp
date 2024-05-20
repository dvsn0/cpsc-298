#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Shape{
    public:
        Shape(double dHeight, double dWidth){
            this->m_dHeight = dHeight;
            this->m_dWidth = dWidth;
            this->m_strType = "";
        }
        virtual ~Shape(){
            cout << "Shape destructor called" << endl;
        }
        virtual void scale(double dScaleFactor) = 0;
        virtual double area() = 0;
        virtual double perimeter() = 0;
        virtual void displayProperties(){
            std::cout << "Shape Type: " << m_strType << ", height : " << m_dHeight << " width: " << m_dWidth << endl;
        }

    protected:
        double m_dHeight;
        double m_dWidth;
        std::string m_strType;
};

class Rectangle : public Shape{
    public:
        Rectangle(double dHeight, double dWidth) : Shape(dHeight, dWidth){
            this->m_strType = "Rectangle";
        }
        virtual ~Rectangle(){
            cout << "Rectangle destructor called" << endl;
        }
        void scale(double dScaleFactor){
            this->m_dHeight *= dScaleFactor;
            this->m_dWidth *= dScaleFactor;
        }
        double area(){
            return m_dHeight * m_dWidth;
        }
        double perimeter(){
            return (m_dHeight * 2) + (m_dWidth * 2);
        }
};

class Circle : public Shape{
    public:
        Circle(double dHeight, double dWidth) : Shape(dHeight, dWidth){
            this->m_dHeight = dHeight;
            this->m_dWidth = dWidth;
            this->m_strType = "Circle";
        }
        virtual ~Circle(){
            cout << "Circle destructor called" << endl;
        }
        void scale(double dScaleFactor){
            this->m_dHeight *= dScaleFactor;
            this->m_dWidth *= dScaleFactor;
        }
        double area(){
            return (m_dHeight / 2) * (m_dHeight / 2) * M_PI;
        }
        double perimeter(){
            return M_PI * m_dHeight;
        }
};

int main(){
    Rectangle* p_shapeRectangle = new Rectangle(2.0, 3.0);
    Circle* p_shapeCircle = new Circle(2.0, 2.0);

    Shape* p_shapes[2];

    p_shapes[0] = p_shapeCircle;
    p_shapes[1] = p_shapeRectangle;

    for(int i = 0; i < 2; i++){
        p_shapes[i]->displayProperties();
        cout << "Area: " << p_shapes[i]->area() << ", Perimeter: " << p_shapes[i]->perimeter() << endl;
        p_shapes[i]->scale(2.0);
        p_shapes[i]->displayProperties();
        cout << "Area: " << p_shapes[i]->area() << ", Perimeter: " << p_shapes[i]->perimeter() << endl;
    }

    for(int i = 0; i < 2; i++){
        delete p_shapes[i];
    }
}