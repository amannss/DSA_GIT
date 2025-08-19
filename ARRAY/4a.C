// COUNT SIBARRAY WITH XOR K 

// BRUTE
// int funct(int a[], int n)
// {   // 2 4 6 4 6 
//     int k = 2 ; int count = 0 ; 
//     int xors = 0 ; 
//     for(int i= 0 ; i < n  ; i ++)
//     {
//         for(int j = i ; j < n ; j++)
//         {   xors = 0 ;
//             for(int k = i ; k < j ; k++)
//             {
//                 xors = xors ^ a[i] ;
//             }
//             if(xors == k ) count++ ;
//         }
//     }
//     return count ;
// }

// BETTER
// int funct(int a[], int n)
// {   // 2 4 6 4 6 
//     int k = 2 ; int count = 0 ; 
//     int xors = 0 ; 
//     for(int i= 0 ; i < n  ; i ++)
//     {   xors = 0 ;
//         for(int j = i ; j < n ; j++)
//         {   
//             xors = xors ^ a[i] ; 
//             if(xors == k ) count++ ;
//         }
//     }
//     return count ;
// }

// OPTIMAL
// int funct(int a[], int n)
// {   // 2 4 6 4 6 
//     int k = 6 ;
//     int xr = 0 ;
//     map<int , int> mpp ;
//     mpp[0] ++ ;
//     int cnt = 0 ;
//     for(int i = 0 ; i < n ; i++)
//     {
//         xr = xr ^a[i] ;
//         int x = xr ^ k ;
//         cnt += mpp[x] ;
//     }
//     return cnt ;
// }

// 3 SUM

// BRUTE
// int funct(int a[], int n)
// {   
//     int k = 0  ;
//     set<vector<int>>  st;
//     //  -1 0 1 2 -1 -4 
//     for(int i = 0 ; i < n - 2; i++)
//     {  
//         for(int j = i+1 ; j < n - 1 ; j++ )
//         {   
//             for(int k = j +1 ; k < n ; k++)
//             {   
//                 if(a[i] + a[j] + a[k] == 0) 
//                 {   
//                     vector<int> temp = {a[i] , a[j] , a[k]} ;
//                     sort(temp.begin() , temp.end()) ;
//                     st.insert(temp) ;
//                     // cout << a[i] << " + " << a[j] << " + " << a[k] << "= 0 "<<endl ; 
//                 }
//             }
//         }
//         vector<vector<int>> ans(st.begin() , st.end()) ;
//         return ans ;
//     }
// }

// BETTER 
// tc -> n^2 * log m
// sc -> n + 2*log m 
// int funct(int a[], int n)
// {   
//     int k = 0  ;
//     set<vector<int>>  st;
//     set<int> hashset ;
//     vector<int> temp ;
//     int third ;
//     //  -1 0 1 2 -1 -4 
//     for(int i = 0 ; i < n ; i++)
//     {  
//         for(int j = i+1 ; j < n  ; j++ )
//         {   
//             third = -(a[i] + a[j]) ;
//             if(hashset.find(third) != hashset.end())
//             {
//                 vector<int> temp= {a[i] , a[j] ,third} ;
//                 sort(temp.begin() , temp.end()) ;
//                 st.insert(temp) ;
//             }
//             hashset.insert(a[j]) ;
//         }
//         vector<vector<int>> ans(st.begin() , st.end()) ;
//     }
// }

// OPTIMAL
    // vector<vector<int>> threeSum(vector<int>& num) {
    //     vector<vector<int>> ans ; 
    //     int n = num.size(); 
    //     sort(num.begin() , num.end()) ; 
    //     for(int i = 0 ; i < n ; i++)
    //     {
    //         if(i>0 && num[i] == num[i-1] ) continue ; 
    //         int j = i+1 ; 
    //         int k = n -1 ;
    //         while(j < k )
    //         {
    //             int  sum = num[i] + num[j]  ;
    //             sum += num[k] ;
    //             if(sum < 0)
    //             {
    //                 j++ ;
    //             }
    //             else if(sum >  0 )
    //             {
    //                 k-- ;
    //             }
    //             else
    //             {
    //                 vector<int> temp = {num[i] , num[j] , num[k]};
    //                 ans.push_back(temp) ;
    //                 j++ ; k-- ;
    //                 while(j<k && num[j]==num[j-1] ) j++ ;
    //                 while(j<k && num[k]==num[k+1] ) k-- ;
    //             }
    //         }
    //     }return ans ;}

