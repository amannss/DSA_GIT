#include<iostream>
#include<bits/stdc++.h>
using namespace std ;

// LEFT ROTATE (ONE PLACE)

// BRUTE
// only to roatate by one 
// so copy in another array

// OPTIMAL
// int main()
// {
//     int n;cout << "enter size of array :" ;cin >> n ;
//     int arr[n] ; cout << "enter elements of aaray : " << endl ; 
//     for(int i=0 ; i < n ;i++ ) cin >> arr[i] ;
//  
//    // 4 6 8 9 0 original
//    // 6 6 8 9 0 
//    // 6 8 8 9 0 
//    // 6 8 9 9 0
//    // 6 8 9 0 0 
//   
// //    for(int i = 0 ; i< n ;i++)
// //    {
// //         if(i==0 ) 
// //         {
// //             temp = arr[i]; 
// //             arr[i] = arr[i+1] ;
// //         }
// //         else if(i<n-1)
// //         {
// //             arr[i] = arr[i+1] ;
// //         }
// //         else arr[i] = temp ;
// //    }
//     int temp = arr[0] ;
//     for(int i = 0 ; i< n-1 ;i++)
//     {
//         arr[i] = arr[i+1] ;
//     }
//     arr[n-1] = temp ;
//    cout << endl << "rotated array is : " ;
//    for(int j = 0 ; j<n ; j++)
//    {
//      cout<< " " << arr[j] ;
//    }
// }

// LEFT ROTATE (D PLACE)

// BRUTE
// complexity is n^2
// int main()
// {
//     int n;cout << "enter size of array :" ;cin >> n ;
//     int arr[n] ; cout << "enter elements of aaray : " << endl ; 
//     for(int i=0 ; i < n ;i++ ) cin >> arr[i] ;
//     int d ;cout <<endl<<"enter the D value : " ;cin >> d ;
//     int temp ;
//     d = d  %  n ;
//     for(int i = 0 ; i<d ; i++)
//     {
//         temp = arr[0] ;
//         for(int j = 0 ; j < n-1 ;j++)
//         {
//             arr[j] = arr[j+1] ;
//         }
//         arr[n-1] = temp ;
//     }
//     cout << "roatated array is : " ;
//     for(int i = 0 ; i < n ; i++)
//     {
//         cout << " " << arr[i] ;
//     }
// }

// BRUTE
// time complexity is  d-0 , n-d - 0 , n - (n-d)
//  == d + n-d +  d ==  n+d
// space complexity is  d cause taking temp extra
// 
//int main()
// {
//     int n;cout << "enter size of array :" ;cin >> n ;
//     int arr[n] ; cout << "enter elements of aaray : " << endl ; 
//     for(int i=0 ; i < n ;i++ ) cin >> arr[i] ;
//     int d ;cout <<endl<<"enter the D value : " ;cin >> d ;
//     int temp[d] ;int x = d ; 
//     // arr = 1 2 3 4 5 
//     // d = 3
//     // temp = 1 2 3
//
// // to make temp array
//
//     for(int i = 0 ; i<d ; i++) // i = 0 1 2
//     {
//         temp[i] = arr[i] ;
//     }
//
// // to shifting elements
//
//     for(int i = 0 ; i < n-d ; i++) // n - d = 5 - 3 = 2
//     {
//         arr[i] = arr[d] ; // 4 5 3 4 5 
//         d++ ; //3 4 5
//     }
// // to merge temp and arr
//     int z = 0 ;
//     for(int i = n - x ; i < n ; i++)
//     {
//         arr[i] = temp[z] ;z ++ ;
//     } 
//     cout << "roatated array is : " ;
//     for(int i = 0 ; i < n ; i++)
//     {
//         cout << " " << arr[i] ;
//     }
// }

