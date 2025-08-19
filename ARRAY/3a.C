#include<bits/stdc++.h>
using namespace std ;

// LONGEST SUBARRAY WITH SUM K

// BRUTE
// LONGEST SUBARRAY WITH SUM K
// int main()
// {
//     int n;cout << "enter size of first array :" ;cin >> n ;
//     int arr[n] ; cout << "enter elements of first array : " << endl ; 
//     for(int i=0 ; i < n ;i++ ) cin >> arr[i] ;
//     int p ;cout << "enter p : " ;
//     cin >> p ;
//     int len = 0;
//     // i and j for findng each subarray 
//     // k for finding sum of each subaaray
//     // 1 2 3 1 1 1 1 4 2 3
//     int s = 0 ;
//     for(int i = 0 ;i< n ;i++)
//     {
//         for(int j = i ;j < n ; j++)
//         {   s = 0 ;
//             for(int k = i ;k<=j ; k++)
//             {s +=arr[k];}
//         if(s == p)  len = max(len , j-i+1);// gives biiger lenght
//         }
//     }
//     cout << "ans is : " << len ;
// }

// OPTIMIZING BRUTE
// int main()
// {
//     int n;cout << "enter size of first array :" ;cin >> n ;
//     int arr[n] ; cout << "enter elements of first array : " << endl ; 
//     for(int i=0 ; i < n ;i++ ) cin >> arr[i] ;
//     int p ;cout << "enter p : " ;
//     cin >> p ;
//     int len = 0;
//     // i and j for findng each subarray 
//     // k for finding sum of each subaaray
//     // 1 2 3 1 1 1 1 4 2 3
//     int s = 0 ;
//     for(int i = 0 ;i< n ;i++)
//     {    s = 0 ;
//         for(int j = i ;j < n ; j++)
//         {  
//             s+= arr[i] ;
//             if(s == p)  len = max(len , j-i+1);// gives bigger lenght
//         }
//     }
//     cout << "ans is : " << len ;
// }

// BETTER
// // tc is n
// int funct(vector<int> &a, long long k)
// {
//     int maxlen = 0;
//     int presum = 0;
//     int len;
//     map<long long, int> mpp;
//     for (int i = 0; i < a.size(); i++)
//     {
//         presum += a[i];
//         if (presum == k)
//         {
//             maxlen = max(maxlen, i + 1);
//         }
//         long long rem = presum - k;
//         if (mpp.find(rem) != mpp.end())
//         {
//             len = i - mpp[rem];
//             maxlen = max(maxlen, len);
//         }
//         if(mpp.find(presum) == mpp.end() ) mpp[presum] = i ;  // means not mpp[presum exists]
//     }
//     return maxlen;
// }
// int main()
// {
//     vector<int> a = {1, 2, 3, 1, 1, 1, 1, 4, 2, 3};
//     long long k;
//     cout << "enter k : ";
//     cin >> k;
//     // 1 2 3 1 1 1 1 4 2 3
//     int ans = funct(a, k);
//     cout << "ans is : " << ans;
// }

// TWO SUM

// BRUTE
// int funct(int a[] , int s)
// {   
//     int n = sizeof(a);
//     // a = 2,6,5,8,11
//     int count = 0 ;
//     for(int i = 0 ; i< n-1  ; i++)
//     {
//         for(int j = i+1 ; j<n ;j++)
//         {
//             if(a[i] + a[j] == s)
//             {
//                 cout << "sum of index " << i << "and" << j ;
//                 count = 1 ;
//             }
//         }
//     }
//     return count ;
// }
// int main()
// {
//     int n1;cout << "enter size of first array :" ;cin >> n1 ;
//     int arr[n1] ; cout << "enter elements of first array : " << endl ;
//     for(int i=0 ; i < n1 ;i++ ) cin >> arr[i] ;
//     cout << endl <<  "enter number : " ;int s ; cin >> s ;
//     int ans = funct(arr , s) ;
//     if(ans == 0)
//     {
//         cout << endl << "not possible!" ;
//     }
// }

// BETTER
// int funct(int a[] , int s)
// {   
//     int n = sizeof(a);
//     // a = 2,6,5,8,11
//     int count = 0 ;
//     map<int , int> mp;
//     int rem= 0;
//     for(int i = 0 ; i < n ; i++)
//     {   rem = s - a[i] ; 
//         if(mp.find(rem) != mp.end())
//         {
//             cout << "i =" << i <<" j = " << mp[rem] ;count++ ;
//         }
//         else
//         {
//             mp[a[i]] = i ;
//         }
//     }
//     return count ;
// // }
// int main()
// {
//     int n1;cout << "enter size of first array :" ;cin >> n1 ;
//     int arr[n1] ; cout << "enter elements of first array : " << endl ;
//     for(int i=0 ; i < n1 ;i++ ) cin >> arr[i] ;
//     cout << endl <<  "enter number : " ;int s ; cin >> s ;
//     int ans = funct(arr , s) ;
//     if(ans == 0)
//     {
//         cout << endl << "not possible!" ;
//     }
// }

