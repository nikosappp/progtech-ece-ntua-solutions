#include <iostream>
#include <string>


using namespace std;

class Player {
    public:
    Player(const string &n){
        name=n;
    }
    virtual ~Player(){
        name.clear();                                                                 //clear  
    }                            
    virtual const string & getType() const = 0;
    virtual Move play(const State &s) = 0;

    friend ostream & operator << (ostream &out, const Player &player){
         out << player.getType() << " player " << player.name;
         return out;
    }

    protected:
    string name;
};


class GreedyPlayer: public Player{
    public:

    GreedyPlayer(const string &n):Player(n){
        type="Greedy";
    }
    
    virtual const string &getType() const override{
        return type;
    }

    virtual Move play(const State &s) override{
        int heapGR=0;
        for(int i=0; i<s.getHeaps(); i++){
            if(s.getCoins(i) > s.getCoins(heapGR)) {
            heapGR=i;
            }
        }
        return Move(heapGR, s.getCoins(heapGR), 0, 0);
    }
    

    private:
    string type;
};

class SpartanPlayer: public Player{
    public:

   SpartanPlayer(const string &n):Player(n){
        type="Spartan";
   }

    virtual const string &getType() const override{
        return type;
    }

    virtual Move play(const State &s) override{
    int heapSP=0;
    for(int i=0; i<s.getHeaps(); i++){
        if(s.getCoins(i)> s.getCoins(heapSP)) {
            heapSP=i;
        }
    } 
    return Move(heapSP, 1, 0, 0);
   }
    
    private:
    string type;
};


class SneakyPlayer: public Player{
    public:

    SneakyPlayer(const string &n):Player(n){
        type="Sneaky";
    }

    virtual const string &getType() const override{
        return type;
    }

    virtual Move play(const State &s) override{
        int heapSN;
        int firstcoins=0;

        while(s.getCoins(firstcoins)==0){firstcoins++;}
        heapSN=firstcoins;

        for(int i=heapSN; i<s.getHeaps(); i++){
            if(s.getCoins(i)!=0 && s.getCoins(i) < s.getCoins(heapSN)){
                heapSN=i;
            }
        }
        return Move(heapSN, s.getCoins(heapSN), 0, 0);
    }
       

    private:
    string type;
};

class RighteousPlayer: public Player{
    public:
    RighteousPlayer(const string &n):Player(n){
        type="Righteous";
    }

    virtual const string & getType() const override {
        return type;
    }

    virtual Move play(const State &s) override{
        int heapPut=0;
        int heapGet=0;
        int coins;

        for(int i=0; i<s.getHeaps(); i++){
            if(s.getCoins(i)>s.getCoins(heapGet)){
                heapGet=i;
            }
            if(s.getCoins(i) < s.getCoins(heapPut)){
                heapPut=i;
            }
        }

        if (s.getCoins(heapGet) % 2 == 0) {
            coins = s.getCoins(heapGet) / 2;
        }
        else {
            coins = ((s.getCoins(heapGet)) / 2) + 1;
        }
        

        return Move(heapGet, coins, heapPut, coins - 1);

    }

    private:
    string type;
};

//int main(){}
