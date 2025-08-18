class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;
        triangle.push_back({1});

        for (int i = 1; i < numRows; i++) {
            vector<int> prev = triangle.back();
            prev.insert(prev.begin(), 0);
            prev.push_back(0);

            vector<int> row;
            for (int j = 0; j < prev.size() - 1; j++) {
                row.push_back(prev[j] + prev[j + 1]);
            }
            triangle.push_back(row);
        }

        return triangle;
    }
};