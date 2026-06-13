#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// THIS FILE CONTAINS THE QUESTIONS OF GRAPHS - DECENT LEVEL .
//BFS
// DFS
// Number of Islands
// Cycle Detection in Undirected Graph
// Topological Sort

vector<int> bfs(int V, vector<int> adj[]) {

    vector<int> ans;
    vector<int> vis(V,0);

    queue<int> q;

    q.push(0);
    vis[0] = 1;

    while(!q.empty()) {

        int node = q.front();
        q.pop();

        ans.push_back(node);

        for(auto nbr : adj[node]) {

            if(!vis[nbr]) {

                vis[nbr] = 1;
                q.push(nbr);
            }
        }
    }

    return ans;
}


void dfsHelper(int node,
               vector<int> adj[],
               vector<int>& vis,
               vector<int>& ans)
{
    vis[node] = 1;

    ans.push_back(node);

    for(auto nbr : adj[node]) {

        if(!vis[nbr]) {

            dfsHelper(
                nbr,
                adj,
                vis,
                ans
            );
        }
    }
}

vector<int> dfs(int V,
                vector<int> adj[])
{
    vector<int> vis(V,0);
    vector<int> ans;

    dfsHelper(
        0,
        adj,
        vis,
        ans
    );

    return ans;
}


void floodFill(int row,
               int col,
               vector<vector<char>>& grid)
{
    int n = grid.size();
    int m = grid[0].size();

    if(row<0 || col<0 ||
       row>=n || col>=m ||
       grid[row][col]=='0')
        return;

    grid[row][col] = '0';

    floodFill(row+1,col,grid);
    floodFill(row-1,col,grid);
    floodFill(row,col+1,grid);
    floodFill(row,col-1,grid);
}

int numIslands(
        vector<vector<char>>& grid)
{
    int islands = 0;

    for(int i=0;i<grid.size();i++) {

        for(int j=0;j<grid[0].size();j++) {

            if(grid[i][j]=='1') {

                islands++;

                floodFill(i,j,grid);
            }
        }
    }

    return islands;
}


bool detectCycle(int node,
                 int parent,
                 vector<int> adj[],
                 vector<int>& vis)
{
    vis[node] = 1;

    for(auto nbr : adj[node]) {

        if(!vis[nbr]) {

            if(detectCycle(
                nbr,
                node,
                adj,
                vis))
                return true;
        }

        else if(nbr != parent)
            return true;
    }

    return false;
}



vector<int> topoSort(
        int V,
        vector<int> adj[])
{
    vector<int> indegree(V,0);

    for(int i=0;i<V;i++) {

        for(auto nbr : adj[i])
            indegree[nbr]++;
    }

    queue<int> q;

    for(int i=0;i<V;i++) {

        if(indegree[i]==0)
            q.push(i);
    }

    vector<int> topo;

    while(!q.empty()) {

        int node = q.front();
        q.pop();

        topo.push_back(node);

        for(auto nbr : adj[node]) {

            indegree[nbr]--;

            if(indegree[nbr]==0)
                q.push(nbr);
        }
    }

    return topo;
}