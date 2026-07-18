class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0; // Guard against empty input

        int n = nums.size();
        int officer = 0;
        int uniq = 1;
        int cm = 1;

        while (cm < n) {
            if (nums[cm] == nums[cm - 1]) {
                cm++;
                continue;
            }
            else {
                nums[officer + 1] = nums[cm];
                officer++;
                uniq++;
                cm++;
            }
        }
        return uniq;
    } // Closes removeDuplicates
};    // Closes class Solution