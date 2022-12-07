#include "Matrix.h"
#include "MatrixExeptions.h"
//#define DEBUG_ENABLED

//class Matrix
Matrix::Matrix(int matrixHeight, int matrixWidth){
    matrixSharedData = new MatrixSharedPointer(matrixHeight, matrixWidth);
}

Matrix::Matrix(std::ifstream& inputFile){
    std::string line;
    int matrixHeight, matrixWidth;
    if (inputFile.is_open()){
        getline(inputFile,line);
        matrixHeight = getHeightFromSizeString(line);
        matrixWidth = getWidthFromSizeString(line);
        matrixSharedData = new MatrixSharedPointer(matrixHeight, matrixWidth);
        for(int row = 0; row < matrixHeight; row++){
            try{
                readMatrixRowFromFile(inputFile, row);
            }catch(std::exception& e){
                throw WrongInputMatrixDataException();
            }
        }
    }else{
        throw IOException();
    }
}

void Matrix::readMatrixRowFromFile(std::ifstream& inputFile, int row){
    std::string line;
    int index;
    getline(inputFile,line);
    for(int colomn = 0; colomn < matrixSharedData->width; colomn++){
        index = 0;
        if(line.size() == 0){
            throw WrongInputMatrixDataException();
        }
        while((index < ((int)line.size())) && (line[index] != ' ')){
            index++;
        }
        operator()(row+1, colomn+1) = std::stod(line.substr(0, index));
        if(colomn < (matrixSharedData->width-1)){
            line = line.substr(index+1, line.size() - index+1);
        }
    }
}

Matrix::Matrix(const Matrix& oldMtrx){
    oldMtrx.matrixSharedData->numberOfAccessers++;
    matrixSharedData = oldMtrx.matrixSharedData;
}

Matrix& Matrix::operator=(const Matrix& oldMtrx){
    oldMtrx.matrixSharedData->numberOfAccessers++;
    detachCurrentMatrixSharedPointer();
    matrixSharedData = oldMtrx.matrixSharedData;
    return *this;
}

Matrix::~Matrix(){
    detachCurrentMatrixSharedPointer();
}

void Matrix::detachCurrentMatrixSharedPointer(){
    (matrixSharedData->numberOfAccessers)--;
    if((matrixSharedData->numberOfAccessers) == 0){
        delete matrixSharedData;
    }
}

void Matrix::pointerNotNull(void* ptr){
    if(ptr == NULL){
        throw InvalidAllocationException();
    }
}

int Matrix::getHeightFromSizeString(std::string inputString){
    int index = 0, res;
    while((index < (int)inputString.size()) && (inputString[index] != ',')){
        index++;
    }
    if(index == (int)inputString.size()){
        throw WrongInputMatrixDataException();
    }
    try{
        res = std::stoi(inputString.substr(0, index));
    }catch(std::exception& e){
        throw WrongInputMatrixDataException();
    }
    return res;
}
int Matrix::getWidthFromSizeString(std::string inputString){
    int index = inputString.size() - 1, res;
    while((index > 0) && (inputString[index] != ' ')){
        index--;
    }
    if(index == 0){
        throw WrongInputMatrixDataException();
    }
    try{
        res = std::stoi(inputString.substr(index+1, inputString.size() - 1 - index));
    }catch(std::exception& e){
        throw WrongInputMatrixDataException();
    }
    return res;
}

std::ostream& operator<<(std::ostream& stream, const Matrix& dispMatrix){
    for(int i = 0; i < dispMatrix.matrixSharedData->height; i++){
        for(int j = 0; j < dispMatrix.matrixSharedData->width; j++){
            stream << dispMatrix.matrixSharedData->matrix_ptr[i][j] << " ";
        }
        stream << std::endl;
    }
    return stream;
}

double Matrix::operator()(int row, int column) const{
    #ifdef DEBUG_ENABLED
        std::cout << "Const accessor was called" << std::endl;
    #endif
    if(!(((row >=1) && (row <= matrixSharedData->height)) &&
        ((column >=1) && (column <= matrixSharedData->width)))){
        throw IndexOutOfBoundException();
    }
    return matrixSharedData->matrix_ptr[row-1][column-1];
}

Matrix::Dref Matrix::operator()(int row, int column){
    if(!(((row >=1) && (row <= matrixSharedData->height)) &&
        ((column >=1) && (column <= matrixSharedData->width)))){
        throw IndexOutOfBoundException();
    }
    return Dref(*this, row-1, column-1);
}

void Matrix::matrixIterationOperation(const Matrix& firstMatrix, const Matrix& secondMatrix, 
                                    double (*operation)(double firstValue, double secondValue)){
    for(int i = 1; i <= matrixSharedData->height; i++){
        for(int j = 1; j <= matrixSharedData->width; j++){
            operator()(i, j) = operation(firstMatrix(i, j), secondMatrix(i, j));
        }
    }
}
double Matrix::addElements(double firstValue, double secondValue){
    return firstValue + secondValue;
}
double Matrix::subElements(double firstValue, double secondValue){
    return firstValue - secondValue;
}

void Matrix::checkEqMatrixSize(const Matrix& secondMatrix) const{
    if((matrixSharedData->height != secondMatrix.matrixSharedData->height) ||
            (matrixSharedData->width != secondMatrix.matrixSharedData->width)){
        throw DifferentMatrixSizeException();
    }
}

