#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

class Poly{
    public:
        Poly(double value = 0);
        Poly(const Poly& parent);
        
        friend std::ostream& operator<<(std::ostream& stream, const Poly& dispPoly);
        double& operator[](int curCoeff);
        double operator()(double xValue) const;

        friend Poly operator+(Poly firstPoly, const Poly& secondPoly);
        friend Poly operator-(Poly firstPoly, const Poly& secondPoly);
        Poly operator-() const;
        friend Poly operator*(const Poly& firstPoly, const Poly& secondPoly);


    private:
        std::vector<double> values;
        std::vector<int> coefficients; //sorted from smaller to bigger
        double& insertNewCoeff(int newCoeff, const int lastElementIndex);
        double toPower(double value, int power) const;
};
