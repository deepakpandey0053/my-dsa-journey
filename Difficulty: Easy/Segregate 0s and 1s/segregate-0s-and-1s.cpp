 #include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void segregate0and1(vector<int>& arr) {
        int left = 0;
        int right = arr.size() - 1;

        while (left < right) {
            // Left me 0 hai toh sahi hai, aage bado
            if (arr[left] == 0) {
                left++;
            }
            // Right me 1 hai toh sahi hai, peeche aao
            else if (arr[right] == 1) {
                right--;
            }
            // Agar left me 1 hai aur right me 0 hai, toh swap kar do
            else {
                swap(arr[left], arr[right]);
                left++;
                right--;
            }
        }
    }
};
    
