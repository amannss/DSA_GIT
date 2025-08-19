
//                                               STRIVER

// L-1

// recursion 
// Recursion is a programming technique in which 
// a function calls itself to solve a problem by breaking it down into smaller subproblems. 
// - stack overflow -
// Stack overflow in recursion occurs
//  when the recursive calls are too deep,
//  causing the program to exceed the stack memory limit.
//  This typically happens if the base case is missing or not reached, 
//  leading to infinite recursion and program crash.

// L-2

// name print n times 
// void counter(string , int) ;
// int cnt = 1 ;
// int main()
// {   int n ;cout << "enter no. =" ;
// cin >> n ;
//     counter("aman" ,n);
// }
// void counter(string name,int n )
// {
//     if( cnt > n) return ;
//     cout << "\t" << name ;
//     cnt++;
//     counter(name , n);
// }
// print 1 to n 
// void counter(int , int) ;
// int main()
// {   int n ;
//     cout << "enter no. =" ;
//     cin >> n ;
//     counter(n ,n);
// }
// void counter(int x,int n )
// {
//     if( x == 0) return ;
//     counter(x-1 , n);
//     cout << "\t" << x ;
// }

// L-3

// sum of n numbers 
// PARAMATERIC
// void sum(int x ,int n , int s)
// {    
//     if(x > n) return  ;
//     s = s + x ;
//     if(x==n ) cout << s <<"\n";
//     sum(++x , n ,s );
// }
// int  main()
// {
//     int n ;
//     cout << "enter the no . =  " ;
//     cin >>  n ;
//     sum(1 , n , 0) ;
// }
// FUNCTIONAL
// int funct(int n)
// {
//     if(n==0) return 0 ;
//     return n + funct(n-1) ;
// }

// L-4

// reverse array
// void funct(int arr[],int i , int j)
// {   
//     if(i>j) return ;
//     swap(arr[i] ,arr[j]);
//     funct(arr,++i,--j) ;
// }
// int main()
// {   int  n ;
//     cout <<"enter  size:- " ;
//     cin >> n ;
//     int arr[n] ;
//     for(int i = 0 ; i< n ;i++) cin >> arr[i] ; cout <<  "\t" ;
//     cout << endl ;
//     funct(arr ,0,n-1) ;
//     for(auto it:arr) cout << it << "\t" ;
// } 
// palindrome check in string
// bool funct(int i )
// {   
//     if(i>= n/2) return True;
//     if(arr[i] != arr[n-i+1]) return false ;
//     funct(++i) ;
// }

// L-5

// multiple reccursive calls
// fibonacci sum
// funct(n)
// {
//     if(n<=1) return n ;
//     last = f(n-1); 
//     slast = f(n-2);
//     return first + last ;
// }

// L-6

// reccursion on subsequences 
// LC-78
//  void funct(vector<vector<int>>& result , int i ,vector<int>& temp,vector<int>& nums)
//     {
//         if(i>=nums.size()){result.push_back(temp) ;return ;}
//     temp.push_back(nums[i]);
//     funct(result,i+1,temp,nums);
//     temp.pop_back() ;
//     funct(result,i+1,temp,nums);
//     return ;
//     }
//     vector<vector<int>> subsets(vector<int>& nums) {
//         vector<vector<int>> result ;
//         vector<int> temp(0,nums.size()) ;
//         funct(result,0,temp,nums);
//         return result ;
//     }

// L-7

// all kind of patterns in reccursion
// find one subsequence with sum = k or check
// int solve(int ind, int sum,vector<int>& arr ,vector<int>& nums,int k) {
//     if (ind == nums.size())
//     {   // condition satisfied
//         if(sum==k) return 1 ;
//         // condition not satisfied
//         else return 0 ;
//     }
//     arr.push_back(nums[ind]) ;
//     sum+=nums[ind] ;
//     int l = solve(ind + 1,sum , arr , nums, k);
//     sum-=nums[ind];
//     arr.pop_back() ;
//     int r = solve(ind + 1,sum , arr , nums, k);
//     return (l || r) ;
// }
// number of subsequence with sum = k
// int solve(int ind, int sum,vector<int>& nums,int k) {
//     if (ind == nums.size())
//     {   // condition satisfied
//         if(sum==k) return 1 ;
//         // condition not satisfied
//         else return 0 ;
//     }
//     sum+=nums[ind] ;
//     int l = solve(ind + 1,sum , nums, k);
//     sum-=nums[ind];
//     int r = solve(ind + 1,sum , nums, k);
//     return (l + r) ;
// }

// L-8

