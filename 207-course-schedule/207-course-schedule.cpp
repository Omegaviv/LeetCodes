class Solution {
public:
    
    bool hasCycle(int i, vector<int> &v, vector<int> &dv, vector<int> adj[]){
        v[i]=1;
        dv[i]=1;
        
        for(auto it:adj[i]){
            if(v[it]==-1){
                if(hasCycle(it,v,dv,adj)) return true;
            }
            else if(dv[it]==1) return true;
        }
        dv[i]=-1;
        return false;
        
    }
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<int> v (n,-1);
        vector<int> dv(n,-1);
        vector<int> adj[n];
        
        for(auto pre : prerequisites){
            
            adj[pre[1]].push_back(pre[0]);
        }
        
        for(int i=0; i<n; i++){
            // if(v[i]!=1){
                if(hasCycle(i,v,dv,adj)) return false;
            // }
        }
        
        return true;
    }
};