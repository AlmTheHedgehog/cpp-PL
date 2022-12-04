#include "Matrix.h"

void fillByIncrValues(Matrix& m1);

void printTest(const Matrix& m1);
void copyConstructorTest(const Matrix& m1);
void assignmentOperatorTest(const Matrix& m1);
void addOperatorTest(const Matrix& m1, const Matrix& m2);
void subOperatorTest(const Matrix& m1, const Matrix& m2);
void multOperatorTest(const Matrix& m1, const Matrix& m2);
void addAssignOperatorTest(Matrix m1, const Matrix& m2);
void subAssignOperatorTest(Matrix m1, const Matrix& m2);
void multAssignOperatorTest(Matrix m1, const Matrix& m2);
void eqOperatorTest(const Matrix& m1, const Matrix& m2);
void notEqOperatorTest(const Matrix& m1, const Matrix& m2);
void test(const Matrix& newM1, const Matrix& newM2, const Matrix& newM3, const Matrix& newM4);


int main(){
    Matrix newM1(5, 4), newM3(4, 3);

    fillByIncrValues(newM1);
    Matrix newM2 = newM1, newM4 = newM1;
    fillByIncrValues(newM3);
    newM4(3, 2) = 8;

    test(newM1, newM2, newM3, newM4);

    return 0;
}

void fillByIncrValues(Matrix& m1){
    for(int i = 1; i <= m1.getHeight(); i++){
        for(int j = 1; j <= m1.getWidth(); j++){
            m1(i, j) = i*10 + j;
        }
    }
}

void test(const Matrix& newM1, const Matrix& newM2, const Matrix& newM3, const Matrix& newM4){
    /*
        newM1 has to be equal to newM2(same size and values)
        newM3 has to have proper size for multiplication by newM1 (newM3 height = newM1 width)
        newM4 has to have the same size as newM1, but different values
        ---
        newM1 = newM2
        newM3.height = newM1.width
        newM4.size = newM1.size, newM4 != newM1
    */
    printTest(newM1);
    copyConstructorTest(newM1);
    assignmentOperatorTest(newM1);
    addOperatorTest(newM1, newM2);
    subOperatorTest(newM1, newM2);
    multOperatorTest(newM1, newM3);
    addAssignOperatorTest(newM1, newM2);
    subAssignOperatorTest(newM1, newM2);
    multAssignOperatorTest(newM1, newM3);
    std::cout << "Have to be true:" << std::endl;
    eqOperatorTest(newM1, newM2);
    std::cout << "Have to be false:" << std::endl;
    eqOperatorTest(newM1, newM4);
    std::cout << "Have to be false:" << std::endl;
    notEqOperatorTest(newM1, newM2);
    std::cout << "Have to be true:" << std::endl;
    notEqOperatorTest(newM1, newM4);
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

void multOperatorTest(const Matrix& m1, const Matrix& m2){
    std::cout << "multOperatorTest:" << std::endl;
    std::cout << m1 * m2 << std::endl;
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

void multAssignOperatorTest(Matrix m1, const Matrix& m2){
    std::cout << "multAssignOperatorTest:" << std::endl;
    m1 *= m2;
    std::cout << m1 << std::endl;
}

void eqOperatorTest(const Matrix& m1, const Matrix& m2){
    std::cout << "eqOperatorTest:" << std::endl;
    std::cout << "m1:" << std::endl << m1 << "m2:" << std::endl << m2 << (m1==m2) << std::endl << std::endl;
}

void notEqOperatorTest(const Matrix& m1, const Matrix& m2){
    std::cout << "notEqOperatorTest:" << std::endl;
    std::cout << "m1:" << std::endl << m1 << "m2:" << std::endl << m2 << (m1!=m2) << std::endl << std::endl;
}



/*
    +copy constructor                               (InvalidAllocationException)
    +assignment operator                            (InvalidAllocationException)
    +display operator <<
    +arithmetic operators: + - * += -= *=           (InvalidMatrixSizeException) - mult; (DifferentMatrixSizeException) - others
    +comparison operators: == !=                    (DifferentMatrixSizeException)
    ability to read matrix from input file stream  (IOExeption)
    +single element access                          (IndexOutOfBoundException)
*/