// 4 SUM

// BRUTE
// tc n^4     sc no. of quads of answer
// int funct(int a[], int n)
// {   
//     //  -1 0 1 2 -1 -4 
//     int k = 0  ;
//     set<vector<int>>  st;
//     for(int i = 0 ; i < n ; i++)
//     {  
//         for(int j = i+1 ; j < n  ; j++ )
//         {   
//             for(int k = j +1 ; k < n ; k++)
//             {   
//                 for(int l = k+1 ; l < n ; l++ )
//                 {
//                     long long sum = a[i] + a[j] ;
//                     sum += a[k] + a[l] ;
//                     if(sum == k)
//                     {
//                         vector<int> temp ={a[i] + a[j] + a[k] + a[l]};
//                         sort(temp.begin() , temp.end() ) ;
//                         st.insert(temp) ;
//                     } 
//                 }
//             }
//         }
//         vector<vector<int>> ans(st.begin() , st.end()) ;
//     }
// }

// BETTER
// just like 3 sum

// OPTIMAL
// class Solution {
// public:
//     vector<vector<int>> fourSum(vector<int>& nums, int target) {
//         int n = nums.size() ;
//         vector<vector<int>> ans ;
//         sort(nums.begin() , nums.end()) ;
//         for(int i = 0 ; i < n ; i ++)
//         {
//             if( i > 0 && nums[i] == nums[i-1]) continue ;
//             for(int j = i+1 ;j < n ; j++ )
//             {
//                 if(j != (i+1) && nums[j] == nums[j-1]) continue ;
//                 int k = j+1 ;
//                 int l = n-1 ;
//                 while(k<l)
//                 {
//                     long long sum = nums[i];
//                     sum+= nums[j];
//                     sum+= nums[k];
//                     sum+= nums[l];
//                     if(sum == target)
//                     {
//                         vector<int> temp = {nums[i] + nums[j] + nums[k] + nums[l]};
//                         ans.push_back(temp) ;
//                         k++ ; l-- ;
//                         while(k < l && nums[k] == nums[k-1]) k++ ;
//                         while(k < l  && nums[l] == nums[l+1]) l-- ;
//                     }
//                     else if(sum < target) k++ ;
//                     else l-- ;
//                 }
//             }
//         }
//         return ans;
//     }
// };

// MERGE OVERLAPPIINNG SEQUENCES

// BRUTE
// int funct(int a[], int n)
// {   vector<vector<int>> nums ; 
//     vector<vector<int>> ans ;
//     sort(nums.begin() , nums.end());
//     for(int i = 0 ; i < n ; i++)
//     {
//         int start = nums[i][0] ;
//         int end   = nums[i][1] ;
//         if(!ans.empty() && end <= ans.back()[1]  ) continue ;
//         for(int j = i +1 ; j < n ; j++)
//         {
//             if(nums[j][0] <= end)
//             {
//                 end = max(end , nums[j][1]) ;
//             }
//             else
//             {
//                break ;
//             }
//         }
//          ans.push_back({start , end});
//     }
// }

// OPTIMAL
// int funct(int a[], int n)
// {   vector<vector<int>> nums ; 
//     vector<vector<int>> ans ;
//     sort(nums.begin() , nums.end());
//     for(int i = 0 ; i < n ; i++)
//     {
//         if(ans.empty() || nums[i][0] > ans.back()[1] )
//         {
//             ans.push_back(nums[i]);
//         }
//         else{
//             ans.back()[1] = max(ans.back()[1] , nums[i][1]) ;
//         }
//     }
//     return ans ;
// }


