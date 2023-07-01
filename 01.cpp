class Solution {
public:
    int distributeCookies(vector<int>& A, int K) {
        int N = A.size();
        vector<int> dp(1 << N, INT_MAX), next(1 << N), sum(1 << N);
        for (int m = 1; m < (1 << N); ++m) {
            int s = 0;
            for (int i = 0; i < N; ++i) {
                if (m >> i & 1) s += A[i];
            }
            sum[m] = s;
            dp[m] = s;
        }
        for (int k = 2; k <= K; ++k) {
            fill(begin(next), end(next), INT_MAX);
            for (int m = 1; m < (1 << N); ++m) {
                for (int s = m; s; s = (s - 1) & m) {
                    next[m] = min(next[m], max(dp[m - s], sum[s]));
                }
            }
            swap(dp, next);
        }
        return dp[(1 << N) - 1];
    }
};