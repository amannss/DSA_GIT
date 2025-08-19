//                          CODESTORY WITH MIK 

// L-1

// LC - 948   BAG OF TOKENS
// class Solution {
// public:
//     int bagOfTokensScore(vector<int>& tokens, int power) {
//         int n=tokens.size() ; int maxscore = 0 ;
//         sort(tokens.begin() , tokens.end() ) ;
//         int i=0;int j=n-1 ; int score =0 ;
//         while(i<=j)
//         {
//             if(power >=tokens[i])
//             {
//                 power -=tokens[i] ;
//                 score++;
//                 i++ ;
//                 maxscore = max(maxscore , score) ;
//             }
//             else if(score >=1)
//             {
//                 power +=tokens[j];score-- ;j--;
//             }
//             else return maxscore ;
//         }
//         return maxscore; 
//     }
// };

// L-2

// LC - 881   BOATS TO SAVE PEOPLE
// class Solution {
// public:
//     int numRescueBoats(vector<int>& people, int limit) {
//         int n = people.size();
//         int boats = 0;
//         int i = 0, j = n - 1;
//         sort(people.begin(), people.end());
//         while (i <= j) {
//             if (people[i] + people[j] <= limit) {
//                 i++; // lightest goes with heaviest
//                 j--;
//             } else {
//                 j--; // heaviest alone
//             }
//             boats++;
//         }
//         return boats;
//     }
// };

// L-3

// LC - 1328  BREAK A PALLINDROME
// class Solution {
// public:
//     string breakPalindrome(string pal) {
//         int n=pal.length() ;
//         if(n==1) return "" ;
//         for(int i=0;i<n/2 ;i++)
//         {
//             if(pal[i] != 'a')
//             {
//                 pal[i] ='a';// break
//                 return pal;
//             }
//         }
//         // change last one to smallest lexicographical non palindrome
//         pal[n-1]='b' ;
//         return pal ;
//     }
// };

// L-4 

// LC - 991   BROKEN CALCULATOR
// class Solution {
// public:
//     int brokenCalc(int startValue, int target) {
//         int ops = 0;
//         while (target > startValue) {
//             if (target % 2 == 0) {
//                 target /= 2;   // reverse of *2
//             } else {
//                 target += 1;   // reverse of -1
//             }
//             ops++;
//         }
//         return ops + (startValue - target);
//     }
// };

// L-5

// LC - 1578 MIN TIME TO MAKE ROPE COLOURFULL
// class Solution {
// public:
//     int minCost(string s, vector<int>& neededTime) {
//         int n = s.size() ; int time=0;int prev =0 ;
//         for(int i=0 ;i <n;i++)
//         {
//             if(i>0 && s[i]!= s[i-1])
//             {
//                 prev = 0;
//             }
//             int curr = neededTime[i] ;
//             time+= min(prev , curr) ;
//             prev = max(prev , curr) ;
//         }
//         return time ;
//     }
// };

// L-6

// LC - 2136 EARLIEST POSSIBLE DAY OF FULL BLOOM
// class Solution {
// public:
//     int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
//         int n= plantTime.size() ;
//         vector<pair<int,int>> vec(n) ; // planttime , growtime
//         for(int i=0;i<n;i++)
//         {
//             vec[i] ={plantTime[i],growTime[i]} ;
//         } 
//         // sort according grow time in descending order
//         auto lambda=[](pair<int,int> &p1,pair<int,int>& p2)
//         {
//             return p1.second > p2.second;
//         };
//         sort(vec.begin(),vec.end(),lambda) ;
//         int maxbloomdays = 0;
//         int prevplantdays= 0;
//         for(int i=0 ;i<n;i++)
//         {
//             int currplanttime=vec[i].first ;
//             int currglowtime =vec[i].second ;
//             prevplantdays+= currplanttime ;
//             int currplantbloomtime =  prevplantdays + currglowtime;
//             maxbloomdays = max(maxbloomdays,currplantbloomtime) ;
//         }
//         return maxbloomdays ;
//     }
// };

// L-7

