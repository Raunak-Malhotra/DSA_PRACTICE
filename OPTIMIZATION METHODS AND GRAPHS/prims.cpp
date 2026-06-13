// PRIM'S ALGORITHM (MST)

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int primMST(int V, vector<vector<int>> adj[]) {

    // {weight, node}
    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
    > pq;

    vector<int> vis(V,0);

    int mstWt = 0;

    // Start from node 0
    pq.push({0,0});

    while(!pq.empty()) {

        auto top = pq.top();
        pq.pop();

        int wt = top.first;
        int node = top.second;

        // Already included in MST
        if(vis[node])
            continue;

        vis[node] = 1;

        mstWt += wt;

        // Explore neighbours
        for(auto nbr : adj[node]) {

            int adjNode = nbr[0];
            int edgeWt = nbr[1];

            if(!vis[adjNode]) {

                pq.push({
                    edgeWt,
                    adjNode
                });
            }
        }
    }

    return mstWt;
}

int main() {

    int V = 5;

    vector<vector<int>> adj[5];

    adj[0].push_back({1,2});
    adj[1].push_back({0,2});

    adj[0].push_back({3,6});
    adj[3].push_back({0,6});

    adj[1].push_back({2,3});
    adj[2].push_back({1,3});

    adj[1].push_back({3,8});
    adj[3].push_back({1,8});

    adj[1].push_back({4,5});
    adj[4].push_back({1,5});

    adj[2].push_back({4,7});
    adj[4].push_back({2,7});

    cout << primMST(V,adj);

    return 0;
}