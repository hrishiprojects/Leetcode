//Space and time-n*m

void dfs(vector<vector<int>>& heights, vector<vector<bool>>& vis,int last,int i,int j)
   {
       if(i < 0 || j < 0 || i >=heights.size() || j >=heights[0].size() ||last >heights[i][j] || vis[i][j]) return;
       vis[i][j]=true;
          dfs(heights,vis,heights[i][j],i+1,j);
          dfs(heights,vis,heights[i][j],i-1,j);
          dfs(heights,vis,heights[i][j],i,j+1);
          dfs(heights,vis,heights[i][j],i,j-1);
   }
   vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
       int n=heights.size();
       if(n == 0) return {};
       int m=heights[0].size();
       vector<vector<bool>> vis1(n,vector<bool> (m,false));  // declaring two map to check the visited position
       vector<vector<bool>>vis2(n,vector<bool>(m,false));
       for(int i=0;i<n;i++)
       {
           dfs(heights,vis1,INT_MIN,i,0);   // from column 0
           dfs(heights,vis2,INT_MIN,i,m-1);  // to column end
       }
        for(int j=0;j<m;j++)
       {
           dfs(heights,vis1,INT_MIN,0,j);  // from row 0
           dfs(heights,vis2,INT_MIN,n-1,j);  // to row end;
       }
       vector<vector<int>> ans;
      
       for(int i = 0; i < n; i++)
           for(int j = 0; j < m; j++)
               if (vis1[i][j] && vis2[i][j])  // comparing two visited map
                   ans.push_back({ i, j });    // storing the coordinates in ans
      
       return ans;
   }
};

