//                                              STRIVER

// L-1 

// LC-00 INTRODUCTION TO SLIDING WINDOW AND TWO POINTER
// BASICS AND INTRO
// TYPES OF QUESTIONS 
// 1.CONSTANT WINDOW
// 2.LONGEST SUBARRAY OR SUBSTRING 
// 3.NUMBER OF SUBARRAY WITH SUM K
// 4.SHORTEST-MINIMUM WINDOW

// L-2 

// LC-1423 MAX POINTS YOU CAN OBTAIN FROM CARDS
// class Solution {
// public:
//     int maxScore(vector<int>& arr, int k) {
//         int lsum =0 ;
//         int rsum =0 ;
//         int maxsum=0 ;
//         // count leftmost first k cards sum
//         for(int i = 0 ; i < k ; i++) lsum+= arr[i] ;
//         maxsum = lsum ;
//         // shrink l and extend r
//         int r_index = arr.size() - 1;
//         for(int i = k-1 ; i>=0 ; i--)
//         {
//             lsum = lsum - arr[i] ;
//             rsum = rsum +  arr[r_index] ;
//             maxsum = max(maxsum , lsum+rsum) ;
//             r_index--;
//         }
//         return maxsum ;
//     }
// };

// L-3 

// LC-3 LONGEST SUBSTRING WITH NON REPEATING CHARACTERS
// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         int l = 0, r = 0, maxlen = 0;
//         int n = s.length();
//         unordered_map<char, int> hash;  // Stores last seen index of characters
//         while (r < n) {
//             if (hash.find(s[r]) != hash.end() && hash[s[r]] >= l) {
//                 l = hash[s[r]] + 1;
//             }
//             maxlen = max(maxlen, r - l + 1);
//             hash[s[r]] = r;
//             r++;
//         }
//         return maxlen;
//     }
// };

// L-4

// LC-1004 MAX CONSECUTIVES ONES III
// class Solution {
// public:
//     int longestOnes(vector<int>& nums, int k) {
//         int maxlen = 0 ; int l = 0 ; int r = 0 ; int len = 0 ; int n = nums.size() ;
//         int z = 0 ;
//         while(r < n)
//         {   
//             if(nums[r] == 0) z++ ;
//             if(z >k)
//             {   
//                 if(nums[l] == 0) z-- ;
//                 l++ ;
//             }
//             if(z<=k)
//             {   
//                 len = r - l + 1;
//                 maxlen = max(maxlen , len) ;
//             }
//             r++ ;
//         }
//         return maxlen ;
//     }
// };

// L-5

// LC-00 FRUITS INTO BASKET
// funct(arr)
// {
//     int l= 0 ; int r = 0; int maxlen = 0 ; unordered_map<int,int> mpp ;
//     while(r < n)
//     {
//         mpp[arr[r]]++ ;
//         if(mpp.size() > k)
//         {
//             mpp[arr[l]]-- ;
//             if(mpp[arr[l]]==0) mpp.erase(arr[l]) ;
//             l++ ;
//         }
//         if(mpp.size() <= k)
//         {
//             maxlen = max(maxlen , r-l+1) ;
//         }
//         r++ ;
//     }
// }

// L-6

// LC-340 LONGEST SUBSTRING AT MOST K DISTINCT CHARACTERS
// suscribe to unlock

// L-7

// LC-1358   NUMBER OF SUBSTRINGS CONTAINING ALL THREE CHARACTERS
// class Solution {
// public:
//     int numberOfSubstrings(string s) {
//         int lastseen[3] = {-1, -1, -1}; 
//         int cnt = 0;
//         for(int i = 0; i < s.length(); i++) {
//             lastseen[s[i] - 'a'] = i;
//             
//             if(lastseen[0] != -1 && lastseen[1] != -1 && lastseen[2] != -1) {
//                 cnt += 1 + min({lastseen[0], lastseen[1], lastseen[2]});
//             }
//         }
//         return cnt;
//     }
// };

