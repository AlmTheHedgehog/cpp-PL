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

ComplexNumber::ComplexNumber(const ComplexNumber& old){
    realPart = old.realPart;
    imgPart = old.imgPart;
}

std::ostream& operator<< (std::ostream& stream, const ComplexNumber& dispNumber){   //TODO operator<< test
    char sign = '+';
    if(dispNumber.imgPart < 0){
        sign = '-';
    }
    return stream << dispNumber.realPart << sign << fabs(dispNumber.imgPart) << "i";
}

ComplexNumber operator+(const ComplexNumber& firstNumber, const ComplexNumber& secondNumber){    //TODO operator+ test
    return ComplexNumber(firstNumber.realPart+secondNumber.realPart, firstNumber.imgPart+secondNumber.imgPart);
}

ComplexNumber operator-(const ComplexNumber& firstNumber, const ComplexNumber& secondNumber){    //TODO operator- test
    return ComplexNumber(firstNumber.realPart-secondNumber.realPart, firstNumber.imgPart-secondNumber.imgPart);
}

ComplexNumber ComplexNumber::operator-() const{     //TODO operator- test (eg -a)
    return ComplexNumber(-realPart, -imgPart);
};

ComplexNumber operator*(const ComplexNumber& firstNumber, const ComplexNumber& secondNumber){    //TODO operator* test
    return ComplexNumber((firstNumber.realPart * secondNumber.realPart) - (firstNumber.imgPart * secondNumber.imgPart),
                        (firstNumber.realPart * secondNumber.imgPart) + (firstNumber.imgPart * secondNumber.realPart));
}

ComplexNumber operator/(const ComplexNumber& firstNumber, const ComplexNumber& secondNumber){    //TODO operator/ test
    double dev = secondNumber.realPart * secondNumber.realPart + secondNumber.imgPart * secondNumber.imgPart;
    return ComplexNumber(((firstNumber.realPart * secondNumber.realPart)+(firstNumber.imgPart * secondNumber.imgPart))/dev,
                        ((firstNumber.imgPart * secondNumber.realPart)-(firstNumber.realPart * secondNumber.imgPart))/dev);
}

ComplexNumber& ComplexNumber::operator+=(const ComplexNumber& secondNumber){    //TODO operator+= test
    realPart += secondNumber.realPart;
    imgPart += secondNumber.imgPart;
    return *this;
}

ComplexNumber& ComplexNumber::operator-=(const ComplexNumber& secondNumber){    //TODO operator-= test
    realPart -= secondNumber.realPart;
    imgPart -= secondNumber.imgPart;
    return *this;
}

ComplexNumber& ComplexNumber::operator/=(const ComplexNumber& secondNumber){    //TODO operator/= test
    double dev = secondNumber.realPart * secondNumber.realPart + secondNumber.imgPart * secondNumber.imgPart;
    realPart = ((realPart * secondNumber.realPart)+(imgPart * secondNumber.imgPart))/dev;
    imgPart = ((imgPart * secondNumber.realPart)-(realPart * secondNumber.imgPart))/dev;
    return *this;
}

ComplexNumber& ComplexNumber::operator*=(const ComplexNumber& secondNumber){    //TODO operator*= test
    realPart = (realPart * secondNumber.realPart) - (imgPart * secondNumber.imgPart);
    imgPart = (realPart * secondNumber.imgPart) + (imgPart * secondNumber.realPart);
    return *this;
}

bool operator==(const ComplexNumber& firstNumber, const ComplexNumber& secondNumber){    //TODO operator== test
    return ((firstNumber.realPart == secondNumber.realPart) && (firstNumber.imgPart == secondNumber.imgPart));
}

bool operator!=(const ComplexNumber& firstNumber, const ComplexNumber& secondNumber){    //TODO operator!= test
    return !((firstNumber.realPart == secondNumber.realPart) && (firstNumber.imgPart == secondNumber.imgPart));
}


double ComplexNumber::getAmplitude(){   //TODO getAmplitude test
    return sqrt((realPart*realPart)+(imgPart*imgPart));
}

double ComplexNumber::getPhase(){   //TODO getPhase test
    return atan2(imgPart, realPart);
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
