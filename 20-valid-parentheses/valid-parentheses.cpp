class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        unordered_map<char, char> mapping;
        mapping[')'] = '(';
        mapping[']'] = '[';
        mapping['}'] = '{';

        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            if (mapping.count(c)) {
                char top = stk.empty() ? '#' : stk.top();
                if (!stk.empty()) stk.pop();
                if (top != mapping[c]) return false;
            } else {
                stk.push(c);
            }
        }

        return stk.empty();
    }
};