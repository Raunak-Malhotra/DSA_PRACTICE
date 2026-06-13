#include <iostream>
#include <vector>
using namespace std;
void solveMaze(vector<vector<int>>& maze,
               int row,
               int col,
               string path,
               vector<vector<int>>& vis)
{
    int n = maze.size();

    if(row == n-1 &&
       col == n-1)
    {
        cout << path << endl;
        return;
    }

    vis[row][col] = 1;

    int dr[] = {1,0,0,-1};
    int dc[] = {0,-1,1,0};

    char dir[] = {'D','L','R','U'};

    for(int k=0;k<4;k++) {

        int nr = row + dr[k];
        int nc = col + dc[k];

        if(nr>=0 &&
           nc>=0 &&
           nr<n &&
           nc<n &&
           !vis[nr][nc] &&
           maze[nr][nc]==1)
        {
            solveMaze(
                maze,
                nr,
                nc,
                path + dir[k],
                vis
            );
        }
    }

    vis[row][col] = 0;
}
