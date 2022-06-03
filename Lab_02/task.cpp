#include <iostream>
#include <string>
#include <stdexcept>

using std::cout;
using std::endl;
using std::cerr;


class MyV {
public:
    int* arrBlock;
    int arrSize;
    MyV(int index = 5) {
        this->arrBlock = new int[index];
        this->arrSize = index;
    }

    int& at(int i) {
        if (i >= arrSize) {
            throw std::out_of_range("The paramter is greater than total array block\n");
        }
        return arrBlock[i];
    }
    MyV& operator=(MyV& src) {
        if (this == &src) {
            throw std::invalid_argument("The LHS and RHS operand are same\n");
        }
        else {
            this->arrBlock = new int[src.arrSize];
            for (int i = 0; i < src.arrSize; i++) {
                this->arrBlock[i] = src.at(i);
            }
            this->arrSize = src.arrSize;
            return *this;
        }
    }

    MyV& operator+(MyV& src) {
        if (this->arrSize == src.arrSize) {
            for (int i = 0; i < src.arrSize; i++) {
                this->arrBlock[i] += src.at(i);
            }
            return *this;
        }
        else {
            throw std::invalid_argument("The vector paramter is invalid because the two vector has different size\n");
        }
    }


    MyV& operator-(MyV& src) {
        if (this->arrSize == src.arrSize) {
            for (int i = 0; i < src.arrSize; i++) {
                this->arrBlock[i] -= src.at(i);
            }
            return *this;
        }
        else {
            throw std::invalid_argument("The vector paramter is invalid because the two vector has different size\n");
        }
    }

    ~MyV() {
        delete[] arrBlock;
    }
};

int main()
{
    try {
        //creating MyV objects with number of array block
        MyV a(2);
        MyV b(2);
        MyV c(4);

        //asssigning values
        a.at(0) = 4;
        a.at(1) = 5;

        b.at(0) = 19;
        b.at(1) = 10;

        cout << "a.at(0): " << a.at(0) << "\na.at(1): " << a.at(1) << "\n\n";
        cout << "b.at(0): " << b.at(0) << "\nb.at(1): " << b.at(1) << "\n\n";


        //calling the operator-() on `b` which will remove `a` from `b`, this will work because both of them have the same array size
        //b.operator-(a);
        b - a;
        cout << "New `b` object after removing `a` from it. \nb.at(0): " << b.at(0) << "\nb.at(1): " << b.at(1) << "\n\n";


        //Object `c` does not have an equal size with `b` so this operation will throw an out of range exception
        //a + c;

        //this will make object `c` to have same array size and values as `b`
        //c.operator=(b);
        c = b;
        cout << "Printing the `c` object after equating it to  `b` from it. \nc.at(0): " << c.at(0) << "\nc.at(1): " << c.at(1) << "\n\n";

    }
    catch (const std::out_of_range& ex) {
        cerr << "Out of Range Exception: " << ex.what() << endl;
    }
    catch (const std::invalid_argument& ex) {
        cerr << "Invalid Argument: "<< ex.what()  << endl;
    }
}
