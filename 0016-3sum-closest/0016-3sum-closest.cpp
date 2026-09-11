class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        
        
        // 1. Array ko sort karo yahan
        sort(nums.begin(),nums.end());
        // 2. Ek variable banao 'closest_sum' aur usme pehle 3 elements ka sum daal do
        int closest_sum = nums[0]+nums[1]+nums[2];
        for(int i = 0; i < n - 2; i++){
            // Duplicate 'i' ko skip karo jaisa tumne likha tha
            if (i>0 && nums[i]==nums[i-1]){
                continue;
            }
            
            int left = i + 1; // Index
            int right = n - 1; // Index
            
            while(left < right){
                int sum = nums[i] + nums[left] + nums[right];
                
                // 3. Check karo: kya abs(sum - target) < abs(closest_sum - target) hai?
               if(  abs(sum - target) <  abs(closest_sum - target)){
                  closest_sum = sum;
               }
                // Agar haan, toh closest_sum ko update kar do.
                
                // 4. Pointers move karne ka logic:
                if(sum < target) {
                    left++;
                } else if(sum > target) {
                    right--;
                } else {
                    // Agar sum bilkul target ke barabar hai, toh isse closest kuch nahi!
                    return sum; 
                }
            }
        }
        
         return closest_sum; // 5. Akhir mein closest_sum return kar do
    }
};