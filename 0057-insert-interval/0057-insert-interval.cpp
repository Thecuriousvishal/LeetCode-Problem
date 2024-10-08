class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        int i = 0;

        // Step 1: Add all intervals that come before the new interval.
        while (i < intervals.size() && intervals[i][1] < newInterval[0]) {
            result.push_back(intervals[i]);
            i++;
        }

        // Step 2: Merge all overlapping intervals with the new interval.
        while (i < intervals.size() && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        result.push_back(newInterval);  // Add the merged newInterval.

        // Step 3: Add all intervals that come after the new interval.
        while (i < intervals.size()) {
            result.push_back(intervals[i]);
            i++;
        }

        return result;
        }
};