#include <bits/stdc++.h>

#define FILEIO freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

using namespace std;

typedef pair<int, int> pi;

vector<pair<int, int>> prims(vector<vector<int>> G, int n) {
    vector<int> cost(n, INT_MAX), parent(n, -1);
    vector<bool> included (n, false);

    priority_queue<pi, vector<pi>, greater<pi>> pq;
    pq.push({0, 0});
    cost[0] = 0;

    while(!pq.empty()) {
        int u = pq.top().second;
        pq.pop(); 
        if(included[u])
            continue;

        included[u] = true;
        for(int i = 0; i < n; i++) {
            if(G[u][i] == -1)
                continue;
            
            if(!included[i] && cost[i] > G[u][i]) {
                cost[i] = G[u][i];
                pq.push({cost[i], i});
                parent[i] = u;
            }
        }
    }

    vector<pi> mst(n);
    for(int i = 0; i < n ; i++) {
        mst[i].first = parent[i];
        mst[i].second = cost[i];
    }

    return mst;
}

int main() {
    FILEIO

    int n, e;
    cin>>n;
    vector<vector<int>> G(n, vector<int> (n, -1));
    cin>>e;
    for(int i = 0; i < e; i++) {
        int u, v, c;
        cin>>u>>v>>c;

        G[u][v] = G[v][u] = c;
    }

    vector<pair<int, int>> mst = prims(G, n);

    int total = 0;
    cout<<"\n Edges : ";
    for(int i = 0; i < n; i++) {
        if(mst[i].first != -1) {
            cout<<"\n\t"<<mst[i].first<<" -> "<<i<<" : "<<mst[i].second;
            total += mst[i].second;
        }
    }
    cout<<"\n\t Total cost : "<<total;
    return 0;
}