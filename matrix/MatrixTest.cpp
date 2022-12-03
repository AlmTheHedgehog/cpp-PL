#include "Matrix.h"

int main(){
    Matrix newM(5, 4);

    std::cout << newM << std::endl;

    std::cout << newM(1, 2) << std::endl;

    newM(1, 2) = 5;

    std::cout << newM << std::endl;

    return 0;
}