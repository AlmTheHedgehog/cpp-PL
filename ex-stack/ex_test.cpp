#include "ex_stack.h"
#include <iostream>

using namespace std;

int main(){
    Stack my_stack1;
    Stack my_stack3;
	Stack my_stack4;

	my_stack4 = my_stack3;
	cout << "stack4 isEmpty - " << my_stack4.isEmpty() << endl;

	for (int i = 1; i < 8; i++) {
		my_stack1.push(i);
	}
    Stack my_stack2(my_stack1);

	my_stack1 = my_stack2;
	cout << "stack1(eq) pop - " << my_stack1.pop() << endl;

	for (int i = 0; i < 5; i++) {
        cout << "stack1 pop - " << my_stack1.pop() << endl;
	}

	for (int i = 0; i < 50; i++) {
        my_stack2.push(i);
	}
	cout << "stack2 pop - " << my_stack2.pop() << endl;

	my_stack2 = my_stack2;
	cout << "stack2(same) pop - " << my_stack2.pop() << endl;

    my_stack3 = my_stack2;
    for (int i = 0; i < 100; i++) {
        my_stack3.push(i);
	}
	cout << "stack3(smaller) pop - " << my_stack3.pop() << endl;

	my_stack3 = my_stack2;
	cout << "stack3(bigger) pop - " << my_stack3.pop() << endl;

	return 0;
}