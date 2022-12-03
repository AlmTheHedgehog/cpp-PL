#pragma once
#include <iostream>
#include <exception>

class Matrix{
    public:
        class Dref{
            public:
                Dref(Matrix& sourceMatrix, int dRow, int dColumn):matrixRef(sourceMatrix), 
                                                                row(dRow), column(dColumn){};
                operator double() const;
                Dref& operator=(double value);
                Dref& operator=(const Dref& ref);
            private:
                Matrix& matrixRef;
                int row, column;
        };

        struct MatrixSharedPointer{
            public:
                int height, width, numberOfAccessers;
                double **matrix_ptr;
                MatrixSharedPointer(int newHeight, int newWidth):MatrixSharedPointer(newHeight, newWidth, NULL){};
                MatrixSharedPointer(int newHeight, int newWidth, double **oldMatrix_ptr);
                ~MatrixSharedPointer();
                MatrixSharedPointer* detach();

            private:
                double** matrixMemAlloc(int newHeight, int newWidth, double **oldMatrix_ptr);
        };


        Matrix():Matrix(0, 0){};
        Matrix(int matrixHeight, int matrixWidth);
        Matrix(const Matrix& oldMtrx);
        Matrix& operator=(const Matrix& oldMtrx);
        ~Matrix();
        
        friend std::ostream& operator<<(std::ostream& stream, const Matrix& dispMatrix);
        double operator()(int row, int column) const;
        Dref operator()(int row, int column);

        int getHeight(){return matrixSharedData->height;};
        int getWidth(){return matrixSharedData->width;};

    private:
        MatrixSharedPointer *matrixSharedData;
        static void pointerNotNull(void* ptr);
        void detachCurrentMatrixSharedPointer();

};