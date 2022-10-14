#include "ex_stack.h"
#include <iostream>

using namespace std;

int main(){
    Stack my_stack;
    Stack my_stack3;

	for (int i = 1; i < 7; i++) {
		my_stack.push(i);
	}
    Stack my_stack2(my_stack);

	for (int i = 0; i < 5; i++) {
        cout << "stack1 pop - " << my_stack.pop() << endl;
	}

	for (int i = 0; i < 50; i++) {
        my_stack2.push(i);
	}
	cout << "stack2 pop - " << my_stack2.pop() << endl;

    my_stack3 = my_stack2;
    for (int i = 0; i < 50; i++) {
        my_stack3.push(i);
	}
	cout << "stack3 pop - " << my_stack3.pop() << endl;

	return 0;


    
    return 0;
}