// OPTIMAL
// int funct(int a[] , int s)
// {   
//     int n = 5;
//     sort(a , a+ n) ;
//     // a = 2,6,5,8,11
//     int count = 0 ;
//     int i = 0;
//     int j = n-1;
//     while(i<j)
//     {
//             if(a[i] + a[j] > s)
//             {
//                 j--;
//             }
//             else if(a[i] + a[j] < s)
//             {
//                 i++;
//             }
//             else
//             {
//                 cout << "i = " << i <<" j = " << j ;count++ ;break ;
//             }
//     }
//     return count ;
// }
// int main()
// {
//     int n1;cout << "enter size of first array :" ;cin >> n1 ;
//     int arr[n1] ; cout << "enter elements of first array : " << endl ;
//     for(int i=0 ; i < n1 ;i++ ) cin >> arr[i] ;
//     cout << endl <<  "enter number : " ;int s ; cin >> s ;
//     int ans = funct(arr , s) ;
//     if(ans == 0)
//     {
//         cout << endl << "not possible!" ;
//     }
// }

// SORT ARRAY OF 0,1,2

// BRUTE
// TC - n logn     SC - n
// int funct(int a[], int n)
// {
//     sort(a, a + n);
//     cout << "sorted array is : " << endl;
//     for (int i = 0; i < n; i++)
//     {
//         cout << " " << a[i];
//     }
// }

// BETTER 
// TC - N+N
// int funct(int a[], int n)
// {   int c0 = 0 ;
//     int c1 = 0 ;
//     int c2 = 0 ;
//     for(int i = 0 ; i < n ; i++)
//     {
//         if(a[i] == 0 ) c0++;
//         else if(a[i] == 1 ) c1++;
//         else c2++;
//     }
//     for(int i = 0 ;i < c0; i++) a[i] = 0 ;
//     for(int i = c0 ;i < c1 + c0; i++) a[i] = 1 ;
//     for(int i = c1 + c0 ;i < n; i++) a[i] = 2 ;
//     cout << "sorted array is : " << endl;
//     for (int i = 0; i < n; i++)
//     {
//         cout << " " << a[i];
//     }
// }

// OPTIMAL (DUTCH ALGO)
// DUTCH NATIONAL FLAG ALGORITHM
// class Solution {
// public:
//     void sortColors(vector<int>&  nums) {
//         int l = 0 ;
//         int m = 0 ;
//         int h = nums.size() - 1 ;
//         while(m <= h)
//         {
//             if(nums[m] == 0)    {   swap(nums[m] , nums[l]); l++ ; m++ ; }
//             else if(nums[m] == 2) { swap(nums[m] , nums[h]); h-- ;}
//             else   m++ ;
//         }      
//     }
// };

// MAX APPEARING 

// BRUTE
// a digit appearing more than n/2 times
// int funct(int a[], int n)
// {   int count = 0 ;
//     // 2 2 3 3 1 2 2 
//     for(int i = 0 ; i<n-1 ; i++)
//     {   count = 1 ;
//         for(int j = i+1 ; j<n ; j++ )
//         {
//             if(a[i] == a[j]) count++ ;
//         }
//         if(count > (n/2)) return a[i] ;
//     }
// }
// int main()
// {
//     int n;cout << "enter size of first array :";
//     cin >> n;int arr[n];
//     for (int i = 0; i < n; i++) cin >> arr[i];
//     cout << endl ;
//     int ans = funct(arr, n);
//     cout << "ans is : " << ans; 
// }

// BETTER
// int funct(int a[], int n)
// {   
//     // 2 2 3 3 1 2 2 
//     int hash[100] = {0} ;
//     for(int i = 0 ; i< n ;i++)
//     {
//         hash[a[i]] +=1 ;
//     }
//     for(int i = 0 ; i<100 ; i++)
//     {
//         if(hash[i] > (n/2)) return i ;
//     }
// }
// int main()
// {
//     int n;cout << "enter size of first array :";
//     cin >> n;int arr[n];
//     for (int i = 0; i < n; i++) cin >> arr[i];
//     cout << endl ;
//     int ans = funct(arr, n);
//     cout << "ans is : " << ans; 
// }

// OPTIMAL ( MOORES ALGO )
//DSFSD
//DSF 

// MAX SUBARRAY SUM

//BRUTE
// use three lopps i , j , k

// BETTER
// int funct(int a[], int n)
// {   
//     // -2 -3 4 -1 -2 1 5 -3 
//     int sum = 0 ; 
//     int maxi = INT_MIN ;
//     for(int i = 0 ; i < n - 1 ;i++)
//     {   //sum = a[i] ;
//         sum = 0 ;
//         for(int j = i ; j < n-1; j ++ )
//         {
//            sum = sum + a[i];
//            maxi = max(sum , maxi) ;
//         }
//     }
// }
// int main()
// {
//     int n;cout << "enter size of first array :";
//     cin >> n;int arr[n];
//     for (int i = 0; i < n; i++) cin >> arr[i];
//     cout << endl ;
//     int ans = funct(arr, n);
//     cout << "ans is : " << ans; 
// }

