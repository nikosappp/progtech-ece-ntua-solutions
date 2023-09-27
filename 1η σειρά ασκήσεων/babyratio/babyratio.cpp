
#include <iostream>
#ifndef CONTEST
#include "babyratio.hpp"
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

rational rational::add(rational r){
    
    int add_nom, add_den;
    add_nom=nom*r.den + den*r.nom;
    add_den=r.den*den;

    
    return rational(add_nom, add_den);
}

rational rational::sub(rational r){

    int sub_nom, sub_den;
    sub_nom=nom*r.den - den*r.nom;
    sub_den=den*r.den;

    
    return rational(sub_nom, sub_den);
}

rational rational::mul(rational r){

    int mulnom, mulden;
    mulnom=(nom*r.nom);
    mulden=(den*r.den);
   
    return rational(mulnom, mulden);
}

rational rational::div(rational r){

    int divnom, divden;
    divnom=nom*r.den;
    divden=r.nom*den;

    
    return rational(divnom, divden);
}

void rational::print(){
    cout << nom << "/" << den;
}