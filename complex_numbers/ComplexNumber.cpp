#include "ComplexNumber.h"

ComplexNumber::ComplexNumber(double realV, double imgV){
    realPart = realV;
    imgPart = imgV;
}

ComplexNumber::ComplexNumber(double realV){
    realPart = realV;
    imgPart = 0;
}

ComplexNumber::ComplexNumber(){
    realPart = 0;
    imgPart = 0;
}

std::ostream& operator<< (std::ostream& stream, const ComplexNumber& dispNumber){
    char sign = '+';
    if(dispNumber.imgPart < 0){
        sign = '-';
    }
    return stream << dispNumber.realPart << sign << fabs(dispNumber.imgPart) << "i";
}

ComplexNumber ComplexNumber::operator+(const ComplexNumber& secondNumber) const{
    return ComplexNumber(realPart+secondNumber.realPart, imgPart+secondNumber.imgPart);
}

ComplexNumber ComplexNumber::operator-(const ComplexNumber& secondNumber) const{
    return ComplexNumber(realPart-secondNumber.realPart, imgPart-secondNumber.imgPart);
}

ComplexNumber ComplexNumber::operator-() const{
    return ComplexNumber(-realPart, -imgPart);
};

ComplexNumber ComplexNumber::operator*(const ComplexNumber& secondNumber) const{
    return ComplexNumber((realPart * secondNumber.realPart) - (imgPart * secondNumber.imgPart),
                        (realPart * secondNumber.imgPart) + (imgPart * secondNumber.realPart));
}

ComplexNumber ComplexNumber::operator/(const ComplexNumber& secondNumber) const{
    double dev = secondNumber.realPart * secondNumber.realPart + secondNumber.imgPart * secondNumber.imgPart;
    return ComplexNumber(((realPart * secondNumber.realPart)+(imgPart * secondNumber.imgPart))/dev,
                        ((imgPart * secondNumber.realPart)-(realPart * secondNumber.imgPart))/dev);
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