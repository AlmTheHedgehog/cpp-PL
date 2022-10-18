#include "ComplexNumber.h"

ComplexNumber::ComplexNumber(double realV, double imgV){
    realPart = realV;
    imgV = imgV;
}







std::ostream& ComplexNumber::operator<< (std::ostream& stream, const ComplexNumber& dispNumber){
    //stream;
    return stream;
}

double ComplexNumber::getRealPart(){
    return realPart;
}
double ComplexNumber::getImgPart(){
    return imgPart;
}
void ComplexNumber::setRealPart(double value){
    realPart = value;
}
void ComplexNumber::setImgPart(double value){
    imgPart = value;
}