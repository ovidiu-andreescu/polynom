#include <list>
#include <cmath>
#include <fstream>
#include "ex3.h"

//read polynomial for real numbers
template <typename T>
list<Polynomial<T>> readPoly(int degree, ifstream &fin){
    T coeff; //coefficient
    int exp; //exponential

    list<Polynomial<T>> l;

    /*
    for(int i = 0; i <= degree; i++){
        fin >>exp;
        fin >>coeff;

        //TODO INSERT THE ELEMENTS BY EXPONENTIAL

        //auto it = l.begin();
        //advance(it, exp + 1);
        //l.push_back(Polynomial<T>(coeff, exp));
    }
    T coeff;
    int exp;

    list<Polynomial<T>> l;
    */

    for(int i = 0; i <= degree; i++){
        fin >>exp;
        fin >>coeff;

        auto it = l.begin();
        advance(it, degree-exp);
        l.insert(it, Polynomial<T>(coeff, exp));
        
    }

    return l;
}

//complex case
template <typename T>
list<Polynomial<T>> readPolyIm(int degree, ifstream &fin){
    T coeff_re, coeff_im;
    int exp;

    list<Polynomial<T>> l;

    for(int i = 0; i <= degree; i++){
        fin >>exp;
        fin >>coeff_re;
        fin >>coeff_im;
        
        auto it = l.begin();
        advance(it, degree-exp);
        l.insert(it, Polynomial<T>(coeff_re, coeff_im, exp));
    }

    return l;
}

template <typename T>
void printPoly(list<Polynomial<T>> l){
    for(auto it=l.begin(); it != l.end(); it++) {
        if(it->getCoeff() != 0) {
            if(it->getExp() == 0)
                cout << it->getCoeff();
            else {
                cout << it->printNode();
                if (it != l.end() && next(it)->getCoeff() > 0){
                    cout <<"+";
                }
            } 
        }
    }

    /*
    for(auto it=l.begin(); it != l.end(); it++) {
        cout << it->getExp() <<" -> " <<it->getCoeff() <<"\n";
    }
    */
}

template <typename T>
void printPolyIm(list<Polynomial<T>> l){
    for(auto it=l.begin(); it != l.end(); it++) {
        if(it->getRe() != 0 && it->getIm() != 0) {
            if(it->getExp() == 0)
                cout << it->getRe() <<"+" <<it->getIm();
            else {
                cout << it->printNodeIm() <<"+";
            } 
        }
    }

}

template <typename T>
T computeX(list<Polynomial<T>> l, T x) {
    T res = 0;

    for(auto it=l.begin(); it != l.end(); it++)
        res += it->getCoeff() * pow(x, it->getExp());     

    return res;
}

template <typename T>
list<Polynomial<T>> sumPoly(list<Polynomial<T>> p1, list<Polynomial<T>> p2, int degree1, int degree2){
    list<Polynomial<T>> pRes;

    if(degree1 > degree2) {
        while(degree1 != degree2) {
            pRes.push_back(p1.front());
            p1.pop_front();
            --degree1;
        }
    }
    else if(degree1 < degree2) {
        while(degree1 != degree2) {
            pRes.push_back(p2.front());
            p2.pop_front();
            --degree2;
        }
    }
    
    for(int i = 0; i <= degree1; i++) {
        T coeff = p1.front().getCoeff() + p2.front().getCoeff();
        int exp = degree1 - i;
        pRes.push_back(Polynomial<T>(coeff, exp));
        p1.pop_front();
        p2.pop_front();
    }

    return pRes;
}

template <typename T>
list<Polynomial<T>> prodPoly(list<Polynomial<T>> p1, list<Polynomial<T>> p2, int degree1, int degree2) {
    list<Polynomial<int>> pRes;

    if(degree1 > degree2) {
        while(degree1 > degree2) {
            ++degree2;
            p2.push_front(Polynomial<T>(0, degree2));
        }
    }
    else if(degree1 < degree2) {
        while(degree1 < degree2) {
            ++degree1;
            p1.push_front(Polynomial<T>(0, degree1));
        }
    }
    
    for(auto it1 = p1.begin(); it1 != p1.end(); it1++) {
        for(auto it2 = p2.begin(); it2 != p2.end(); it2++) {
            T coeff = it1->getCoeff() * it2->getCoeff();
            int exp = it1->getExp() + it2->getExp();
            pRes.push_back(Polynomial<T>(coeff, exp));
        }
    }

    return pRes;
}

int main(){
    int s;
    while(s != 6)
    {
        cout << "\nChoose option: \n";
        cout << "1. Display polynomial\n";
        cout << "2. Compute polynomial for a given X\n";
        cout << "3. Sum of polynomials\n";
        cout << "4. Product of polynomials\n";
        cout << "5. Complex polynomials\n";
        cout << "6. Exit\n";
        cout << "Your choice: \n";
        cin >> s;

        switch(s) {
            case 1:
            {
                ifstream fin("ex3_case1.in");

                int degree;
                fin >>degree;
                list<Polynomial<int>> p1 = readPoly<int>(degree, fin);

                printPoly(p1);
                cout <<"\n";
                break;
            }

            case 2:
            {
                ifstream fin("ex3_case2.in");

                int degree, x;
                fin >>degree;
                list<Polynomial<int>> p1 = readPoly<int>(degree, fin);

                fin >> x;
                cout <<"Computation for x=" << x << ": "<<computeX<int>(p1, 2) <<"\n";
                cout <<"\n";
                break;
            }

            case 3:
            {
                ifstream fin("ex3_case3.in");

                int degree1, degree2;
                fin >> degree1 >> degree2;
                list<Polynomial<int>> p1 = readPoly<int>(degree1, fin);
                list<Polynomial<int>> p2 = readPoly<int>(degree2, fin);
                list<Polynomial<int>> p3;

                p3 = sumPoly<int>(p1, p2, degree1, degree2);
                printPoly(p3);
                cout <<"\n";

                break;
            }

            case 4:
            {
                ifstream fin("ex3_case4.in");

                int degree1, degree2;
                fin >> degree1 >> degree2;
                list<Polynomial<int>> p1 = readPoly<int>(degree1, fin);
                list<Polynomial<int>> p2 = readPoly<int>(degree2, fin);
                list<Polynomial<int>> p3;

                p3 = prodPoly(p1,p2, degree1, degree2);

                printPoly(p3);
                cout <<"\n";

                break;
            }

            case 5:
            {
                ifstream fin("ex3_case5.in");

                int degree;
                fin >>degree;
                list<Polynomial<int>> p1 = readPolyIm<int>(degree, fin);

                printPolyIm(p1);

                break;
            }
            default:
                cout <<"Not good";
                break;
        }
    }
}