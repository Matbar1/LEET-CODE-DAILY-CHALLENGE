class Solution {
    public:

    vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> permutations;
    permuteRecursive(permutations, nums, 0);
    return permutations;
}

void permuteRecursive(vector<vector<int>>& permutations, vector<int>& nums, int start) {
    if (start == nums.size() - 1) {
        permutations.push_back(nums);
        return;
    }

    for (int i = start; i < nums.size(); i++) {
        swap(nums[start], nums[i]);
        permuteRecursive(permutations, nums, start + 1);
        swap(nums[start], nums[i]); // backtrack
    }
}
};