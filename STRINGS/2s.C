#include<iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std ;
// str.find(sub_string)
// str.erase(start , end)

//                                       APNA COLLEGE

// L - 2 VALID PALLINDROME
// LC - 125  
// bool isAlphaNum(char ch)
// {
//     if((ch>= '0' && ch <= '9') || (tolower(ch)>= ' a' && tolower(ch) <= 'z'))
//     {
//         return false ;
//     }
//     return true ;
// }
// bool isPalindrome(string s) {
//     int start = 0 ;
//     int end = s.length() - 1 ;
//     while(start < end)
//     {
//         if(!isAlphaNum(s[start]))
//         {
//             start++ ; continue ;
//         }
//         if(!isAlphaNum(s[end]))
//         {
//             end-- ; continue ;
//         }
//         if( tolower(s[start]) != tolower(s[end])) return false;
//         start++ ; end-- ;
//     }
//     return true ;
// }

// L - 2 REMOVE ALL OCCURENCES OF SUBSTRING
// LC - 1910
// string removeOccurrences(string s, string part) {
//     while(s.find(part) < s.length())
//     {
//         s.erase(s.find(part) , part.length() ) ;
//     }
//     return s;
// }

// L - 3 PERMUTATION IN STRINGS
// LC - 567

// L - 4 REVERSE WORDS IN STRING
// LC - 151
        // reverse(s.begin() , s.end()) ;string ans ="";
        // for(int i = 0 ; i < s.length() ; i++)
        // {   string word="" ;
        //     while(i < s.length() && s[i] != ' ')
        //     {
        //             word = word+s[i] ;
        //             i++; 
        //     }
        //     reverse(word.begin() , word.end()) ;  
        //     if(word.length()>0 ) ans += " " + word ;
        // }
        // return ans.substr(1) ;

//                                       A2Z  SHEET


// 1 - REMOVE OUTERMOST PARANTHESIS
// LC - 1021

// 2 - PALLINDROME CHECK
// LC - 151
//  reverse(s.begin() , s.end()) ;string ans ="";
//         for(int i = 0 ; i < s.length() ; i++)
//         {   string word="" ;
//             while(i < s.length() && s[i] != ' ')
//             {
//                     word = word+s[i] ;
//                     i++; 
//             }
//             reverse(word.begin() , word.end()) ;
//             if(word.length()>0 ) ans += " " + word ;
//         }
//         return ans.substr(1) ;

// 3 - LARGEST ODD NUMBER IN STRING
// LC - 1903
//        for(int i = num.length()-1 ; i >= 0 ; i--)
//        {
//            if( (num[i] - '0') %2 !=0 ) return num.substr(0,i+1) ;
//        }
//        return "" ;

// 4 - LONGEST COMMON PREFIX
// LC - 14
// string longestCommonPrefix(vector<string>& strs) {
//         sort(strs.begin(),strs.end());
//         string result="";
//         int vectsize = strs.size() ;
//         // int  n = strs[vectsize - 1].length();
//          for(int i=0;i<strs[0].length();i++){
//              char first =(strs[0][i]);
//              char  last = (strs[vectsize-1][i]);
//             if(first!=last){
//                 break;
//             }
//             result+=first;
//         }
//          return result;

// 5 - ISOMORPHIC STRING
// LC - 205
// bool isIsomorphic(string s, string t)
// {
//         unordered_map<char,char> mp1 ;
//         unordered_map<char,char> mp2 ;
//         for(int i = 0 ; i < s.length() ; i++)
//         {
//             char ch1 = s[i];
//             char ch2 = t[i];
//             if((mp1.find(ch1)!= mp1.end() && mp1[ch1] != ch2) || 
//                 (mp2.find(ch2)!= mp2.end() && mp2[ch2] != ch1))
//                 return false ;
//                 mp1[ch1] = ch2;
//                 mp2[ch2] = ch1;
//         }
//         return true ;
// }

