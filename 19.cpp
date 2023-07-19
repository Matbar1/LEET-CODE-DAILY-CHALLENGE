class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& A) {
        sort(begin(A), end(A), [](auto &a, auto &b) { return a[1] < b[1]; });
        int ans = 0, e = INT_MIN;
        for (auto &v : A) {
            if (v[0] >= e) e = v[1];
            else ++ans;
        }
        return ans;
    }
};