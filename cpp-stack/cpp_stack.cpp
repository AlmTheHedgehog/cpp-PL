#include "cpp_stack.h"

Stack::Stack(){
    this->height = -1;
    this->arr_size = 4;
    this->arr = (int*)malloc(sizeof(int) * this->arr_size);
}
Stack::~Stack(){
    free(this->arr);
}

bool Stack::isEmpty(){
    if(this->height < 0){
        return 1;
    }else{
        return 0;
    }
}

void Stack::push(int value){
    if((this->height+1) == this->arr_size){
        this->arr_size *= 2;
        int *new_arr = (int*)malloc(sizeof(int) * this->arr_size);
        for(int i = 0; i < (this->arr_size/2); i++){
            new_arr[i] = this->arr[i];
        }
        free(this->arr);
        this->arr = new_arr;
    }
    this->height++;
    this->arr[this->height] = value;
}

int Stack::pop(){
    if(!this->isEmpty()){
        this->height--;
        return this->arr[this->height+1];
    }else{
        std::cout << "Stack is empty!" << std::endl;
        this->~Stack();
        abort();
    }
}