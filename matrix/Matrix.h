#pragma once
#include <iostream>
#include <fstream>
#include <string>
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
        Matrix(std::ifstream& inputFile);
        Matrix& operator=(const Matrix& oldMtrx);
        ~Matrix();

        friend std::ostream& operator<<(std::ostream& stream, const Matrix& dispMatrix);
        double operator()(int row, int column) const;
        Dref operator()(int row, int column);
        Matrix operator+(const Matrix& secondMatrix) const;
        Matrix operator-(const Matrix& secondMatrix) const;
        Matrix& operator+=(const Matrix& secondMatrix);
        Matrix& operator-=(const Matrix& secondMatrix);
        Matrix operator*(const Matrix& secondMatrix) const;
        Matrix& operator*=(const Matrix& secondMatrix);
        bool operator==(const Matrix& secondMatrix) const;
        bool operator!=(const Matrix& secondMatrix) const;

        int getHeight(){return matrixSharedData->height;};
        int getWidth(){return matrixSharedData->width;};

    private:
        MatrixSharedPointer *matrixSharedData;
        static void pointerNotNull(void* ptr);
        void detachCurrentMatrixSharedPointer();
        void matrixIterationOperation(const Matrix& firstMatrix, const Matrix& secondMatrix,
                                    double (*operation)(double firstValue, double secondValue));
        static double addElements(double firstValue, double secondValue);
        static double subElements(double firstValue, double secondValue);
        void checkEqMatrixSize(const Matrix& secondMatrix) const;
        void matrixIterationMultiply(const Matrix& firstMatrix, const Matrix& secondMatrix);
        int getHeightFromSizeString(std::string inputString);
        int getWidthFromSizeString(std::string inputString);
        void readMatrixRowFromFile(std::ifstream& inputFile, int row);

};