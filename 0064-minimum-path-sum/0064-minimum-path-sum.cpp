class Solution {
public:

    int minimumPathSum(int i, int j, int m, int n, vector<vector<int>>& grid,vector<vector<int>>& dp){
        //base case
        // if(i==0&&j==0){
        //     return grid[i][j];
        // }
        dp[0][0]=grid[0][0];

        //edge case
        // if(i<0||j<0){
        //     return 1e9;
        // }
        int uo =1e9;
        int lo = 1e9;


        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i==0&&j==0){
                    dp[0][0] = grid[0][0];
                }
                else{
                    int up=1e9;
                    if(i>0){
                        up=grid[i][j]+dp[i-1][j];
                    }
                    int left=1e9;
                    if(j>0){
                        left=grid[i][j]+dp[i][j-1];
                    }
                    dp[i][j]=min(up,left);
                }
            }
        }
        return dp[m-1][n-1];

        // if(dp[i][j]!=-1){
        //     return dp[i][j];  //s-3
        // }

        // //main logic 
        // int up = grid[i][j] + minimumPathSum(i-1,j,m,n,grid,dp);
        // int left = grid[i][j] + minimumPathSum(i,j-1,m,n,grid,dp);
        // return dp[i][j]=min(up,left); //s-3
        

    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1)); //s-1,s-2
        int i = m-1;
        int j = n-1;
        return minimumPathSum(i,j,m,n,grid,dp);
    }
};