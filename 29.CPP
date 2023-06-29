class Solution {
    int getKey(int x, int y, int keys) {
        return 10000 * x + 100 * y + keys;
    }
    tuple<int, int, int> parseKey(int key) {
        return { key / 10000, key % 10000 / 100, key % 100 };
    }
public:
    int shortestPathAllKeys(vector<string>& A) {
        int M = A.size(), N = A[0].size(), keys = 0, step = 0, dirs[4][2] = { {0,1},{0,-1},{1,0},{-1,0} }, sx = 0, sy = 0;
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (A[i][j] >= 'a' && A[i][j] <= 'f') keys |= 1 << (A[i][j] - 'a');
                else if (A[i][j] == '@') sx = i, sy = j;
            }
        }
        int init = getKey(sx, sy, keys);
        queue<int> q{ {init} };
        unordered_set<int> seen{init};
        while (q.size()) {
            int cnt = q.size();
            while (cnt--) {
                auto [x, y, keys] = parseKey(q.front());
                q.pop();
                if (keys == 0) return step;
                for (auto &[dx, dy] : dirs) {
                    int a = x + dx, b = y + dy, next = 0;
                    if (a < 0 || a >= M || b < 0 || b >= N || A[a][b] == '#') continue;
                    if (A[a][b] >= 'A' && A[a][b] <= 'F') {
                        int k = A[a][b] - 'A';
                        if (keys >> k & 1) continue; // we don't have to corresponding key yet.
                        next = getKey(a, b, keys);
                    } else if (A[a][b] >= 'a' && A[a][b] <= 'f') {
                        int k = A[a][b] - 'a';
                        next = getKey(a, b, keys & ~(1 << k));
                    } else {
                        next = getKey(a, b, keys);
                    }
                    if (seen.count(next)) continue;
                    seen.insert(next);
                    q.push(next);
                }
            }
            step++;
        }
        return -1;
    }
};