// OPTIMAL
// time complexity is n
// space complexity is 0  cause no extra variable
// 
// int main()
// {
//     int n;cout << "enter size of array :" ;cin >> n ;
//     int arr[n] ; cout << "enter elements of aaray : " << endl ; 
//     for(int i=0 ; i < n ;i++ ) cin >> arr[i] ;
//     int d ;cout <<endl<<"enter the D value : " ;cin >> d ;
//     int temp[d] ;int x = d ; 
//     // arr = 1 2 3 4 5 
//     // d = 3
//     // temp = 1 2 3 
//     reverse(arr , arr+d) ;// 3 2 1 4 5
//     reverse(arr+d , arr + n) ;// 3 2 1 5 4 
//     reverse(arr , arr + n ) ; // 4 5 1 2 3 
//     cout << "roatated array is : " ;
//     for(int i = 0 ; i < n ; i++)
//     {
//         cout << " " << arr[i] ;
//     }
// }

// SHIFT ZEROES

// BRUTE
// move all zeroes to end
// int main()
// {
//     int n;cout << "enter size of array :" ;cin >> n ;
//     int arr[n] ; cout << "enter elements of aaray : " << endl ; 
//     for(int i=0 ; i < n ;i++ ) cin >> arr[i] ;
//     int a[n];
//     int count = 0 ;
//     int j = 0 ;
//     int x = 0 ;
    // 1 0 2 3 0 0 4
//     // method 1 
//     // n
//     for(int i= 0 ; i < n ; i++ )
//     {
//         if(arr[i] == 0) count++ ;
//         else
//         {
//             a[j] = arr[i] ;
//             j++;// 4       
//         }
//     }
//     cout <<"j is : " << j << endl ;
//     cout << "count is : " << count << endl;
//     // n
//     for(int i = 1 ; i <= count ;i++ )
//     {
//         a[j] = 0 ; j++ ;
//     }
//     // method 2
//      cout << "final array is : " ;
//     for(int i = 0 ; i < n ; i++)
//     {
//         cout << " " << a[i] ;
//     }
// }

// OPTIMAL
// int main()
// {
//     int n;cout << "enter size of array :" ;cin >> n ;
//     int arr[n] ; cout << "enter elements of aaray : " << endl ; 
//     for(int i=0 ; i < n ;i++ ) cin >> arr[i] ;
    //int j=0;
    // method 1
    // 1 0 2 3 0 0 4   i = 0 , j =-1
    // 1 2 0 3 0 0 4   i = 1 , j = 0
    // 1 2 3 0 0 0 4   i = 2 , j = 1
    // 1 2 3 0 0 0 4   i = 3 , j = 2
    // 1 2 3 0 0 0 4   i = 4 , j = 3
    // 1 2 3 0 0 4 0   i = 5 , j = 4
    // 1 2 3 0 4 0 0   i = 5 , j = 3
    // 1 2 3 4 0 0 0   i = 5 , j = 2
    // 
    // for(int i=0;i<n-1;i++)
    //   {
    //        j=i-1;
    //       if(arr[i]==0)
    //       {
    //         swap(arr[i],arr[i+1]);
    //       }
    //       while(arr[j]==0 && j>0)
    //         {
    //           swap(arr[j],arr[j+1]);
    //           j--;
    //         }
    //     }
    //
    // method 2
    // N , no extra space
//     int j= -1 ;
//     for(int i = 0 ;i < n ;i++) // x
//     {
//         if(arr[i] == 0) {j = i ;break;}
//     }
//     for(int i = j+1 ; i < n ; i++)// n -x
//     {   
//         if(arr[i] != 0 )
//         {
//             swap(arr[i] , arr[j]);
//             j++ ;
//         }
//     }
//     cout << "final array is : " ;
//     for(int i = 0 ; i < n ; i++)
//     {
//         cout << " " << arr[i] ;
//     }
// }

// LINEAR SEARCH

// BRUTE
//complexity is N  
// int main()
// {
//     int n;cout << "enter size of array :" ;cin >> n ;
//     int arr[n] ; cout << "enter elements of aaray : " << endl ; 
//     for(int i=0 ; i < n ;i++ ) cin >> arr[i] ;
//     int data ; cout << "enter value to be searched : " ; cin >> data ;
//     int count = 0 ;
//     for(int i = 0 ; i < n; i++)
//     {
//         if(arr[i] == data) 
//         {
//             cout << "element found at index :" << i ;
//             count = 1 ;
//             break ;
//         }
//     }
//     if(count == 0 ) cout <<"element not found !" ;
// }

