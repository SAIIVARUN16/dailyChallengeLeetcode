class Solution {
public:
    void bfs(int i,int j,vector<vector<int>>& grid,queue<pair<int,int>> &q,vector<vector<int>>& vis){
        int n=grid.size();
        int m=grid[0].size();
        vis[i][j]=1;
        queue<pair<int,int>>qq;
        qq.push({i,j});
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        while(!qq.empty()){
            int row=qq.front().first;
            int col=qq.front().second;
            q.push({row,col});
            qq.pop();
            for(int i=0;i<4;i++){
                int nrow=row+drow[i];
                int ncol=col+dcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && 
                    !vis[nrow][ncol] && grid[nrow][ncol]==1){
                    vis[nrow][ncol]=1;
                    qq.push({nrow,ncol});
                }
            }
        }
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>>q;
        vector<vector<int>>vis(n,vector<int>(m,0));
        bool found=false;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    bfs(i,j,grid,q,vis);
                    found=true;
                    break;
                }
            }
            if(found) break;
        }
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        int ans=0;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                int row=q.front().first;
                int col=q.front().second;
                q.pop();
                for(int i=0;i<4;i++){
                    int nrow=row+drow[i];
                    int ncol=col+dcol[i];
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && 
                        !vis[nrow][ncol]){
                        if(grid[nrow][ncol]==1)
                            return ans;
                        vis[nrow][ncol]=1;
                        q.push({nrow,ncol});
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};