// LC - 2131 LONGEST PALINDROME BY CONCATENATING TWO LETTER WORDS
// class Solution {
// public:
//     int longestPalindrome(vector<string>& words) {
//         unordered_map<string ,int> mp ;
//         for(string &word : words) mp[word]++ ;
//         bool centerused = false ; int result = 0 ;
//         for(string &word : words)
//         {
//             string rev= word ;
//             reverse(rev.begin() ,rev.end()) ;
//             if(rev != word )// 'ab' , 'ba'
//             {
//                 if(mp[word] >0  && mp[rev]>0)
//                 {
//                     mp[word]-- ;mp[rev]-- ;result+= 4 ;
//                 }
//             }
//             else // 'cc' , 'cc'
//                 {   
//                     if(mp[word] >= 2)
//                     {
//                         mp[word]-=2 ; result+=4;
//                     }
//                     else if(mp[word] == 1 && centerused == false )
//                     {
//                         mp[word]-- ; result +=2 ; centerused = true ;
//                     }
//                 }
//         }
//         return result ;
//     }
// };

// L-8

// LC - 1323 MAXIMUM 69 NUMBER 
// class Solution {
// public:
//     int maximum69Number (int num) {
//         int placevalue = 0 ; int placevaluesix = -1 ;
//         int temp = num ;
//         while(temp > 0)
//         {
//             int remain = temp%10 ;
//             if(remain == 6) placevaluesix = placevalue ;
//             temp = temp/10 ;
//             placevalue++ ;
//         }
//         if(placevaluesix == -1) return num ;
//         return num +3* pow(10,placevaluesix) ; 
//     }
// };

// L-9

// LC - 2279 MAXIMUM BAGS WITH FULL CAPACITY
// class Solution {
// public:
//     int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
//         int n = capacity.size();
//         vector<int> required;
//         // calculate how many rocks each bag still needs
//         for (int i = 0; i < n; i++) {
//             required.push_back(capacity[i] - rocks[i]);
//         }
//         // fill the smallest required first
//         sort(required.begin(), required.end());
//         int cnt = 0;
//         for (int i = 0; i < n; i++) {
//             if (additionalRocks >= required[i]) {
//                 additionalRocks -= required[i];
//                 cnt++;
//             } else {
//                 break; // not enough rocks for this bag
//             }
//         }
//         return cnt;
//     }
// };

// L-10 

// LC - 2244 MIN ROUNDS TO COMPLETE ALL FASKS
// class Solution {
// public:
//     int minimumRounds(vector<int>& tasks) {
//         unordered_map<int ,int> mp ;
//         for(int &task : tasks)
//         {
//             mp[task]++ ;
//         }
//         int round = 0 ;
//         for(auto &it : mp)
//         {
//             int cnt = it.second ;
//             if(cnt == 1) return -1 ;
//             if(cnt % 3 == 0 )
//             {
//                 round += cnt / 3 ;
//             }
//             else
//             {
//                 round += (cnt/3) + 1 ;
//             }
//         }
//         return round ;
//     }
// };

// L-11

// LC - 1833 MAXIMUM ICE CREAM BARS 
// class Solution {
// public:
//     int maxIceCream(vector<int>& costs, int coins) {
//         sort(costs.begin() , costs.end()) ;
//         int cnt = 0 ;
//         for(int &cost : costs)
//         {
//             if(cost > coins) return cnt ;
//             else 
//             {
//                 cnt++ ; coins-= cost ; 
//             }
//         }
//         return cnt ;
//     }
// };

// L-12

