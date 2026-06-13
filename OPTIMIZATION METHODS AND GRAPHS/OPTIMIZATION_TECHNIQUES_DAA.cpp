#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

 // 6 DIJKSTRA


vector<int> dijkstra(
        int V,
        vector<vector<int>> adj[])
{
    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
    > pq;

    vector<int> dist(V,INT_MAX);

    dist[0] = 0;

    pq.push({0,0});

    while(!pq.empty()) {

        auto it = pq.top();
        pq.pop();

        int d = it.first;
        int node = it.second;

        for(auto nbr : adj[node]) {

            int adjNode = nbr[0];
            int wt = nbr[1];

            if(d + wt < dist[adjNode]) {

                dist[adjNode] = d + wt;

                pq.push({
                    dist[adjNode],
                    adjNode
                });
            }
        }
    }

    return dist;
}

// 7 BELLMAN FORD

vector<int> bellmanFord(
        int V,
        vector<vector<int>>& edges,
        int src)
{
    vector<int> dist(V,1e8);

    dist[src] = 0;

    for(int i=0;i<V-1;i++) {

        for(auto edge : edges) {

            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            if(dist[u] != 1e8 &&
               dist[u] + wt < dist[v])
            {
                dist[v] = dist[u] + wt;
            }
        }
    }

    return dist;
}

// 8 FLOYD WARSHALL

void floydWarshall(
        vector<vector<int>>& dist)
{
    int n = dist.size();

    for(int via=0; via<n; via++) {

        for(int i=0; i<n; i++) {

            for(int j=0; j<n; j++) {

                dist[i][j] =
                    min(
                        dist[i][j],
                        dist[i][via]
                        + dist[via][j]
                    );
            }
        }
    }
}

