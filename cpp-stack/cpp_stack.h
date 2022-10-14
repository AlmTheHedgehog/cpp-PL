#pragma once
#include <iostream>
#include <cstdlib>

class Stack{
    public:
        Stack();
        ~Stack();
        void push(int value);
        int pop();
        bool isEmpty();

    private:
        int height;
        int *arr;
        int arr_size;
};