// 6 - ROTATION OF ANOTHER STRING
// LC - 796
// brute
        // bool rotateString(string s, string goal)
        // {
        // int m = s.length() ;
        // int n = goal.length() ;
        // if(m!= n) return false ;
        // for(int  i = 1 ; i<= m ; i++)
        // {
        //     rotate(s.begin() , s.begin() +1 ,s.end()) ;
        //     if(s == goal ) return true ;
        // }
        // return false ;
        // }
// optimal
        // if((s+s).find(goal)!= string::npos) return true ;
        // else return false ;

// 7 - ANAGRAM
// LC - 242
//       bool isAnagram(string s, string t) 
//      {
//         sort(s.begin(),s.end()) ;
//         sort(t.begin(),t.end()) ;
//         if(s==t) return true ;
//         else return false ;
//     }

// 8 - ATOI
// LC -8
// class Solution {
//         public:
//             int myAtoi(string s) {
//                 long ans = 0; int sign = +1 ; int i = 0 ;
//                 while(i<s.length() && s[i]==' ') i++;
//                 s= s.substr(i) ;
//                 if(s[0] == '-') sign = -1;
//                 int max = INT_MAX ; int min = INT_MIN ;
//                 i = (s[0] =='-' || s[0] =='+') ? 1 : 0 ;
//                 while(i<s.length())
//                 {
//                     if(s[i]== ' ' || !isdigit(s[i])) break ;
//                     ans = ans*10 + (s[i] - '0');
//                     if(sign== -1 && -1*ans < min) return min ;
//                     if(sign== 1 &&  ans > max) return max ;
//                     i++ ;
//                 }
//                 return (int)(sign*ans) ;
//             }
//         };
//                                         MIK 
// 4 12 13 16 23 29 31 33 34 35 36

// 9 - COUNT BEAUTIFUL SUBSTRING
// LC- 2949
// class Solution {
//         public:
//             bool isvowel(char ch)
//             {
//                 return ch=='a' || ch=='e' ||   ch=='i' ||  ch=='o' || ch=='u' ;
//             }
//             #define ll long long 
//             long long beautifulSubstrings(string s, int k)
//             {
//                 ll vowel=0;
//                 ll consonants=0;
//                 ll result=0;
//                 unordered_map<ll ,unordered_map<ll,ll>>mp;
//                 mp[0][0]=1;
//                 for(char &ch:s)
//                 {
//                     if(isvowel(ch)) vowel++;
//                     else consonants++;        
//                    ll psum=(vowel - consonants);
//                    for(auto &[pastvowelcount,count] :mp[psum])
//                    {
//                       ll count_vowel=vowel;
//                       ll past_vowel=pastvowelcount;
//                       ll curr_sub_vowel_count=count_vowel - past_vowel;
//                       if((vowel%k - pastvowelcount) * (vowel%k - pastvowelcount) %  k ==0)
//                       {
//                         result+=count;
//                       }
//                    }
//                    mp[psum][vowel%k]++;
//                 }
//                 return result;
//             }
//         };

// 10 - SUM OF BEAUTY OF ALL SUBSTRING
// LC -1781
// int beauty(vector<int>&freq)
// {
//     int maxs = -1 ;int mins = 1e9 ;
//     for(int i = 0 ; i < 26 ;i++)
//     {
//         maxs = max(maxs , freq[i]) ;
//         if(freq[i] >= 1) mins = min(mins , freq[i]) ;
//     }
//     return maxs-mins ;
// }
// int beautySum(string s)
// {
//     int sum = 0 ;
//     for(int i = 0 ; i < s.length() ; i++)
//     {   
//         vector<int> freq(26,0) ;
//         for(int j = i ; j < s.length() ; j++)
//         {   
//             freq[s[j] - 'a']++;
//             sum = sum + beauty(freq) ;
//         }
//     }
//     return sum ;
// }

// 11 - SHORTEST PALLINDRIOME
// LC - 214


//                                      MIK


