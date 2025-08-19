//                                                  STRIVER

// L-1

// LC-225 IMPLEMENT STACK USING QUEUE
// class MyStack {
// public:
//     queue<int> que1 ;
//     queue<int> que2 ;
//     MyStack() {
//     }
//     void push(int x) {
//         que2.push(x);
//         while(!que1.empty())
//         {
//             que2.push(que1.front());
//             que1.pop() ;
//         }
//         swap(que1, que2) ; // (destination , soure) means que1 filled at end
//     }  
//     int pop() {
//         int result = que1.front() ;
//         que1.pop() ;
//         return result ;
//     }
//     int top() {
//         return que1.front() ;
//     }
//     bool empty() {
//         return que1.empty() ;
//     }
// };
// /**
//  * Your MyStack object will be instantiated and called as such:
//  * MyStack* obj = new MyStack();
//  * obj->push(x);
//  * int param_2 = obj->pop();
//  * int param_3 = obj->top();
//  * bool param_4 = obj->empty();
//  */

// LC-232 IMPLEMENT QUEUE USING STACK
// do it later

// L-2

// LC-20 VALID PARANTHESIS
    // bool isValid(string s) {
    //     stack<char> stacks ;
    //     for(int i =0 ; i < s.length() ; i++)
    //     {
    //         if(s[i]=='('|| s[i]=='{' || s[i]=='[') stacks.push(s[i]) ;
    //         else 
    //         {
    //             if(stacks.empty()) return false ;
    //             char ch = stacks.top() ;stacks.pop() ;
    //         if((s[i]==')' && ch=='(' )|| (s[i]=='}' && ch=='{') ||( s[i]==']' && ch=='[') )
    //                 continue;
    //         else return false ;
    //         }
    //     }
    //     return stacks.empty() ;
    // }

// L-3