// L-8

// LC-424 LONGEST REPEATING CHARACTER REPLACEMENT
// class Solution {
// public:
//     int characterReplacement(string s, int k) {
//         int l = 0, r = 0, maxlen = 0, maxfreq = 0;
//         int hash[26] = {0}; // Fixed array size to 26
//         while (r < s.length()) {
//             hash[s[r] - 'A']++;
//             maxfreq = max(maxfreq, hash[s[r] - 'A']);
//             // If window size - maxfreq > k, shrink from left
//             if ((r - l + 1) - maxfreq > k) {
//                 hash[s[l] - 'A']--;
//                 l++;
//             }
//             maxlen = max(maxlen, r - l + 1); // Always update maxlen
//             r++;
//         }
//         return maxlen;
//     }
// };

// L-9 

// LC-930   BINARY SUBARRAYS WITH SUM
// class Solution {
// public:
//     int countAtMost(vector<int>& nums, int goal) {
//         if (goal < 0) return 0;
//         int l = 0, sum = 0, count = 0;
//         for (int r = 0; r < nums.size(); ++r) {
//             sum += nums[r];
//             while (sum > goal) {
//                 sum -= nums[l++];
//             }
//             count += r - l + 1;
//         }
//         return count;
//     }
//     int numSubarraysWithSum(vector<int>& nums, int goal) {
//         return countAtMost(nums, goal) - countAtMost(nums, goal - 1);
//     }
// };

// L-10

// LC-1248  COUNT NUMBER OF NICE SUBARRAYS 
// class Solution {
// public:
//     int countAtMost(vector<int>& nums, int goal) {
//         if (goal < 0) return 0;
//         int l = 0, sum = 0, count = 0;
//         for (int r = 0; r < nums.size(); ++r) {
//             sum += nums[r]%2;// odd toh 1 even toh 0
//             while (sum > goal) {
//                 sum -= nums[l++]%2;
//             }
//             count += r - l + 1;
//         }
//         return count;
//     }
//     int numberOfSubarrays(vector<int>& nums, int k) {
//         return countAtMost(nums, k) - countAtMost(nums,k - 1);
//     }
// };

// L-11

// LC-992   SUBARRAY WITH K DIFFERENT INTEGERS
// class Solution {
// public:
//     int countAtMost(vector<int>& nums, int k) {
//         if (k < 0) return 0;
//         int l = 0, sum = 0, count = 0;int r = 0 ;
//         unordered_map<int,int> mpp ;
//         while(r < nums.size())
//         {
//             mpp[nums[r]]++ ;
//             // distinct char > k then shrink
//             while(mpp.size()> k)
//             {
//                 mpp[nums[l]]-- ;
//                 if(mpp[nums[l]]==0) mpp.erase(nums[l]) ;
//                 l++ ;
//             }
//             count += (r-l+1) ;
//             r++ ;
//         }
//         return count;
//     }
//     int subarraysWithKDistinct(vector<int>& nums, int k) {
//          return countAtMost(nums, k) - countAtMost(nums,k - 1);
//     }
// };

// L-12

// LC-76   MINIMUN WINDOW SUBSTRING 
//

// L-13

// LC-239 SLIDING WINDOW MAXIMUM
// class Solution {
// public:
//     vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//         vector<int> result ;
//         deque<int> que ;
//         for(int i =0;i<nums.size() ;i++)
//         {
//             // maintain window len in deque
//             while(!que.empty() && que.front() <= i-k)
//             {
//                 que.pop_front() ;
//             }
//             // remove lesser than curr elements
//             while(!que.empty() && nums[i] > nums[que.back()])
//             {
//                 que.pop_back() ;
//             }
//             // insert curr element 
//            que.push_back(i) ;
//             // insert in result
//             if(i>= k -1) 
//             {
//                 result.push_back(nums[que.front()]) ;
//             }
//         }
//         return result ;
//     }
// };






















