#include <iostream>
#include <vector>
using namespace std;


// 7. SUDOKU SOLVER


bool isValid(vector<vector<char>>& board,
             int row,
             int col,
             char ch)
{
    for(int i=0;i<9;i++) {

        if(board[row][i] == ch)
            return false;

        if(board[i][col] == ch)
            return false;

        if(board[
            3*(row/3)+i/3]
            [3*(col/3)+i%3]
            == ch)
            return false;
    }

    return true;
}

bool solveSudoku(
        vector<vector<char>>& board)
{
    for(int row=0;row<9;row++) {

        for(int col=0;col<9;col++) {

            if(board[row][col] == '.') {

                for(char ch='1';
                    ch<='9';
                    ch++)
                {
                    if(isValid(
                        board,
                        row,
                        col,
                        ch))
                    {
                        board[row][col] = ch;

                        if(solveSudoku(board))
                            return true;

                        board[row][col] = '.';
                    }
                }

                return false;
            }
        }
    }

    return true;
}


bool isPal(string& s,
           int l,
           int r)
{
    while(l < r) {

        if(s[l] != s[r])
            return false;

        l++;
        r--;
    }

    return true;
}

void partition(string& s,
               int idx,
               vector<string>& ds)
{
    if(idx == s.length()) {

        for(string str : ds)
            cout << str << " ";

        cout << endl;
        return;
    }

    for(int i=idx;
        i<s.length();
        i++)
    {
        if(isPal(s,idx,i)) {

            ds.push_back(
                s.substr(
                    idx,
                    i-idx+1
                )
            );

            partition(
                s,
                i+1,
                ds
            );

            ds.pop_back();
        }
    }
}