#include <iostream>
#include <cmath>

class ComplexNumber{
    public:
        ComplexNumber();
        ComplexNumber(double realV);
        ComplexNumber(double realV, double imgV);
        ComplexNumber(const ComplexNumber& old);
        friend std::ostream& operator<< (std::ostream& stream, const ComplexNumber& dispNumber);
        
        ComplexNumber operator+(const ComplexNumber& secondNumber) const;
        ComplexNumber operator-(const ComplexNumber& secondNumber) const;
        ComplexNumber operator-() const;
        ComplexNumber operator*(const ComplexNumber& secondNumber) const;
        ComplexNumber operator/(const ComplexNumber& secondNumber) const;

        ComplexNumber& operator+=(const ComplexNumber& secondNumber);
        ComplexNumber& operator-=(const ComplexNumber& secondNumber);
        ComplexNumber& operator/=(const ComplexNumber& secondNumber);
        ComplexNumber& operator*=(const ComplexNumber& secondNumber);

        bool operator==(const ComplexNumber& secondNumber) const;
        bool operator!=(const ComplexNumber& secondNumber) const;

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