// LC-39 COMBINATION SUM I
// void function(int ind,int target, vector<vector<int>>& ans,vector<int>& arr,vector<int>& ds)
// {
//     if(ind == arr.size())
//     {
//         if(target == 0) ans.push_back(ds) ;
//         return ;
//     }
//     // pick
//     if(arr[ind]<= target) 
//     {
//         ds.push_back(arr[ind]) ;
//         function(ind, target-arr[ind] , ans ,arr ,ds ) ;
//         ds.pop_back() ;
//     }
//     // not picking
//     function(ind +1 , target , ans ,arr ,ds ) ;
// }
//     vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
//         vector<vector<int>> ans ;
//         vector<int> ds ;
//         function(0, target , ans ,candidates ,ds ) ;
//         return ans ;
//     }

// L-9

// LC-40 COMBINATION SUM II
// void function(int ind,int target, vector<vector<int>>& ans,vector<int>& arr,vector<int>& ds)
// {
//     if(target == 0){ ans.push_back(ds) ;return ; }
//     // pick
//     for(int i = ind ; i < arr.size() ; i++)
//     {   if(i>ind && arr[i] == arr[i-1]) continue ;
//         if(arr[i] > target) break;
//         ds.push_back(arr[i]) ;
//         function(i+1, target-arr[i] , ans ,arr ,ds ) ;
//         ds.pop_back() ;
//     }
// }
//     vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
//         vector<vector<int>> ans ;
//         vector<int> ds ;
//         sort(candidates.begin() , candidates.end()) ;
//         function(0, target , ans ,candidates ,ds ) ;
//         return ans ;
//     }

// L-10 

// LC-78 SUBSET  I
    // void funct(vector<int>& result , int i ,int sum,vector<int>& nums)
    // {
    // if(i>=nums.size()){ result.push_back(sum) ;return ;}
    // // pick
    // funct(result,i+1,sum+nums[i],nums);
    // // not pick
    // funct(result,i+1,sum,nums);
    // }
    // vector<vector<int>> subsets(vector<int>& nums) {
    //     vector<int> result ;
    //     vector<int> temp(0,nums.size()) ;
    //     funct(result,0,0,nums);
    //     return result ;
    // }

// L-11

// LC-90 SUBSET  II
// void function(int ind,vector<vector<int>>& ans,vector<int>& arr,vector<int>& ds)
// {
//     ans.push_back(ds) ;
//     // pick
//     for(int i = ind ; i < arr.size() ; i++)
//     {   if(i>ind && arr[i] == arr[i-1]) continue ;
//         ds.push_back(arr[i]) ;
//         function(i+1 , ans ,arr ,ds ) ;
//         ds.pop_back() ;
//     }
// }
//     vector<vector<int>> subsetsWithDup(vector<int>& candidates) {
//         vector<vector<int>> ans ;
//         vector<int> ds ;
//         sort(candidates.begin() , candidates.end()) ;
//         function(0,ans ,candidates ,ds ) ;
//         return ans ;
//     }

// L-12,13

// LC-46 PRINT ALL PERMUTATION OF STRING-ARRAY
    // void function(int index , vector<vector<int>>& ans ,vector<int>& nums)
    // {
    //     if(index == nums.size()) {ans.push_back(nums);return ;}
    //     for(int i = index ; i < nums.size() ; i++)
    //     {
    //         swap(nums[index] , nums[i]) ;
    //         function( index+1 , ans ,nums) ;
    //         swap(nums[index] , nums[i]) ;
    //     }
    //     return ;
    // }
    // vector<vector<int>> permute(vector<int>& nums) {
    //     vector<vector<int>> ans ;
    //     function(0,ans ,nums) ;
    //     return ans ;
    // }

// L-14

// LC-51 N - QUEENS
// 
// bool safe_to_insert(int col ,int row,vector<string>& board )
//     {
//         int rows = row ;
//         int cols = col ;
//         // uppper diagonal
//         while(row >= 0 && col>= 0)
//         {
//             if(board[row][col] == 'Q') return false ;
//             row -- ; col--;
//         }
//         // left parallel
//         row =rows ;
//         col =cols ;
//         while(col >= 0)
//         {
//             if(board[row][col] == 'Q') return false ;
//             col-- ;
//         }
//          row =rows ;
//         col =cols ;
//         // lower diagonal
//         while(col >= 0 && row< board.size())
//         {
//             if(board[row][col] == 'Q') return false ;
//             row++ ; col-- ;
//         }
//         return true ;
//     }
//     void solve(int col ,  vector<vector<string>>& ans ,vector<string>& board )
//     {
//         if(col == board.size()) {   ans.push_back(board) ; return ; }
//         for(int row = 0 ; row < board.size() ; row++)
//         {
//             if(safe_to_insert(col , row ,board) == true) 
//             {   
//                 board[row][col] ='Q' ;
//                 solve(col+1 , ans,board);
//                 board[row][col] = '.' ;
//             }
//         }
//     }
//     vector<vector<string>> solveNQueens(int n) {
//         vector<vector<string>> ans ;
//         vector<string> board(n) ;
//         string s(n,'.') ;//"...."
//         for(int i = 0 ; i <n ; i++) board[i] = s;
//         solve(0 ,ans , board) ;
//         return ans ;
//     }