// LC-0 EXPRESSION CONVERSION
// bool priority(char ch)
// {
// }
// void infix_to_postfix(string s)
// {
//     string ans ="" ;int i = 0 ; int n = s.length() ;stack<char> st ;  
//     while(i<n)
//     {
//         if(s[i]>='a' && s[i]<='z' || s[i]>='A' && s[i]<='Z' || 
//             s[i]>='0' && s[i]<=9) ans.push_back(s[i]) ;
//         else if(s[i] == '(') st.push(s[i]);
//         else if(s[i] == ')')
//         {
//             while(st.empty() && st.top() =='(')
//             {
//                 ans.push_back(st.top()) ; st.pop() ;
//             }
//             st.pop() ; // removing ( from stack
//         }
//         else
//         {
//             while(!st.empty() && ( priority(s[i]) <= priority(st.top()) ))
//             {   
//                 char ch = st.top() ; st.pop() ;
//                 ans.push_back(ch) ;
//             }
//             st.push(s[i]) ;
//         }
//         i++ ;
//     }
//     // empty the stack
//     while(!st.empty())
//     {
//         ans+=st.top() ; st.pop() ;
//     }
//     cout << endl ;
//     cout << "infix : " << s << endl << "prefix : " << ans ;
// }
// void infix_to_prefix(string s)
// {
//     reverse(s.begin() ,s.end()) ;
//     string ans ="" ;int i = 0 ; int n = s.length() ;stack<char> st ;  
//     while(i<n)
//     {   // alphabets
//         if(s[i]>='a' && s[i]<='z' || s[i]>='A' && s[i]<='Z' || 
//             s[i]>='0' && s[i]<=9) ans.push_back(s[i]) ;
//         // brackets
//         else if(s[i] == ')') st.push(s[i]);
//         else if(s[i] == '(')
//         {
//             while(st.empty() && st.top() ==')')
//             {
//                 ans.push_back(st.top()) ; st.pop() ;
//             }
//             st.pop() ; // removing ( from stack
//         }
//         // operators
//         else
//         {    // two ^^ cant come in stack together
//             if(s[i] == '^')
//             {
//                 while(!st.empty() && ( priority(s[i]) <= priority(st.top()) ))
//                 {   
//                     char ch = st.top() ; st.pop() ;
//                     ans.push_back(ch) ;
//                 }
//                 st.push(s[i]) ;
//             }
//             // ++ can come or -- can come because same associativity
//             // so < in place of <=
//             else
//             {
//                 while(!st.empty() && ( priority(s[i]) < priority(st.top()) ))
//                 {   
//                     char ch = st.top() ; st.pop() ;
//                     ans.push_back(ch) ;
//                 }
//                 st.push(s[i]) ;
//             }
//         }
//         i++ ;
//     }
//     // empty the stack
//     while(!st.empty())
//     {
//         ans+=st.top() ; st.pop() ;
//     }
//     // reverse
//     reverse(ans.begin() , ans.end()) ;cout << endl ;
//     cout << "infix : " << s << endl << "prefix : " << ans ;
// }
// void postfix_to_infix(string s)
// {   // stack is made to store string cause a+b can also come 
//     string ans ="" ;int i = 0 ; int n = s.length() ;stack<string> st ;  
//     while(i<n)
//     {   // alphabets
//         // operands
//         char x = s[i] ;
//         string str="" + s[i] ;
//         if(s[i]>='a' && s[i]<='z' || s[i]>='A' && s[i]<='Z' || 
//             s[i]>='0' && s[i]<=9) st.push(str) ;
//         // operator
//         else
//         {
//             string t1 = st.top() ; st.pop() ;
//             string t2 = st.top() ; st.pop() ;
//             string temp = '(' + t2 + s[i] + t1 + ')' ;
//             st.push(temp) ;
//         }
//         i++ ;
//     }
//     cout << endl ;
//     cout << "postfix : " << s << endl << "infix : " << ans ;
// }
// void prefix_to_infix(string s)
// {   // stack is made to store string cause a+b can also come 
//     string ans ="" ;int i = 0 ; int n = s.length() ;stack<string> st ;   
//     while(i<n)
//     {   // alphabets
//         // operands
//         char x = s[i] ;
//         string str="" + s[i] ;
//         if(s[i]>='a' && s[i]<='z' || s[i]>='A' && s[i]<='Z' || 
//             s[i]>='0' && s[i]<=9) st.push(str) ;
//         // operator
//         else
//         {
//             string t1 = st.top() ; st.pop() ;
//             string t2 = st.top() ; st.pop() ;
//             // just changing this
//             string temp = '(' + t1 + s[i] + t2 + ')' ;
//             st.push(temp) ;
//         }
//         i++ ;
//     }
//     cout << endl; 
//     cout << "prefix : " << s << endl << "infix : " << ans ;
// }
// void postfix_to_prefix(string s)
// {   // stack is made to store string cause a+b can also come 
//     string ans ="" ;int i = 0 ; int n = s.length() ;stack<string> st ;   
//     while(i<n)
//     {   
//         // operands
//         char x = s[i] ;
//         string str="" + s[i] ;
//         if(s[i]>='a' && s[i]<='z' || s[i]>='A' && s[i]<='Z' || 
//             s[i]>='0' && s[i]<=9) st.push(str) ;
//         // operator
//         else
//         {
//             string t1 = st.top() ; st.pop() ;
//             string t2 = st.top() ; st.pop() ;
//             // '(' + s[i] + t2 + t1 + ')'
//             string temp = s[i] +  t2 + t1  ;
//             st.push(temp) ;
//         }
//         i++ ;
//     }
//     cout<<endl ;
//     cout << "postfix : " << s << endl << "prefix : " << ans ;
// }
// void prefix_to_postfix(string s)
// {   // stack is made to store string cause a+b can also come 
//     string ans ="" ;int i = 0 ; int n = s.length() ;stack<string> st ;  
//     while(i<n)
//     {   
//         // operands
//         char x = s[i] ;
//         string str="" + s[i] ;
//         if(s[i]>='a' && s[i]<='z' || s[i]>='A' && s[i]<='Z' || 
//             s[i]>='0' && s[i]<=9) st.push(str) ;
//         // operator
//         else
//         {
//             string t1 = st.top() ; st.pop() ;
//             string t2 = st.top() ; st.pop() ;
//             // '(' + s[i] + t2 + t1 + ')' 
//             string temp =  s[i]+  t2 + t1;
//             st.push(temp) ;
//         }
//         i++ ;
//     }
//     cout<<endl ;
//     cout << "prefix : " << s << endl << "postfix : " << ans ;
// }
// int main()
// {
//     vector<int> nums = {1,2,3,4,5} ;
//     string expression = "A+B*(C^D-E)" ;
//     infix_to_postfix(expression) ;
//     infix_to_prefix(expression) ;
//     postfix_to_infix(expression) ;
//     prefix_to_infix(expression) ;
//     postfix_to_prefix(expression) ;
//     prefix_to_postfix(expression) ;
//     return 0;
// }

