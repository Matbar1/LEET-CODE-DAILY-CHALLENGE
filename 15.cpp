class Solution {
public:
    int maxValue(vector<vector<int>>& A, int k) {
        sort(begin(A), end(A));
        vector<vector<int>> dp(k + 1, vector<int>(A.size(), -1));
        function<int(int, int)> dfs = [&](int k, int i) {
            if (k == 0 || i >= A.size()) return 0;
            if (dp[k][i] != -1) return dp[k][i];
            int j = upper_bound(begin(A) + i + 1, end(A), A[i][1], [](int t, auto &a) { return a[0] > t; }) - begin(A);
            return dp[k][i] = max(dfs(k, i + 1), A[i][2] + dfs(k - 1, j));
        };
        return dfs(k, 0);
    }
};