class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
    int max_value = candies[0];
    vector<int>v1;
    for (int i = 0; i < candies.size(); ++i) {
        if (candies[i] > max_value) {
            max_value = candies[i]; // Update max_value
        }
        v1.push_back( candies[i] + extraCandies);
    }
    vector<bool> v2;
    for(int i = 0 ; i < v1.size();i++){

    if (v1[i] < max_value)
        v2.push_back(false);
    else
        v2.push_back(true);
    }
    return v2;

    }


};