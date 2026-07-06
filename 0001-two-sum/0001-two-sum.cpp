#include <vector>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        // Do loops chalakar har ek pair ko check karenge
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                // Agar do numbers ka sum target ke barabar hai
                if (nums[i] + nums[j] == target) {
                    return {i, j}; // Unke indices return kar do
                }
            }
        }
        return {}; // Agar koi pair nahi milta
    }
};