// L-4

// LC-155 MIN STACK
// minstack
// optimal
// stack<int> st ; int min ;
//     MinStack(){   
//     }  
//     void push(int val) {
//         if(st.empty()) {    st.push(val) ; min = val ; }
//         else
//         {
//             if(val > min){ st.push(val) ;}
//             else // val < min
//             {   
//                 st.push(2*val - min) ;
//                 min =val ;
//             }
//         }
//     }
//     void pop() {
//         if(st.empty()) return ;
//         int x = st.top() ;
//         st.pop() ;
//         if(x < min) min = 2*min - x ;
//     }
//     int top() {
//         // if(st.empty()) return ;
//         int x = st.top() ;
//         if(min < x) return x ;
//         else return min ;
//     }
//     int getMin() {
//         return min ;
//     }
// brute
// class MinStack {
// public:
//    stack<pair<int,int>>st;
//     MinStack() {      
//     }
//     void push(int val) {
//         if(st.empty()){
//             st.push({val,val});
//         }
//         else {
//             st.push({val,min(val,st.top().second)});
//         }
//     }  
//     void pop() {
//         int el=st.top().first;
//         st.pop();      
//     }  
//     int top() {
//         return st.top().first;
//     }   
//     int getMin() {
//         return st.top().second;
//     }
// };

// L-5

// LC-496 NEXT GREATER ELEMENT
// if only nums1 given 
    // vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    //     // nge = next greater element
    //     vector<int> nge(nums.size()) ; stack<int> st ;
    //     for(int i = nums.size() ; i>=0 ; i--)
    //     {    
    //         while(!st.empty() && st.top() < nums[i]) st.pop() ;         
    //         if(st.empty()) nge[i] = -1 ;
    //         else nge[i] = st.top() ;
    //         st.push(nums[i]) ;
    //     }
    //     return nge ;
    // }
// if nums1 and nums2 both given
    // vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    //     // nge = next greater element
    //     unordered_map<int,int> mp ;
    //     stack<int> st ;
    //     vector<int> res ;
    //     for(int i = nums2.size()-1 ; i>=0 ; i--)
    //     {    
    //         while(!st.empty() && st.top() < nums2[i]) st.pop() ;  
    //         if(st.empty()) 
    //             mp[nums2[i]] = -1 ;        
    //         else mp[nums2[i]] = st.top() ;
    //         st.push(nums2[i]) ;
    //     }
    //     for(int i = 0  ; i < nums1.size() ; i++)
    //     {
    //         res.push_back(mp[nums1[i]]) ;
    //     }
    //     return res ;
    // }
// L-6

// L-6

// LC-503 NEXT GREATER ELEMENT II
// class Solution {
// public:
//     vector<int> nextGreaterElements(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> res(n, -1);
//         stack<int> st;
//         // Traverse twice: simulate circular array
//         for (int i = 2 * n - 1; i >= 0; --i) {
//             int curr = nums[i % n];
//             // Pop smaller or equal elements
//             while (!st.empty() && st.top() <= curr) {
//                 st.pop();
//             }
//             // Set result only during the first pass
//             if (i < n) {
//                 if (!st.empty()) {
//                     res[i] = st.top();
//                 }
//             }
//             st.push(curr);
//         }
//         return res;
//     }
// };

// L-7

// LC-0 PREVIOUS SMALLER ELEMENT
// same approach ha NGE

// l-8

