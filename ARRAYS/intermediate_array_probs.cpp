#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// =================================================
// 4. MOVE ZEROES (Leetcode 283)
// ============================================

void moveZeroes(vector<int>& nums) {

    int j = 0;

    for(int i=0;i<nums.size();i++) {

        if(nums[i] != 0) {

            swap(nums[i], nums[j]);

            j++;
        }
    }
}


// 5. MERGE INTERVALS (Leetcode 56)


vector<vector<int>> mergeIntervals(
        vector<vector<int>>& intervals)
{
    vector<vector<int>> ans;

    sort(intervals.begin(),
         intervals.end());

    ans.push_back(intervals[0]);

    for(int i=1;i<intervals.size();i++) {

        if(intervals[i][0]
            <= ans.back()[1])
        {
            ans.back()[1] =
                max(ans.back()[1],
                    intervals[i][1]);
        }
        else {
            ans.push_back(intervals[i]);
        }
    }

    return ans;
}

// 6. NEXT PERMUTATION (Leetcode 31)


void nextPermutation(vector<int>& nums) {

    int index = -1;

    for(int i=nums.size()-2;i>=0;i--) {

        if(nums[i] < nums[i+1]) {

            index = i;
            break;
        }
    }

    if(index == -1) {

        reverse(nums.begin(),
                nums.end());

        return;
    }

    for(int i=nums.size()-1;i>index;i--) {

        if(nums[i] > nums[index]) {

            swap(nums[i], nums[index]);
            break;
        }
    }

    reverse(nums.begin()+index+1,
            nums.end());
}

int main() {

    cout<<"Intermediate Array Problems\n";

    return 0;
}