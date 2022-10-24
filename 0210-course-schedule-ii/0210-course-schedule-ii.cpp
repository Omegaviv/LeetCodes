class Solution {
    
public:
    bool checkCycle(int node, vector<int> adj[], vector<int> &vis, vector<int> &d){
        vis[node] = 1;
        d[node] = 1;
        for(auto i:adj[node]){
            if(vis[i]==-1){
                if(checkCycle(i,adj,vis,d)) return true;
            }
            else if(d[i]==1) return true;
        }
        d[node] =-1;
        return false;
    }
    
    
    void dfs(int i,vector<int> &vis, stack<int> &ans, vector<int> adj[]){
        vis[i] = 1;
        
        for(auto j : adj[i] ){
            cout<<j<<" inside dfs"<<endl;
            if(vis[j]==-1) dfs(j,vis,ans,adj);
        }
        ans.push(i);
    }

    
    vector<int> findOrder(int n, vector<vector<int>>& p) {
        if(p.size()==0){
            vector<int> ans;
            for(int i=0; i<n; i++) ans.push_back(i);
            cout<<"p is empty"<<endl;
            return ans;
            
        }
        vector<int> adj[n];
        
        for(int i=0; i<p.size(); i++){
            
            adj[p[i][1]].push_back(p[i][0]);
        }
        stack<int> ans;
        
        vector<int> visc(n,-1);
        vector<int> dc(n,-1);
        bool hasCycle = false;
        for(int i=0; i<n; i++){
            if(visc[i]==-1){
                if(checkCycle(i,adj,visc,dc)){
                    hasCycle = true;
                    break;
                }
            }
        }
        if(hasCycle){
            cout<<"cycel detected"<<endl;
            return {};}
        vector<int> vis(n,-1);
        for(int i=0;i<n; i++){
            cout<<i<<endl;
            if(vis[i]==-1){
                cout<<"calling dfs"<<endl;
                dfs(i,vis,ans,adj);
            }
        }
        
        // if(ans.size()!=n) return {};
        
        vector<int> res;
        cout<<"start reversing stack, stack size"<<ans.size()<<endl;
        while(!ans.empty()){
            cout<<ans.top()<<endl;
            res.push_back(ans.top());
            ans.pop();
        }
        return res;
        
    }
};