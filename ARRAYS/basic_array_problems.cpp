#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
using namespace std;


// 1. TWO SUM (Leetcode 1)


vector<int> twoSum(vector<int>& nums, int target) {

    unordered_map<int,int> mp;

    for(int i=0;i<nums.size();i++) {

        int complement = target - nums[i];

        if(mp.find(complement) != mp.end()) {
            return {mp[complement], i};
        }

        mp[nums[i]] = i;
    }

    return {};
}


// 2. BEST TIME TO BUY AND SELL STOCK (Leetcode 121)


int maxProfit(vector<int>& prices) {

    int minPrice = INT_MAX;
    int maxProfit = 0;

    for(int price : prices) {

        minPrice = min(minPrice, price);

        maxProfit = max(maxProfit,
                        price - minPrice);
    }

    return maxProfit;
}


// 3. KADANE'S ALGORITHM


int maxSubArray(vector<int>& nums) {

    int sum = 0;
    int maxi = INT_MIN;

    for(int num : nums) {

        sum += num;

        maxi = max(maxi,sum);

        if(sum < 0)
            sum = 0;
    }

    return maxi;
}

int main() {

    cout<<"Basic Array Problems\n";

    return 0;
}