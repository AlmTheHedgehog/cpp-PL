#include "Matrix.h"
#include "MatrixExeptions.h"
//#define DEBUG_ENABLED

Matrix::Matrix(int matrixHeight, int matrixWidth){
    matrixSharedData = new MatrixSharedPointer(matrixHeight, matrixWidth);
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
    if(!(((row >=1) && (row <= matrixSharedData->height)) &&
        ((column >=1) && (column <= matrixSharedData->width)))){
        throw IndexOutOfBoundExeption();
    }
    return matrixSharedData->matrix_ptr[row][column];
}

Matrix::Dref Matrix::operator()(int row, int column){
    if(!(((row >=1) && (row <= matrixSharedData->height)) &&
        ((column >=1) && (column <= matrixSharedData->width)))){
        throw IndexOutOfBoundExeption();
    }
    return Dref(*this, row-1, column-1);
}






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