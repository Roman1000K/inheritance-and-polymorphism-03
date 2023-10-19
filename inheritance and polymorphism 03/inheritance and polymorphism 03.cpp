#include <iostream>
#include <Windows.h>

class Figure {
private:
    int sides_count;

protected:
    Figure(int sides) : sides_count(sides) {}

public:
    Figure() : Figure(0) {}

    virtual void print_info() {

        std::cout << "Фигура:" << std::endl;

        if (check()) {
            std::cout << "Правильная" << std::endl;
        }
        else {
            std::cout << "Неправильная" << std::endl;
        };

        std::cout << "Количество сторон:"<< " " << sides_count << std::endl;

    };
    virtual bool check() {
        return (sides_count==0);
    }
};

class Triangle {
protected:
    int a, b, c;
    int A, B, C;

public:
    Triangle(int a, int b, int c, int A, int B, int C) : a(a), b(b), c(c), A(A), B(B), C(C) {}

    int get_a() { return a; }
    int get_b() { return b; }
    int get_c() { return c; }
    int get_A() { return A; }
    int get_B() { return B; }
    int get_C() { return C; }

    virtual void print_info(Triangle* shape) {

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
    RightTriangle(int a, int b, int c, int A, int B) : Triangle(a, b, c, A, B, 90) {}

    void  print_info(Triangle* shape) override {
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
        return C == 90;
    }
  };

class IsoscelesTriangle : public Triangle {
public:
    IsoscelesTriangle(int a, int c, int A, int B) : Triangle(a, c, a, A, B, A) {}

    void  print_info(Triangle* shape) override {
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
        return a == c && c == b && b == a;
    }
};

class EquilateralTriangle : public Triangle {
public:
    EquilateralTriangle(int a) : Triangle(a, a, a, 60, 60, 60) {}

    void  print_info(Triangle* shape) override {
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
        return a == c && a == b && A == 60 && B == 60 && C == 60;
    }
};


class Quadrilateral {
protected:
    int a, b, c, d;
    int A, B, C, D;
public:
    Quadrilateral(int a, int b, int c, int d, int A, int B, int C, int D) : a(a), b(b), c(c), d(d), A(A), B(B), C(C), D(D) {}

    int get_a() { return a; }
    int get_b() { return b; }
    int get_c() { return c; }
    int get_d() { return d; }
    int get_A() { return A; }
    int get_B() { return B; }
    int get_C() { return C; }
    int get_D() { return D; }

    virtual void print_info(Quadrilateral* shape) {

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
    Parallelogram(int a, int b, int A, int B) : Quadrilateral(a, b, a, b, A, B, A, B) {}

    void print_info(Quadrilateral* shape) override {      

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

     bool check() override {
     return a == c && b == c && A == C && B == D;
      };


};

class Rectangl : public Quadrilateral {
public:
    Rectangl(int a, int b) : Quadrilateral(a, b, a, b, 90, 90, 90, 90) {}

    void print_info(Quadrilateral* shape) override {
       
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
    bool check() override {
        return a == c && b == D && A == 90 && B == 90 && C == 90 && D == 90;
    };
};

class Square : public Rectangl {
public:
    Square(int a) : Rectangl(a, a) {}

    void print_info(Quadrilateral* shape) override {

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
    bool check() override {
        return a == c && b == c && d == c && A == 90 && B == 90 && C == 90 && D == 90 ;
    };
};


class Rhomb : public Parallelogram {
public:
    Rhomb(int a, int A, int B) : Parallelogram(a, a, A, B) {}

    void print_info(Quadrilateral* shape) override {        
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
    bool check() override {
        return a == c && b == c && d == c && d == a && A == C && B == D;
    };
};

//void print_info(Triangle* shape) {
//    std::cout << "Стороны: a=" << shape->get_a() << " b=" << shape->get_b() << " c=" << shape->get_c() << std::endl;
//
//    std::cout << "Углы: A=" << shape->get_A() << " B=" << shape->get_B() << " C=" << shape->get_C() << std::endl;
//}


int main() {


    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Figure figure;
    figure.print_info();

    std::cout << std::endl;

    Triangle triangle(10, 20, 30, 50, 60, 70);
    std::cout << "Треугольник:" << std::endl;
    triangle.print_info(&triangle);

    std::cout << std::endl;

    RightTriangle rightTriangle(10, 20, 30, 50, 60);
    std::cout << "Прямоугольный треугольник:" << std::endl;
    rightTriangle.print_info(&rightTriangle);

    std::cout << std::endl;

    IsoscelesTriangle isoscelesTriangle(10, 20, 50, 60);
    std::cout << "Равнобедренный треугольник:" << std::endl;
    isoscelesTriangle.print_info(&isoscelesTriangle);

    std::cout << std::endl;

    EquilateralTriangle equilateralTriangle(10);
    std::cout << "Равносторонний треугольник:" << std::endl;
    equilateralTriangle.print_info(&equilateralTriangle);

    std::cout << std::endl;

    Quadrilateral quadrilateral(10, 20, 30, 40, 50, 60, 70, 80);  
    std::cout << "Четырехугольник:" << std::endl;
    quadrilateral.print_info(&quadrilateral);

    std::cout << std::endl;

    Rectangl rectangl(10, 20); 
    std::cout << "Прямоугольник:" << std::endl;
    rectangl.print_info(&rectangl);

    std::cout << std::endl;

    Parallelogram parallelogram(20, 30, 30, 40); 
    std::cout << "Параллелограмм:" << std::endl;
    parallelogram.print_info(&parallelogram);

    std::cout << std::endl;

    Square squre(20);  
    std::cout << "Квадрат:" << std::endl;
    squre.print_info(&squre);

    std::cout << std::endl;

    Rhomb rhomb(30, 40, 30); 
    std::cout << "Ромб:" << std::endl;
    rhomb.print_info(&rhomb);

    

    return 0;
}