// L - 1 STRING COMPRESSION
// LC - 443
// int compress(vector<char>& arr) {
//         // char  curr_char = arr[0] ;
//         int cnt = 0 ; 
//         int index = 0 ;
//         int i =0 ;
//         while(i < arr.size())
//         {   cnt = 0 ;
//             char curr_char = arr[i] ;
//         // count duplicates
//             while(i < arr.size() && arr[i] == curr_char)
//             {
//                 i++ ; cnt++ ;
//             }
//         // asign current char
//             arr[index] = curr_char ;
//             index++;
//             if(cnt > 1)
//             {
//                 string str = to_string(cnt) ;
//                 for(char &ch : str)
//                 {
//                     arr[index] = ch ;
//                     index++ ;
//                 }
//             }
//         }
//         return index ;
//     }

// L - 2 IS PANAGRAM OR NOT
// LC - 1832
// bool checkIfPangram(string sentence) {
//         // vector<int> arr(26 , 0) ;
//         int arr[26] = {0} ;
//         int index ;
//         for(auto &ch : sentence)
//         {   
//             index = ch - 'a' ;
//             arr[index]++ ;
//         }
//         for(auto &i : arr)
//         {
//             if(i == 0) return false ;
//         }
//         return true ;
    
// L - 3 COUNT AND SAY
// LC - 38
// string countAndSay(int n) {
//         if(n==1) return "1"; 
//         // recursive
//         string say =countAndSay(n-1);
//         //processing
//         string result="" ;
//         for(int i = 0 ; i<say.length();i++)
//         {
//             char ch =say[i];int cnt= 1;
//             while(i < say.length()-1 && say[i]==say[i+1])
//             {
//                 cnt++ ;i++; 
//             }
//             result+= to_string(cnt) + string(1,ch) ;
//         }
//         return result ;
//     }

// L - 4 INTEGER TO ROMAN 
// LC - 12

// L - 5 STRING ARRAYS ARE EQUIVALENT 
// LC - 1662
// bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2)
// {
//         string result1 = "";
//         string result2 = "";
//         for(int i = 0 ; i < word1.size() ; i++) result1 += word1[i] ;
//         for(int i = 0 ; i < word2.size() ; i++) result2 += word2[i] ;
//         if(result1 == result2) return true ;
//         else return false ;
// }

// L - 6 ORDERLY QUEUE
// LC - 899
//     string orderlyQueue(string s, int k)
//     {
//         if(k > 1) 
//         {
//             sort(s.begin() , s.end()) ;
//             return s ;
//         }
//         string result = s ;
//         int n = s.length() ;
//         for(int i = 1 ;i <= n-1; i++ )
//         {
//                 string temp = s.substr(i) + s.substr(0 , i) ;
//                 result = min(temp , result) ;
//         }
//         return result ;
//     }

// L - 7 MAKE THE STRING GREAT
// // LC - 1544
//         string makeGood(string s)
//         {
//         string result = "";
//         for(char &ch : s)
//         {
//             if( (result.size() > 0 ) && (result.back() + 32 == ch || result.back() - 32 == ch) )
//             {
//                 result.pop_back() ;
//             }
//             else result.push_back(ch) ;
//         }
//         return result ;
//        }

// L - 8 IF STRINGS HALF ARE ALIVE
// LC -1704
// int n = s.length();
// int i=0;
// int j=n/2;
// unordered_set<char>st;
// st.insert('a');
// st.insert('e');
// st.insert('i');
// st.insert('o');
// st.insert('u');
// st.insert('A');
// st.insert('E');
// st.insert('I');
// st.insert('O');
// st.insert('U');
// int lcount=0;
// int rcount=0;
// while(i<n/2&&j<n){
//     if(st.find(s[i])!=st.end())lcount++;
//      if(st.find(s[j])!=st.end())rcount++;
//      i++;
//      j++;
//      }
//      if(lcount==rcount) return true;
//      return false;

// L - 9 IF TWO STRINGS ARE CLOSE
// LC - 1657
//         bool closeStrings(string word1, string word2) {
//         int m = word1.length(); int n = word2.length() ;
//         if(m!=n) return false ;
//         vector<int> freq1(26); vector<int> freq2(26);
//         for(int i = 0 ; i < m ; i++)
//         {
//             char ch1 = word1[i];
//             char ch2 = word2[i];
//             int idx1 = ch1 -'a' ;
//             int idx2 = ch2 -'a' ;
//             freq1[idx1]++;
//             freq2[idx2]++;
//         }
//         // point 1 - jo char word1 me hai ,2 me bhi hona chaiye
//         for(int i = 0 ; i < 26 ; i++)
//         {
//                 if(freq1[i] != 0  && freq2[i]!= 0) continue;
//                 if(freq1[i] == 0  && freq2[i]== 0) continue;
//                 return false ;
//         }
//         // point 2 - check frequency 231 == 231
//         sort(freq1.begin(), freq1.end());
//         sort(freq2.begin(), freq2.end());
//         if(freq1 != freq2) return false ;
//         return true ;
//         }

