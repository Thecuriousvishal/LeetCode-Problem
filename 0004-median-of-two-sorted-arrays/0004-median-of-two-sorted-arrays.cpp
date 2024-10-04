class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Ensure nums1 is the smaller array
    if (nums1.size() > nums2.size()) {
        std::swap(nums1, nums2);
    }

    int m = nums1.size();
    int n = nums2.size();
    int imin = 0, imax = m, halfLen = (m + n + 1) / 2;

    while (imin <= imax) {
        int i = (imin + imax) / 2; // partition nums1
        int j = halfLen - i;       // partition nums2

        // If i is too small, we need to increase it
        if (i < m && nums2[j - 1] > nums1[i]) {
            imin = i + 1; // i is too small, must increase it
        }
        // If i is too big, we need to decrease it
        else if (i > 0 && nums1[i - 1] > nums2[j]) {
            imax = i - 1; // i is too big, must decrease it
        }
        // i is perfect
        else {
            // Get max of left side
            int maxLeft = 0;
            if (i == 0) {
                maxLeft = nums2[j - 1]; // nums1 is empty
            } else if (j == 0) {
                maxLeft = nums1[i - 1]; // nums2 is empty
            } else {
                maxLeft = std::max(nums1[i - 1], nums2[j - 1]);
            }

            // If the total number of elements is odd, return the max of left side
            if ((m + n) % 2 == 1) {
                return maxLeft;
            }

            // Get min of right side
            int minRight = 0;
            if (i == m) {
                minRight = nums2[j]; // nums1 is empty
            } else if (j == n) {
                minRight = nums1[i]; // nums2 is empty
            } else {
                minRight = std::min(nums1[i], nums2[j]);
            }

            // Return the average of max of left side and min of right side
            return (maxLeft + minRight) / 2.0;
        }
    }

    // If we get here, there is an error
    throw std::invalid_argument("Input arrays are not sorted.");
    }
};