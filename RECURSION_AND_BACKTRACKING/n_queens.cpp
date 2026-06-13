#include <iostream>
#include <vector>
using namespace std;


// 5. N QUEENS


bool isSafe(vector<string>& board,
            int row,
            int col,
            int n)
{
    int r = row;
    int c = col;

    // left row
    while(c >= 0) {

        if(board[r][c] == 'Q')
            return false;

        c--;
    }

    // upper diagonal
    r = row;
    c = col;

    while(r >= 0 && c >= 0) {

        if(board[r][c] == 'Q')
            return false;

        r--;
        c--;
    }

    // lower diagonal
    r = row;
    c = col;

    while(r < n && c >= 0) {

        if(board[r][c] == 'Q')
            return false;

        r++;
        c--;
    }

    return true;
}

void solveNQ(vector<string>& board,
             int col,
             int n)
{
    if(col == n) {

        cout << "Solution Found\n";
        return;
    }

    for(int row=0; row<n; row++) {

        if(isSafe(board,row,col,n)) {

            board[row][col] = 'Q';

            solveNQ(board,col+1,n);

            board[row][col] = '.';
        }
    }
}
