#include <iostream>
#include "babyratio.cpp"

using namespace std;

int main(){
    rational a(-3, 4);
    rational b(7, 8);
    rational c(3, 2);

    a.add(b).print();
    a.sub(c).print();
    c.div(a).print();
    a.mul(b).print();
    
}