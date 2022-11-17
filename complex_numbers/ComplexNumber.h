#include <iostream>
#include <cmath>

class ComplexNumber{
    public:
        ComplexNumber();
        ComplexNumber(double realV);
        ComplexNumber(double realV, double imgV);
        ComplexNumber(const ComplexNumber& old);
        friend std::ostream& operator<< (std::ostream& stream, const ComplexNumber& dispNumber);
        
        friend ComplexNumber operator+(const ComplexNumber& firstNumber, const ComplexNumber& secondNumber);
        friend ComplexNumber operator-(const ComplexNumber& firstNumber, const ComplexNumber& secondNumber);
        ComplexNumber operator-() const;
        friend ComplexNumber operator*(const ComplexNumber& firstNumber, const ComplexNumber& secondNumber);
        friend ComplexNumber operator/(const ComplexNumber& firstNumber, const ComplexNumber& secondNumber);

        ComplexNumber& operator+=(const ComplexNumber& secondNumber);
        ComplexNumber& operator-=(const ComplexNumber& secondNumber);
        ComplexNumber& operator/=(const ComplexNumber& secondNumber);
        ComplexNumber& operator*=(const ComplexNumber& secondNumber);
        
        friend bool operator==(const ComplexNumber& firstNumber, const ComplexNumber& secondNumber);
        friend bool operator!=(const ComplexNumber& firstNumber, const ComplexNumber& secondNumber);

        double getAmplitude();
        double getPhase();
        
        double getRealPart();
        double getImgPart();
        void setRealPart(double value);
        void setImgPart(double value);

    private:
        double realPart;
        double imgPart;
};
