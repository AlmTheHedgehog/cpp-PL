#include "Poly.h"
#include <iostream>
#include <algorithm>

Poly::Poly():Poly(0){
}

Poly::Poly(const Poly& parent){
    values = parent.values;
    coefficients = parent.coefficients;
}

Poly::Poly(double value){
    coefficients.push_back(0);
    values.push_back(value);
}

Poly::~Poly(){
}

double& Poly::operator[] (const int& curCoeff){
    const int lastElementIndex = coefficients.size() - 1;
    for(int i=0; i<= lastElementIndex; i++){
        if(coefficients[i] == curCoeff){
            return values[i];
        }
    }
    return insertNewCoeff(curCoeff, lastElementIndex);    
}

double& Poly::insertNewCoeff(const int& newCoeff, const int lastElementIndex){
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
    for(int i=INDEX_OF_LAST_ELEMENT; i>=0; i--){
        if(dispPoly.values[i] != 0){
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
    return stream;
}









//in printing if values[i] == 0 - not print!