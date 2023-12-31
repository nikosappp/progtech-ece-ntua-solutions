#include "gcd.hpp"

int gcd(int x, int y){
    while (x>0 && y>0){
     if(x>y) x%=y; 
     else y%=x;
    }
    return x+y;
}