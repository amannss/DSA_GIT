//                              CODESTORY WITH MIK

// L-1

// LC - 295 FIND MEADIAN FFROM DATA STREAM
// class MedianFinder {
// public:
//     priority_queue<int> left_max ;
//     priority_queue<int , vector<int>, greater<int>> right_min ;
//     MedianFinder() {   
//     }
//     void addNum(int num) {
//         if(left_max.empty() || num < left_max.top())
//         {
//             left_max.push(num);
//         }
//         else
//         {
//             right_min.push(num) ;
//         }
// maintain left heap size exactly greater than righ by only 1
// or just maintain equal size 
//       if(abs((int)left_max.size() - (int)right_min.size()) > 1)
//         {
//             right_min.push(left_max.top()) ;
//             left_max.pop();
//         }
//         else if(left_max.size() < right_min.size() )
//         {
//             left_max.push(right_min.top()) ;
//             right_min.pop() ;
//         }
//     }
//     double findMedian() {
//         if(left_max.size() == right_min.size())
//         {
//             // means number of elements even
//             return (double)(left_max.top() + right_min.top())/2 ;        
//         }
//         else
//         {
//             // left me 1 jyada hai element 
//             return left_max.top() ;
//         }
//     }
// };
// /**
//  * Your MedianFinder object will be instantiated and called as such:
//  * MedianFinder* obj = new MedianFinder();
//  * obj->addNum(num);
//  * double param_2 = obj->findMedian();
//  */

// L-2

// LC - 451 SORT CHARACTERS BY FREQUENCY
// class Solution {
// public:
//     typedef pair<char,int> p;
//     struct lambda
//     {
//         bool operator()(p &p1 ,p &p2)
//         {
//             return p1.second < p2.second ;
//         }
//     }
// ;
//     string frequencySort(string s) {
//         priority_queue<p,vector<p>,lambda> pq ;   
//         unordered_map<char ,int> mpp ;
//     // frequency added in map
//         for(auto &ch: s) mpp[ch]++ ;
//     // fill in heap from map
//         for(auto &it :mpp)
//         {
//             pq.push({it.first , it.second}) ;
//         } 
//     // heap is sorted , max frequency on top
//     string result ="";
//         while(!pq.empty())
//         {
//             p temp = pq.top() ;
//             pq.pop() ;
//             result+= string(temp.second, temp.first) ;
//         }
//         return result ;
//     }
// };

// L-3

// LC - 1962 REMOVE STONES TO MINIMIZE TOTAL
// class Solution {
// public:
//     int minStoneSum(vector<int>& piles, int k) {
//         int n = piles.size();
//         int sum = 0;
//         // create priority queue
//         priority_queue<int> pq;//bydefaault max heap
//         for(int i=0;i<n;i++)
//         {
//                 pq.push(piles[i]); sum+=piles[i];
//         }
//         //
//         for(int i=0; i<k ;i++)
//         {
//             int max_ele = pq.top() ; pq.pop() ;
//             int remove = max_ele/2 ;
//             sum-= remove ;
//             max_ele-=remove ;
//             pq.push(max_ele);
//         }
//         return sum ;
//     }
// };
 
// L-4

// LC - 1834 SINGLE THREADED CPU
// class Solution {
// public:
//     vector<int> getOrder(vector<vector<int>>& tasks) {
//         typedef pair<int,int> P ;
//         vector<array<int , 3>> sorted_tasks ;
//         int n = tasks.size() ;
//         // update tasks array and sort it
//         for(int i=0;i<n ;i++)
//         {
//             int start_time =tasks[i][0] ;
//             int processing_time = tasks[i][1] ;
//             sorted_tasks.push_back({start_time,processing_time,i}) ;
//         }
//         // sorted_tasks = [{1 2 0},{2 4 1},{3 2 2},{4 1 3}]
//         // sort on basis of enque time
//         sort(sorted_tasks.begin() , sorted_tasks.end()) ;
//         vector<int> result ;
//         long long curr_time = 0 ;
//         int idx = 0 ;
//         priority_queue<P ,vector<P> , greater<P>> pq ;
//         // insert in min heap on basis of 
//         // { process time , index }
//         while(idx < n || !pq.empty())
//         {
//             if(pq.empty() && curr_time < sorted_tasks[0][0])
//             {   // Ist time inserting in pq , runs only one time
//                 curr_time = sorted_tasks[0][0] ;
//             }
//             while(idx<n && sorted_tasks[idx][0] <= curr_time)
//             {   
//                 int processing_time = sorted_tasks[idx][1] ;
//                 int index = sorted_tasks[idx][2] ;
//                 pq.push({ processing_time ,index});
//                 idx++ ;
//             }
//             pair<int,int>  tops = pq.top() ; pq.pop() ; 
//             curr_time += tops.first ; // processing time
//             result.push_back(tops.second) ;
//         }
//         return result ;
//     }
// };
// L-5

