class Solution {
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int left = 1, right = row * col;
        
        while (left < right) {
            int mid = left + (right - left + 1) / 2;
            
            if (canCross(row, col, cells, mid)) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        
        return left;
    }
    
private:
    bool canCross(int row, int col, vector<vector<int>>& cells, int day) {
        vector<vector<bool>> grid(row, vector<bool>(col, false));
        
        for (int i = 0; i < day; i++) {
            grid[cells[i][0] - 1][cells[i][1] - 1] = true;
        }
        
        vector<int> dirs = {-1, 0, 1, 0, -1};
        queue<pair<int, int>> q;
        
        for (int j = 0; j < col; j++) {
            if (!grid[0][j]) {
                q.emplace(0, j);
                grid[0][j] = true;
            }
        }
        
        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            
            if (r == row - 1) {
                return true;
            }
            
            for (int i = 0; i < 4; i++) {
                int nr = r + dirs[i];
                int nc = c + dirs[i + 1];
                
                if (nr >= 0 && nr < row && nc >= 0 && nc < col && !grid[nr][nc]) {
                    q.emplace(nr, nc);
                    grid[nr][nc] = true;
                }
            }
        }
        
        return false;
    }

};