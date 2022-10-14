#include "cpp_stack.h"
#include <iostream>

using namespace std;

int main(){

    Stack my_stack;

    my_stack.push(1);
    my_stack.push(2);
    my_stack.push(3);
    my_stack.push(4);
    my_stack.push(5);
    my_stack.push(6);
    cout << my_stack.pop() << endl
         << my_stack.pop() << endl
         << my_stack.pop() << endl
         << my_stack.pop() << endl
         << my_stack.pop() << endl
//         << my_stack.pop() << endl
         << my_stack.pop() << endl;

    return 0;
}