// L-5

// LC - 1046 LAST STONE WEIGHT
// class Solution {
// public:
//     int lastStoneWeight(vector<int>& stones) {
//         priority_queue<int> pq ;// max heap
//         for(auto &it : stones) pq.push(it) ;// filling heap
//         while(pq.size() > 1)
//         {
//             int a = pq.top() ; pq.pop() ;
//             int b = pq.top() ; pq.pop() ;
//             pq.push(abs(a-b)) ;
//         }
//         return pq.top() ;
//     }
// };

// L-6

// LC - 347  TOP K FREQUENT ELEMENTS 
// TC - O(n*log k)
// class Solution {
// public:
//     vector<int> topKFrequent(vector<int>& nums, int k) {
//         typedef pair<int,int> P ;
//         priority_queue<P , vector<P> ,greater<P> > pq ;
//     // 1.store in map
//         unordered_map<int,int> mp ;
//         for(auto &it : nums) mp[it]++ ;
//     // 2.store in pq based on freq
//         for(auto &it : mp)
//         {   
//             int value = it.first ;
//             int freq = it.second ;
//             pq.push({freq , value}) ;
//             // min freq wala on top
//             if(pq.size() > k) pq.pop() ;
//         }
//     // 3.store in result 
//     vector<int> result ;
//     while(!pq.empty())
//     {
//         result.push_back(pq.top().second);
//         pq.pop() ;
//     }
//     return result ;
//     }
// };

// L-7

// LC - 703 Kth LARGEST ELEMENT IN STREAM
// class KthLargest {
// public:
// int K ;
// priority_queue<int ,vector<int> ,greater<int>> pq ;
//     KthLargest(int k, vector<int>& nums) {
//         K = k; 
//         // store nums in pq
//         for(int &num : nums)
//         {
//             pq.push(num) ;
//             if(pq.size() > k) pq.pop() ;
//             // min on top
//         }
//     }
//     int add(int val) {
//         pq.push(val) ;
//         if(pq.size() > K) pq.pop() ;
//         return pq.top() ;
//     }
// };

// L-8

// LC - 2542 MAXIMUM SUBSEQUENCE SCORE
// class Solution {
// public:
//     long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
//         int n = nums1.size();
//         // Step 1: Pair nums1 and nums2
//         vector<pair<int, int>> vec(n);
//         for (int i = 0; i < n; i++) {
//             vec[i] = {nums1[i], nums2[i]};
//         }
//         // Step 2: Sort by nums2 descending
//         sort(vec.begin(), vec.end(), [](pair<int,int>& a, pair<int,int>& b) {
//             return a.second > b.second;
//         });
//         // Step 3: Initialize min heap and ksum
//         priority_queue<int, vector<int>, greater<int>> pq;
//         long long ksum = 0;
//         for (int i = 0; i < k; i++) {
//             ksum += vec[i].first;
//             pq.push(vec[i].first);
//         }
//         long long result = ksum * vec[k-1].second;
//         // Step 4: Try next elements
//         for (int i = k; i < n; i++) {
//             ksum += vec[i].first - pq.top();
//             pq.pop();
//             pq.push(vec[i].first);
//             result = max(result, ksum * (long long)vec[i].second);
//         }
//         return result;
//     }
// };

// L-9

// LC - TOTAL COST TO HIRE K WORKERS
// class Solution {
// public:
//     long long totalCost(vector<int>& costs, int k, int candidates) {
//         int n = costs.size() ; long long  ans = 0 ;
//         int i= 0; int j = n-1;
//         priority_queue<int,vector<int> , greater<int>> pq1 ;
//         priority_queue<int,vector<int> , greater<int>> pq2 ;
//         while(k--)
//         {
//             while(pq1.size() < candidates && i<= j)
//             {
//                 pq1.push(costs[i++]);
//             }
//             while(pq2.size() < candidates && j>=i)
//             {
//                 pq2.push(costs[j--]);
//             }
//             int top1= pq1.size()>0 ? pq1.top() : INT_MAX ; 
//             int top2= pq2.size()>0 ? pq2.top() : INT_MAX ;
//             if(top1 <= top2)
//             {
//                 ans += top1; pq1.pop() ;
//             }
//             else
//             {
//                 ans += top2; pq2.pop() ;
//             }
//         }
//         return ans ;
//     }
// };

