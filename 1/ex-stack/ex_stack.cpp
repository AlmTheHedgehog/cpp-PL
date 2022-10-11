#include "ex_stack.h"

//TODO assignment operator

Stack::Stack(){
    height = -1;
    arr_size = 4;
    arr = (int*)malloc(sizeof(int) * this->arr_size);
}

Stack::Stack(const Stack &parent){
    height = parent.height;
    arr_size = parent.arr_size;
    arr = (int*)malloc(sizeof(int) * arr_size);
    memcpy(arr, parent.arr, sizeof(int) * arr_size);
}

Stack::~Stack(){
    free(arr);
}

bool Stack::isEmpty(){
    if(height < 0){
        return 1;
    }else{
        return 0;
    }
}

void Stack::push(int value){
    if((height+1) == arr_size){
        arr_size *= 2;
        int *new_arr = (int*)malloc(sizeof(int) * arr_size);
        for(int i = 0; i < (arr_size/2); i++){
            new_arr[i] = arr[i];
        }
        free(arr);
        arr = new_arr;
    }
    height++;
    arr[height] = value;
}

int Stack::pop(){
    if(!isEmpty()){
        height--;
        return arr[height+1];
    }else{
        std::cout << "Stack is empty!" << std::endl;
        this->~Stack();
        abort();
    }
}

