// FIRST NON-REPEATING CHARACTER

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

string firstNonRepeating(
            string stream)
{
    vector<int> freq(26,0);

    queue<char> q;

    string ans = "";

    for(char ch : stream) {

        freq[ch-'a']++;

        q.push(ch);

        while(!q.empty() &&
              freq[q.front()-'a'] > 1)
        {
            q.pop();
        }

        if(q.empty())
            ans += '#';
        else
            ans += q.front();
    }

    return ans;
}

int main() {

    string stream = "aabc";

    cout << firstNonRepeating(stream);

    return 0;
}