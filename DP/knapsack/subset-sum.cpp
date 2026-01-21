// TOP - DOWN 
bool  solve(vector<int>& arr , int n, int sum , int idx ,int t[1001][1001])
{   
    if(sum == 0 ) return true ;
    if(idx <0 ) return false ;
    if(t[idx][sum] != -1) return t[idx][sum] ;
    if(arr[idx] <=  sum  )
    {
        return t[idx][sum] = (solve(arr ,n , sum-arr[idx] , idx-1,t ) ||
                    solve(arr , n,sum , idx-1 ,t)) ;
    }
    else return t[idx][sum] = solve(arr , n , sum  ,idx-1 ,t ) ;
    return false ;
}
bool isSubsetSum(vector<int>& arr, int sum) {
    // code here
    int n = arr.size() ;
    int t[1001][1001] ;
    memset(t, -1 , sizeof(t)) ;
    return solve(arr ,n , sum , n-1 , t) ;
    }
};
// BOTTOM UP
class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        vector<vector<bool>> t(n + 1, vector<bool>(sum + 1, false));
        // Base cases
        for (int i = 0; i <= n; i++) {
            t[i][0] = true;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= sum; j++) {
                if (arr[i - 1] <= j) {
                    t[i][j] = t[i - 1][j] || t[i - 1][j - arr[i - 1]];
                } else {
                    t[i][j] = t[i - 1][j];
                }
            }
        }
        return t[n][sum];
    }
};
