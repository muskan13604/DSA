class Solution {
    public:
    int nthMagicalNumber(int n, int a, int b) {
        long long MOD =  1e9 + 7;
        long long L = std::lcm((long long)a, (long long)b);
        long long low = 1;
        long long high = (long long)min(a, b) * n;
        long long ans = high;
        while (low <= high) {
        long long mid = low + (high - low) / 2;
        long long cnt = mid / a + mid / b - mid / L;
        if (cnt >= n) {
            ans = mid;
            high = mid - 1;
            } else {
                low = mid + 1;
                }
                }
                return ans % MOD;
                }
                };
        
  