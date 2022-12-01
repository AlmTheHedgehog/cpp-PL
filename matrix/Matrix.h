#pragma once
#include <iostream>

class Matrix{
    public:
        Matrix():Matrix(0, 0){};
        Matrix(int height, int weight);
        ~Matrix();

    private:
        double *matrix_ptr;
        int height, weight;
        void pointerNotNull(void* ptr);

};