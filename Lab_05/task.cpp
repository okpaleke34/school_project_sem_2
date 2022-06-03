
#include <iostream>
class err0 {
public:
    std::string msg;
    err0(std::string msg) {
        this->msg = msg;
    }
};

class err1 {
public:
    std::string msg;
    err1(std::string msg) {
        this->msg = msg;
    }
};

class MyStack {
private:
    int* stack;
    int length;
public:
    MyStack() {
        length = 0;
        stack = new int[10];
    }
    ~MyStack() {
        delete[] stack;
    }
    void push(int val) {
        if (this->length == 10) {
            throw err1("Out of Memory");
        }
        this->stack[length] = val;
        this->length++;
    }
    void pop() {

        if (this->length == 0) {
            throw err0("Empty Stack Condition");
        }
        else {
            this->length--;
        }
    }
    void size() {
        std::cout << "The length of my stack is " << this->length;
    }
    void print() {
        if (length == 0) {
            std::cout << "There is no element in this stack\n";
        }
        else {
            std::cout << "The list of elements in my stack are: \n";
            for (int i = 0; i < length; i++) {
                std::cout << stack[i] << "\n";
            }
        }
    }
};
int main()
{

    try {
        MyStack money;
        money.push(9);
        money.push(4);
        money.push(23);
        money.pop();
        money.print();
    }
    catch (err0 x) {
        std::cerr << x.msg << " There is no element in the stack " << '\n';
    }
    catch (err1 x) {
        std::cerr << x.msg << " The maximum memory for the stack is 10 elements" << '\n';
    }
}