// LC-42 TRAPPING RAIN WATER
//vector<int>getlm(vector<int>& height,int &n){
    //     vector<int>lm (n);
    //     lm[0]=height[0];
    //     for(int i=1;i<n;i++){
    //         lm[i]=max(lm[i-1],height[i]);
    //     }
    //     return lm;
    // }
    //     vector<int>getrm(vector<int>& height,int &n){
    //     vector<int>rm (n);
    //     rm[n-1]=height[n-1];
    //     for(int i=n-2;i>=0;i--){
    //         rm[i]=max(rm[i+1],height[i]);
    //     }
    //     return rm;
    // }
    // int trap(vector<int>& height) {
    //     int n = height.size();
    //     vector<int>lm=getlm(height,n);
    //     vector<int>rm=getrm(height,n);
    //     int sum=0;
    //     for(int i=0;i<n;i++){
    //         int h = min(lm[i],rm[i])-height[i];
    //         sum+=h;
    //     }
    //     return sum;

// L-9

// LC-907 SUM OF SUBARRAY MINIMUM
// class Solution {
// public:
//     vector<int> nextSmallerOrEqual(vector<int>& arr) {
//         int n = arr.size();
//         vector<int> nse(n);
//         stack<int> st;
//         for (int i = n - 1; i >= 0; i--) {
//             while (!st.empty() && arr[st.top()] >= arr[i]) st.pop();
//             nse[i] = st.empty() ? n : st.top();  // Next smaller or equal to the right
//             st.push(i);
//         }
//         return nse;
//     }
//     vector<int> prevSmaller(vector<int>& arr) {
//         int n = arr.size();
//         vector<int> pse(n);
//         stack<int> st;
//         for (int i = 0; i < n; i++) {
//             while (!st.empty() && arr[st.top()] > arr[i]) st.pop();
//             pse[i] = st.empty() ? -1 : st.top();  // Previous strictly smaller
//             st.push(i);
//         }
//         return pse;
//     }
//    int sumSubarrayMins(vector<int>& arr) {
//         int mod = 1e9 + 7;
//         int n = arr.size();
//         vector<int> next = nextSmallerOrEqual(arr);
//         vector<int> prev = prevSmaller(arr);
//         long total = 0;
//         for (int i = 0; i < n; i++) {
//             long left = i - prev[i];
//             long right = next[i] - i;
//             total = (total + arr[i] * left % mod * right % mod) % mod;
//         }
//         return (int)total;
//     }
// };

// L-1O

// LC-2104 SUM OF SUBARRAY RANGES
// class Solution {
// public:
// // SUBARRAY MINS
//     vector<int> nextSmallerOrEqual(vector<int>& arr) {
//         int n = arr.size();
//         vector<int> nse(n);
//         stack<int> st;
//         for (int i = n - 1; i >= 0; i--) {
//             while (!st.empty() && arr[st.top()] >= arr[i]) st.pop();
//             nse[i] = st.empty() ? n : st.top();  
//             // Next smaller or equal to the right
//             st.push(i);
//         }
//         return nse;
//     }
//     vector<int> prevSmaller(vector<int>& arr) {
//         int n = arr.size();
//         vector<int> pse(n);
//         stack<int> st;
//         for (int i = 0; i < n; i++) {
//             while (!st.empty() && arr[st.top()] > arr[i]) st.pop();
//             pse[i] = st.empty() ? -1 : st.top();  // Previous strictly smaller
//             st.push(i);
//         }
//         return pse;
//     }
//     long long sumSubarrayMins(vector<int>& arr) {
//         //int mod = 1e9 + 7; 
//         int n = arr.size();
//         vector<int> next = nextSmallerOrEqual(arr);
//         vector<int> prev = prevSmaller(arr);
//         long long total = 0;
//         for (int i = 0; i < n; i++) {
//             long left = i - prev[i];
//             long right = next[i] - i;
//             total = (total + arr[i] * left  * right );
//         }
//         return total;
//     }
// // SUBARRAY MAXS
//     vector<int> nextgreaterOrEqual(vector<int>& arr) {
//         int n = arr.size();
//         vector<int> nge(n);
//         stack<int> st;
//         for (int i = n - 1; i >= 0; i--) {
//             while (!st.empty() && arr[st.top()] <= arr[i]) st.pop();
//             nge[i] = st.empty() ? n : st.top();  
//             // Next greater or equal to the right
//             st.push(i);
//         }
//         return nge;
//     }
//     vector<int> prevgreater(vector<int>& arr) {
//         int n = arr.size();
//         vector<int> pge(n);
//         stack<int> st;
//         for (int i = 0; i < n; i++) {
//             while (!st.empty() && arr[st.top()] < arr[i]) st.pop();
//             pge[i] = st.empty() ? -1 : st.top();  
//             // Previous strictly greater
//             st.push(i);
//         }
//         return pge;
//     }
//     long long sumSubarrayMaxs(vector<int>& arr) {
//         //int mod = 1e9 + 7; 
//         int n = arr.size();
//         vector<int> next = nextgreaterOrEqual(arr);
//         vector<int> prev = prevgreater(arr);
//         long long total = 0;
//         for (int i = 0; i < n; i++) {
//             long left = i - prev[i];
//             long right = next[i] - i;
//             total = (total + arr[i] * left  * right );
//         }
//         return total;
//     }
//     long long subArrayRanges(vector<int>& nums) {
//             return sumSubarrayMaxs(nums) - sumSubarrayMins(nums) ;
//     }
// };

