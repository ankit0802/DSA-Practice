class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& edges) {
        map<int,int> indeg;
        map<int,vector<int>> graph;
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            indeg[i]=0;
            vector<int> v;
            graph[i]=v;
        }
        for(int i=0;i<edges.size();i++)
        {
            graph[edges[i][0]].push_back(edges[i][1]);
            indeg[edges[i][1]]+=1;
        }
        queue<int> q;
        
        for(auto x:indeg)
        {
            if(x.second==0)
                q.push(x.first);
        }
        
        while(!q.empty())
        {
            int source=q.front();
            q.pop();
            ans.push_back(source);
            vector<int> temp=graph[source];
            for(auto x:temp)
            {
                indeg[x]-=1;
                if(indeg[x]==0)
                    q.push(x);
            }
        }
        if(ans.size()==n)
            return true;
        return false;
        
        
    }
};
