class Solution {
public:
    vector<int> asteroidCollision(vector<int>& A) {
        vector<int> ans;
        for (int n : A) {
            if (ans.empty() || ans.back() < 0 || n > 0) ans.push_back(n);
            else {
                while (ans.size() && ans.back() > 0 && ans.back() < -n) ans.pop_back();
                if (ans.size() && ans.back() == -n) ans.pop_back();
                else if (ans.empty() || ans.back() < 0) ans.push_back(n);
            }
        }
        return ans;
    }
};
