#include <iostream>
#include <iomanip>

using namespace std;

class ChessBoardArray{
    protected:

     class Row{
        public:
        Row(ChessBoardArray &a, int i):
        chess_board_array(a), row(i) {}
        
        int & operator[] (int i) const{
            return chess_board_array.select(row,i);
        }
        private:
        ChessBoardArray &chess_board_array;
        int row;
     };   

     class ConstRow{
        public:
        ConstRow(const ChessBoardArray &a, int i):
            chess_board_array(a), row(i) {}
        
        const int & operator [] (int i) const{
            return chess_board_array.select(row,i);
        }
        private:
        const ChessBoardArray &chess_board_array;
        int row;
     };
     

    public:

    ChessBoardArray(unsigned size=0, unsigned base=0):
        data(new int[((size*size)+1)/2]),
        arraysize(size), arraybase(base)
         {}

    ChessBoardArray(const ChessBoardArray &a):
        data(new int[((a.arraysize*a.arraysize)+1)/2]),
        arraysize(a.arraysize),                                 ////////////
        arraybase(a.arraybase) {
        for(unsigned i=0; i<((arraysize*arraysize)+1)/2; ++i){
            data[i]=a.data[i];
        }
    }
        
    ~ChessBoardArray(){
        delete [] data;
    }

    ChessBoardArray & operator=(const ChessBoardArray &a){
        delete [] data;
        arraysize=a.arraysize;
        arraybase=a.arraybase;
        data=new int [((arraysize*arraysize)+1)/2];  
        for(unsigned i=0; i<((arraysize*arraysize)+1)/2; ++i){
            data[i]=a.data[i];
        }
        return *this;
    }

    int & select(int i, int j){
        return data[loc(i,j)];
    }

    const int & select(int i, int j) const {
        return data[loc(i,j)];
    }

    const Row operator[] (int i){
        return Row(*this, i);
    }

    const ConstRow operator [] (int i) const{
        return ConstRow(*this, i);
    }

    friend ostream &operator << (ostream &out, const ChessBoardArray &a){
        for(int i=0; i<a.arraysize; i++){
            for(int j=0; j<a.arraysize; j++){
                out << setw(4);
                if((i+j)%2==0){
                    out << a.select(i+a.arraybase, j+a.arraybase);
                }
                else out << 0;
            }
                cout << endl;
        }
    
    }
     
    private:

    int *data;
    unsigned arraysize, arraybase;

    unsigned loc(int i, int j) const throw (out_of_range){
        int di=i-arraybase , dj=j-arraybase;
        if(di<0 || dj<0 || di>=arraysize || dj>=arraysize || (i+j)%2==1) throw out_of_range("invaldi index");
        else return ((di*arraysize + dj)/2);                                    ///////////////////////
        }

};

/*int main(){
    ChessBoardArray a(4, 1); // size 4x4, rows and columns numbered from 1
a[3][1] = 42;
a[4][4] = 17;
try { a[2][1] = 7; }
catch(out_of_range &e) { cout << "a[2][1] is black" << endl; }
try { cout << a[1][2] << endl; }
catch(out_of_range &e) { cout << "and so is a[1][2]" << endl; }
cout << a;
}
*/
    