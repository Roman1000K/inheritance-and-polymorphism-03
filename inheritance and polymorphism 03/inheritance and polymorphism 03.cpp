#include <iostream>
#include <Windows.h>

class Figure {
protected:
    int sides_count;
    std::string name;
    
public:
    Figure() : sides_count(0), name("Фигура") {}

    virtual void print_info() {

        std::cout << name << std::endl;

        if (check()) {
            std::cout << "Правильная" << std::endl;
        }
        else {
            std::cout << "Неправильная" << std::endl;
        };
        std::cout << "Количество сторон: " << sides_count << std::endl;
    };

    bool check() {
        return (sides_count==0);
    }
};

class Triangle : Figure {
protected:
    int a, b, c;
    int A, B, C;
    std::string name;

public:
    Triangle() :a(10), b(20), c(30), A(50), B(60), C(70), name("Треугольник") {}

    std::string get_name() { return name; }
    int get_a() { return a; }
    int get_b() { return b; }
    int get_c() { return c; }
    int get_A() { return A; }
    int get_B() { return B; }
    int get_C() { return C; }

    void print_info(Triangle* shape) {
        std::cout << name << std::endl;

        if (check()) {
            std::cout << "Правильная" << std::endl;
        }
        else {
            std::cout << "Неправильная" << std::endl;
        }     
        std::cout << "Количество сторон: 3" << std::endl;
        std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << std::endl;
        std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << std::endl;        
    }

    virtual bool check() {
        return ((A + B + C ) == 180);
    }
};

class RightTriangle : public Triangle {
public:
    RightTriangle() {
        C = 90;
        name = "Прямоугольный треугольник:";
    }   
   bool check()override {
        return C == 90;
    }
  };

class IsoscelesTriangle : public Triangle {
public:
    IsoscelesTriangle() {
        c = 10; C = 50;
        name = "Равнобедренный треугольник:";
    }

    bool check() override {
        return a == c && c == b && b == a;
    }
};

class EquilateralTriangle : public Triangle {
public:
    EquilateralTriangle() {
        a = 30; b = 30;
        A = 60; B = 60; C = 60;
        name = "Равносторонний треугольник:";
    }

    bool check() override {
        return a == c && a == b && A == 60 && B == 60 && C == 60;
    }
};

class Quadrilateral{
protected:
    int a, b, c, d;
    int A, B, C, D;
    std::string name;
public:
    Quadrilateral() : a(10), b(20), c(30), d(40), A(50), B(60), C(70), D(80), name("Четырехугольник:") {}

    std::string get_name() { return name; }
    int get_a() { return a; }
    int get_b() { return b; }
    int get_c() { return c; }
    int get_d() { return d; }
    int get_A() { return A; }
    int get_B() { return B; }
    int get_C() { return C; }
    int get_D() { return D; }

    virtual void print_info(Quadrilateral* shape) {

        std::cout << name << std::endl;

        if (check()) {
            std::cout << "Правильная" << std::endl;
        }
        else {
            std::cout << "Неправильная" << std::endl;
        }
        std::cout << "Количество сторон: 4" << std::endl;
        std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << " d=" << d << std::endl;
        std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << " D=" << D << std::endl;
    }

    virtual bool check() {
        return ((A + B + C + D) == 360);
    }
};

class Parallelogram : public Quadrilateral {
public:
    Parallelogram() {
        a = 20; b = 30; c = 20; d = 30;
        A = 30; B = 40; C = 30; D = 40;
        name = "Параллелограмм:";
    }  

     bool check() override {
     return a == c && b == c && A == C && B == D;
      };
};

class Rectangl : public Quadrilateral {
public:
    Rectangl() {
        a = 10; c = 10; d = 20;
        A = 90; B = 90; C = 90; D = 90;
        name = "Прямоугольник:";
    }
    bool check() override {
        return a == c && b == d && A == 90 && B == 90 && C == 90 && D == 90;
    };
};

class Square : public Rectangl {
public:
    Square() {
        a = 20; c = 20;
        name = "Квадрат:";
    }
    bool check() override {
        return a == c && b == c && d == c && A == 90 && B == 90 && C == 90 && D == 90 ;
    };
};

class Rhomb : public Parallelogram {
public:
    Rhomb() {
        a = 30; b = 30; c = 30; d = 30;
        name = "Ромб:";
    }
    bool check() override {
        return a == c && b == c && d == c && d == a && A == C && B == D;
    };
};


int main() {


    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Figure figure;
    figure.print_info();

    std::cout << std::endl;

    Triangle triangle;   
    triangle.print_info(&triangle);

    std::cout << std::endl;

    RightTriangle rightTriangle;   
    rightTriangle.print_info(&rightTriangle);

    std::cout << std::endl;

    IsoscelesTriangle isoscelesTriangle;
    isoscelesTriangle.print_info(&isoscelesTriangle);

    std::cout << std::endl;

    EquilateralTriangle equilateralTriangle;    
    equilateralTriangle.print_info(&equilateralTriangle);

    std::cout << std::endl;

    Quadrilateral quadrilateral;     
    quadrilateral.print_info(&quadrilateral);

    std::cout << std::endl;

    Rectangl rectangl;    
    rectangl.print_info(&rectangl);

    std::cout << std::endl;

    Parallelogram parallelogram;
    parallelogram.print_info(&parallelogram);

    std::cout << std::endl;

    Square squre;    
    squre.print_info(&squre);

    std::cout << std::endl;

    Rhomb rhomb;    
    rhomb.print_info(&rhomb);    

    return 0;
}