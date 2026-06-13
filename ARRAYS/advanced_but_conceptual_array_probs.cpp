#include <iostream>
#include <vector>
using namespace std;


// 7. MAJORITY ELEMENT 


int majorityElement(vector<int>& nums) {

    int count = 0;
    int candidate = 0;

    for(int num : nums) {

        if(count == 0)
            candidate = num;

        if(num == candidate)
            count++;
        else
            count--;
    }

    return candidate;
}


// 8. PRODUCT OF ARRAY EXCEPT SELF


vector<int> productExceptSelf(
        vector<int>& nums)
{
    int n = nums.size();

    vector<int> ans(n,1);

    int prefix = 1;

    for(int i=0;i<n;i++) {

        ans[i] = prefix;

        prefix *= nums[i];
    }

    int suffix = 1;

    for(int i=n-1;i>=0;i--) {

        ans[i] *= suffix;

        suffix *= nums[i];
    }

    return ans;
}


// 9. SET MATRIX ZEROES

void setZeroes(vector<vector<int>>& matrix) {

    int rows = matrix.size();
    int cols = matrix[0].size();

    vector<int> row(rows,0);
    vector<int> col(cols,0);

    for(int i=0;i<rows;i++) {

        for(int j=0;j<cols;j++) {

            if(matrix[i][j] == 0) {

                row[i] = 1;
                col[j] = 1;
            }
        }
    }

    for(int i=0;i<rows;i++) {

        for(int j=0;j<cols;j++) {

            if(row[i] || col[j]) {

                matrix[i][j] = 0;
            }
        }
    }
}

// =====================================================
// 10. TRAPPING RAIN WATER  ( IMPORTANT AND INTERESTING AS WELL)
// =====================================================

int trap(vector<int>& height) {

    int left = 0;
    int right = height.size()-1;

    int leftMax = 0;
    int rightMax = 0;

    int water = 0;

    while(left < right) {

        if(height[left] < height[right]) {

            if(height[left] >= leftMax)
                leftMax = height[left];
            else
                water += leftMax-height[left];

            left++;
        }
        else {

            if(height[right] >= rightMax)
                rightMax = height[right];
            else
                water += rightMax-height[right];

            right--;
        }
    }

    return water;
}

int main() {

    cout<<"Advanced Array Problems\n";

    return 0;
}