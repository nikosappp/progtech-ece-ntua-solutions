#include <iostream>
#ifndef CONTEST
#include "fullratio.hpp"
#endif

using namespace std;


int rational::gcd(int x, int y){
    while (x>0 && y>0){
     if(x>y) x%=y; 
     else y%=x;
    }
    return x+y;
}


rational::rational (int n, int d){
    nom=n/gcd(abs(n), abs(d));                     
    den=d/gcd(abs(n), abs(d));
    if(den<0){
        nom=-nom;
        den=-den;
    }
}

rational operator + (const rational &x, const rational &y){
    int addnom, addden;
    addnom=(x.nom*y.den) + (y.nom*x.den);
    addden=x.den*y.den;
    
    return rational(addnom, addden);
}

rational operator - (const rational &x, const rational &y){
    int subnom, subden;
    subnom=(x.nom*y.den) - (y.nom*x.den);
    subden=x.den*y.den;

    return rational(subnom, subden);
}

rational operator * (const rational &x, const rational &y){
    int mulnom, mulden;
    mulnom=x.nom*y.nom;
    mulden=x.den*y.den;

    return rational(mulnom, mulden);
}

rational operator / (const rational &x, const rational &y){
    int divnom, divden;
    divnom=x.nom*y.den;
    divden=x.den*y.nom;
    
    return rational(divnom, divden);
}

std::ostream& operator << (std::ostream &out, const rational &x){
    out << x.nom << "/" << x.den;
    return out;
}