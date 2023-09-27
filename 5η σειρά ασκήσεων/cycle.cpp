#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

class Graph{
    private:

    int vertices;
    list<int> *ptr;
    vector<int> color;
    vector<int> parent;
    int start, end;


    bool dfs(int v){
        color[v]=1;
        for(int u:ptr[v]){
            if(color[u]==0){
                parent[u]=v;
                if(dfs(u)) return true;
            }
            else if(color[u]==1){
                end=v;
                start=u;
                return true;
            }    
        }
        color[v]=2;
        return false;
    }

    public:

    Graph(int V): vertices(V) {
        ptr=new list<int>[vertices];
    }

    ~Graph() { delete [] ptr;}

    void addEdge (int u, int v) {
        ptr[u].push_back(v);
    }

    bool cycle(vector<int> &path){
        color.assign(vertices, 0);
        parent.assign(vertices, -1);
        start=-1;

        for(int v=0; v<vertices; v++){
            if(color[v]==0 && dfs(v))
            break;
        }

        if(start==-1){
            return false;
        }
        else{
            path.push_back(start);
            for(int v=end; v!=start; v=parent[v])
            path.push_back(v);
            reverse(path.begin(), path.end());
            return true;
        }
    }


};

// int main() {
// int V, E;
// cin >> V >> E;
// Graph g(V);
// for (int i = 0; i < E; ++i) { int u, v; cin >> u >> v; g.addEdge(u, v); }
// vector<int> path;
// bool c = g.cycle(path);
// if (c) {
// cout << "CYCLE: ";
// for (int i = 0; i < path.size(); ++i)
// cout << path[i] << (i == path.size()-1 ? "\n" : " ");
// } else {
// cout << "NO CYCLE" << endl;
// }
// }
