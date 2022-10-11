#include "ex_stack.h"
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
         << my_stack.pop() << endl;

    Stack my_stack2 = my_stack;

    cout
         << my_stack.pop() << endl
//         << my_stack.pop() << endl
         << my_stack.pop() << endl;

    cout
         << my_stack2.pop() << endl
//         << my_stack.pop() << endl
         << my_stack2.pop() << endl;

    return 0;
}