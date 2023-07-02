class Solution {
public:
    int maximumRequests(int n, vector<vector<int>>& A) {
        int M = A.size(), ans = 0, cnt[20] = {};
        auto valid = [&](int m) {
            memset(cnt, 0, sizeof(cnt));
            for (int i = 0; i < M; ++i) {
                if ((m >> i & 1) == 0) continue;
                --cnt[A[i][0]];
                ++cnt[A[i][1]];
            }
            for (int i = 0; i < n; ++i) {
                if (cnt[i]) return false;
            }
            return true;
        };
        for (int m = 1; m < (1 << M); ++m) {
            if (valid(m)) ans = max(ans, __builtin_popcount(m));
        }
        return ans;
    }
};