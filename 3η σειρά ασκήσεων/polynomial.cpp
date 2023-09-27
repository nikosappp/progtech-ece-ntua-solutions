#include <iostream>
#include <cmath>

using namespace std;

class Polynomial{
    protected:

    class Term{
        protected:

        int exponent;
        int coefficient;
        Term *next;
        
        Term(int exp, int coeff, Term *n):
        exponent(exp), coefficient(coeff), next(n) {}
        
        friend class Polynomial;
        friend Polynomial operator + (const Polynomial &p, const Polynomial &q);
        friend Polynomial operator * (const Polynomial &p, const Polynomial &q);
        friend ostream & operator << (ostream &out, const Polynomial &p);              //για να βλεπει η polynomial το protected του term;

    };

    Term *head;

    public:

    Polynomial():
    head(nullptr) {}

    Polynomial(const Polynomial &p):
    head(nullptr)
    {
        Term *pointer1=p.head;
        Term *pointer2=head;
        while(pointer1!=nullptr){
            Term *t = new Term(pointer1->exponent, pointer1->coefficient, nullptr);
            if(head==nullptr) {
                head=t; pointer2=t;                                       //xreiazetai to pointer2=t;
            }
            else{
                pointer2->next=t; 
                pointer2=pointer2->next;
            }
            pointer1=pointer1->next;
        }
    }

    ~Polynomial(){
        Term *p=head;
        while(p!=nullptr){
            Term *q=p;
            p=p->next;
            delete q;                //που παει ο head
        }
    }

    Polynomial & operator = (const Polynomial &p) {
         Term *ptr=head;
        while(ptr!=nullptr){
            Term *q=ptr;
            ptr=ptr->next;
            delete q;
        }

        head=nullptr;                                     //xreiazetai;
        Term *pointer1=p.head;
        Term *pointer2=head;
        while(pointer1!=nullptr){
            Term *t = new Term(pointer1->exponent, pointer1->coefficient, nullptr);
            if(head==nullptr) {
                head=t; pointer1=t;                                     
            }
            else{
                pointer2->next=t; 
                pointer2=pointer2->next;
            }
            pointer1=pointer1->next;
        }
            
        return *this;
    }   


void addTerm(int expon, int coeff){  
  
      Term *oros1;  
      Term *oros2;  
      Term *neos_oros = new Term(expon, coeff, nullptr);  
  
      if(coeff==0){  
        delete neos_oros;  
        return;  
      } 
      
      if else(head==nullptr){  
        head = neos_oros;  
        head->next = nullptr;  
        return;  
      }  

      else if(head->exponent < expo){
        t->next=head->next;
        head=t;
      }
  
       
  
      else if(head->exponent==expon){  
        head->coefficient += coeff;  
        if(head->coefficient==0){  
          oros1=head;  
          head=head->next;  
          delete oros1;  
        }  
        delete neos_oros;  
        return;  
      }  
     //kbitsakos14@gmail.com
      oros1=head;  
      oros2=oros1->next;  
      while(oros2 != nullptr && oros2->exponent > expon){  
        oros1=oros2;  
        oros2=oros2->next;  
      }  
  
      else if(oros2!=nullptr && oros2->exponent==expon){  
        oros2->coefficient += coeff;  
        if(oros2->coefficient==0){  
          oros1->next = oros2->next;  
          delete oros2;  
        }
        delete neos_oros;  
      }  
  
      else{  
        if(neos_oros->exponent < oros1->exponent){  
          neos_oros->next = oros1->next;  
          oros1->next = neos_oros;  
        }  
  
        else{  
          neos_oros->next = oros1;  
          head = neos_oros;  
        }  
      }  
    }  

    
    double evaluate(double x){
        double result=0;
        Term *ptr=head;
        while(ptr!=nullptr){
            result+=ptr->coefficient * pow(x, ptr->exponent);
            ptr=ptr->next;
        }
        return result;
    }

