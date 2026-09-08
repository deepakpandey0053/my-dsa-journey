class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> pos;
        vector<int> neg;

        // 1. Separate karte waqt hi square kar do (Sirf ek baar)
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < 0)
                neg.push_back(nums[i] * nums[i]);
            else 
                pos.push_back(nums[i] * nums[i]);
        } 

        // 2. Negative squares ko reverse karo (taaki chote se bada ho jaye)
        reverse(neg.begin(), neg.end());

        // 3. Two pointer merge algorithm (Dono arrays ko combine karo)
        vector<int> res;
        int i = 0; // neg ke liye pointer
        int j = 0; // pos ke liye pointer

        while (i < neg.size() && j < pos.size()) {
            if (neg[i] <= pos[j]) { 
                res.push_back(neg[i]);
                i++;
            } else {
                res.push_back(pos[j]);
                j++;
            }
        }

        // Agar neg mein kuch bach gaya toh usko daal do
        while (i < neg.size()) {
            res.push_back(neg[i]);
            i++;
        }

        // Agar pos mein kuch bach gaya toh usko daal do
        while (j < pos.size()) {
            res.push_back(pos[j]);
            j++;
        }

        return res;
    }
};