// OPTIMAL ( KADANNE'S ALGO )
// int funct(int a[], int n)
// {   
//     // -2 -3 4 -1 -2 1 5 -3 
//     int sum = 0 ; 
//     int maxi = INT_MIN ;
//     for(int i = 0 ; i < n - 1 ;i++)
//     {   
//         sum += a[i] ;
//         if(sum > maxi) maxi = sum  ;
//         if(sum < 0) sum = 0 ;
//     }
//     return maxi ;
// }
// int main()
// {
//     int n;cout << "enter size of first array :";
//     cin >> n;int arr[n];
//     for (int i = 0; i < n; i++) cin >> arr[i];
//     cout << endl ;
//     int ans = funct(arr, n);
//     cout << "ans is : " << ans; 
// }

// DP

// BRUTE
// max profit
// int funct(int arr[], int n)
// {   
//     // 7 1 5 3 6 4 
//     //
//     int x = 0 ; int y = 0 ;
//     int maxi = INT_MIN ;
//     int d = 0 ;
//     for(int i = 0 ; i< n-1 ; i++)
//     {
//         for(int j = i+1 ; j < n ;j++)
//         {   d = arr[j] - arr[i] ;
//             if(arr[i] < arr[j] )
//             {   
//                 if(d > maxi) {  maxi = d  ; x = i ; y = j ; }
//             }
//             else continue ;
//         }
//     }
//     cout << " " << x << " " << y ;
// } 

// OPTIMAL
//
// int funct(int arr[], int n)
// {   
//     // 7 1 5 3 6 4 
//     //
//     int buy = 0 ; int sell = 0 ;
//     int maxi = INT_MIN ;
//     int mini = arr[0] ;
//     int d = 0 ;
//     for(int i = 1 ; i< n ; i++)
//     {
//         d = arr[i] - mini ;
//         if(d > 0 && d>maxi)
//         {
//             maxi = d ; buy =mini ; sell = i ;
//         }
//         mini = min(arr[i], mini) ;
//     }
//     cout << "buy =  " << buy << " " << "sell = " << sell ;
// }

// REARRANGE IN +VE AND -VE

// BRUTE
// int funct(int a[], int n)
// {   
//     // 3 1 -2 -5 2 -4
//     // 3 -2 1 -5 2 -4
//     int  arr[n/2] ; //  3  1  2
//     int  brr[n/2] ; // -2 -5 -4 
//     int x =0 ; int y = 0 ;
//     // TC  - N
//     for(int i = 0 ; i< n ; i++)
//     {
//         if(a[i] >= 0)
//         {
//             arr[x] = a[i] ; x++ ;
//         }
//         else
//         {
//             brr[y] = a[i] ; y++ ;
//         }
//     }
//     // TC  - n
//     x = 0 ; y = 0  ;
//     for(int i  = 0 ; i< n ; i++)
//     {
//         a[2*i] = arr[i] ;
//         a[2*i + 1] = brr[i] ;        
//     }
//     for(int i = 0 ; i< n ; i ++) cout << " " << a[i] ;
// }

// NEXT PERMUTATIONS

// OPTIMAL
// class Solution {
// public:
//     void nextPermutation(vector<int>& nums) {
//         int n = nums.size();
//         int index=-1;
//         for(int i=n-2;i>=0;i--){
//             if(nums[i]<nums[i+1]){
//                 index=i;
//                 break;
//             }
//         }
//         if(index==-1){
//             reverse(nums.begin(),nums.end());return ; 
//         }
//         for(int i=n-1;i>index;i--){
//             if(nums[i]>nums[index]){
//                 swap(nums[i],nums[index]);
//                 break;
//             }
//         }
//         reverse(nums.begin()+index+1,nums.end());
//     }
// };

// LEADERS IN ARRAY

// BRUTE
// int funct(int a[], int n)
// {   
//     // 10 22 12 3 0 6
//     int leader ; 
//     vector<int> vec ;
//     for(int i = 0 ; i< n-1 ; i++)
//     {   leader = true; 
//         for(int j =  i+1 ; j< n  ;j++)
//         {
//             if(a[j]>a[i])
//             {
//                 leader = false ; break ;
//             }          
//         }if(leader == true) vec.push_back(a[i]) ;
//     }
//     vec.push_back(a[n-1]) ;
//     for(auto it : vec)
//     {
//         cout << " " << it ;
//     }
//     // for(int i = 0 ; i< n ; i++) cout << " " ;
// }

// LONGEST CONSECUTIVE

// BRUTE
// tc - n^2

// COUNT SUBARRAY WITH SUM K

// BRUTE
// int k =3 ;
//     int count = 0 ;
//     //  1 2 3 -3 1 1 1 4 2 -3
//     int  sum= 0  ;
//     for(int i = 0 ; i < n - 1; i++)
//     {
//         for(int j = i ; j < n ; j++ )
//         {
//             sum = sum + a[j] ;
//             if(sum == k) count++ ;
//         }
//     }
//     cout << " ans is  : " << count ; 

// BETTER 




