class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> *p0, *p1;
        int m, n; 
        if (nums1.size() > nums2.size()) {
            m = nums2.size();
            n = nums1.size();
            p0 = &nums2;
            p1 = &nums1;
        }
        else {
            m = nums1.size();
            n = nums2.size();
            p0 = &nums1;
            p1 = &nums2;
        }
        int l = 0, r = m, i, j, maxl, minr;
        while (l <= r) {
            i = (l + r) / 2;
            j = (m + n + 1) / 2 - i;
            if (i < m && (*p0)[i] < (*p1)[j-1]) {
                l = i + 1;
            }
            else if (i > 0 && (*p0)[i-1] > (*p1)[j]) {
                r = i - 1;
            }
            else {
                if (i == 0) {
                    maxl = (*p1)[j-1];
                }
                else if (j == 0) {
                    maxl = (*p0)[i-1];
                }
                else {
                    maxl = (*p0)[i-1] > (*p1)[j-1] ? (*p0)[i-1] : (*p1)[j-1];
                }
                if ((m + n) % 2) {
                    return maxl;
                }
                
                if (i == m) {
                    minr = (*p1)[j];
                }
                else if (j == n) {
                    minr = (*p0)[i];
                }
                else {
                    minr = (*p0)[i] < (*p1)[j] ? (*p0)[i] : (*p1)[j];
                }
                return (maxl + minr) / 2.0;
            }
        }
        return 0.0;
    }
};