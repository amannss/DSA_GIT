#include<iostream>
using namespace std ;
#include<bits/stdc++.h>
// HASHING
// -> prestoring or fetching


// arr[1e7] possible if global
// initially every thing null if global declared
// int main()
// {   int n ;cout << "enter size of array :" ;
//     cin >> n ;
//     int arr[n] ;
//     cout << "enter elements of array : \n" ;
//     for(int i = 0 ; i<n ;i++)
//     {
//         cin >>arr[i]; 
//     }
//     int hash[13] = {0};
//     // max element is 12 given
//     for(int i = 0 ; i<n ; i++ )
//     {
//         hash[arr[i]] += 1 ;
//     }
    
//     int q ;
//     cout << "enter queries :" ;
//     cin >> q ;

//     while(q--)
//     {   cout << "enter the number : " ;
//         int number ;
//         cin >> number ;

//         // fetch 
      
//         cout << hash[number] << endl ;

//     }
//     return 0 ;
// }

int main()
{   int n ;cout << "enter size of string :" ;
    cin >> n ;
    char arr[n] ;
    cout << "enter elements of strings : \n" ;
    for(int i = 0 ; i<n ;i++)
    {
        cin >>arr[i]; 
    }
    int hash[26] = {0};
    // for small letters

    for(int i = 0 ; i<n ; i++ )
    {
        hash[arr[i] - 'a' ] += 1 ;
    }
    
    int q ;
    cout << "enter queries :" ;
    cin >> q ;

    while(q--)
    {   cout << "enter the char : " ;
        char c ;
        cin >> c ;

        // fetch 
      
        cout << hash[c - 'a'] << endl ;

    }
    return 0 ;
}

