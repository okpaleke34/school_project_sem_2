// Lab3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using std::string;

class Figure {
protected:
    int x, y;
    string color;
public:
    Figure(int i, int j, string myColor) {
        this->x = i;
        this->y = j;
        this->color = myColor;
    };

    virtual void Draw() {
        std::cout << "Nothing to draw\n";
    }
    virtual void Print() {
        std::cout << "Nothing to print\n";
    }
};

class Circle : public Figure {
private:
    int r;
public:
    Circle(int i, int j, string myColor, int radius) :Figure(i, j, myColor)
    {
        this->x = i;
        this->y = j;
        this->color = myColor;
        this->r = radius;
    };
    void Draw() {
        std::cout << "Now drawing a " << color << " circle\n";
    }
    void Print() {
        std::cout << "Drawing a " << color << " circle with radius " << r << " at x -" << x << " and y - " << y << "\n";
    }
};

class Square : public Figure {
private:
    int a;
public:
    Square(int i, int j, string myColor, int length) :Figure(i, j, myColor)
    {
        this->x = i;
        this->y = j;
        this->color = myColor;
        this->a = length;
    };
    void Draw() {
        std::cout << "Now drawing a " << color << " square\n";
    }
    void Print() {
        std::cout << "Drawing a " << color << " circle with radius " << a << " at x -" << x << " and y - " << y << "\n";
    }
};
int main()
{
    Figure* pf;
    pf = new Circle(1, 2, "green", 39);
    pf->Draw();

    Circle ci(2, 3, "Orange", 14);
    ci.Draw();

    Square sq(2, 3, "Blue", 35);
    sq.Draw();

    Figure* ff[5];
    ff[0] = new Circle(1, 2, "Red", 48);
    ff[0]->Draw();
    ff[0]->Print();

}