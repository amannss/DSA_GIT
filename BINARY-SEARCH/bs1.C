

// L - 45   INTRODUCTION TO BS
// LC - 704 binary search
//
//
// normal code 
// reccursive code
//int bs(int a[] ,int n , int l , int mid , int r,int target )
// {
//     if(l > r) return -1 ;
//     mid = (l + r) / 2 ;
//     if(target < a[mid])
//     {
//         r = mid - 1 ; 
//         mid = (l + r) / 2 ;
//         bs( a , n ,  l ,  mid ,  r, target );
//     }
//     else if(target > a[mid])
//     {
//         l = mid + 1 ;
//         mid = (l + r) / 2 ;
//         bs( a , n ,  l ,  mid ,  r, target );
//     }
//     else return mid ;
// }

// L - 46   LOWER AND UPPER BOUND
// 
// lower boound  
// GFG 
        // int ans = -1 ; 
        // int  n = arr.size() ;
        // int  l = 0 ;
        // int  h = n-1 ;
        // while(l <= h)
        // {
        //     int mid = (l+h) / 2 ;
        //     if(arr[mid] >= k)
        //     {
        //         ans = mid ;
        //         h = mid - 1 ;
        //     }
        //     else l = mid + 1  ;
        // }
        // return ans ;
//
// upper bound 
// GFG
        // int ans = -1 ; 
        // int  n = arr.size() ;
        // int  l = 0 ;
        // int  h = n-1 ;
        // while(l <= h)
        // {
        //     int mid = (l+h) / 2 ;
        //     if(arr[mid] > k)
        //     {
        //         ans = mid ;
        //         h = mid - 1 ;
        //     }
        //     else l = mid + 1  ;
        // }
        // return ans ;
// LC - 35
// SEARCH INSERT POSITION
        // class Solution {
        // public:
        //     int searchInsert(vector<int>& arr, int k) {    
        //         int  n = arr.size() ;
        //         int ans =n ; 
        //         int  l = 0 ;
        //         int  h = n-1 ;
        //         while(l <= h)
        //         {
        //             int mid = (l+h) / 2 ;
        //             if(arr[mid] >= k)
        //             {
        //                 ans = mid ; 
        //                 h = mid - 1 ; 
        //             }
        //             else   l = mid + 1 ;
        //         }
        //         return ans ;
        //     }
        // };
//
// FLOOR AND CEIL

// L - 47   FIRST AND LAST OCCURENCE IN ARRAY
// LC - 34  
// BRUTE
        // void  funct(int a[], int n )
        // {    // 2 4 6 8 8 8 11 13
        //     int k = 8 ;
        //     int first = -1 ;
        //     int last = -1 ;
        //     for(int i =0 ; i < n ;i++)
        //     {
        //         if(a[i] == k)
        //         {
        //             if(first == -1) 
        //             {   first = i ;
        //                 last = i ;
        //             }
        //             else last = i ;
        //         }
        //     }
        //     cout <<"first = " << first << endl ;
        //     cout <<"last = " << last << endl ;
        // }
// BETTER
        // class Solution {
        // public:
        //      int lowerbound(vector<int>& arr , int k)
        //     {
        //             int  n = arr.size() ;
        //             int ans = n; 
        //             int  l = 0 ;
        //             int  h = n-1 ;
        //             while(l <= h)
        //             {
        //                 int mid = (l+h) / 2 ;
        //                 if(arr[mid] >= k)
        //                 {
        //                     ans = mid ;
        //                     h = mid - 1 ;
        //                 }
        //                 else l = mid + 1  ;
        //             }
        //             return ans ;
        //     }
        //     int upperbound(vector<int>& arr , int k)
        //     {
        //         int  n = arr.size() ;
        //         int ans = n ;
        //         int  l = 0 ;
        //         int  h = n-1 ;
        //         while(l <= h)
        //         {
        //             int mid = (l+h) / 2 ;
        //             if(arr[mid] > k)
        //             {
        //                 ans = mid ;
        //                 h = mid - 1 ;
        //             }
        //             else l = mid + 1  ;
        //         }
        //         return ans ;
        //     }
        //     vector<int>  searchRange(vector<int>& nums, int target) {
        //         int n =nums.size() ;
        //         vector<int> ans{-1 , -1 };
        //         int lb = lowerbound(nums , target) ;
        //         if( (lb == n) ||  nums[lb] != target ) return {-1 , -1} ;
        //         return {lb , upperbound(nums ,target)-1} ;
        //     }
        // };
// OPTIMAL
// using binary search functions to find first aand last occurence

//          NUMBER OF OCCURENCE IN ARRAY
// GFG
// BRUTE
        // traverse using for loop and compare then couunt++ ;
// OPTIMAL
        // return ub-lb ;

// L - 48   SEARCH IN ROTATED SORTED ARRAY I
// LC - 33
// BRTUE
        // do linear search with TC -  n