// L-11 

// LC-735 AESTROID COLLISION 
// class Solution {
// public:
//     vector<int> asteroidCollision(vector<int>& asteroids) {
//         stack<int> st;
//         for (int i = 0; i < asteroids.size(); i++) {
//             int x = asteroids[i];
//             // If current asteroid is moving right or stack is empty or top is negative (same direction)
//             if (x >= 0) {
//                 st.push(x);
//             } else {
//                 while (!st.empty() && st.top() > 0 && st.top() < abs(x)) {
//                     st.pop();  // Right asteroid explodes
//                 }
//                 // If both are same size, both explode
//                 if (!st.empty() && st.top() == abs(x)) {
//                     st.pop();  // Both explode, don't push x
//                 }
//                 // If stack is empty or top is negative, then push x
//                 else if (st.empty() || st.top() < 0) {
//                     st.push(x);
//                 }
//                 // else: top is larger, left-moving x explodes (do nothing)
//             }
//         }
//         // Transfer stack to result
//         vector<int> ans;
//         while (!st.empty()) {
//             ans.push_back(st.top());
//             st.pop();
//         }
//         reverse(ans.begin(), ans.end());
//         return ans;
//     }
// };

// L-12

// LC-84 LARGEST RECTANGLE IN HISTOGRAM
// class Solution {
// public:
// // SUBARRAY MINS
//     vector<int> nextSmallerOrEqual(vector<int>& arr) {
//         int n = arr.size();
//         vector<int> nse(n);
//         stack<int> st;
//         for (int i = n - 1; i >= 0; i--) {
//             while (!st.empty() && arr[st.top()] >= arr[i]) st.pop();
//             nse[i] = st.empty() ? n : st.top();  
//             // Next smaller or equal to the right
//             st.push(i);
//         }
//         return nse;
//     }
//     vector<int> prevSmaller(vector<int>& arr) {
//         int n = arr.size();
//         vector<int> pse(n);
//         stack<int> st;
//         for (int i = 0; i < n; i++) {
//             while (!st.empty() && arr[st.top()] > arr[i]) st.pop();
//             pse[i] = st.empty() ? -1 : st.top();  // Previous strictly smaller
//             st.push(i);
//         }
//         return pse;
//     }
//     int largestRectangleArea(vector<int>& arr) {
//         int n = arr.size();int maxi = 0 ;
//         vector<int> next = nextSmallerOrEqual(arr);
//         vector<int> prev = prevSmaller(arr);
//         for(int i = 0 ; i< n ; i++)
//         {
//             maxi = max(maxi , arr[i]*(next[i]- prev[i] - 1)) ;
//         }
//         return maxi ;
//     }
// };
// class Solution {
// public:
//     int largestRectangleArea(vector<int>& arr) {
//         stack<int> st ; int max_area = 0 ;
//         for(int i = 0 ; i<arr.size(); i++)
//         {   // pushing index in stack
//             while(!st.empty() && arr[st.top()] > arr[i])
//             {
//                 int element = st.top() ; st.pop() ;
//                 int nse = i ;
//                 int pse = st.empty() ?-1:st.top() ;
//                 max_area = max(max_area,arr[element]*(nse-pse-1));
//             }
//             st.push(i);
//         }
//         // if stack is not empty
//         while(!st.empty())
//         {
//             int nse = arr.size();
//             int element = st.top() ; st.pop() ;
//             int pse = st.empty() ? -1 :st.top() ;
//             max_area = max(max_area ,arr[element]*(nse - pse - 1));
//         }
//         return max_area ;
//     }
// };

