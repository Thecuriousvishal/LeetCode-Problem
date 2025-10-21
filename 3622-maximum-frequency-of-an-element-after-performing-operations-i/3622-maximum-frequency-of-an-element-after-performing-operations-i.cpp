class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        const int MAXV = 100000;
        vector<int> freq(MAXV + 1, 0);
        for (int x : nums) if (x >= 1 && x <= MAXV) freq[x]++;

        // prefix sums
        vector<int> pref(MAXV + 1, 0);
        for (int v = 1; v <= MAXV; ++v) pref[v] = pref[v-1] + freq[v];

        int ans = 0;
        for (int T = 1; T <= MAXV; ++T) {
            if (pref[MAXV] - pref[0] == 0) break; // no numbers at all (safe-guard)
            // range [T-k, T+k]
            int L = max(1, T - k);
            int R = min(MAXV, T + k);
            int inRange = pref[R] - pref[L - 1];      // count numbers that can be moved to T (including those already equal)
            int count_eq = freq[T];
            int count_can_move = inRange - count_eq;  // those that need an operation to become T
            int cur = count_eq + min(numOperations, count_can_move);
            ans = max(ans, cur);
        }
        return ans;
    }   
};