// L -10 DETECT CAPITAL 
// LC - 520
//    bool detectCapitalUse(string word)
//    {
//         int cnt = 0 ;int n = word.length() ;
//         for(char ch : word)
//         {
//             if(isupper(ch)) cnt++ ;
//         }
//         if(cnt == n) return true;
//         if(cnt == 0) return true;
//         if(cnt == 1 && isupper(word[0])) return true;
//         else return false ;
//     }

// L -11 DELETE COLUMNS TO MAKE SORTED
// LC - 944
        // int minDeletionSize(vector<string>& strs) {
        // int cnt = 0 ;
        // int k = strs[1].length() ;
        // int n = strs.size() ;
        // // for letters
        // for(int i = 0 ; i < k ; i++ )
        // {   
        //     for(int j = 1; j < n ; j++)
        //     {
        //         if(strs[j][i] < strs[j-1][i])
        //         {
        //             cnt++; break ;
        //         }
        //     }
        // }
        // return cnt ;
        // }

// L -12 RESTORE IP ADDRESS
// LC - 93

// L -13 CONCANATED WORDS
// LC - 472

// L -14 FIND INDEX OF FIRST OCCURENCE
// LC -28
//         int strStr(string haystack, string needle)
//         {
//         int m = haystack.length() ;
//         int n = needle.length() ;
//         if(m<n) return -1 ;
//         for(int i = 0 ; i <= haystack.length() - n ; i++)
//         {
//             if(haystack.substr(i,n) == needle) return i ;
//         }
//         return -1 ;
//        }

// L -15 BUDDY STRING
// LC-859
// int checkfreq(string s){
//         int freq[26]={0};
//         for(char &ch :s){
//             freq[ch-'a']++;
//             if(freq[ch-'a']>1) return true;
//         }
//         return false;
//     }   
//     bool buddyStrings(string s, string goal) {
//         int n = s.length();
//         int m = goal.length();
//         int count =0;
//         if(m!=n) return false;     
//         if(s==goal){
//             return checkfreq(s);
//         }
//           vector<int>index;
//            for(int i=0;i<n;i++){
//             if(s[i]!=goal[i]){
//                 index.push_back(i);
//             }
//          }
//          if(index.size()!=2) return false;
//          swap(s[index[0]],s[index[1]]);
//          return s==goal;

// L -16 SUBSTRING WITH LARGEST VARIANCE
// LC - 2272

// L -17 REPEATED WITH LARGEST VARIANCE
// LC - 459
//      bool repeatedSubstringPattern(string s)
//      {
//         int l = s.length() ;
//         string n = s ;
//         for(int i = 1; i<=l/2 ;i++)
//         {
//             rotate(n.begin(),n.begin()+1,n.end()) ;
//             if(n == s) return true ;
//         }
//         return false ;
//     }

// L -18 TEXT JUSTIFICATION
// LC - class Solution {
// public:
// int MAX_WIDTH ;
// string findline(int i ,int j ,int each_gaddha_space,int extra_space_to_gaddha,vector<string>& words)
// {
// }
// vector<string> fullJustify(vector<string>& words, int maxWidth) {
//     int n = words.size() ;
//     int i = 0 ; int j = i + 1 ;
//     int letters_count = words[i].length() ;
//     int gaddhe = 0 ; MAX_WIDTH = maxWidth ;
//     vector<string> result = "";
//     while(i < n)
//     {
//         while(j < n && words[j] + 1 + letters_count + gaddhe <= maxWidth )
//         {
//             letters_count += words[j].length() ;
//             j++ ;
//             gaddhe++ ;
//         }
//         int remaining_gaddhe = maxWidth - gaddhe ;
//         int each_gaddha_space = gaddhe==0 :0 ? maxWidth / gaddhe ;
//         int extra_space_to_gaddha = gaddhe==0 :0 ? maxWidth % gaddhe ;
//         if(j==n)
//         {
//             each_gaddha_space = 1 ;extra_space_to_gaddha = 0;
//         }
//         result.push_back(findline(i , j ,each_gaddha_space,extra_space_to_gaddha,words)) ;
//         i = j ;
//     } 
//     return result ;
// }
// };

