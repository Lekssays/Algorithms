#include <cstdio>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

namespace Task {

const int N = 100100; /* Nodes */
const int M = 100100; /* Edges */
const int INF = 1e10;

int n, m, q, s;
int e;

int last[N];
int prev[M];
int to[M];
int cost[M];
int dist[N];

void add_directed( int x, int y, int w ) {
    prev[e] = last[x];
    last[x] = e;
    to[e] = y;
    cost[e] = w;
    e += 1;
}

void init( void ) {
    e = 0;
    for(int i = 0; i < n; i++)
        last[i] = -1;
}



bool relax( int x, int y, int cost ) {
    if(dist[y] > dist[x] + cost) {
        dist[y] = dist[x] + cost;
        return true;
    }
    return false;
}

void dijkstra( int pss ) {
    priority_queue< pair<int, int>,
                    vector< pair<int, int> >,
                    greater< pair<int, int> > > Q;

    for(int i = 0; i < n; i++)
        dist[i] = INF;
    dist[pss] = 0;

    Q.push({dist[pss], pss});

    while(Q.empty() == false) {
        auto p = Q.top();
        Q.pop();

        int x = p.second;
        for(int e = last[x]; e + 1; e = prev[e]) {
            int y = to[e];
            if(relax(x, y, cost[e]))
                Q.push({dist[y], y});
        }
    }
}

};

using namespace Task;

int main( void ) {

    while(true) {

        cin >> n >> m;
        if((n + m == 0)
            return EXIT_SUCCESS;

        init();

        for(int i = 0; i < m; i++) {
            int x, y, cost;
            cin >> x >> y >> cost;
            add_directed(x, y, cost);
        }
        int soutce = 0;
        dijkstra(source);
        cout << dist[n - 1]<< endl;
    }

    return EXIT_SUCCESS;
}