// UNION OF SORTED ARRAYS

// BRUTE
// int main()
// {
//     int n1;cout << "enter size of first array :" ;cin >> n1 ;
//     int arr[n1] ; cout << "enter elements of first array : " << endl ; 
//     for(int i=0 ; i < n1 ;i++ ) cin >> arr[i] ; 
//     int n2;cout << "enter size of second array :" ;cin >> n2 ;
//     int brr[n2] ; cout << "enter elements of aaray : " << endl ; 
//     for(int i=0 ; i < n2 ;i++ ) cin >> brr[i] ; 
// // making set
//     set<int> st ;
//     // nlogn
//     for(int i = 0 ;i<n1 ;i++)
//     {
//         st.insert(arr[i]) ;
//     }
//     // nlogn
//     for(int i = 0 ;i<n2 ;i++)
//     {
//         st.insert(brr[i]);
//     }
// // making array named union
//     //n1 + n2 (worst case)
//     // space -> for solve = n1+ n2
//     //          for return ans = n1+ n2
// // printing set 
//     cout<< endl << "set is : " ; 
//     for(auto kt : st)
//     {
//         cout << kt << "\t";
//     }
//     int ans[st.size()] ;
//     int i =0 ;
//     for(auto it : st)
//     {
//         ans[i] = it ;
//         i++ ;
//     }
//     cout << endl << "ans is :" ;
//     for(int j = 0 ;j < i ; j++ )
//     {
//         cout  << ans[j] << "\t" ;
//     }
// }

// OPTIMAL
// tc -> n1 + n2
// space -> n1 + n2 worst case if both arrayss are different or unique elements are present
// vector<int> sortedarray(vector<int> &a ,vector<int> &b )
// {   cout << "function initiated,wait!" << endl ;
//     int i =0 ;int j =0 ;
//     int n1 = a.size(); 
//     int n2 = b.size();
//     vector<int> uniona ;
//     while(i< n1 && j <n2)
//     {
//         if(a[i] <= b[j])
//         {
//             if(uniona.size() == 0 || uniona.back() != a[i])
//             {
//                 uniona.push_back(a[i]) ;
//             } 
//             i++ ;
//         }
//         else // b[j] < a[i]
//         {
//             if(uniona.size() == 0 || uniona.back() != b[j])
//             {
//                 uniona.push_back(b[j]) ;
//             } 
//             j++ ;
//         }
//     }
//     while(i < n1)
//     {
//         if(uniona.size() == 0 || uniona.back() != a[i])
//             {
//                 uniona.push_back(a[i]) ;
//             } 
//             i++ ;
//     }
//     while(j < n2)
//     {
//            if(uniona.size() == 0 || uniona.back() != b[j])
//             {
//                 uniona.push_back(b[j]) ;
//             } 
//             j++ ;
//     }
//     return uniona ;
// }
// int main()
// {   
//     vector<int> a = {1,1,2,3,4,5} ;
//     vector<int> b = {2,3,4,4,5,6,7} ;
//     vector<int> ans = sortedarray(a, b) ;
//     for(auto it : ans)
//     {
//         cout << " " << it ;
//     }
//     cout<<endl  << "done" ;
// }

// INTERSECTION

// BRUTE
// tc= n1*n2
// sc= n2 for vis and 10 for ans
//  int main()
// {  // using a visited array inititalized by 0
//     int n1;cout << "enter size of first array :" ;cin >> n1 ;
//     int arr[n1] ; cout << "enter elements of first array : " << endl ; 
//     for(int i=0 ; i < n1 ;i++ ) cin >> arr[i] ; 
//     int n2;cout << "enter size of second array :" ;cin >> n2 ;
//     int brr[n2] ; cout << "enter elements of aaray : " << endl ; 
//     for(int i=0 ; i < n2 ;i++ ) cin >> brr[i] ; 
//     int vis[n2]= {0};int k = 0;
//     int ans[10] ; 
//      for(int i =0 ; i < n1 ; i++)
//      {
//         for(int j = 0 ; j <n1 ; j++)
//         {
//             if(arr[i] == brr[j] && vis[j]==0)
//             {
//                 ans[k] = arr[i] ;
//                 k++ ;
//                 break ;
//             }
//             if(arr[i] < brr[j]) break ;
//         }
//      }
//     cout << endl << "ans is :" ;
//     for(int j = 0 ;j < 10  ; j++ )
//     {
//         cout  << ans[j] << "\t" ;
//     }
// }