// L -19 IN SUBSEQUENCE
// LC - 392
// bool isSubsequence(string s, string t) {
//         int i = 0 ; int j = 0 ; int check = 1 ;
//         int n = s.length() ; int m = t.length() ;
//         while(i < n && j < m)
//         {
//             if(s[i]==t[j])
//             {
//                 i++ ; j++ ;
//             }
//             else 
//             j++ ;
//         }
//         if(i!= n) return false;
//         else return true;
//     }

// L -20 REMOVE DUPLICATE LETTERS
// LC - 316
// int n = s.length();
//         vector<bool>taken(26,false);
//         vector<int>lastindex(26);
//         for(int i=0;i<n;i++){
//             lastindex[s[i]-'a']=i;
//         }
//          string result=""
//         for(int i=0;i<n;i++){
//             int indx=s[i]-'a';
//             if(taken[indx]==true) continue;
//             while(result.length()>0 && result.back()>s[i] && lastindex[result.back()-'a']>i){
//                 taken[result.back()-'a']=false;
//                 result.pop_back();
//             }
//             result.push_back(s[i]);
//             taken[s[i]-'a']=true;
//         }
//        return result;

// L -21 DECODED STRING
// LC - 394
// string decodeAtIndex(string s, int k) {
//         int n = s.length() ;
//         long long size = 0 ;
//         for(int i =0 ; i < n; i++)
//         {
//             if(isdigit(s[i])) size = size*(s[i] - '0') ;
//             else  size++ ;
//         }
//         for( int i = n -1 ; i>= 0 ; i--)
//         {   k = k % size ;
//             if(k == 0 && isalpha(s[i]))
//             {
//                 return string(1,s[i]) ;
//             }
//             if(isalpha(s[i]))
//             {
//                 size-=1 ;
//             }
//             else size = size /(s[i] - '0') ;
//         }
//         return "" ;
//     }

// L -22 REVERSE WORDS IN STRING III
// LC - 557
// string reverseWords(string s) {
//         string ans = "" ;
//         // reverse(s.begin() , s.end()) ;string ans ="";
//         for(int i = 0 ; i < s.length() ; i++)
//         {   string word="" ;
//             while(i < s.length() && s[i] != ' ')
//             {
//                     word = word+s[i] ;
//                     i++; 
//             }
//             reverse(word.begin() , word.end()) ;
//             if(word.length()>0 ) ans += " " + word ;
//         }
//         return ans.substr(1) ;
//     }

// L -23 BACKSPACE STRING COMPARE
// LC - 844

// L -24 COUNT NUMBER OF HOMOGENEOUS SUBSTRINGS
// LC -1759
// int countHomogenous(string s) {
//         int mod = 1e9+ 7 ;
//         int n = s.length() ;
//         int result = 0; int len = 0 ;
//         for(int i = 0 ; i  < n ;i++)
//         {        
//             if(i!=0 && s[i]==s[i-1])
//             {
//                 len++; 
//             }
//             else
//             {   
//                 len = 1;
//             }
//             result = (result + len ) % mod;      
//         }
//         return result ;
//     }