// L-10

// LC - 373 FIND K PAIRS WITH SMALLEST SUMS BRUTE
// class Solution {
// public:
// typedef pair<int,pair<int,int>> P ;
//     vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
//         set<pair<int,int>> visited ; priority_queue<P,vector<P>,greater<P>> pq ;
//         int m = nums1.size() ; int n =nums2.size() ;
//         int sum = nums1[0] + nums2[0] ;
//         pq.push({sum,{0,0}}); visited.insert({0,0}); 
//         vector<vector<int>> result ;
//         while(k-- && !pq.empty())
//         {
//             auto temp = pq.top() ; pq.pop() ;
//             int i= temp.second.first ;
//             int j= temp.second.second ;
//             result.push_back({nums1[i],nums2[j]}) ;
//             // push (i,j+1) if possible
//             if(j+1 < n && visited.find({i,j+1})==visited.end())
//             {
//                 pq.push({nums1[i]+nums2[j+1],{i,j+1}}) ;
//                 visited.insert({i,j+1});
//             }
//             // push (i+1,j) if possible
//             if(i+1 < m && visited.find({i+1,j})==visited.end())
//             {
//                 pq.push({nums1[i+1]+nums2[j],{i+1,j}}) ;
//                 visited.insert({i+1,j});
//             }
//         }
//         return result ;
//     }
// };

// L-11

// LC - 373 FIND K PAIRS WITH SMALLEST SUMS OPTIMAL
// class Solution {
// public:
// typedef pair<int,pair<int,int>> P ;
//     vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
//         set<pair<int,int>> visited ; priority_queue<P,vector<P>,greater<P>> pq ;
//         int m = nums1.size() ; int n =nums2.size() ;
//         int sum = nums1[0] + nums2[0] ;
//         pq.push({sum,{0,0}}); visited.insert({0,0}); 
//         vector<vector<int>> result ;
//         while(k-- && !pq.empty())
//         {
//             auto temp = pq.top() ; pq.pop() ;
//             int i= temp.second.first ;
//             int j= temp.second.second ;
//             result.push_back({nums1[i],nums2[j]}) ;
//             // push (i,j+1) if possible
//             if(j+1 < n && visited.find({i,j+1})==visited.end())
//             {
//                 pq.push({nums1[i]+nums2[j+1],{i,j+1}}) ;
//                 visited.insert({i,j+1});
//             }
//             // push (i+1,j) if possible
//             if(i+1 < m && visited.find({i+1,j})==visited.end())
//             {
//                 pq.push({nums1[i+1]+nums2[j],{i+1,j}}) ;
//                 visited.insert({i+1,j});
//             }
//         }
//         return result ;
//     }
// };

// L-12

// LC - 215 Kth LARGEST ELEMENT IN ARRAY
// class Solution {
// public:
//     int findKthLargest(vector<int>& nums, int k) {
//         priority_queue<int,vector<int>,greater<int> > pq ; // min heap
//         for(auto &it : nums)
//         {   
//             pq.push(it) ;
//             if(pq.size() > k) pq.pop() ;
//         }
//         int ans = pq.top() ;
//         return ans ;
//     }
// };

// L-13

// LC - 767 REORGANIZE STRING
// class Solution {
// public:
//     string reorganizeString(string s) {
//         typedef pair<int,char> P ; vector<int> count(26,0) ; int n = s.length() ;
//         // count freq 
//         for(char &ch : s)
//         {   count[ch -'a']++ ; if(count[ch-'a'] > (n+1)/2) return "" ; }
//         // max heap 
//         priority_queue<P , vector<P>> pq ;
//         for(char ch = 'a' ; ch <= 'z' ;ch++)
//         {
//             if(count[ch-'a'] > 0) pq.push({count[ch-'a'] , ch}) ;
//         }
//         // 
//         string result = "" ;
//         while(pq.size() >= 2)
//         {
//             auto p1 = pq.top() ; pq.pop() ;
//             auto p2 = pq.top() ; pq.pop() ;
//             result.push_back(p1.second) ;p1.first-- ;
//             result.push_back(p2.second) ;p2.first-- ;
//             if(p1.first > 0) pq.push(p1) ;
//             if(p2.first > 0) pq.push(p2) ;
//         }
//         if(!pq.empty()) result.push_back(pq.top().second); 
//         return result ;
//     }
// };

