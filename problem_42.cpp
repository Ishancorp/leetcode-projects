// Problem 42
// Given n non-negative integers representing an elevation map where the width of each bar is 1,
//  compute how much water it can trap after raining.

class Solution {
public:
    int trap(vector<int>& height) {
        auto l = height.begin(), r = height.end() - 1;
        int level = 0, water = 0;
        while (l != r + 1) {
            int lower = *l < *r ? *l++ : *r--;
            level = max(level, lower);
            water += level - lower;
        }
        return water;
    }
};