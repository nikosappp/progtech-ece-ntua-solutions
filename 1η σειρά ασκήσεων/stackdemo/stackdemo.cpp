#include <iostream>

using namespace std;

template <typename T>
class stack {
 public:

   stack(int size){
      megethos=size;
      array=new T[megethos];
      top=0;
   }

   stack(const stack &s){
      megethos=s.megethos;
      array=new T[megethos];
      top=s.top;
      for(int i=0; i<top; i++){
         array[i]=s.array[i];
      }
      
   }


   ~stack() {
      delete [] array;
   }

   const stack & operator = (const stack &s) {
      if(this !=&s){
         delete [] array;
         megethos=s.megethos;
         top=s.top;
         array = new T[megethos];
         for(int i=0; i<top; i++){
            array[i]=s.array[i];
         }
      }
      return *this;
   } 

   bool empty(){
      return top==0;
   }

   void push(const T &x){
        array[top++]=x;
   }

   T pop(){
         return array[--top];
      } 

   int size(){
       return top;
   }

   friend ostream & operator << (ostream &out, const stack &s) {
   if(s.top==0) out<<"[]"; 
    else {
     out<<"[";
     for(int i=0; i<s.top-1; i++){
      out<< s.array[i] <<", ";
    }
    out<<s.array[s.top-1];
    out<<"]";
    return out;
  }
 }

   

 private:
   T *array;
   int megethos;
   int top;
};

#ifndef CONTEST
 int main () {
 
stack<int> s(10);
cout <<"s is empty:" << s << endl;
 s.push(42);
 cout <<"s has one element:" << s << endl;
 s.push(17);
 s.push(34);
 cout <<"s has more elements:" << s << endl;
 cout <<"How many? " << s.size() << endl;
 stack<int> t(5);
 t.push(7);
 cout <<"t:" << t << endl;
 t = s;
 cout << "popping from s: " << s.pop() << endl;

 s.push(8);
 stack<int> a(5);
 cout << "hey" << endl;
 t.push(99);
 a.push(77);
 cout <<"s:" << s << endl;
 cout <<"t:" << t << endl;
 cout <<"a:" << a << endl;

 stack<double> c(4);
 c.push(3.14);
 c.push(1.414);
 cout << "c contains doubles" << c << endl;
 
 stack<char> k(4);
 k.push('$');
 cout <<"k contains a character " << k << endl;
 }
 #endif




