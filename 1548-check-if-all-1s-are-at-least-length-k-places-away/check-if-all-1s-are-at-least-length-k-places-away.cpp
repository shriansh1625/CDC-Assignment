class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        // Initialize count to k. This handles the edge case of the first '1'
        // being valid, as k >= k will never be false.
        int count = k; 
        
        for (int num : nums) {
            if (num == 1) {
                // If we find a '1', check if we have seen at least k zeros
                // since the last '1'.
                if (count < k) {
                    // If not, they are too close.
                    return false;
                }
                // Reset the counter, as we've just seen a '1'.
                count = 0;
            } else {
                // If it's a '0', just increment the counter.
                count++;
            }
        }
        
        // If we get through the whole array without returning false,
        // it means all '1's were valid.
        return true;
    }
};