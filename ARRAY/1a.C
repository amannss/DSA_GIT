
#include<bits/stdc++.h>
#include<iostream>
using namespace std ;

//  LARGEST ELEMENT

//  BRUTE  
//  complexity nlogn using sort

//  OPTIMAL
//  complexity is n
//int main()
// { // also can be using sort
//     int n;cout << "enter size of array :" ;cin >> n ;
//     int arr[n] ; cout << "enter elements of aaray : " << endl ; 
//     for(int i=0 ; i < n ;i++ ) cin >> arr[i] ;
//     int max= arr[0] ;
//     for(int j =0 ; j < n ;j ++)
//     {
//         if(arr[j] > max) max = arr[j] ;
//     } 
//     cout << "largest element is :" << max ;
//     return 0;
// }
// 

// SECOND LARGEST

// BRUTE
// complexity is nlog n + n 
// int main()
// {
//     int n;cout << "enter size of array :" ;cin >> n ;
//     int arr[n] ; cout << "enter elements of aaray : " << endl ; 
//     for(int i=0 ; i < n ;i++ ) cin >> arr[i] ;
//     int x = sizeof(arr)/ sizeof(arr[0]) ;
//     sort(arr , arr + n) ;
//     // array is sorted
//     cout << "sorted array is : " << endl ;
//     for(int i : arr)
//     {
//         cout << " " << i ;
//     }
//     int smax = arr[0] ;
//     for(int i = n-1  ; i >=0 ; i--)
//     {
//         if(arr[i-1] < arr[i]  ) { smax = arr[i-1] ;break ;} 
//     }
//     cout <<endl << "largest is : " << arr[n-1] ;
//     cout <<endl << "second largest is : " << smax ;
// return 0 ;
// }

// BETTER
// complexity is n
// int main()
// {
//     int n;cout << "enter size of array :" ;cin >> n ;
//     int arr[n] ; cout << "enter elements of aaray : " << endl ; 
//     for(int i=0 ; i < n ;i++ ) cin >> arr[i] ;
//     int max= arr[0] ;
//     int smax = INT_MIN ;
//     for(int j =0 ;j <n ; j++)
//     {
//         if(arr[j] > max ) max =arr[j] ;    
//     }
//     for(int j = 0 ; j < n ;j++)
//     {
//         if(arr[j] > smax && arr[j]!= max) smax = arr[j] ;
//     }
//     cout << "largest : " <<  max << endl;
//     cout << "second largest :" << smax ;
// return 0 ;
// }

// OPTIMAL 
// int secondlargest(int arr[] ,int n )
// {   int max =INT_MIN  ;
//     int smax = INT_MIN ;
//     for(int i =0 ; i< n ; i++)
//     {
//         if(arr[i] > max) 
//         {   
//             smax = max ;
//             max = arr[i] ;
//         }
//         else if(arr[i] > smax && arr[i]!= max) 
//         {
//             smax = arr[i] ;
//         }
//         else continue ;
//     }
//     return smax ;
// }
// int main()
// {
//     int n;cout << "enter size of array :" ;cin >> n ;
//     int arr[n] ; cout << "enter elements of aaray : " << endl ; 
//     for(int i=0 ; i < n ;i++ ) cin >> arr[i] ;
//     int slargest = secondlargest(arr , n) ;
//     cout << "second largest is : " << slargest ;
// }


// SORTED OR NOT

// NORMAL
// int sorted(int arr[] , int n )
// {
//     for(int i = 0 ; i< n-1 ;i++)
//     {
//         if(arr[i] <= arr[i+1]) continue ;
//         else return -1 ; 
//     }
//     return 0;
// }
// int main()
// {
//     int n;cout << "enter size of array :" ;cin >> n ;
//     int arr[n] ; cout << "enter elements of aaray : " << endl ; 
//     for(int i=0 ; i < n ;i++ ) cin >> arr[i] ;
//     int ans = sorted(arr , n) ;
//     if(ans == -1) cout << "array not sorted" ;
//     else cout << "array sorted" ; 
// }

// REMOVE THE DUPLICATE NUMBER

// BRUTE
// using sets cause unique
// nlogn + n
//
//                                    mine function
//
// int funct(int arr[] , int n)
// {   set<int> st ;
//     // making set
//     for(int i = 0 ;i < n ; i++)
//     {
//         st.insert(arr[i]) ;
//     }
//     auto it = st.begin() ;
//     int count = 0 ;
//     for(int i = 0 ;i < n ; i++)
//     {   if( (it) != st.end() )
//         {
//             arr[i] = *(it) ;
//             it++ ;
//             count ++ ;
//         }
//         else 
//         {
//             arr[i] = 0 ;
//         }
//     }
//     cout <<"number of non duplicate number is : " << count <<endl ;
//     cout <<"new array is : " ;
//     for(int i = 0 ; i< n ;i++) cout << " " << arr[i] ;
// }
//
//                                 striver function
//
// int funct(int arr[] , int n)
// {   set<int> st ;
//     // forming set
//     for(int i = 0 ;i < n ; i++)
//     { // 1 1 2 2 2 3 3 
//         st.insert(arr[i]) ;
//     }
//     // printing set
//     cout <<"set is : ";
//     for(auto it : st)
//     {
//         cout <<" " << it ;
//     }
//     cout << endl ;
//     int index = 0 ;
//     int count = 0 ;
//     for(auto it : st) 
//     {
//         arr[index] = it ;
//         count ++ ; 
//         index ++ ; 
//     }
//     for(int i = index ; i< n ;i++)
//     {
//         arr[i] = 0 ;
//     }
//     cout <<"number of non duplicate number is : " << count <<endl ;
//     cout <<"new array is : " ;
//     for(int i = 0 ; i< n ;i++) cout << " " << arr[i] ;
// }
//
// int main()
// {
//     int n;cout << "enter size of array :" ;cin >> n ;
//     int arr[n] ; cout << "enter elements of aaray : " << endl ; 
//     for(int i=0 ; i < n ;i++ ) cin >> arr[i] ;
//     funct(arr , n) ;
// }

//  OPTIMAL
// using two pointers
// int funct(int arr[] , int n)
// {
//     int i =0 ;
//     int count = 0 ;
//     for(int j = 1 ; j < n ; j++)
//     {
//         if(arr[i] != arr[j])
//         {   i++ ;
//             arr[i] = arr[j] ;
//             count ++ ;
//         }
//     }
//     for(int x = i+1 ; x < n ;x ++)
//     {
//         arr[x] = 0 ;
//     }
//     cout <<"number of non duplicate number is : " << ++count <<endl ;
//     cout <<"new array is : " ;
//     for(int i = 0 ; i< n ;i++) cout << " " << arr[i] ;
// }
// int main()
// {
//     int n;cout << "enter size of array :" ;cin >> n ;
//     int arr[n] ; cout << "enter elements of aaray : " << endl ; 
//     for(int i=0 ; i < n ;i++ ) cin >> arr[i] ;
//     funct(arr , n) ;
// }
