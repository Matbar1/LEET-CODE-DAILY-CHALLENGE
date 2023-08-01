class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        
    vector<vector<int>> combinations;
    vector<int> current;
    combineRecursive(combinations, current, n, k, 1);
    return combinations;
}

void combineRecursive(vector<vector<int>>& combinations, vector<int>& current, int n, int k, int start) {
    if (k == 0) {
        combinations.push_back(current);
        return;
    }

    for (int i = start; i <= n; i++) {
        current.push_back(i);
        combineRecursive(combinations, current, n, k - 1, i + 1);
        current.pop_back();
    }
}
        
    
};