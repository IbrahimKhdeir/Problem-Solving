class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row(rowIndex + 1, 1); // initialize with 1s
        
        for (int i = 2; i <= rowIndex; i++) {
            // update backwards to avoid overwriting values we still need
            for (int j = i - 1; j > 0; j--) {
                row[j] = row[j] + row[j - 1];
            }
        }
        return row;
    }
};