Matrix Matrix::operator+(const Matrix& secondMatrix) const{
    checkEqMatrixSize(secondMatrix);
    Matrix newMatrix(matrixSharedData->height, matrixSharedData->width);
    newMatrix.matrixIterationOperation(*this, secondMatrix, &addElements);
    return newMatrix;
    
}

Matrix Matrix::operator-(const Matrix& secondMatrix) const{
    checkEqMatrixSize(secondMatrix);
    Matrix newMatrix(matrixSharedData->height, matrixSharedData->width);
    newMatrix.matrixIterationOperation(*this, secondMatrix, &subElements);
    return newMatrix;
}

Matrix& Matrix::operator+=(const Matrix& secondMatrix){
    checkEqMatrixSize(secondMatrix);
    matrixIterationOperation(*this, secondMatrix, &addElements);
    return *this;
}

Matrix& Matrix::operator-=(const Matrix& secondMatrix){
    checkEqMatrixSize(secondMatrix);
    matrixIterationOperation(*this, secondMatrix, &subElements);
    return *this;
}

void Matrix::matrixIterationMultiply(const Matrix& firstMatrix, const Matrix& secondMatrix){
    double newValue = 0;
    for(int i = 1; i<= matrixSharedData->height; i++){
        for(int j = 1; j<= matrixSharedData->width; j++){
            newValue = 0;
            for(int oldFirstMtrxRow = 1; oldFirstMtrxRow <= firstMatrix.matrixSharedData->width; oldFirstMtrxRow++){
                newValue += firstMatrix(i, oldFirstMtrxRow)*secondMatrix(oldFirstMtrxRow, j);
            }
            operator()(i, j) = newValue;
        }
    }
}

Matrix Matrix::operator*(const Matrix& secondMatrix) const{
    if(matrixSharedData->width != secondMatrix.matrixSharedData->height){
        throw InvalidMatrixSizeException();
    }
    Matrix newMatrix(matrixSharedData->height, secondMatrix.matrixSharedData->width);
    newMatrix.matrixIterationMultiply(*this, secondMatrix);
    return newMatrix;
}

Matrix& Matrix::operator*=(const Matrix& secondMatrix){
    operator=(operator*(secondMatrix));
    return *this;
}

bool Matrix::operator==(const Matrix& secondMatrix) const{
    checkEqMatrixSize(secondMatrix);
    for(int i = 1; i <= matrixSharedData->height; i++){
        for(int j = 1; j <= matrixSharedData->width; j++){
            if(operator()(i, j) != secondMatrix(i, j)){
                return false;
            }
        }
    }
    return true;
    
}

bool Matrix::operator!=(const Matrix& secondMatrix) const{
    return !operator==(secondMatrix);
}





//class Dref
Matrix::Dref::operator double() const{
    #ifdef DEBUG_ENABLED
        std::cout << "read access"<< std::endl;
    #endif
    return matrixRef.matrixSharedData->matrix_ptr[row][column];
}

Matrix::Dref& Matrix::Dref::operator=(double value){
    #ifdef DEBUG_ENABLED
        std::cout << "write access"<< std::endl;
    #endif
    matrixRef.matrixSharedData = matrixRef.matrixSharedData->detach();
    matrixRef.matrixSharedData->matrix_ptr[row][column] = value;
    return *this;
}

Matrix::Dref& Matrix::Dref::operator=(const Matrix::Dref& ref){
    return operator=((double)ref);
}





//class MatrixSharedPointer
double** Matrix::MatrixSharedPointer::matrixMemAlloc(int newHeight, int newWidth, double **oldMatrix_ptr){
    matrix_ptr = new double*[height];
    pointerNotNull(matrix_ptr);
    if(oldMatrix_ptr == NULL){
        for(int i = 0; i < height; i++){
            matrix_ptr[i] = new double[width]();
            pointerNotNull(matrix_ptr[i]);
        }
    }else{
        for(int i = 0; i < height; i++){
            matrix_ptr[i] = new double[width]();
            pointerNotNull(matrix_ptr[i]);
            for(int j = 0; j < width; j++){
                matrix_ptr[i][j] = oldMatrix_ptr[i][j];
            }
        }
    }
    return matrix_ptr;
}

Matrix::MatrixSharedPointer::MatrixSharedPointer(int newHeight, int newWidth, double **oldMatrix_ptr){
    height = newHeight;
    width = newWidth;
    numberOfAccessers = 1;
    try{
        matrix_ptr = matrixMemAlloc(newHeight, newWidth, oldMatrix_ptr);
    }catch(InvalidAllocationException& e){
        std::cout << e.what();
        exit(1);
    }
}

Matrix::MatrixSharedPointer::~MatrixSharedPointer(){
    for(int i = 0; i < height; i++){
        delete[] matrix_ptr[i];
    }
    delete[] matrix_ptr;
}

Matrix::MatrixSharedPointer* Matrix::MatrixSharedPointer::detach(){
    if(numberOfAccessers == 1){
        return this;
    }
    numberOfAccessers--;
    return new MatrixSharedPointer(height, width, matrix_ptr);
}