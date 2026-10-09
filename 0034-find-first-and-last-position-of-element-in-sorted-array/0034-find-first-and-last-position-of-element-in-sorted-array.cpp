class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        // Dono functions ko call karke answers variables me store kar lo
        int first = firstOccurrence(nums, target);
        
        // Agar first hi -1 hai, toh last dhundne ki zaroorat hi nahi
        if (first == -1) {
            return {-1, -1};
        }
        
        int last = lastOccurrence(nums, target);
        
        
        return {first, last};
    }

private: // Helper functions ko private rakhna best practice hai
    int firstOccurrence(vector<int>& arr, int target) {
        int low = 0, high = arr.size() - 1;
        int ans = -1; 
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (arr[mid] == target) {
                ans = mid;         
                high = mid - 1;    // Left me jao
            }
            else if (arr[mid] < target) {
                low = mid + 1;     
            }
            else {
                high = mid - 1;    
            }
        }
        return ans;
    }

    int lastOccurrence(vector<int>& arr, int target) {
        int low = 0, high = arr.size() - 1;
        int ans = -1; 
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (arr[mid] == target) {
                ans = mid;         
                low = mid + 1;     // Right me jao
            }
            else if (arr[mid] < target) {
                low = mid + 1;     
            }
            else {
                high = mid - 1;    
            }
        }
        return ans;
    }
};