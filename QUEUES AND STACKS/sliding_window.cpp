// SLIDING WINDOW MAXIMUM

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

vector<int> maxSlidingWindow(
            vector<int>& nums,
            int k)
{
    deque<int> dq;

    vector<int> ans;

    for(int i=0;i<nums.size();i++) {

        // Remove out-of-window indices
        while(!dq.empty() &&
              dq.front() <= i-k)
        {
            dq.pop_front();
        }

        // Remove smaller elements
        while(!dq.empty() &&
              nums[dq.back()] <= nums[i])
        {
            dq.pop_back();
        }

        dq.push_back(i);

        // Window formed
        if(i >= k-1) {

            ans.push_back(
                nums[dq.front()]
            );
        }
    }

    return ans;
}

int main() {

    vector<int> nums =
    {1,3,-1,-3,5,3,6,7};

    int k = 3;

    vector<int> ans =
        maxSlidingWindow(nums,k);

    for(int x : ans)
        cout << x << " ";

    return 0;
}