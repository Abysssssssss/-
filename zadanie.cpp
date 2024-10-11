#define _USE_MATH_DEFINES
#include<iostream>
#include<cmath>
#include <iomanip>

using namespace std;

class Shape{
  public:
  virtual double area() const=0;
  virtual double perimeter() const=0;

  virtual ~Shape() {};
};

class Rectangle: public Shape{
  public:
    double area() const override{
      return width*height;
    }

    double perimeter() const override{
      return width*2+height*2;
    }

    Rectangle(double width, double height){
      this->width=width;
      this->height=height;
    }
    ~Rectangle() override{
      cout << "\n" << "Прямоугольник уничтожен";
    }
  private:
    double width;
    double height;
};

class Circle: public Shape{
  public:
    double area() const override{
      return M_PI*radius*radius;
    }

    double perimeter() const override{
      return 2*M_PI*radius;
    }

    Circle(double radius){
      this->radius=radius;
    }

    ~Circle() override{
      cout << "\n" << "Круг уничтожен";
    }

  private:
    double radius;
};


void printShapeInfo(const Shape& buff){
  cout << fixed;
  cout << "Площадь: " << buff.area() << " Периметр: " << buff.perimeter();
}

int main(){
  setlocale(LC_ALL,"RUSSIAN");
  Rectangle rectangle{1000,1000};
  Circle circle{10};
  printShapeInfo(rectangle);
  cout << endl;
  printShapeInfo(circle);
  return 0;
}