#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    vector<int> nodes (N, 0);
    vector<int> path;

    for(int i=0; i<M; i++){
       int u, v;
       cin >> u >> v;
       nodes[u]++;
       nodes[v]++;
    }

    for(int i=0; i<N; i++){
        if(nodes[i] % 2 != 0){
            path.push_back(i);
        }

    }

    if(path.size()==0){
        cout << "CYCLE" << endl;
    }

    else if(path.size()==2){

        cout << "PATH ";

        if(path[0] < path[1]){
            cout << path[0] << " " << path[1] << endl;
        }
        else{
            cout << path[1] << " " << path[0] << endl;
        }
    }

    else{
        cout << "IMPOSSIBLE" << endl;
    }


}