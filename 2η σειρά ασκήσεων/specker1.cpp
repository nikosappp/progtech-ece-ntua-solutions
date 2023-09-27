
#include <iostream>
#include <stdexcept>

using namespace std;

class Move {
    public:
    // take sc coins from the hea sh and purt tc coins to heap th
    Move(int sh, int sc, int th, int tc);

    int getSource() const;
    int getSourceCoins() const;
    int getTarget() const;
    int getTargetCoins() const;

    friend ostream & operator << (ostream &out, const Move &move);

    private:
    int source, source_coins, target, target_coins;   
};


Move::Move(int sh, int sc, int th, int tc){
    source=sh;
    source_coins=sc;
    target=th;
    target_coins=tc;
}

int Move::getSource() const{
    return source;
}

int Move::getSourceCoins() const{
    return source_coins;
}

int Move::getTarget() const{
    return target;
}

int Move::getTargetCoins() const{
    return target_coins;
}

ostream & operator << (ostream &out, const Move &move){
    if(move.target_coins!=0){
        out << "takes " << move.source_coins 
        << " coins from heap " << move.source
        << " and puts " << move.target_coins 
        << " coins to heap " << move.target;
    }

    else {
        out << "takes " << move.source_coins 
        << " coins from heap " << move.source
        << " and puts nothing";
    }

}

class State{
    public:
    State(int h, const int c[], int n);
    ~State();

    void next(const Move &move) throw(logic_error);
    bool winning() const;

    int getHeaps() const;
    int getCoins(int he) const throw(logic_error);

    int getPlayers() const;
    int getPlaying() ;

    friend ostream & operator << (ostream &out, const State &stae);

    private:
    int heaps;
    int players;
    int *array;
    int playing_now;
};

State::State(int h, const int c[], int n){
    heaps=h;
    players=n;
    array = new int[heaps];
    for(int i=0; i<heaps; i++){
        array[i]=c[i];
    }
    playing_now=0;
}

State::~State(){
    delete [] array;
}

void State::next(const Move &move) throw(logic_error){

    if(move.getSource() >= heaps ||                        // source ektos orion 
    move.getSource() < 0 ||                               // source akuro <0
    move.getTarget() >= heaps ||                           // target ektos orion  
    move.getTarget() < 0 ||                               // target akuro <0
    move.getSourceCoins() > getCoins(move.getSource()) ||  // pairnw perissotera apo osa exei
    move.getSourceCoins() < 1 ||                          // pairnw akuro <0
    move.getTargetCoins() >= move.getSourceCoins() ||     // dino perissotera apo osa phra -1 
    move.getTargetCoins() < 0                             // dino akuro <0
    ){
        throw logic_error("invalid move");
    }

    else{
        array[move.getSource()] -= move.getSourceCoins();
        array[move.getTarget()] += move.getTargetCoins();
    }

    if(playing_now == players-1) playing_now=0;
    else playing_now++;
}

int State::getPlayers() const{
    return players;
}

int State::getHeaps() const{
    return heaps;
}

int State::getCoins(int he) const throw (logic_error){
    if (he < 0 || he >= heaps) throw logic_error("invalid heap");
    else return array[he];
}

int State::getPlaying(){
    return playing_now;
}

ostream & operator << (ostream &out, const State & state){
    for(int i=0; i<state.heaps-1; i++){
        out << state.array[i] << ", ";
    }
    out << state.array[state.heaps-1] << " with " << state.playing_now<< "/" << state.players << " playing next";
}

bool State::winning() const{
   bool flag=true;
   for(int i=0; i<heaps; i++){
    if(array[i]!=0){
    flag=false; break;
    }
   }
   if(flag) return true;
   else return false;
   }






