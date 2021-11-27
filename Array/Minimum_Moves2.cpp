// Given an integer array nums of size n, return the minimum number of moves required to make all array elements equal.

// In one move, you can increment or decrement an element of the array by 1.

// Test cases are designed so that the answer will fit in a 32-bit integer.

 

// Example 1:

// Input: nums = [1,2,3]
// Output: 2
// Explanation:
// Only two moves are needed (remember each move increments or decrements one element):
// [1,2,3]  =>  [2,2,3]  =>  [2,2,2]

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(begin(nums), end(nums));
        int len = nums.size(), median = len % 2 ? nums[len / 2] : (nums[len / 2] + nums[len / 2 - 1]) / 2;
        
        int ret=0;
        for(int i=0;i<len;i++){
            ret+=(abs(nums[i]-median));
        }
        return ret;
    }
};
