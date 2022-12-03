#include "Matrix.h"


void fillByIncrValues(Matrix& m1);

void printTest(const Matrix& m1);
void copyConstructorTest(const Matrix& m1);
void assignmentOperatorTest(const Matrix& m1);


int main(){
    Matrix newM1(5, 4);

    fillByIncrValues(newM1);

    printTest(newM1);
    copyConstructorTest(newM1);
    assignmentOperatorTest(newM1);

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