// L-14

// LC - 621 TASK SCHEDULER
// class Solution {
// public:
//     int leastInterval(vector<char>& tasks, int n) {
//         vector<int> mp(26,0) ; 
//         // count frequency
//         for(char &ch : tasks)  mp[ch-'A']++ ;
//         int time = 0 ; priority_queue<int> pq ; // max heap 
//         // push freq in pq
//         for(int i =0;i < 26;i++) 
//         {
//             if(mp[i] > 0) pq.push(mp[i]) ;
//         }
//         while(!pq.empty())
//         {   
//             vector<int> temp ;// no. of task each time = n + 1
//             for(int i =1;i<= n+1 ; i++)
//             {   
//                 if(!pq.empty()) 
//                 {   int freq = pq.top(); pq.pop() ;
//                     freq-- ;
//                     temp.push_back(freq) ;
//                 }
//             }
//             // again push from vector to pq
//             for(int &f : temp)
//             {   
//                 if(f>0) pq.push(f) ;
//             }
//             // count time
//             if(pq.empty()) time += temp.size() ;
//             else time+= n+1 ;
//         }
//         return time ;
//     }
// };

// L-15 

// LC - 786 KTH SMALLEST PRIME FRACTION

// L-16

// LC - 857 MINIMUM COST TO HIRE K WORKERS
// BRUTE 
// class Solution {
// public:
//     double mincostToHireWorkers(vector<int>& quality, vector<int>& min_wage, int k) {
//         int n = quality.size();
//         double result = DBL_MAX;
//         for (int manager = 0; manager < n; manager++) {
//             double manager_ratio = (double)min_wage[manager] / quality[manager];
//             vector<double> group;
//             // Add manager's own wage first
//             group.push_back(manager_ratio * quality[manager]);
//             for (int worker = 0; worker < n; worker++) {
//                 if (worker == manager) continue;
//                 double worker_wage = manager_ratio * quality[worker];
//                 if (worker_wage >= min_wage[worker]) {
//                     group.push_back(worker_wage);
//                 }
//             }
//             // Check if we have at least k workers including the manager
//             if (group.size() < k) continue;
//             // Use max-heap to get smallest k wages
//             priority_queue<double> pq;
//             double sum_wage = 0;
//             for (double &wage : group) {
//                 sum_wage += wage;
//                 pq.push(wage);
//                 if (pq.size() > k) {
//                     sum_wage -= pq.top();
//                     pq.pop();
//                 }
//             }
//             if (pq.size() == k) {
//                 result = min(result, sum_wage);
//             }
//         }
//         return result;
//     }
// };
// BETTER
// class Solution {
// public:
//     double mincostToHireWorkers(vector<int>& quality, vector<int>& min_wage, int k) {
//         int n = quality.size();
//         double result = DBL_MAX;
//         vector<pair<double ,int>> worker_ratio(n) ;
//         for(int worker =0; worker <n;worker++)
//         {
// worker_ratio[worker] =make_pair((double)min_wage[worker]/quality[worker],quality[worker]) ;
//         }
//         sort(worker_ratio.begin() , worker_ratio.end()) ;
//         for (int manager = k-1 ; manager < n; manager++)
//         {
//             double manager_ratio = worker_ratio[manager].first ;
//             vector<double> group;
//             for (int worker = 0; worker <= manager ; worker++)
//             {
//                 double worker_wage = manager_ratio * worker_ratio[worker].second;
//                 group.push_back(worker_wage); 
//             }
//             // Use max-heap to get smallest k wages
//             priority_queue<double> pq;
//             double sum_wage = 0;
//             for (double &wage : group) {
//                 sum_wage += wage;
//                 pq.push(wage);
//                 if (pq.size() > k) {
//                     sum_wage -= pq.top();
//                     pq.pop();
//                 }
//             }
//             if (pq.size() == k) {
//                 result = min(result, sum_wage);
//             }
//         }
//         return result;
//     }
// };
// OPTIMAL
// class Solution {
// public:
//     double mincostToHireWorkers(vector<int>& quality, vector<int>& min_wage, int k) {
//     int n = quality.size();
//     double result = DBL_MAX;
//     vector<pair<double ,int>> worker_ratio(n) ;
//         for(int worker =0; worker <n;worker++)
//         {
//                 worker_ratio[worker] =make_pair((double)min_wage[worker]/
//                                         quality[worker],quality[worker]) ;
//         }
//         sort(worker_ratio.begin() , worker_ratio.end()) ;
//     priority_queue<int,vector<int>> pq ;
//     int sum_quality = 0 ;
//         for(int i =0;i<k;i++)
//         {
//             pq.push(worker_ratio[i].second);
//             sum_quality += worker_ratio[i].second ;
//         }
//         // first manager
//         double manager_ratio = worker_ratio[k-1].first ;
//         result = manager_ratio * sum_quality ;
//         for (int manager = k ; manager < n; manager++)
//         {
//             manager_ratio = worker_ratio[manager].first ;
//             pq.push(worker_ratio[manager].second) ;
//             sum_quality += worker_ratio[manager].second ;
//             if(pq.size() > k )
//             {
//                 sum_quality-=pq.top() ;
//                 pq.pop() ;
//             }
//             result = min(result , manager_ratio * sum_quality);
//         }
//         return result;
//     }
// };