// OPTIMAL
// #include<bits/stdc++.h>
// #include<iostream>
// using namespace std ;
// vector<int>sol(vector<int> &a , vector<int> &b)
// {   vector<int> ans ; 
//     int n1 = a.size() ;
//     int n2 = b.size() ;
//     int i = 0 ;int j = 0 ;
//     while(i<n1 && j<n2)
//     {   
//         if(a[i] < b[j])
//         {
//             i++ ;
//         }
//         else if(a[i] > b[j])
//         {
//             j++ ;
//         }
//         else// a[i] == b[j]
//         {
//            ans.push_back(a[i]) ;
//             i++;
//             j++;
//         }
//     }
//     return ans ;
// }
// // tc= n1*n2
// // sc= n2 for vis and 10 for ans
//  int main()
// {   // move both i and j if matched
//     // two pointer
//     vector<int> a ={1,1,2,3,3,3,4};
//     vector<int> b ={2,3,3,5,7};
//     vector<int> ans = sol(a,b) ;
//     cout << endl << "ans is :" ;
//     for(auto it : ans)
//     {
//         cout << it << " " ;
//     }
// }

// MISSING ELEMENT

// BRUTE
// if n is size then n+1 digit posible
// int main()
// {
//     int n;cout << "enter size of first array :" ;cin >> n ;
//     int arr[n] ; cout << "enter elements of first array : " << endl ; 
//     for(int i=0 ; i < n ;i++ ) cin >> arr[i] ;
//     int hash[n+1] = {0} ;
//     for(int i = 0 ; i< n ; i++)
//     {
//         hash[arr[i]] +=1 ;
//     }
//     for(int i = 1 ; i< n+1 ;i++)
//     {
//         if(hash[i] == 0 ) 
//         {
//             cout << "missing number is :" << i ;
//         }
//     }
//     // second brute
//     // 4 1 2 0 5          n=5 given     range = [0 ,5]
//      for(int i = 1 ; i <= n+1 ; i++)
    // {
    //     for(int j = 0 ; j < n ;j ++)
    //     {
    //         if(arr[j] != i)
    //         {
    //             count ++ ;
    //           continue ;
    //         }
    //         else
    //         {
    //             count = 0 ; // 0 matlab present hai
    //             break ;
    //         }
    //     }if(count != 0 ) cout << endl << i << " => is missing" ;
    // }
// }

// OPTIMAL
// int xor1 = 0 ;
//     int xor2 = 0 ;
//     for(int i = 0 ; i < n ; i++)
//     {
//         xor1 = xor1 ^ arr[i] ; // 1^2^3^4^6
//     }
//     xor2 = xor1 ; // 1^2^3^4^6
//     for(int i = 1 ; i <=n+1 ; i++ )
//     {
//         xor2 = xor2 ^ i ;
//     }
//     // 1^2^3^4^6^1^2^3^4^5^6 = 0^0^0^0^5^6
//     if(xor2 == 0 ) cout << "all present!" ;
//     else cout << "missing number is : " <<  xor2 ;

// MAX CONSECUTIVE ONES

// OPTIMAL
// int main()
// {
//     int n;cout << "enter size of first array :" ;cin >> n ;
//     int arr[n] ; cout << "enter elements of first array : " << endl ; 
//     for(int i=0 ; i < n ;i++ ) cin >> arr[i] ;
//     int count =  0 ;
//      int max = 0 ;
//      for(int i = 0 ; i < n; i++)
//      {
//         if(arr[i] ==  1 ) 
//         {
//             count ++ ;
//             if(max <= count ) max =count ;
//         }
//         else count = 0 ;
//      }
//      cout << "count is :" << max ;
//}




