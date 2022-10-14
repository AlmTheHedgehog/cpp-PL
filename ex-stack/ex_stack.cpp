#include "ex_stack.h"

//TODO assignment operator

Stack::Stack(){
    height = -1;
    arr_size = 4;
    arr = (int*)malloc(sizeof(int) * this->arr_size);
    pointerNotNull(arr);
}

Stack::Stack(const Stack &parent){
    height = parent.height;
    arr_size = parent.arr_size;
    arr = (int*)malloc(sizeof(int) * arr_size);
    pointerNotNull(arr);
    memcpy(arr, parent.arr, sizeof(int) * arr_size);
}

Stack::~Stack(){
    free(arr);
}

Stack& Stack::operator=(const Stack &parent){
    if(this != &parent){
        height = parent.height;
        arr_size = parent.arr_size;
        free(arr);
        arr = (int*)malloc(sizeof(int) * arr_size);
        pointerNotNull(arr);
        memcpy(arr, parent.arr, sizeof(int) * arr_size);
    }
    return *this;    
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
        pointerNotNull(new_arr);
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
        abort();
    }
}

void Stack::pointerNotNull(void *p){
    if(p == NULL){
        std::cout << "Allocation problem!" << std::endl;
        abort();
    }
}

