#include "ComplexNumber.h"

void outOperatorTest(ComplexNumber& cn1); // operator<<                                   
void addOperatorTest(ComplexNumber& cn1, ComplexNumber& cn2); // operator+                
void substrOperatorTest(ComplexNumber& cn1, ComplexNumber& cn2); // operator-             
void negationOperatorTest(ComplexNumber& cn1); // operator- (-a)                          
void divOperatorTest(ComplexNumber& cn1, ComplexNumber& cn2); // operator/                
void multOperatorTest(ComplexNumber& cn1, ComplexNumber& cn2); // operator*               
void addAssignOperatorTest(ComplexNumber cn1, ComplexNumber& cn2); // operator+=          
void substrAssignOperatorTest(ComplexNumber cn1, ComplexNumber& cn2); // operator-=       
void divAssignOperatorTest(ComplexNumber cn1, ComplexNumber& cn2); // operator/=          
void multAssignOperatorTest(ComplexNumber cn1, ComplexNumber& cn2); // operator*=         
void equalTest(ComplexNumber& cn1, ComplexNumber& cn2); // operator==                     
void notEqualTest(ComplexNumber& cn1, ComplexNumber& cn2); // operator!=
void getAmpPhaseTest(ComplexNumber& cn1); // phase and amp                

int main(){

    ComplexNumber cn1(3, 2), cn2(3.5, -4);
    outOperatorTest(cn1);
    addOperatorTest(cn1, cn2);
    substrOperatorTest(cn1, cn2);
    negationOperatorTest(cn1);
    divOperatorTest(cn1, cn2);
    multOperatorTest(cn1, cn2);
    addAssignOperatorTest(cn1, cn2);
    substrAssignOperatorTest(cn1, cn2);
    divAssignOperatorTest(cn1, cn2);
    multAssignOperatorTest(cn1, cn2);
    equalTest(cn1, cn2);
    notEqualTest(cn1, cn2);
    getAmpPhaseTest(cn1);

    return 0;
}

void outOperatorTest(ComplexNumber& cn1){
    std::cout << "operator<< test cn1:" << cn1 << std::endl;
}

void addOperatorTest(ComplexNumber& cn1, ComplexNumber& cn2){
    std::cout << "operator+ test cn1+cn2:" << cn1+cn2 << std::endl;
    std::cout << "operator+ test cn1+5:" << cn1+5 << std::endl;
    std::cout << "operator+ test 5+cn1:" << 5+cn1 << std::endl;
}

void substrOperatorTest(ComplexNumber& cn1, ComplexNumber& cn2){
    std::cout << "operator- test cn1-cn2:" << cn1-cn2 << std::endl;
}

void negationOperatorTest(ComplexNumber& cn1){
    std::cout << "negation test cn1:" << -cn1 << std::endl;
}

void divOperatorTest(ComplexNumber& cn1, ComplexNumber& cn2){
    std::cout << "operator/ test cn1/cn2:" << cn1/cn2 << std::endl;
}

void multOperatorTest(ComplexNumber& cn1, ComplexNumber& cn2){
    std::cout << "operator* test cn1*cn2:" << cn1*cn2 << std::endl;
    std::cout << "operator* test cn1*5:" << cn1*5 << std::endl;
    std::cout << "operator* test 5*cn2:" << 5*cn1 << std::endl;
}

void addAssignOperatorTest(ComplexNumber cn1, ComplexNumber& cn2){
    cn1 += cn2;
    std::cout << "operator+= test cn1+=cn2:" << cn1 << std::endl;
    std::cout << "operator+= test cn1+=cn2+=c1:" << (cn1 += cn2 += cn1) << std::endl;
}

void substrAssignOperatorTest(ComplexNumber cn1, ComplexNumber& cn2){
    cn1 -= cn2;
    std::cout << "operator-= test cn1-=cn2:" << cn1 << std::endl;
}

void divAssignOperatorTest(ComplexNumber cn1, ComplexNumber& cn2){
    cn1 /= cn2;
    std::cout << "operator/= test cn1/=cn2:" << cn1 << std::endl;
}

void multAssignOperatorTest(ComplexNumber cn1, ComplexNumber& cn2){
    cn1 *= cn2;
    std::cout << "operator*= test cn1*=cn2:" << cn1 << std::endl;
    std::cout << "operator*= test (cn1 =* cn2) =* cn1:" << ((cn1 *= cn2) *= cn1) << std::endl;
}

void equalTest(ComplexNumber& cn1, ComplexNumber& cn2){
    ComplexNumber cnNew(cn1);
    std::cout << std::endl;
    std::cout << "operator== test cn1==cn2:" << (cn1==cn2) << "(false - correct)" << std::endl;
    std::cout << "operator== test cn1==3+2i:" << (cn1==cnNew) << "(true - correct)" << std::endl;
    std::cout << "operator== test cn1==3.5:" << (cn1==3.5) << "(false - correct)" << std::endl;
    std::cout << "operator== test 3.5==cn1:" << (3.5==cn1) << "(false - correct)" << std::endl;
}

void notEqualTest(ComplexNumber& cn1, ComplexNumber& cn2){
    ComplexNumber cnNew(cn1);
    std::cout << "operator!= test cn1!=cn2:" << (cn1!=cn2) << "(true - correct)" << std::endl;
    std::cout << "operator!= test cn1!=3+2i:" << (cn1!=cnNew) << "(false - correct)" << std::endl;
}

void getAmpPhaseTest(ComplexNumber& cn1){
	std::cout << "Amp:" << cn1.getAmplitude() << std::endl;
	std::cout << "Phase:" << cn1.getPhase() << std::endl;
}
