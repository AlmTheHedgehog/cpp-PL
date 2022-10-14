#include <stdio.h>
#include "stack.h"

int main(){
    stack my_stack;

    init(&my_stack);
    push(&my_stack, 1);
    push(&my_stack, 2);
    push(&my_stack, 3);
    push(&my_stack, 4);
    push(&my_stack, 5);
    push(&my_stack, 6);
    printf("%d\n", pop(&my_stack));
    printf("%d\n", pop(&my_stack));
    printf("%d\n", pop(&my_stack));
    printf("%d\n", pop(&my_stack));
    printf("%d\n", pop(&my_stack));
    //printf("%d\n", pop(&my_stack));
    //printf("%d\n", pop(&my_stack));
    //printf("%d\n", pop(&my_stack));

    destroy(&my_stack);
    return 0;
}

void init(stack *s){
    s->height = -1;
    s->arr_size = 4;
    s->arr = malloc(sizeof(int) * s->arr_size);
}

bool isEmpty(stack *s){
    if(s->height < 0){
        return 1;
    }else{
        return 0;
    }
}

void destroy(stack *s){
    free(s->arr);
}

void push(stack *s, int value){
    if((s->height+1) == s->arr_size){
        s->arr_size *= 2;
        int *new_arr = malloc(sizeof(int) * s->arr_size);
        for(int i = 0; i < (s->arr_size/2); i++){
            new_arr[i] = s->arr[i];
        }
        free(s->arr);
        s->arr = new_arr;
    }
    s->height++;
    s->arr[s->height] = value;
}

int pop(stack *s){
    if(!isEmpty(s)){
        s->height--;
        return s->arr[s->height+1];
    }else{
        printf("Stack is empty!");
        destroy(s);
        abort();
    }
}