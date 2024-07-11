class Solution {
public:
    int passThePillow(int n, int time) {
        // int rounds=time/(n-1);
        // int ans=0;
        // if(rounds%2==0){
        //     ans=1+time%(n-1);
        // }else{
        //     ans=(n-time%(n-1));
        // }
        // return ans;
    
    
    
    
     int current_person = 1;  // Start from person 1
     int direction = 1;       // Direction: 1 for forward, -1 for backward

     for (int i = 0; i < time; ++i) {
        if (current_person == 1) {
            direction = 1;  // Start moving forward
        } else if (current_person == n) {
            direction = -1; // Start moving backward
        }
        
        current_person += direction;
    }

    return current_person;
        
    }
};