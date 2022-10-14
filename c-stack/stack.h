#pragma once
#include <stdlib.h>
#include <stdbool.h>

typedef struct{
    int height;
    int *arr;
    unsigned int arr_size;
}stack;

void init(stack *s);
void push(stack *s, int value);
void destroy(stack *s);
int pop(stack *s);
bool isEmpty(stack *s);