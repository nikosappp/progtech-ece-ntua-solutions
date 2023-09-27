#include <iostream>
#include <string>

using namespace std;

int main(){
    string str1="aabb";
    string str2="abbb";

    if(str1.compare(str2)==0) cout << "idia";
    else if(str1.compare(str2)>0) cout << "prota to 2";
    else if(str1.compare(str2)<0) cout << "prota to 1";
}
