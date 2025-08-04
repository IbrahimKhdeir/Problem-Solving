class Solution {
public:
    int romanToInt(string s) {
        map<char,int>rmap={
            {'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}
        };
        int num=0;
        for(int i=0;i<s.length();i++){
            if(rmap[s[i]]>=rmap[s[i+1]])
            num+=rmap[s[i]];

            else num-=rmap[s[i]];
           
        }

    return num;
    }
};