// OPTIMAL
        //         int search(vector<int>& nums, int target) {
        //         int n = nums.size() ;
        //         int l = 0 ; int h = n- 1;
        //         int mid = -1 ;
        //         while(l <= h)
        //         {   mid = (l+h) / 2 ;
        //             if(nums[mid] == target) return mid ;
        //         // left sorted
        //             if(nums[l] <= nums[mid])
        //             {   // is target lying or not
        //                 if(nums[l] <= target && target <= nums[mid]) h =mid -1 ;
        //                 else l = mid +1 ;
        //             }
        //         // right sorted
        //             else
        //             {
        //                 if(nums[mid] <= target && target <= nums[h]) l = mid + 1 ;
        //                 else h =mid -1 ;
        //             }
        //         }
        //         return -1 ;
        //     }

// L - 49   SEARCH IN ROTATED SORTED ARRAY II
// LC - 81
// array contains duplicate numbers 
// OPTIMAL
        // int n = nums.size() ;
        // int l = 0 ; int h = n- 1;
        // int mid = -1 ;
        // while(l <= h)
        // {   mid = (l+h) / 2 ;
        //     if(nums[mid] == target) return true ;
        //     // trimming
        //     if(nums[l]==nums[mid] && nums[mid]== nums[h])
        //     {
        //         l = l+1;
        //         h=h-1;
        //         continue;
        //     }
        // // left sorted
        //     if(nums[l] <= nums[mid])
        //     {   // is target lying or not
        //         if(nums[l] <= target && target <= nums[mid]) h =mid -1 ;
        //         else l = mid + 1 ;
        //     }
        // // right sorted
        //     else
        //     {
        //         if(nums[mid] <= target && target <= nums[h]) l = mid + 1 ;
        //         else h =mid -1 ;
        //     }
        // }
        // return false ;

// L - 50   FIND MINIMUM IN ROTATED SORTED ARRAY
// LC - 153
// BRUTE
        // linear traversing TC - n
// OPTIMAL
        // 
        // int findMin(vector<int>& nums) {
        //         int n = nums.size() ;
        //         int l = 0 ; int h = n -1; 
        //         int mid ; int mins = INT_MAX ;
        //         while(l<=h)
        //         {
        //             mid = (l+h) / 2 ;
        //             if(nums[l] <= nums[h])
        //             {
        //                 mins = min(nums[l] , mins) ;
        //                 break ;
        //             }
        //             // left sorted
        //             if(nums[l] <= nums[mid])
        //             {
        //                 mins= min(nums[l] , mins ) ;
        //                 l =mid +1 ;
        //             }
        //             //right sorted
        //             else
        //             {
        //                 h = mid -1 ;
        //                 mins =min(nums[mid]  , mins ) ;
        //             }
        //         }
        //         return mins ;
        //     }

// L - 51   HOW MANY TIME ARRAY IS ROTATED
// GFG
// OPTIMAL
        //          int n = nums.size() ;
        //         int l = 0 ; int h = n - 1; 
        //         int mid ; int mins = INT_MAX ;
        //         int index = -1 ;
        //         while(l<=h)
        //         {
        //             mid = (l+h) / 2 ;
        //             if(nums[l] <= nums[h])
        //             {
        //                 if(nums[l] < mins )
        //                 {
        //                     mins = nums[l];
        //                     index =l ;
        //                 }
        //                 break ;
        //             }
        //             // left sorted
        //             if(nums[l] <= nums[mid])
        //             {
        //                 if(nums[l] < mins )
        //                 {
        //                     mins = nums[l];
        //                     index =l ;
        //                 }
        //                 l =mid +1 ;
        //             }
        //             //right sorted
        //             else
        //             {       
        //                 if(nums[mid] < mins )
        //                 {
        //                     mins = nums[mid];
        //                     index =mid ;
        //                 }
        //                 h = mid -1 ;
        //             }
        //         }return index ; 

// L - 52   SINGLE ELEMENT IN SORTED ARRAY
// LC - 540
// all elements are repeated twice but one element only once
    //         int singleNonDuplicate(vector<int>& arr) {
        //         int n = arr.size() ;
        //         int l = 1 ; int h = n -2; 
        //         int mid ; 
        //         int ans = INT_MAX ;
        //         if(n==1) return arr[0];
        //         if(arr[0] != arr[1]) return arr[0];
        //         if(arr[n-1] != arr[n-2]) return arr[n-1] ;
        //         while(l<=h)
        //         {   
        //             mid = (l+h) / 2 ;
        //             if( (arr[mid] != arr[mid+1]) && arr[mid] != arr[mid-1] ) 
        //                 return arr[mid];
        //             // we are on left
        //             if( ( (mid % 2 == 0) && arr[mid]== arr[mid+1]) || 
        //                 ( (mid % 2 == 1) && arr[mid]== arr[mid-1]) )
        //                 l = mid +1 ;
        //             else h = mid -1 ;
        //         }
        //         return -1;
        //     }

// L - 53   FIND PEAK ELEMENT
// LC - 162
// OPTIMAL
        