    friend Polynomial operator+ (const Polynomial &p, const Polynomial &q){
        Term *ptrq=q.head;
        Term *ptrp=p.head;
        Polynomial result;

        while(ptrp!=nullptr && ptrq!=nullptr){

            if(ptrp->exponent == ptrq->exponent){
                result.addTerm(ptrp->exponent, ptrp->coefficient + ptrq->coefficient);
                ptrp=ptrp->next;
                ptrq=ptrq->next;
            }

            else if(ptrp->exponent > ptrq->exponent){
                result.addTerm(ptrp->exponent, ptrp->coefficient);
                ptrp=ptrp->next;
            }

            else{
                result.addTerm(ptrq->exponent, ptrq->coefficient);
                ptrq=ptrq->next;
            }
        }
        
        while(ptrq!=nullptr){
            result.addTerm(ptrq->exponent, ptrq->coefficient);
            ptrq=ptrq->next;
        }

        while(ptrp!=nullptr){
            result.addTerm(ptrp->exponent, ptrp->coefficient);
            ptrp=ptrp->next;
        }

        return result;
    }

    friend Polynomial operator * (const Polynomial &p, const Polynomial &q){
     
        
        Term *ptrp=p.head;
       
        Polynomial result;

        while(ptrp!=nullptr){ 
            Term *ptrq=q.head;   
            while(ptrq!=nullptr){
                result.addTerm(ptrp->exponent + ptrq->exponent, ptrp->coefficient * ptrq->coefficient);
                ptrq=ptrq->next;
            }
            ptrp=ptrp->next;
        }
        return result;
    }

    /*friend Polynomial operator * (const Polynomial &p, const Polynomial &q){  
      Polynomial t;  
      Term *oros_p;  
      Term *oros_q;  

      for(oros_p=p.head; oros_p != nullptr; oros_p = oros_p->next){  
        for(oros_q=q.head; oros_q != nullptr; oros_q = oros_q->next){  
          t.addTerm(oros_p->exponent + oros_q->exponent, oros_p->coefficient * oros_q->coefficient);  
        }  
      }  
      return t;  
  
    }  */


    
        

    friend ostream & operator << (ostream &out, const Polynomial &p){
        Term *pointer=p.head;

        if(p.head==nullptr){
            out << 0;
            return out;
        }

        if(pointer->coefficient < 0) 
            out << "- ";

        if(abs(pointer->coefficient) != 1) 
            out << abs(pointer->coefficient);

        if(pointer->exponent == 0 && abs(pointer->coefficient) == 1) 
            out << "1";

        if(pointer->exponent == 1) 
            out << "x";

        else if(pointer->exponent != 0) 
            out << "x^" << pointer->exponent;

        pointer = pointer->next;

        while(pointer!=nullptr){
            
            if(pointer->coefficient < 0){
                out << " - ";
            }
            else{
                out << " + ";
            }

            if(abs(pointer->coefficient) != 1 || pointer->exponent==0){
                out << abs(pointer->coefficient);
            }

            if(pointer->exponent==1){
                out <<"x";
            }

            else if(pointer->exponent!=0){
                out << "x^" << pointer->exponent;
            }
            pointer=pointer->next;
           
        }

        return out;

           
    }
        
        
};

//  int main(){
    
// Polynomial p; 
//  p.addTerm(10,0);
//  p.addTerm(4,-1); 

//  p.addTerm(2, 2); 
//  p.addTerm(1, 6);
//  p.addTerm(0, 4); 

//  Polynomial q;
//  q.addTerm(2, -6);
//  q.addTerm(1, 5); 

//  cout << "P(x) = " << p << endl;
//  cout << "P(1) = " << p.evaluate(1) << endl;
//  cout << "Q(x) = " << q << endl;
//  cout << "Q(1) = " << q.evaluate(1) << endl;
//  cout << "(P+Q)(x) = " << p+q << endl;
//  cout << "(P*Q)(x) = " << p*q << endl;
//  }


