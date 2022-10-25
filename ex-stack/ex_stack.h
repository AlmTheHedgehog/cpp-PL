#pragma once
#include <iostream>
#include <cstdlib>
#include <cstring>

class Stack{
    public:
        Stack();
        Stack(const Stack &parent);
        ~Stack();
        Stack& operator=(const Stack &parent);
        void pointerNotNull(void *p);
        void resetMal(int newHeight, int newArrSize);
        void resetReal(int newHeight, int newArrSize);
        void resetFirstVar(int newHeight, int newArrSize);
        void push(int value);
        int pop();
        bool isEmpty();

    private:
        int height;
        int *arr;
        int arr_size;
};
