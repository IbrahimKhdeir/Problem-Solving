class Solution {
public:
    void backtrack(vector<string> &res, string current, int open, int close, int maxPairs) {
        if (current.size() == maxPairs * 2) {
            res.push_back(current);
            return;
        }

        if (open < maxPairs)
            backtrack(res, current + "(", open + 1, close, maxPairs);
        if (close < open)
            backtrack(res, current + ")", open, close + 1, maxPairs);
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        backtrack(res, "", 0, 0, n);
        return res;
    }
};