#include <iostream>

class ComplexNumber{
    public:
        ComplexNumber(double realV, double imgV);
        friend std::ostream& operator<< (std::ostream& stream, const ComplexNumber& dispNumber);


        
        double getRealPart();
        double getImgPart();
        void setRealPart(double value);
        void setImgPart(double value);

    private:
        double realPart;
        double imgPart;
};