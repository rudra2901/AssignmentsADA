#include <bits/stdc++.h>

#define FILEIO freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

using namespace std;

typedef pair<int, int> pi;

vector<int> dijkstras(vector<vector<int>> G, int n, int source) {
    vector<int> dist(n, INT_MAX);
    priority_queue<pi, vector<pi>, greater<pi>> pq;

    pq.push({0, source});
    dist[source] = 0;

    while(!pq.empty()) {
        int u = pq.top().second;
        pq.pop(); 
        
        for(int i = 0; i < n; i++) {
            if(G[u][i] == -1)
                continue;
            if(dist[i] > dist[u]+G[u][i]) {
                dist[i] = dist[u] + G[u][i];
                pq.push({dist[i], i});
            }
        }
    }

    return dist;
}

int main() {
    FILEIO

    int n, e;
    cin>>n;
    vector<vector<int>> G(n, vector<int> (n, -1));
    cin>>e;
    int source;
    cin>>source;

    for(int i = 0; i < e; i++) {
        int u, v, c;
        cin>>u>>v>>c;

        G[u][v] = c;
    }
    vector<int> res = dijkstras(G, n, source);
    cout<<"\n Shortest Path from source vertex "<<source<<" : ";
    for(int i = 0; i < n; i++)
        cout<<"\n\t to "<<i<<" : "<<res[i];

    return 0;
}