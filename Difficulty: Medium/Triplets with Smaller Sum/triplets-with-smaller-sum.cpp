class Solution {
public:
    int countTriplets(int sum, vector<int>& arr) {
        int n = arr.size();
        int ans = 0; // Initialize the counter

        // Step 1: Sort the array to use the two-pointer technique
        sort(arr.begin(), arr.end());

        // Step 2: Fix the first element one by one
        for (int i = 0; i < n - 2; i++) {
            int left = i + 1;
            int right = n - 1;

            // Step 3: Use two pointers to find valid pairs
            while (left < right) {
                int current_sum = arr[i] + arr[left] + arr[right];

                if (current_sum >= sum) {
                    // Sum is too large, decrease the right pointer to get a smaller sum
                    right--;
                } else {
                    // If current_sum < sum, then keeping 'i' and 'left' fixed, 
                    // any 'right' between 'left+1' and 'right' will also form a valid triplet.
                    ans += (right - left);

                    // Move left pointer to check for other possibilities
                    left++;
                }
            }
        }

        return ans;
    }
};