// LC - 134 GAS STATION 
// class Solution {
// public:
//     int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
//         int n = gas.size();
//         for (int i = 0; i < n; i++) {
//             int currGas = 0;
//             int j = i;
//             bool valid = true;
//             do {
//                 currGas += gas[j];
//                 if (currGas < cost[j]) { // can’t move forward
//                     valid = false;
//                     break;
//                 }
//                 currGas -= cost[j];
//                 j = (j + 1) % n;
//             } while (j != i);
//             if (valid) return i;
//         }
//         return -1;
//     }
// };
// class Solution {
// public:
//     int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
//         int total = 0;   // total net gas over the whole circuit
//         int curr = 0;    // current tank balance
//         int start = 0;   // candidate starting station
//         for (int i = 0; i < gas.size(); i++) {
//             int diff = gas[i] - cost[i];
//             total += diff;
//             curr +=diff;
//             // If tank becomes negative, can't start from current "start"
//             if (curr < 0) {
//                 start = i + 1;  // reset start to next station
//                 curr = 0;       // reset tank
//             }
//         }
//         // If total gas < total cost, it's impossible
//         return total >= 0 ? start : -1;
//     }
// };

// L-13

// LC - 2405 OPTIMAL PARTIOTION OF STRINGS
// class Solution {
// public:
//     int partitionString(string s) {
//         vector<int> lastseen(26 ,-1) ;
//         int cnt = 0 ;int n = s.length() ;
//         int current_substr_start = 0 ;
//         for(int i=0 ;i<n;i++)
//         {
//             char ch = s[i] ;
//             if(lastseen[ch-'a'] >=current_substr_start)
//             {
//                 cnt++ ; current_substr_start = i ;
//             }
//             lastseen[ch-'a'] = i ;
//         }
//         return cnt+1 ;
//     }
// };

// L-14

// LC - 649 DOTA 2 SENATE
// class Solution {
// public:
//     string predictPartyVictory(string senate) {
//         int n = senate.size();
//         int countR = 0, countD = 0;
//         // Initial counts
//         for (char c : senate) {
//             if (c == 'R') countR++;
//             else countD++;
//         }
//         int banR = 0, banD = 0;
//         vector<bool> alive(n, true); // keep track of active senators
//         while (countR > 0 && countD > 0) {
//             for (int i = 0; i < n; i++) {
//                 if (!alive[i]) continue;
//                 if (senate[i] == 'R') {
//                     if (banR > 0) {
//                         // This Radiant senator is banned
//                         alive[i] = false;
//                         countR--;
//                         banR--;
//                     } else {
//                         // Radiant survives, bans a Dire senator
//                         banD++;
//                     }
//                 } else { // 'D'
//                     if (banD > 0) {
//                         // This Dire senator is banned
//                         alive[i] = false;
//                         countD--;
//                         banD--;
//                     } else {
//                         // Dire survives, bans a Radiant senator
//                         banR++;
//                     }
//                 }
//                 if (countR == 0 || countD == 0) break;
//             }
//         }
//         return countR > 0 ? "Radiant" : "Dire";
//     }
// };

//                                  STRIVER

// L-1

// LC - 455 ASSIGN COOKIES
// class Solution {
// public:
//     int findContentChildren(vector<int>& g, vector<int>& s) {
//         int n = g.size() ; int m= s.size() ;
//         int l=0 ; int r = 0 ;
//         sort(g.begin() , g.end()) ;
//         sort(s.begin() , s.end()) ;
//         while(l<m && r < n)
//         {
//             if(g[r] <= s[l]) 
//             {
//                 r++ ;
//             }
//             l++ ;
//         }
//         return r ;
//     }
// };

// L-2

// LC - 860 LEMONADE CHANGE 
// class Solution {
// public:
//     bool lemonadeChange(vector<int>& bills) {
//         int n = bills.size() ; int cntf = 0 ;int cntt = 0 ;
//         for(int i=0; i<n;i++)
//         {   
//             if(bills[i] == 5) cntf++ ;
//             if(bills[i] == 10) 
//             {   
//                 if(cntf < 1)  return false ;
//                 else cntf-=1 ;
//                 cntt++ ;
//             }
//             if(bills[i] == 20 )
//             {
//                 if(cntt && cntf ){cntt-- ; cntf-- ;}
//                 else if(cntf >=3) cntf-=3 ;
//                 else return false ;
//             }
//         }
//         return true ;
//     }
// };

// L-3