// L-17

// LC - 3170 LEXICOGRAPHICALLY MINIMUM STRING AFTER REMOVING STARS
// class Solution {
// public:
// typedef pair<char,int> p ;
// struct comp{
//     bool operator()(p &p1,p &p2)
//     {
//         if(p1.first == p2.first) return p1.second < p2.second ;
//         else return p1.first > p2.first ;
//     }
// };
//     string clearStars(string s) {
//         int n =s.length() ; string result ="" ;
//         priority_queue<p ,vector<p> ,comp> pq ;
//         for(int i=0 ;i <n;i++)
//         {   
//             if(s[i]=='*' )
//             {
//                 int idx = pq.top().second ;
//                 pq.pop() ;
//                 s[idx] = '*' ;
//             }
//             else pq.push({s[i],i}) ;
//         }
//         for(int i=0;i<n;i++)
//         {
//             if(s[i]!='*') result.push_back(s[i]) ;
//         }
//         return result ;
//     }
// };

// L-18

// LC - 502 IPO
// class Solution {
// public:
//     int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
//         int n = profits.size();
//         vector<pair<int, int>> vec(n);
//         // Pair each capital with its corresponding profit
//         for (int i = 0; i < n; i++) {
//             vec[i] = {capital[i], profits[i]};
//         }
//         // Sort projects by capital requirement
//         sort(vec.begin(), vec.end());
//         priority_queue<int> pq;  // Max heap to pick highest profit
//         int i = 0;
//         // Choose at most k projects
//         while (k--) {
//             // Push all affordable projects into the heap
//             while (i < n && vec[i].first <= w) {
//                 pq.push(vec[i].second);
//                 i++;
//             } 
//             // No projects can be done with current capital
//             if (pq.empty()) break;
//             // Choose the most profitable one
//             w += pq.top();
//             pq.pop();
//         }
//         return w;
//     }
// };

// L-19

// LC - 1508 RANGE SUM OF SORTED SUBARRAY SUMS
// class Solution {
// public:
// typedef pair<int,int> p ;
// int M = 1e9+7 ;
//     int rangeSum(vector<int>& nums, int n, int left, int right) {
//         priority_queue<p ,vector<p>,greater<p>> pq ;
//         int result = 0 ;
//     // push first time
//         for(int i=0;i<nums.size();i++) pq.push({nums[i] ,i}) ;
//     //
//         for(int count = 1; count <= right ;count++)
//         {
//             auto x = pq.top();pq.pop() ;
//             int sum = x.first ;
//             int idx = x.second;
//             if(count >= left) result = (result+sum)% M;
//             int new_idx = idx+1 ;
//             p new_pair ;
//             if(new_idx < n)
//             {
//                 new_pair.first = sum + nums[new_idx];
//                 new_pair.second= new_idx ;
//                 pq.push(new_pair);
//             }
//         }
//         return result ;
//     }
// };









