#include <iostream>
#include <vector>

using namespace std;

class unionfind{
    private:
    vector<int> parent;
    vector<int> size;
    int num;

    public:
    unionfind(int n){
        num=n;
        parent.resize(n);
        size.resize(n, 1);
        for(int i=0; i<n; i++) parent[i]=i;
    }

    int getnum(){
        return num;
    }

    int find(int x){
        if(parent[x]==x) return x;
        else return find(parent[x]);
    }

    void unite(int x, int y){
        int rootx=find(x);
        int rooty=find(y);

        if(rootx!=rooty){
            if(size[rootx]<size[rooty]){
                swap(rootx, rooty);
            }
            num--;
            parent[rooty]=rootx;
            size[rootx]+=size[rooty];
        }
    }
};

int main(){
    int N, M, K;
    cin >> N >> M >> K;
    unionfind uf(N);
    
    int x, y;
    for(int i=0; i<M; ++i){
        cin >> x >> y;
        uf.unite(x, y);
    }
    int diff = uf.getnum() - K;
    if(diff < 2) cout<< 1 << endl;
    else cout << diff << endl;
    return 0;
}