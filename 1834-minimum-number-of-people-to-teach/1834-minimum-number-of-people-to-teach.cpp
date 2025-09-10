class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int m = languages.size();
    
        // Convert each user's languages to set for easier checking
        vector<set<int>> langSet(m);
        for (int i = 0; i < m; i++) {
            for (int l : languages[i])
                langSet[i].insert(l);
        }
        
        int minTeach = INT_MAX;
        
        // Try teaching each language
        for (int teachLang = 1; teachLang <= n; teachLang++) {
            set<int> taughtUsers;
            
            for (auto& f : friendships) {
                int u = f[0] - 1;
                int v = f[1] - 1;
                
                // Check if u and v can communicate
                bool canCommunicate = false;
                for (int l : langSet[u]) {
                    if (langSet[v].count(l)) {
                        canCommunicate = true;
                        break;
                    }
                }
                
                if (!canCommunicate) {
                    // Teach teachLang to one of them if they don't know it
                    if (!langSet[u].count(teachLang)) taughtUsers.insert(u);
                    if (!langSet[v].count(teachLang)) taughtUsers.insert(v);
                }
            }
            
            minTeach = min(minTeach, (int)taughtUsers.size());
        }
        
        return minTeach;
    }
};