// L -25 SORT VOWELS IN STRING
// LC - 2785
// bool isVowel(char ch)
//         {
//             char x =tolower(ch) ;
//             return (x=='a' || x=='e'  || x=='i' || x=='o' || x=='u');
//         }
//     string sortVowels(string s) {  
//         map<char,int> mpp;
//         for(int i =0 ; i<s.length();i++)
//         {
//             if(isVowel(s[i]))
//             {
//                 mpp[s[i]]++ ;
//             }
//         }
//         string v ="AEIOUaeiou" ;int j = 0 ;
//         for(int i = 0 ;i<s.length() ;i++)
//         {
//             if(isVowel(s[i]))
//             {
//                 while(mpp[v[j]]==0) j++; 
//                 s[i] = v[j] ;
//                 mpp[v[j]]-- ;
//             }
//         }
//         return s ;
//     }

// L -26 UNIQUE LENGTH -3 PALLINDROMIC SUBSEQUENCES
// LC - 1930
// int countPalindromicSubsequence(string s) {
//         unordered_set<char> letters ; 
//         for(int i= 0 ; i < s.length() ;i++)
//         {
//             letters.insert(s[i]);
//         }
//         char letter ; int result = 0 ;
//         for(char letter : letters)
//         {
//             int l_index = -1;
//             int r_index = -1;
//             for(int i = 0 ; i < s.length() ; i++)
//             {
//                 if(s[i] == letter)
//                 {
//                     if(l_index == -1)
//                     {
//                         l_index =i ;r_index = i ;
//                     }
//                     r_index = i ;
//                 }
//             }
//             unordered_set<char> st ;
//             for(int middle = l_index + 1 ; middle <= r_index - 1 ;middle++)
//             {
//                 st.insert(s[middle]) ;
//             }
//             result += st.size() ;
//         }
//         return result ;
//     }

// L -27 FIND UNIQUE BINARY STRING
// LC- 1980
// string findDifferentBinaryString(vector<string>& nums) {
//         int n = nums.size() ; string result = "" ;
//         for(int i =0 ; i< n ;i++)
//         {
//             char ch = nums[i][i];
//             if(ch == '0') result += '1';
//             else result +='0'; 
//         }
//         return result ;
//     }

// L -28 COUNT BEAUTIFUL SUBSTRING I
// LC -2947
// bool isVowel(char ch)
//     {
//         char x =tolower(ch) ;
//         return (x=='a' || x=='e'  || x=='i' || x=='o' || x=='u');
//     }
//     int beautifulSubstrings(string s, int k) {
//         int result = 0; 
//         for(int i =0;i<s.length();i++)
//         {   int vowels = 0 ; int consonants= 0;
//             for(int j =i ; j< s.length() ; j++)
//             {   char ch = s[j]; 
//                 if(isVowel(ch)) vowels++ ;
//                 else consonants++;
//                 if(vowels == consonants && (vowels*consonants)%k==0)
//                 {
//                     result++;
//                 }
//             }
//         }
//         return result ;
//     }

// L -29 COUNT BEAUTIFUL SUBSTRING II
// LC -

// L -30 NUMBER OF WAYS TO DIVIDE A CORRIDOR
// LC -2417
// int numberOfWays(string corridor) {
//         int M = 1e9 + 7 ;
//         int n = corridor.length() ;
//         vector<int> indices_seats ;
//         for(int i = 0 ; i < n ; i++)
//         {
//             if(corridor[i] == 'S') indices_seats.push_back(i);
//         } 
//         if(indices_seats.size()%2 != 0 || indices_seats.size() == 0) return 0 ;   
//         long long result = 1; 
//         int prev =  indices_seats[1] ;
//         for(int i = 2; i<indices_seats.size() ; i+=2)
//         {  
//             int length = indices_seats[i] - prev ;
//             result = ( result * length ) % M ;
//             prev = indices_seats[i+1] ;
//         }
//         return result ;
//     }
 
