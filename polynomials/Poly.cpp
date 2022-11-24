#include "Poly.h"

Poly::Poly(const Poly& parent){
    values = parent.values;
    coefficients = parent.coefficients;
}

Poly::Poly(double value){
    coefficients.push_back(0);
    values.push_back(value);
}

double& Poly::operator[] (int curCoeff){
    const int lastElementIndex = coefficients.size() - 1;
    for(int i=0; i<= lastElementIndex; i++){
        if(coefficients[i] == curCoeff){
            return values[i];
        }
    }
    return insertNewCoeff(curCoeff, lastElementIndex);    
}

double& Poly::insertNewCoeff(int newCoeff, const int lastElementIndex){
    int insertionIndex = 0;
    while((coefficients[insertionIndex] < newCoeff) && (insertionIndex < lastElementIndex)){
        insertionIndex++;
    }
    if((insertionIndex == lastElementIndex) && (coefficients[insertionIndex] < newCoeff)){
        coefficients.push_back(newCoeff);
        values.push_back(0);
        return values.back();
    }else{
        coefficients.insert(coefficients.begin() + insertionIndex, newCoeff);
        values.insert(values.begin() + insertionIndex, 0);
        return values[insertionIndex];
    }
}

std::ostream& operator<< (std::ostream& stream, const Poly& dispPoly){
    const int INDEX_OF_LAST_ELEMENT = dispPoly.coefficients.size() - 1;
    bool notZero = false;
    for(int i=INDEX_OF_LAST_ELEMENT; i>=0; i--){
        if(dispPoly.values[i] != 0){
            notZero = true;
            if((dispPoly.values[i] > 0) && (i != INDEX_OF_LAST_ELEMENT)){
                stream << "+";
            }
            if(dispPoly.coefficients[i] == 0){
                stream << dispPoly.values[i];
            }else{
                stream << dispPoly.values[i] << "x^" << dispPoly.coefficients[i];
            }
        }
    }
    if(!notZero){
        stream << "0";
    }
    return stream;
}

Poly operator+(Poly firstPoly, const Poly& secondPoly){
    for(int i = 0; i<(int)secondPoly.values.size(); i++){
        firstPoly[secondPoly.coefficients[i]] += secondPoly.values[i];
    }
    return firstPoly;
}

Poly operator-(Poly firstPoly, const Poly& secondPoly){
    for(int i = 0; i<(int)secondPoly.values.size(); i++){
        firstPoly[secondPoly.coefficients[i]] -= secondPoly.values[i];
    }
    return firstPoly;
}

Poly Poly::operator-() const{
    Poly newPoly = *this;
    for(int i=0; i<(int)newPoly.values.size(); i++){
        newPoly.values[i] = -newPoly.values[i];
    }
    return newPoly;
}

Poly operator*(const Poly& firstPoly, const Poly& secondPoly){
    Poly newPoly;
    double newValue;
    int newCoeff;
    for(int i = 0; i<(int)firstPoly.coefficients.size(); i++){
        for(int j = 0; j<(int)secondPoly.coefficients.size(); j++){
            if((firstPoly.values[i] != 0) && (secondPoly.values[j] != 0)){
                newValue = firstPoly.values[i] * secondPoly.values[j];
                newCoeff = firstPoly.coefficients[i] + secondPoly.coefficients[j];
                if(newPoly[newCoeff] == 0){
                    newPoly[newCoeff] = newValue;
                }else{
                    newPoly[newCoeff] += newValue;
                }
            }
        }  
    }
    return newPoly;
}

double Poly::operator()(double xValue) const{
    double result = 0;
    for(int i = 0; i < (int)values.size(); i++){
        result += values[i] * toPower(xValue, coefficients[i]);
    }
    return result;
}

double Poly::toPower(double value, int power) const{
    double result = 1;
    for(int i = 0; i < power; i++){
        result *= value;
    }
    return result;
}
