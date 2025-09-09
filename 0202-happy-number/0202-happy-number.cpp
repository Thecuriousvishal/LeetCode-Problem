class Solution {
public:
    int getNext(int n)
    {
        int total = 0;
        while(n>0)
        {
            int d=n%10;
            total+=d*d;
            n/=10;
        }
        return total;
    }

    bool isHappy(int n) {
        unordered_set<int> seen;
        while(true)
        {
            if(n==1) return true;
            if(seen.count(n)) return false;
            seen.insert(n);
            n=getNext(n);
        }
    }
};