// L-15 

// LC-0 SUDOKU SOLVER 
// will do later

// L-16 

// LC-0 M COLOURING PROBLEM
// GRAPH TOPIC

// L-17 

// LC-131 PALINDROME PARTIONING
    // bool isPalindrome(string s , int start , int end)
    // {
    //     while(start<= end) 
    //     {
    //         if(s[start++] != s[end--]) return false ;
    //     }
    //     return true ;
    // }
    // void part(int index,vector<vector<string>>& result,vector<string>& path,string& s)
    // {
    //     if(index == s.length()){result.push_back(path) ; return ;}
    //     for(int i= index ; i<s.length() ;i++)
    //     {
    //         if(isPalindrome(s,index ,i))
    //         {
    //             path.push_back(s.substr(index,i-index+1)) ;
    //             part(i+1 , result , path , s);
    //             path.pop_back() ;
    //         }
    //     }
    // }
    // vector<vector<string>> partition(string s) {
    //     vector<vector<string>> result ;
    //     vector<string> path ;
    //     part(0,result,path,s);
    //     return result ;
    // }

// L-18 

// LC-60 PERMUTATION SEQUENCE

// L-19 

// LC-0 RAT IN MAZE
//  void solve(int i,int j,vector<vector<int>>& maze ,int n,string move,vector<string>& ans,vector<vector<int>>& vis )
//   {
//       if(i==n-1 && j==n-1){ans.push_back(move) ; return ;}
//       // down
//       if(i+1<n && !vis[i+1][j] && maze[i+1][j]==1)
//       {
//           vis[i][j] = 1;
//           solve(i+1,j,maze ,n ,move + 'D',ans ,vis) ;
//           vis[i][j] = 0;
//       }
//       // left
//       if(j-1>=0 && !vis[i][j-1] && maze[i][j-1]==1)
//       {
//           vis[i][j] = 1;
//           solve(i,j-1,maze ,n ,move + 'L',ans ,vis) ;
//           vis[i][j] = 0;
//       }
//       // right
//       if(j+1<n && !vis[i][j+1] && maze[i][j+1]==1)
//       {
//           vis[i][j] = 1;
//           solve(i,j+1,maze ,n ,move + 'R',ans ,vis) ;
//           vis[i][j] =0;
//       }
//       // upward
//       if(i-1>=0 && !vis[i-1][j] && maze[i-1][j]==1)
//       {
//           vis[i][j] = 1;
//           solve(i-1,j,maze ,n ,move + 'U',ans ,vis) ;
//           vis[i][j] =0 ;
//       }
//   }
//     vector<string> ratInMaze(vector<vector<int>>& maze) {
//         // code here
//         int n =maze.size() ;
//         vector<string> ans; 
//         vector<vector<int>> vis(n,vector<int> (n,0)) ;
//         if(maze[0][0] == 1) solve(0,0,maze,n,"",ans,vis) ;
//     }
// OPTIMAL
//   void solve(int i,int j,vector<vector<int>>& maze ,int n,string move,vector<string>& ans,vector<vector<int>>& vis,int di[],int dj[])
//   {
//       if(i==n-1 && j==n-1){ans.push_back(move) ; return ;}     
//       string dir ="DLRU" ;
//       for(int ind = 0 ; ind <4 ;ind++)
//       {
//           int nexti= i+di[ind] ;
//           int nextj= j+dj[ind] ;
//           if(nexti>=0 && nextj>=0 && nexti < n && nextj < n && !vis[nexti][nextj] && maze[nexti][nextj] == 1 )
//           {
//               vis[i][j] = 1 ;
//               solve(nexti , nextj ,maze , n, move + dir[ind],ans , vis ,di,dj) ;
//               vis[i][j] = 0 ;
//           } 
//       }
//   }
//     vector<string> ratInMaze(vector<vector<int>>& maze) {
//         // code here
//         int n =maze.size() ;
//         vector<string> ans; 
//         vector<vector<int>> vis(n,vector<int> (n,0)) ;
//         int di[] = {1,0,0,-1};
//         int dj[] = {0,-1,1,0};       
//         if(maze[0][0] == 1) solve(0,0,maze,n,"",ans,vis,di,dj) ;
//         return ans ;
//     }



