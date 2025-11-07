#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // check if we can make every city's power >= x using at most k additions
    bool canMake(vector<int>& stations, int r, long long k, long long x) {
        int n = stations.size();
        // compute initial power for each city using prefix sums
        vector<long long> pref(n + 1, 0);
        for (int i = 0; i < n; ++i) pref[i + 1] = pref[i] + stations[i];
        vector<long long> power(n, 0);
        for (int i = 0; i < n; ++i) {
            int L = max(0, i - r);
            int R = min(n - 1, i + r);
            power[i] = pref[R + 1] - pref[L];
        }

        // diff array to simulate added stations' effect on ranges
        vector<long long> diff(n + 1, 0); // diff[n] used for easy subtraction
        long long addedPrefix = 0; // current cumulative added effect
        long long used = 0;

        for (int i = 0; i < n; ++i) {
            addedPrefix += diff[i]; // apply any diff that starts/ends at i
            long long cur = power[i] + addedPrefix;
            if (cur < x) {
                long long need = x - cur;
                used += need;
                if (used > k) return false;
                addedPrefix += need;
                // placing at pos = min(n-1, i + r) results in effect up to end = min(n-1, i + 2*r)
                int end = min(n - 1, i + 2 * r);
                diff[end + 1] -= need; // remove effect after 'end'
            }
        }
        return true;
    }

    long long maxPower(vector<int>& stations, int r, int k) {
        long long low = 0;
        long long sum = 0;
        for (int v : stations) sum += v;
        long long high = sum + k; // upper bound: all existing + all new in one city
        long long ans = 0;
        while (low <= high) {
            long long mid = (low + high) / 2;
            if (canMake(stations, r, k, mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};
