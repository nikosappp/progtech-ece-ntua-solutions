#include <iostream>

using namespace std;

class Game{
    public:
    Game(int h, int p){
    maxheaps=h; maxplayers=p;
    
    heapcounter=0;
    playercounter=0;

    heaps=new int[maxheaps];
    players=new Player*[maxplayers];                                                        //gt *                                        
    }

    ~Game(){
    delete [] heaps;
    delete [] players;
    }
    
    void addHeap(int coins) throw(logic_error){
        if(coins<0 || heapcounter>=maxheaps) throw logic_error("error!!!");
        else{
            heaps[heapcounter++]=coins;
        }
    }

    void addPlayer(Player *player) throw(logic_error){
    if(playercounter >= maxplayers) throw logic_error("error!!!");
    else{
        players[playercounter++]=player;
    }
    }

    void play(ostream &out) throw(logic_error){
    if(playercounter<maxplayers) throw logic_error("you need more players bro!");
    else if(heapcounter<maxheaps) throw logic_error("complete all the heaps idiot!");
    
    else{
        State s(maxheaps, heaps, maxplayers);

        while(!s.winning()){
            out << "State: " << s << endl;
            out << *getPlayer(s.getPlaying()) << " " << players[s.getPlaying()]->play(s) <<endl;     //* sto get
            s.next(players[s.getPlaying()]->play(s));
        }
        out << "State: " << s << endl;
        if(s.getPlaying()==0){
        out << *players[maxplayers-1] << " wins" << endl;                                   //* sto player
        }
        else out << *players[s.getPlaying()-1] << " wins" << endl;
        }
    }


    int getPlayers() const{
    return maxplayers;
    }

    const Player *getPlayer(int p) const throw(logic_error){             //ti epistrefei
    if(p>=maxplayers || p<0) throw logic_error("error");
    
    else return players[p];
    }

    private:
    int maxheaps, maxplayers;
    int heapcounter, playercounter;
    int *heaps;
    Player **players;                                                   //gt 2 *                                          
};






