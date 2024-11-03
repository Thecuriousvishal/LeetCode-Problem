class Solution {
public:
    bool rotateString(string s, string goal) {
        //step 1: check if length are equal
        if(s.length()!=goal.length()){
            return false;
        }
        //step 2: concatenate s with it self
        string double_str=s+s;
        
        //step 2: check if goal is substring of double_str
        return double_str.find(goal)!=string::npos;
    }
};