// KMP ALGORITHM
// LPS 
// void computeLPS(string &pattern , vector<int> &LPS ,int M)
// {   LPS[0] = 0 ;
//     int i = 1 ;
//     int length  = 0;
//     while(i<M)
//     {
//         if(pattern[i]==pattern[length]) 
//         {   
//             length++ ;
//             LPS[i] = length ;
//             i++ ;
//         }
//         else
//         {   if(length != 0)
//             {   
//                 length = LPS[length - 1] ;
//             }
//             else
//             {  
//             }
//         }
//     }
// }
// // main function            
//             int N = txt.length() ;
//             int M = pattern.length();
//             int i = 0; int j = 0;
//             vector<int> result ;
//             vector<int> LPS(M,0) ;
//             computeLPS(pattern , LPS ,M)
//             while(i < N )
//             {
//                 if(txt[i] == pattern[j])
//                 {
//                     i++ ;j++ ;
//                 }
//                 // found completely
//                 if(j == m)
//                 {
//                     result.push_back(i-m+1);
//                     j = LPS[j-1]; 
//                 }
//                 // not equal
//                 else if(txt[i] != pattern[j])
//                 {
//                     if(j!=0) j = LPS[j-1] ;
//                     else i++;
//                 }
//             }
//             return result ;

// L -31 NUMBER OF LASER BEAMS IN BANK
// LC - 2125

// L -32 MIN NUMBER OF STEPS TO MAKE ANAGRAM
// LC - 1347
// int minSteps(string s, string t) {
//         int arr_s[26] ={0} ;int arr_t[26] ={0} ;
//         for(int i = 0 ; i < s.size() ; i++)
//         {
//               arr_s[s[i]-'a']++ ;
//               arr_t[t[i]-'a']++ ;
//         }
//         int result = 0;
//         for(int i = 0 ; i < 26 ; i++)
//         {
//              if(arr_s[i] > arr_t[i])
//              result += (arr_s[i] - arr_t[i]) ;
//         }
//         return result ;
//      }

// L -33 FIND BEAUTIFUL INDICES IN GIVEN ARRAY
// LC - 3006,3008  

// L -34 MIN TIME TO REVERST WORD TO INITIAL STATE
// LC - 3029,3031

// L -35 CUSTOM SORT STRING
// LC - 791

// L -36 SHORTEST UNCOMMON SUBSTRING
// LC - 3076

// L -37 COUNT SUBSTRING STARTING AND ENDING WITH GIVEN CHARACTER
// LC - 3084
// long long countSubstrings(string s, char c) {
//         int cnt = 0 ;
//         long long ans = 0; 
//         for(int i = 0 ;i < s.length() ; i++)
//         {
//             if(s[i] == c)
//             {
//                 ans += cnt +1 ;cnt++ ;
//             }
//         }
//         return ans ;
//     }

// L -38 COMPARE VERSION NUMBERS
// LC -165
// class Solution {
//         public:
//             vector<string> getToken(string version)
//             {
//                 stringstream ss(version) ;
//                 string token="" ;
//                 vector<string> tokens ;
//                 while(getline(ss,token,'.'))
//                 {
//                     tokens.push_back(token);
//                 }
//                 return tokens ;
//             }
//             int compareVersion(string version1, string version2) {
//                 vector<string> v1 = getToken(version1);
//                 vector<string> v2 = getToken(version2);
//                 int i = 0 ;int n = v1.size(); int m = v2.size() ;
//                 while(i<m || i<n)
//                 {
//                     int a = i<n ? stoi(v1[i]) : 0 ;
//                     int b = i<m ? stoi(v2[i]) : 0 ;
//                     if(a<b) return -1;
//                     else if(a>b) return 1;
//                     else i++;
//                 }
//                 return 0 ;
//             }
//         };

// L -39 APPEND CHAR TO STRING TO MAKE SUBSEQUENCE
// LC - 2486
// class Solution {
//         public:
//             int appendCharacters(string s, string t) {
//                 int m = s.length() ; int n = t.length() ;
//                 int i = 0 ; 
//                 int j = 0 ;
//                 while(i < m && j < n)
//                 {
//                     if(s[i] == t[j]){i++ ; j++ ;}
//                     else i++;
//                 }
//                 return n-j;
//             }
//         };

// L -45 SEPERSTE BLACK AND WHITE BALLS
// LC -2938
// check no. of 1 in left of encountered 0
// long long minimumSteps(string s) {
//         int cnt = 0 ; long long  ans = 0 ;
//         for(int i = 0 ; i < s.length() ; i++)
//         {
//             if(s[i] == '1') cnt++;
//             else
//             {
//                 ans += cnt ;
//             }
//         }
//         return ans ;
//     }



