class Solution {
public:
    bool isPossible(int mid, vector<int>& nums, int threshold){
        int sum = 0;
        for(int i=0; i <  nums.size(); i++){
            sum += nums[i]/mid;
            if(nums[i]%mid != 0){
                sum += 1;
            }
        }
        return sum <= threshold;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        int ans;
        while(low <= high){
            int mid = (low + high) / 2;
            if(isPossible(mid,nums,threshold) == true){
                ans = mid;
                high = mid - 1;
            }
            else{
                low =  mid + 1;
            }
        }
        return ans;
    }
};