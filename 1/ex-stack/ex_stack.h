#pragma once
#include <iostream>
#include <cstdlib>
#include <cstring>

class Stack{
    public:
        Stack();
        Stack(const Stack &parent);
        ~Stack();
        void push(int value);
        int pop();
        bool isEmpty();

    private:
        int height;
        int *arr;
        int arr_size;
};