class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int size = nums.size();
        vector<int> pos;
        vector<int> neg;

        // Separate negative and non-negative numbers
        for (int i = 0; i < size; i++) {
            if (nums[i] < 0)
                neg.push_back(nums[i]);
            else 
                pos.push_back(nums[i]);
        } 

        int n = neg.size();
        int m = pos.size();

        // Case 1: No negative elements
        if (n == 0) {
            for (int i = 0; i < m; i++)
                pos[i] = pos[i] * pos[i];
            return pos;
        } 

        // Case 2: No positive elements
        if (m == 0) {
            for (int i = 0; i < n; i++)
                neg[i] = neg[i] * neg[i];
            reverse(neg.begin(), neg.end());
            return neg;
        } 

        // Square negative elements and reverse to make them ascending
        for (int i = 0; i < n; i++)
            neg[i] = neg[i] * neg[i];
        reverse(neg.begin(), neg.end());

        // Square positive elements
        for (int i = 0; i < m; i++)
            pos[i] = pos[i] * pos[i];

        // Two pointer merge algorithm
        int i = 0, j = 0;
        int id = 0;
        vector<int> res(n + m);

        while (i < n && j < m) {
            if (neg[i] <= pos[j]) { // Fixed: changed pos[i] to pos[j]
                res[id] = neg[i];
                id++;
                i++;
            } else {
                res[id] = pos[j];
                id++;
                j++;
            }
        }

        // Copy remaining negative elements if any
        while (i < n) {
            res[id] = neg[i];
            id++;
            i++;
        }

        // Copy remaining positive elements if any
        while (j < m) {
            res[id] = pos[j];
            id++;
            j++; // Fixed: changed i++ to j++
        }

        return res;
    }
};