// L-13

// LC-85 MAXIMAL RECTANGLE
// class Solution {
// public:
//     int largestRectangleArea(vector<int>& arr) {
//         stack<int> st;
//         int max_area = 0;
//         for (int i = 0; i < arr.size(); i++) {
//             while (!st.empty() && arr[st.top()] > arr[i]) {
//                 int element = st.top(); st.pop();
//                 int nse = i;
//                 int pse = st.empty() ? -1 : st.top();
//                 max_area = max(max_area, arr[element] * (nse - pse - 1));
//             }
//             st.push(i);
//         }
//         while (!st.empty()) {
//             int element = st.top(); st.pop();
//             int nse = arr.size();
//             int pse = st.empty() ? -1 : st.top();
//             max_area = max(max_area, arr[element] * (nse - pse - 1));
//         }
//         return max_area;
//     }
//     int maximalRectangle(vector<vector<char>>& matrix) {
//         if (matrix.empty()) return 0;
//         int n = matrix.size(), m = matrix[0].size();
//         vector<vector<int>> presum(n, vector<int>(m, 0));
//         int max_area = 0;
//         // Fill presum matrix (histogram)
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < m; j++) {
//                 if (matrix[i][j] == '1') {
//                     presum[i][j] = (i == 0) ? 1 : presum[i - 1][j] + 1;
//                 }
//             }
//         }
//         // For each row, treat it as histogram
//         for (int i = 0; i < n; i++) {
//             max_area = max(max_area, largestRectangleArea(presum[i]));
//         }
//         return max_area;
//     }
// };

// L-14

// LC-402 REMOVE K DIGITS
// class Solution {
// public:
//     string removeKdigits(string num, int k) {
//         stack<char> st ;
//         for(int i = 0; i< num.size() ;i++)
//         {
//             while(!st.empty() && k>0 && ( st.top()-'0' ) > (num[i] -'0') )
//             { st.pop() ; k-- ;}
//             st.push(num[i]); 
//         }
//         while(k>0) { st.pop() ; k--;}
//         if(st.empty()) return "0" ;
//         string res= "" ;
//         while(!st.empty())
//         {   
//             res += st.top() ;
//             st.pop() ;
//         }
//         // zeroes will be in end of stack and res both
//         while(res.length() != 0 && res.back()=='0')
//         {
//             res.pop_back() ;
//         }
//         reverse(res.begin() , res.end()) ;
//         if(res.empty() ) return "0" ;
//         return res ;
//     }
// };

// L-15 

// LC-901 STOCK SPAN PROBLEM
// class StockSpanner {
// public:
// stack<pair<int, int>> st ;
// int ind = - 1; 
//     StockSpanner() {
//        ind = -1 ;
//           while (!st.empty()) {
//         st.pop();
//     }
//     }
//     int next(int price) {
//         ind++;int ans ;
//         while(!st.empty() && st.top().first <= price) st.pop() ;      
//         ans = ind - (st.empty() ? -1 : st.top().second) ;
//         st.push({price , ind}) ;
//         return ans ;
//     }
// };
// /**
//  * Your StockSpanner object will be instantiated and called as such:
//  * StockSpanner* obj = new StockSpanner();
//  * int param_1 = obj->next(price);
//  */

// L-16 

// LC-239 SLIDING WINDOEW MAXIMUM

// L-17

// LC-0 THE CELEBRITY PROBLEM

// L-18

// LC-0 IMPLEMENT LRU CACHE

