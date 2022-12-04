#include "Matrix.h"


void fillByIncrValues(Matrix& m1);

void printTest(const Matrix& m1);
void copyConstructorTest(const Matrix& m1);
void assignmentOperatorTest(const Matrix& m1);
void addOperatorTest(const Matrix& m1, const Matrix& m2);
void subOperatorTest(const Matrix& m1, const Matrix& m2);
void addAssignOperatorTest(Matrix m1, const Matrix& m2);
void subAssignOperatorTest(Matrix m1, const Matrix& m2);


int main(){
    Matrix newM1(5, 4);

    fillByIncrValues(newM1);
    Matrix newM2 = newM1;

    printTest(newM1);
    copyConstructorTest(newM1);
    assignmentOperatorTest(newM1);
    addOperatorTest(newM1, newM2);
    subOperatorTest(newM1, newM2);
    addAssignOperatorTest(newM1, newM2);
    subAssignOperatorTest(newM1, newM2);

    return 0;
}

void fillByIncrValues(Matrix& m1){
    for(int i = 1; i <= m1.getHeight(); i++){
        for(int j = 1; j <= m1.getWidth(); j++){
            m1(i, j) = i*10 + j;
        }
    }
}

void printTest(const Matrix& m1){
    std::cout << "printTest:" << std::endl;
    std::cout << m1 << std::endl;
}

void copyConstructorTest(const Matrix& m1){
    std::cout << "copyConstructorTest:" << std::endl;
    Matrix m2(m1);
    std::cout << m2 << std::endl;
}

void assignmentOperatorTest(const Matrix& m1){
    std::cout << "assignmentOperatorTest:" << std::endl;
    Matrix m2;
    m2 = m1;
    std::cout << m2 << std::endl;
}

void addOperatorTest(const Matrix& m1, const Matrix& m2){
    std::cout << "addOperatorTest:" << std::endl;
    std::cout << m1 + m2 << std::endl;
}

void subOperatorTest(const Matrix& m1, const Matrix& m2){
    std::cout << "subOperatorTest:" << std::endl;
    std::cout << m1 - m2 << std::endl;
}

void addAssignOperatorTest(Matrix m1, const Matrix& m2){
    std::cout << "addAssignOperatorTest:" << std::endl;
    m1 += m2;
    std::cout << m1 << std::endl;
}

void subAssignOperatorTest(Matrix m1, const Matrix& m2){
    std::cout << "subAssignOperatorTest:" << std::endl;
    m1 -= m2;
    std::cout << m1 << std::endl;
}



/*
    +copy constructor                                  (InvalidAllocationException)
    +assignment operator                               (InvalidAllocationException)
    +display operator <<
    arithmetic operators: + - * += -= *=              (InvalidMatrixSizeException)
    comparison operators: == !=                       (DifferentMatrixSizeException)
    ability to read matrix from input file stream     (IOExeption)
    +single element access                             (IndexOutOfBoundException)
*/