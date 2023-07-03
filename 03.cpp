class Solution {
public:
 bool buddyStrings(string A, string B) {
    int n = A.size();
    int m = B.size();

    if (n != m) {
        return false;
    }

    if (A == B) {
        unordered_set<char> uniqueChars;
        for (char c : A) {
            if (uniqueChars.count(c) > 0) {
                return true;
            }
            uniqueChars.insert(c);
        }
        return false;
    }

    int diffCount = 0;
    int firstDiffIndex = -1;
    int secondDiffIndex = -1;

    for (int i = 0; i < n; i++) {
        if (A[i] != B[i]) {
            diffCount++;
            if (firstDiffIndex == -1) {
                firstDiffIndex = i;
            } else if (secondDiffIndex == -1) {
                secondDiffIndex = i;
            }
        }
    }

    if (diffCount != 2) {
        return false;
    }

    return (A[firstDiffIndex] == B[secondDiffIndex]) && (A[secondDiffIndex] == B[firstDiffIndex]);
}
};