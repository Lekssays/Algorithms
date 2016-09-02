#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define MAXN 30023
#define eps 1e-7

using namespace std;

struct edge {
    int u, v, w;
    
    bool operator < (edge o) const {
        if( abs(o.w - w) < eps )
            return pair<int, int>(u, v) < pair<int, int>(o.u, o.v);
        return w < o.w;
    }
};


int p[MAXN];
vector<edge> edgeList;
vector< pair<int,int> > connectedEdges;

int find(int u) {
    return p[u] == u ? u : find(p[u]);
}

void merge(int u, int v) {
    int pu = find(u), pv = find(v);
    p[pu] = pv;
}

int main(void){
    int u, v, w, n, e;

    while(true){
        cin >> n >> e;
        if(n == 0 && e == 0) return 0;
        edgeList.clear();
        connectedEdges.clear();
        for(int i = 0; i < e; i++){
            cin >> u >> v >> w;
            edgeList.push_back((edge){u, v, w});
        }

        sort(edgeList.begin(), edgeList.end());
        for(int i = 0; i < n; i++) p[i] = i;

        int res = 0;
        for(int i = 0; i < edgeList.size(); i++) {
            int u = edgeList[i].u, v = edgeList[i].v;
            if( find(u) == find(v) ) continue;
            merge(u, v);
            res += edgeList[i].w;
            if(edgeList[i].v > edgeList[i].u){
                connectedEdges.push_back(make_pair(edgeList[i].u, edgeList[i].v));
            } else {
                connectedEdges.push_back(make_pair(edgeList[i].v, edgeList[i].u));
            }
        }

        sort(connectedEdges.begin(), connectedEdges.end());
        if(res == 0 || connectedEdges.size() != n - 1) puts("Impossible");
        else {
            cout << res << endl;
            for (int i = 0; i < connectedEdges.size(); i++){
                cout << connectedEdges[i].first << " " << connectedEdges[i].second << endl;
            }
        }
    }
    return 0;
}
