#pragma once
#include <iostream>
#include <vector>

class Poly{
    public:
        Poly();
        Poly(double value);
        Poly(const Poly& parent);
        ~Poly();

        friend std::ostream& operator<<(std::ostream& stream, const Poly& dispPoly);
        double& operator[](const int& curCoeff);

        friend Poly operator+(Poly firstPoly, const Poly& secondPoly);
        friend Poly operator-(Poly firstPoly, const Poly& secondPoly);
        Poly operator-() const;
        friend Poly operator*(const Poly& firstPoly, const Poly& secondPoly);



    private:
        std::vector<double> values;
        std::vector<int> coefficients; //sorted from smaller to bigger
        double& insertNewCoeff(const int& newCoeff, const int lastElementIndex);
};