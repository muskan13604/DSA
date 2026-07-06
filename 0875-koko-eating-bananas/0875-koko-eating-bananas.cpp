class Solution {
public:
    bool canfinish(int n, vector<int> &piles, int h){
        double sum = 0;
        for(int i = 0; i < piles.size(); i++){
            sum += ceil((double)piles[i]/n);
        }
        return sum <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int ans ;
        
        while(low <= high){
            int mid = low + (high - low)/2;

            if(canfinish(mid, piles, h)){
                ans = mid;
                high = mid - 1;
            } else{
                low = mid + 1;
            }
        }
        return ans;
    }
};