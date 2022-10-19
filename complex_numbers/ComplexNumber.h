#include <iostream>
#include <cmath>

class ComplexNumber{
    public:
        ComplexNumber();
        ComplexNumber(double realV);
        ComplexNumber(double realV, double imgV);
        friend std::ostream& operator<< (std::ostream& stream, const ComplexNumber& dispNumber);
        
        ComplexNumber operator+(const ComplexNumber& secondNumber) const;
        ComplexNumber operator-(const ComplexNumber& secondNumber) const;
        ComplexNumber operator-() const;
        ComplexNumber operator*(const ComplexNumber& secondNumber) const;
        ComplexNumber operator/(const ComplexNumber& secondNumber) const;
        
        double getRealPart();
        double getImgPart();
        void setRealPart(double value);
        void setImgPart(double value);

    private:
        double realPart;
        double imgPart;
};

/*
TODO
arithmetic operators: += -= *= /=
comparison operators: == !=
functions returning amplitude and phase (you can use in your implementation functions from the C++ standard library)
*/