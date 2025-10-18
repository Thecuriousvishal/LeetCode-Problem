class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long long curr = LLONG_MIN;
        int count=0;

        for(int x: nums)
        {
            long long left = (long long)x-k;
            long long right = (long long)x+k;

            //agar curr is smaller than left,  move it to left
            if(curr < left) curr=left;
            //agr curr is within the range, assign it and move ahead
            if(curr <= right)
            {
                count++;
                curr++;
            }
        }
        return count;
    }
};