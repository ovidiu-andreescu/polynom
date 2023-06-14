#include <string>
#include <iostream>
using namespace std;

template <typename T> class Polynomial {
private:
    T coeff, re, im;
    int exp;


public:
    //Default constructor
    Polynomial() {
        this->coeff = 0;
        this->exp=0;
    }

    //Constructor for real polynomials
    Polynomial(T coeff, int exp) {
        this->coeff = coeff;
        this->exp = exp;
    }

    //Constructor for complex polynomials
    Polynomial(T re, T im, int exp) {
        this->re = re;
        this->im = im;
        this->exp = exp;
    }
    
    string printNode() {
        return to_string(this->coeff) + "x^" + to_string(this->exp);
    }

    string printNodeIm() {
        return "(" + to_string(this->re) + "+" + to_string(this->im) + "i" + ")" + "x^" + to_string(this->exp);
    }

    T getCoeff(){
        return this->coeff;
    }

    T getRe(){
        return this->re;
    }

    T getIm(){
        return this->im;
    }

    int getExp() {
        return this->exp;
    }

    void setCoeff(T coeff) {
        this->coeff = coeff;
    }

    void setExp(int exp) {
        this->exp = exp;
    }

    
};