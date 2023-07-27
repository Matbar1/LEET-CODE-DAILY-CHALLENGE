class Solution {
private:
    bool isPossibleToRun(int n, const std::vector<int>& computers, long long avgTime) {
        long long duration = 0;
        for (long long ele : computers) {
            duration += std::min(ele, avgTime);
        }
        return avgTime * n <= duration;
    }

public:
    long long maxRunTime(int n, const std::vector<int>& computers) {
        long long startTime = 0;
        long long sum = 0;
        long long ans = 0;
        for (long long ele : computers) {
            sum += ele;
        }
        long long endTime = sum;

        while (startTime <= endTime) {
            long long avgTime = (startTime + endTime) / 2;
            if (isPossibleToRun(n, computers, avgTime)) {
                ans = avgTime;
                startTime = avgTime + 1;
            } else {
                endTime = avgTime - 1;
            }
        }
        return ans;
    }
};