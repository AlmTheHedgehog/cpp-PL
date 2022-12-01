#include "Matrix.h"

Matrix::Matrix(int height, int weight){
    matrix_ptr = (double*)malloc(sizeof(double)*height*weight);
    pointerNotNull(matrix_ptr);
}

Matrix::~Matrix(){
    free(matrix_ptr);
}

void Matrix::pointerNotNull(void* ptr){
    if(ptr == NULL){
        std::cout << "Allocation problem!";
        abort;
    }
}