// LC - 00  SHORTEST JOB FIRST 
// fuct()
// {
//     t =0;cnt =0 ;
//     for(i = 0 -> n-1)
//     {
//         wt+=t ;
//         t+=arr[i] ;
//     }
//     return (wt/n)
// }

// L-4

// LC - 55  JUMP GAME I
// class Solution {
// public:
//     bool canJump(vector<int>& nums) {
//         int maxind = 0 ;
//         for(int i=0;i<nums.size(); i++)
//         {
//             if(i > maxind ) return false ;
//             maxind = max(maxind , nums[i] + i) ;
//         }
//         return true ;
//     }
// };

// L-5

// LC - 45 JUMP GAME II 
// class Solution {
// public:
//     int jump(vector<int>& nums) {
//         int jumps = 0, l = 0, r = 0;
//         int n = nums.size();
//         while (r < n - 1) {  // stop before last index
//             int farthest = 0;
//             for (int i = l; i <= r; i++) {
//                 farthest = max(farthest, i + nums[i]);
//             }
//             l = r + 1;
//             r = farthest;
//             jumps++;
//         }
//         return jumps;
//     }
// };

// L-6

// LC - 00 JOB SEQUENCING
// ........
// .;[;']

// 

// L-8

// LC - 435 NON OVERLAPPING INTERVALS
// class Solution {
// public:
//     static bool comp(vector<int>& a, vector<int>& b) {
//         return a[1] < b[1];  // sort by end time
//     }
//     int eraseOverlapIntervals(vector<vector<int>>& arr) {
//         sort(arr.begin(), arr.end(), comp);
//         int n = arr.size();
//         int cnt = 1;  // count of non-overlapping intervals
//         int lastendtime = arr[0][1];
//         for (int i = 1; i < n; i++) {
//             if (arr[i][0] >= lastendtime) {
//                 cnt++;
//                 lastendtime = arr[i][1];
//             }
//         }
//         return n - cnt;  // intervals to remove
//     }
// };

// L-9

// LC - 57 INSERT INTERVAL
// class Solution {
// public:
//     vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
//         vector<vector<int>> result;
//         int i = 0, n = intervals.size();
//         // 1. Add all intervals that end before newInterval starts
//         while (i < n && intervals[i][1] < newInterval[0]) {
//             result.push_back(intervals[i]);
//             i++;
//         }
//         // 2. Merge overlapping intervals with newInterval
//         while (i < n && intervals[i][0] <= newInterval[1]) {
//             newInterval[0] = min(newInterval[0], intervals[i][0]);
//             newInterval[1] = max(newInterval[1], intervals[i][1]);
//             i++;
//         }
//         result.push_back(newInterval);
//         // 3. Add remaining intervals (after newInterval ends)
//         while (i < n) {
//             result.push_back(intervals[i]);
//             i++;
//         }
//         return result;
//     }
// };

// L-11  

// LC - 678 VALID PARANTHESIS STRINGS
// class Solution {
// public:
//     bool checkValidString(string s) {
//         int min =0; int max =0 ;
//         for(int i=0;i<s.length() ;i++)
//         {
//             if(s[i]=='('){min++ ; max++ ;}
//             else if(s[i] ==')') {min-- ; max-- ;}
//             else // *
//             {
//                 min-- ;max++ ;
//             }
//             if(min < 0) min =0 ;
//             if(max < 0) return false ;
//         }
//         return (min==0) ;
//     }
// };

// L-12

// LC - 135  CANDY
// class Solution {
// public:
//     int candy(vector<int>& ratings) {
//         int sum =1;int n = ratings.size() ; int i =1;
//         while(i < n)
//         {
//             if(ratings[i]== ratings[i-1]) {sum++ ;i++;continue ;}
//             int peak = 1;
//             while(i<n && ratings[i] > ratings[i-1])
//             {peak++ ;sum+=peak;i++;}
//             int down = 1;
//             while(i<n && ratings[i] < ratings[i-1])
//             {sum+=down;down++ ;i++;}
//         //
//             if(down > peak) sum+= down -peak ;
//         }
//         return sum ;
//     }
// };



