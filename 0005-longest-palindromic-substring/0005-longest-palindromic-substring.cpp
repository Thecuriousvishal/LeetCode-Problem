class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        if(n<=1) return s;
        
        int start=0, maxLength=0;
        
        //Helper function for to expand around the center 
        auto expandAroundCenter = [&](int left, int right )
        {
            while(left>=0 && right<n &&s[left]==s[right])
            {
                left--;
                right++;
            }
            int length = right -left - 1;
            if(length>maxLength)
            {
                maxLength=length;
                start=left+1;
            }
        };
        //iterate through each character as a center
        for(int i=0; i<n;i++){
            expandAroundCenter(i,i);
            expandAroundCenter(i,i+1);
        
        }
        //Extract the longest palindromic substring
        return s.substr(start, maxLength);
    }
};