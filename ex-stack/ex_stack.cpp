#include "ex_stack.h"

// TODO assignment operator

Stack::Stack()
{
	resetMal(-1, 4);
}

Stack::Stack(const Stack& parent)
{
	resetMal(parent.height, parent.arr_size);
	memcpy(arr, parent.arr, sizeof(int) * arr_size);
}

Stack::~Stack()
{
	free(arr);
}

void Stack::resetReal(int newHeight, int newArrSize)
{
	arr = (int*)realloc(arr, sizeof(int) * newArrSize);
	resetFirstVar(newHeight, newArrSize);
}

void Stack::resetFirstVar(int newHeight, int newArrSize)
{
	height = newHeight;
	arr_size = newArrSize;
	pointerNotNull(arr);
}

void Stack::resetMal(int newHeight, int newArrSize)
{
	arr = (int*)malloc(sizeof(int) * newArrSize);
	resetFirstVar(newHeight, newArrSize);
}

Stack& Stack::operator=(const Stack& parent)
{
	if (this != &parent) {
		if (arr_size < parent.height) {
			resetReal(parent.height, parent.height + 1);
			memcpy(arr, parent.arr, sizeof(int) * arr_size);
		}
		else {
			if (parent.height >= 0) {
				memcpy(arr, parent.arr, sizeof(int) * parent.height + 1);
				height = parent.height;
			}
			else {
				resetReal(-1, 4);
			}
		}
	}
	return *this;
}

bool Stack::isEmpty()
{
	if (height < 0) {
		return 1;
	}
	else {
		return 0;
	}
}

void Stack::push(int value)
{
	if ((height + 1) == arr_size) {
		arr_size *= 2;
		int* new_arr = (int*)malloc(sizeof(int) * arr_size);
		pointerNotNull(new_arr);
		for (int i = 0; i < (arr_size / 2); i++) {
			new_arr[i] = arr[i];
		}
		free(arr);
		arr = new_arr;
	}
	height++;
	arr[height] = value;
}

int Stack::pop()
{
	if (!isEmpty()) {
		height--;
		return arr[height + 1];
	}
	else {
		std::cout << "Stack is empty!" << std::endl;
		abort();
	}
}

void Stack::pointerNotNull(void* p)
{
	if (p == NULL) {
		std::cout << "Allocation problem!" << std::endl;
		abort();
	}
}
