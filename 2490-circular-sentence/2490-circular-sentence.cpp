class Solution {
public:
    // Space-Efficient Solution
    bool isCircularSentence(string s) { 
        int n = s.size();
        if(s[0] != s[n-1]){
            return false;
        }
        vector<string> subs = trim(s);
        for(int i=1; i<subs.size(); i++){
            if(subs[i-1].back() != subs[i].front()){
                return false;
            }
        }
        return true;
    }
    vector<string> trim(string &s){
        vector<string>res;
        string sub;
        for(char c:s){
            if(c != ' '){
                sub.push_back(c);
            }
            else{
                res.push_back(sub);
                sub.clear();
            }
        }
        res.push_back(sub);
        return res;
    }

    // Space-Using Solution
    
    // bool isCircularSentence(string s) { 
    //     int n = s.size();
    //     if(s[0] != s[n-1]){
    //         return false;
    //     }
    //     for(int i=0; i<n; i++){
    //         if(s[i] == ' '){
    //             if(s[i-1] != s[i+1]){
    //                 return false;
    //             }
    //         }
    //     }
    //     return true;
    // }

};