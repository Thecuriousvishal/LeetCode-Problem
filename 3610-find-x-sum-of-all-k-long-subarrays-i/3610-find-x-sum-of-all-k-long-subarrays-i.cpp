class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
       int n = nums.size();
        vector<int> ans;

        for (int i = 0; i <= n - k; i++) 
        {
            unordered_map<int, int> freq;

            for (int j = i; j < i + k; j++) 
            {
                freq[nums[j]]++;
            }

            vector<pair<int, int>> vec;

            for (auto& p : freq)
                vec.push_back({p.first, p.second});

            sort(vec.begin(), vec.end(), [](auto& a, auto& b)
            {
                if (a.second == b.second)
                    return a.first > b.first;
                return a.second > b.second;
            });

            unordered_set<int> keep;
            for (int j = 0; j < x && j < vec.size(); j++)
                keep.insert(vec[j].first);

            int sum = 0;
            for (int j = i; j < i + k; j++) {
                if (keep.count(nums[j])) sum += nums[j];
            }
            ans.push_back(sum);
        }
        return ans;
    }
};