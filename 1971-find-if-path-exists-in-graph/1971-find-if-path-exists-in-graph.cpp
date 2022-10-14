
 
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        if(edges.size()==0) return true;
        vector<int> adj[n]; 
        
        for(int i=0; i<edges.size(); i++){
           
            
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        queue<int> q;
        q.push(source);
        vector<bool> vis(n,0); 
        
        vis[source] = 1;
       
        while(!q.empty()){
            
            int top = q.front();
            q.pop();
            if(top==destination) return true;
            for(auto j : adj[top]){
                // if(j==destination) return true;
                if(!vis[j]){
                    vis[j]=1;
                    q.push(j);
                }
            }
            
        }
        
        return false;
    }
};