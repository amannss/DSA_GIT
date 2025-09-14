//                                  STRIVER

// LC - 104 MAXIMUM DEPTH OF BINARY TREE
// class Solution {
// public:
// void levelorder(int &count , TreeNode* root)
// {   
//     if(root == NULL ) return ;
//     queue<TreeNode*> q ;
//     q.push(root) ; q.push(NULL) ;
//     while(!q.empty())
//     {   
//         TreeNode* temp = q.front() ; q.pop() ;
//         if(temp == NULL) 
//         {
//             count++ ;
//             if(!q.empty()) q.push(NULL) ; 
//         }
//         else
//         {   
//             if(temp->left)  q.push(temp->left) ;
//             if(temp->right) q.push(temp->right) ;
//         }
//     }
// }
//     int maxDepth(TreeNode* root) {
//         int count = 0 ; 
//         levelorder(count, root) ;
//         return count ;
//     }
// };

// L-1

// LC - 00  INTRODUCTION TO TREE
// basics of treee

// L-2

// LC - 00  BINARY TREE REPRESENTATION
// in c++

// L-3

// LC - 00  BINARY TREE REPRESENTATION
// in java

// L-4

// LC - 144 PREORDER TRAVERSAL
// class Solution {
// public:
// void inorder(vector<int> &vec , TreeNode* root)
// {   
//     if(root == NULL ) return ;
//     vec.push_back(root->val) ;
//     inorder(vec , root->left );
//     inorder(vec , root->right );
// }
//     vector<int> preorderTraversal(TreeNode* root) {
//         vector<int> vec ;
//         inorder(vec,root) ;
//         return vec ;
//     }
// };

// L-5

// LC - 94 INORDER TRAVERSAL
// class Solution {
// public:
// void preorder(vector<int> &vec , TreeNode* root)
// {   
//     if(root == NULL ) return ;
//     preorder(vec , root->left );
//     vec.push_back(root->val) ;
//     preorder(vec , root->right );
// }
//     vector<int> inorderTraversal(TreeNode* root) {
//         vector<int> vec ;
//         preorder(vec,root) ;
//         return vec ;
//     }
// };

// L-6

// LC - 145 POSTORDER TRAVERSAL
// class Solution {
// public:
// void postorder(vector<int> &vec , TreeNode* root)
// {   
//     if(root == NULL ) return ;
//     postorder(vec , root->left );
//     postorder(vec , root->right );
//     vec.push_back(root->val) ;
// }
//     vector<int> postorderTraversal(TreeNode* root) {
//         vector<int> vec ;
//         postorder(vec,root) ;
//         return vec ;
//     }
// };

// L-7

// LC - 102 LEVEL ORDER TRAVERSAL
// class Solution {
// public:
// void levelorder(vector<vector<int>> &vec , TreeNode* root)
// {   
//     if(root == NULL ) return ;
//     queue<TreeNode*> q ;
//     q.push(root) ; q.push(NULL) ;
//     vector<int> s ;
//     while(!q.empty())
//     {   
//         TreeNode* temp = q.front() ; q.pop() ;
//         if(temp !=NULL) s.push_back(temp->val) ;
//         if(temp == NULL) 
//         {
//             vec.push_back(s) ;
//             s.clear() ;
//             if(!q.empty()) q.push(NULL) ; 
//         }
//         else
//         {   
//             if(temp->left)  q.push(temp->left) ;
//             if(temp->right) q.push(temp->right) ;
//         }
//     }
// }
//     vector<vector<int>> levelOrder(TreeNode* root) {
//         vector<vector<int>> vec; 
//         levelorder(vec , root) ;
//         return vec ;
//     }
// };

// L-13

// LC - 00  PREORDER INORDER POSTORDER IN ONE TRAVERSAL
//
//

// L-14

// LC - 104 MAXIMUM DEPTH IN BT
// class Solution {
// public:
// int inorder(TreeNode* root)
// {   
//     if(root == NULL ) return 0 ;
//     int x = inorder(root->left) ; 
//     int y = inorder(root->right) ;
//     return max(x,y) + 1;
// }
//     int maxDepth(TreeNode* root) {
//         return inorder(root) ;
//     }
// };

// L-15

// LC - 110 BALANCED BINARY TREE
// class Solution {
// public:
// bool check = true ;
// int inorder(TreeNode* root)
// {   
//     if(root == NULL ) return 0 ;
//     int x = inorder(root->left) ; 
//     int y = inorder(root->right) ;
//     if(abs(x-y) > 1) check= false; 
//     return max(x,y) + 1;
// }
//     bool isBalanced(TreeNode* root) {
//         inorder(root) ;
//         return check ;
//     }
// };

// L-16

// LC - 543 DIAMETER OF BT
// class Solution {
// public:
//     int diameterOfBinaryTree(TreeNode* root) {
//         int diameter = 0 ;
//         height(root , diameter) ;
//         return diameter ;
//     }
// private:
//     int height(TreeNode* node , int & diameter)
//     {
//         if(!node) return 0;
//         int lh = height(node->left,diameter) ; 
//         int rh = height(node->right,diameter) ; 
//         diameter = max(diameter , lh + rh) ;
//         return 1+max(lh,rh) ;
//     }
// };

// L-17

// LC - 124 MAXIMUM PATH SUM IN BT
// class Solution {
// public:
//     int maxPathSum(TreeNode* root) {
//         int maxi = INT_MIN ;
//         maxpath(root , maxi) ;
//         return maxi ;
//     }
//     int maxpath(TreeNode* node,int  &maxi)
//     {
//         if(node == NULL) return 0;
//         int l = max(0 , maxpath(node->left , maxi)) ;
//         int r = max(0 , maxpath(node->right , maxi)) ;
//         maxi = max(maxi, l+r+node->val) ;
//         return max(l,r) + node->val ;
//     }
// };

// L-18 

// LC - 100 SAME TREE
// class Solution {
// public:
// bool x= true ;
// void check(TreeNode* p, TreeNode* q)
// {
//     if(p ==NULL && q == NULL) return ;
//     if(p==NULL || q==NULL){x = false; return ;}
//     if(p->val != q->val)  { x = false ; return ; }
//     check(p->left,q->left) ;
//     check(p->right,q->right) ;
// }
//     bool isSameTree(TreeNode* p, TreeNode* q) {
//         check(p,q) ;
//         return x ;
//     }
// };

// L-19 

// LC - 103 BT ZIGZAG LEVEL ORDER TRAVERSAL
// class Solution {
// public:
//     vector<vector<int>> res;
//     vector<int> vec;
//     void funct(TreeNode* node, vector<vector<int>> &res) {
//         if (node == NULL) return;   // ✅ handle empty tree
//         queue<TreeNode*> q;
//         q.push(node);
//         q.push(NULL);
//         while (!q.empty()) {
//             TreeNode* temp = q.front();
//             q.pop();
//             if (temp != NULL) {
//                 vec.push_back(temp->val);
//                 if (temp->left)  q.push(temp->left);
//                 if (temp->right) q.push(temp->right);
//             } else {
//                 if (res.size() % 2 == 0) res.push_back(vec);
//                 else {
//                     reverse(vec.begin(), vec.end());
//                     res.push_back(vec);
//                 }
//                 vec.clear();
//                 if (!q.empty()) q.push(NULL);
//             }
//         }
//     }
//     vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
//         res.clear();   // ✅ clear global before use
//         vec.clear();
//         funct(root, res);
//         return res;
//     }
// };

// L-20

// LC - 545 BOUNDARY TRAVERSAL OF BT
// void addLeftBoundary(Node* root, vector<int> &res) {
//     Node* cur = root->left;
//     while (cur) {
//         if (!isLeaf(cur)) res.push_back(cur->data);
//         if (cur->left) cur = cur->left;
//         else cur = cur->right;
//     }
// }
// void addRightBoundary(Node* root, vector<int> &res) {
//     Node* cur = root->right;
//     vector<int> tmp;
//     while (cur) {
//         if (!isLeaf(cur)) tmp.push_back(cur->data);
//         if (cur->right) cur = cur->right;
//         else cur = cur->left;
//     }
//     for (int i = tmp.size()-1; i >= 0; --i) {
//         res.push_back(tmp[i]);
//     }
// }
// void addLeaves(Node* root, vector<int>& res) {
//     if (isLeaf(root)) {
//         res.push_back(root->data);
//         return;
//     }
//     if (root->left) addLeaves(root->left, res);
//     if (root->right) addLeaves(root->right, res);
// }
// public:
// vector<int> printBoundary(Node *root) {
//     vector<int> res;
//     if (!root) return res;
//     if (!isLeaf(root)) res.push_back(root->data);
//     addLeftBoundary(root, res);
//     addLeaves(root, res);
//     addRightBoundary(root, res);
//     return res;
// }

// L-21

// LC - 987 VERTICAL ORDER TRAVERSAL
// class Solution {
// public:
//     vector<vector<int>> verticalTraversal(TreeNode* root) {
//         map<int, map<int, multiset<int>>> nodes; 
//         queue<pair<TreeNode*, pair<int,int>>> todo;
//         // BFS with coordinates (x=vertical, y=level)
//         /todo.push({root,{0,0}});
//         while(!todo.empty()) {
//             auto p = todo.front(); todo.pop();
//             TreeNode* node = p.first;
//             int x = p.second.first;   // vertical index
//             int y = p.second.second;  // level (depth)
//             nodes[x][y].insert(node->val);
//             if(node->left)  todo.push({node->left,  {x-1, y+1}});
//             if(node->right) todo.push({node->right, {x+1, y+1}});
//         }
//         vector<vector<int>> ans;
//         for(auto &p : nodes) {
//             vector<int> col;
//             for(auto &q : p.second) {
//                 col.insert(col.end(), q.second.begin(), q.second.end());
//             }
//             ans.push_back(col);
//         }
//         return ans;
//     }
// };

// L-22

// LC - 00  TOP VIEW OF BT
// class Solution {
//   public:
//     // Function to return a list of nodes visible from the top view
//     // from left to right in Binary Tree.
//     vector<int> topView(Node *root) {
//         // code here
//         vector<int> ans ;
//         if(root== NULL) return ans ;
//         map<int,int> mp ;
//         queue<pair<Node* , int>> q ;
//         q.push({root,0}) ;
//         while(!q.empty())
//         {
//             auto it = q.front() ; q.pop() ;
//             Node* node = it.first ;
//             int line=it.second ;
//             if(mpp.find(line)== mo.end())
//             {
//                 mpp[line] = node->val ;
//             }
//             if(node->left !=NULL) q.push({node->left , line-1}) ;
//             if(node->right!=NULL) q.push({node->right, line+1}) ;
//         }
//         for(auto it : mp) ans.push_back(it.second) ;
//         return ans ;
//     }
// };

// L-23

// LC - 00  BOTTOM VIEW OF BT

// L-24

// LC - 199 RIGHT-LEFT VIEW OF BT

// L-25

// LC - 101 SYMMETRIC BT
// class Solution {
// public:
// bool trees(TreeNode* p ,TreeNode* q)
// {
//     if(p==NULL || q==NULL) return p == q ;
//     return (p->val == q->val) &&
//     trees(p->left , q->right) &&
//     trees(p->right,q->left) ; 
// }
//     bool isSymmetric(TreeNode* root) {
//         if(root == NULL) return false ;
//         return trees(root->left , root->right) ;
//     }
// };

// L-26

// LC - 00  PRINT ROOT TO NODE PATH
// bool getpath(TreeNode* root , vector<int> &arr,int x)
// {
//     if(!root) return false ;
//     arr.push_back(root->val);
//     if(root->val == x) return true; 
//     if(getpath(root->left,arr,x) || 
//        getpath(root->right,arr,x)) return true ;
//     arr.pop_back() ;
//     return false ;
// }
// vector<int> solution::aolve(TreeNode* A ,int B)
// {
//     vector<int> arr ;
//     if(A==NULL) return arr ;
//     getpath(A,arr,B) ;
//     return arr ;
// }

// L-27

// LC - 27  LOWEST COMMON ANSCESTOR
// class Solution {
// public:
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         if(root == NULL || root == p || root == q)
//         {
//             return root ;
//         }
//         TreeNode* left = lowestCommonAncestor(root->left,p,q);
//         TreeNode* right= lowestCommonAncestor(root->right,p,q);
//         //
//         if(left == NULL) return right ;
//         else if(right==NULL) return left ;
//         // when both not null means found
//         else return root ;
//     }
// };

// L-28

// LC - 662 MAXIMUM WIDTH OF BT
// class Solution {
// public:
//     int widthOfBinaryTree(TreeNode* root) {
// if (!root) return 0;
// long long ans = 0;
// queue<pair<TreeNode*, long long>> q;  // use long long
// q.push({root, 0});
// while (!q.empty()) {
//     int size = q.size();
//             long long mini = q.front().second;
//             long long first = 0, last = 0;
//             for (int i = 0; i < size; i++) {
//                 long long cur_id = q.front().second - mini; // normalize
//                 TreeNode* node = q.front().first;
//                 q.pop();
//                 if (i == 0) first = cur_id;
//                 if (i == size - 1) last = cur_id;
//                 if (node->left)  q.push({node->left,  cur_id * 2 + 1});
//                 if (node->right) q.push({node->right, cur_id * 2 + 2});
//             }
//             ans = max(ans, last - first + 1);
//         }
//         return (int)ans;
//     }
// };

// L-29

// LC - 00 CHILDREN SUM PROPERTY 
// void changetree(bt<int> root)
// {
//     if(rott == NULL) return ;
//     int child = 0 ;
//     if(root->left)
//     {
//         child += root->left->data ;
//     }
//     if(root->right)
//     {
//         child+= root->right->data ;
//     }
//     if(child >= root->data) root->data = child ;
//     else
//     {
//         if(root->left) root->left->data = root->data ;
//         if(root->right) root->data->data=root->data ;
//     }
//     changetree(root->left) ;
//     changetree(root->right);
//     int tot = 0;
//     if(root->left) tot+=root->left->data;
//     if(root->right) tot+=root->right->data;
//     if(root->left || root->right ) root->data = tot ;
// }

// L-30

// LC - 863 PRINT ALL NODES AT DISTANCE OF K IN BT
// class Solution {
// public:
//     unordered_map<TreeNode*, TreeNode*> parent;
//     void inorder(TreeNode* root) {
//         if (!root) return;
//         if (root->left) {
//             parent[root->left] = root;
//             inorder(root->left);
//         }
//         if (root->right) {
//             parent[root->right] = root;
//             inorder(root->right);
//         }
//     }
//     vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
//         inorder(root);
//         queue<TreeNode*> q;
//         unordered_set<TreeNode*> visited;
        // q.push(target);
        // visited.insert(target);
        // int level = 0;
        // while (!q.empty()) {
        //     int n = q.size();
        //     if (level == k) break;
        //     for (int i = 0; i < n; i++) {
        //         TreeNode* curr = q.front(); q.pop();
        //         if (curr->left && !visited.count(curr->left)) {
        //             q.push(curr->left);
                    // visited.insert(curr->left);
//                 }
//                 if (curr->right && !visited.count(curr->right)) {
//                     q.push(curr->right);
//                     visited.insert(curr->right);
//                 }
//                 if (parent.count(curr) && !visited.count(parent[curr])) {
//                     q.push(parent[curr]);
//                     visited.insert(parent[curr]);
//                 }
//             }
//             level++;
//         }
//         vector<int> result;
//         while (!q.empty()) {
//             result.push_back(q.front()->val);
//             q.pop();
//         }
//         return result;
//     }
// };

// L-31

// LC - 2385 MIN TIME TAKEN TO BURN BT
// class Solution {
// public:
//     unordered_map<TreeNode*, TreeNode*> parent;
//     void inorder(TreeNode* root) {
//         if (!root) return;
//         if (root->left) {
//             parent[root->left] = root;
//             inorder(root->left);
//         }
//         if (root->right) {
//             parent[root->right] = root;
//             inorder(root->right);
//         }
//     }
//     TreeNode* findNode(TreeNode* root, int start) {   // helper to find start node
//         if (!root) return NULL;
//         if (root->val == start) return root;
//         TreeNode* left = findNode(root->left, start);
//         if (left) return left;
//         return findNode(root->right, start);
//     }
//     int distanceK(TreeNode* root, int start) {
//         TreeNode* startNode = findNode(root, start);   // ✅ find the node to start BFS
//         queue<TreeNode*> q;
//         unordered_set<TreeNode*> visited;
//         q.push(startNode);
//         visited.insert(startNode);
//         int level = 0;
//         while (!q.empty()) {
//             int n = q.size();
//             for (int i = 0; i < n; i++) {
//                 TreeNode* curr = q.front(); q.pop();
//                 if (curr->left && !visited.count(curr->left)) {
//                     q.push(curr->left);
//                     visited.insert(curr->left);
//                 }
//                 if (curr->right && !visited.count(curr->right)) {
//                     q.push(curr->right);
//                     visited.insert(curr->right);
//                 }
//                 if (parent.count(curr) && !visited.count(parent[curr])) {
//                     q.push(parent[curr]);
//                     visited.insert(parent[curr]);
//                 }
//             }
//             if (!q.empty()) level++;  // ✅ increase level only if next layer exists
//         }
//         return level;
//     }
//     int amountOfTime(TreeNode* root, int start) {
//         inorder(root);
//         return distanceK(root, start);
//     }
// };

// L-32

// LC - 222 COUNT TOTAL NODES IN A COMPLETE BT
// int cnt =0;
// void  size(TreeNode* root)
// {
//     if(!root) return ;
//     size(root->left) ;
//     cnt++ ;
//     size(root->right) ;
// }
//     int countNodes(TreeNode* root) {
//         size(root) ;
//         return cnt ;    
//     }
// };

// L-33

// LC - 00 REQUIRMENT NEEDED TO CONSTRUCT A UNIQUE BT 
// question on gfg

// L-34

// LC - 105 CONSTRUCT BT FROM PREORDER AND INORDER
// class Solution {
// public:
//     TreeNode* make(vector<int>& preorder, vector<int>& inorder, int start, int end, int& idx) {
//         if (start > end) return NULL;
//         int rootval = preorder[idx];   // root comes from preorder
//         int i = start;
//         for (; i <= end; i++) {
//             if (inorder[i] == rootval) break; // find root in inorder
//         }
//         idx++;
//         TreeNode* root = new TreeNode(rootval);
//         root->left = make(preorder, inorder, start, i - 1, idx);
//         root->right = make(preorder, inorder, i + 1, end, idx);
//         return root;
//     }
//     TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
//         int idx = 0;
//         int n = preorder.size();
//         return make(preorder, inorder, 0, n - 1, idx);
//     }
// };

// L-35

// LC - 106 CONSTRUCT BT FROM POSTORDER AND INORDER
// class Solution {
// public:
//     TreeNode* solve(vector<int>& inorder ,vector<int>& postorder ,
//                     int instart,int inend,int poststart,int postend)
//     {
//         if (instart > inend || poststart > postend) return NULL;
//         TreeNode* root = new TreeNode(postorder[postend]) ;
//         // find index of root in inorder
//         int i = instart;
//         for (; i <= inend; i++) {
//             if (inorder[i] == root->val) break;
//         }
//         int leftsize = i - instart;
//         int rightsize = inend - i;
//         root->left  = solve(inorder, postorder, instart, i-1, poststart, poststart + leftsize - 1);
//         root->right = solve(inorder, postorder, i+1, inend, postend - rightsize, postend - 1);
//         return root;
//     }
//     TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
//         int n = inorder.size();
//         return solve(inorder, postorder, 0, n-1, 0, n-1);
//     }
// };

// L-36

// LC - 297 SERIALIZE AND DESERIALIZE BT
// class Codec {
// public:
//     // Encodes a tree to a single string.
//     string serialize(TreeNode* root) {
//         if (!root) return "";
//         queue<TreeNode*> q;
//         q.push(root);
//         string s = "";
//         while (!q.empty()) {
//             TreeNode* curr = q.front();
//             q.pop();
//             if (curr == NULL) {
//                 s.append("#,");
//             } else {
//                 s.append(to_string(curr->val) + ',');
//                 q.push(curr->left);
//                 q.push(curr->right);
//             }
//         }
//         return s;
//     }
//     // Decodes your encoded data to tree.
//     TreeNode* deserialize(string data) {
//         if (data.size() == 0) return NULL;
//         stringstream s(data);
//         string str;
//         getline(s, str, ',');
//         TreeNode* root = new TreeNode(stoi(str));
//         queue<TreeNode*> q;
//         q.push(root);
//         while (!q.empty()) {
//             TreeNode* node = q.front();
//             q.pop();
//             // left child
//             if (getline(s, str, ',')) {
//                 if (str == "#") {
//                     node->left = NULL;
//                 } else {
//                     TreeNode* leftNode = new TreeNode(stoi(str));
//                     node->left = leftNode;
//                     q.push(leftNode);
//                 }
//             }
//             // right child
//             if (getline(s, str, ',')) {
//                 if (str == "#") {
//                     node->right = NULL;
//                 } else {
//                     TreeNode* rightNode = new TreeNode(stoi(str));
//                     node->right = rightNode;
//                     q.push(rightNode);
//                 }
//             }
//         }
//         return root;
//     }
// };

// L-37

// LC - 94 MORRISS TRAVERSAL
// it doesnt uses reccursion so no use of stack hence space complexity O(1)

// L-38

// LC - 114 FLATTEN A BT
//class Solution {
// public:
// TreeNode* prev = NULL ;
//     void flatten(TreeNode* node) {   
//         if(node==NULL) return ;
//         flatten(node->right) ;
//         flatten(node->left)  ;
//         node->right = prev ;
//         node->left = NULL ;
//         prev = node ;
//     }
// };

// L-39

// LC - 00 INTRODUCTION TO BINARY SEARCH TREE
// tc of searching - O(log n )

// L-40

// LC - 700 SEARCH IN BST
// class Solution {
// public:
//     TreeNode* searchBST(TreeNode* root, int val) {
//         while(root!=NULL && root->val!= val)
//         {
//             root=val < root->val? root->left:root->right ;
//         }
//         return root ;
//     }
// };

// L-41

// LC - 00 CEIL IN BST
// find ceil()
// {
//         int ceil = -1 ;
//         while(root)
//         {
//                 if(root->data == key)
//                 {
//                         ceil = root->data ;
//                         return ceil ;
//                 }
//                 if(key > root->data) root = root->right ;
//                 else
//                 {
//                         ceil = root->data ;
//                         root = root->left ;
//                 }
//         }
//         return ceil ;
// }

// L-42

// LC - 00 FLOOR IN BST
// floor(root ,key)
// {
//         int floor = -1 ;
//         while(root)
//         {
//                 if(root->val == key) return key ;
//                 if(key> root->val)
//                 {
//                         floor = root->val ;
//                         root = root->right ;
//                 }
//                 else 
//                 {
//                         root = root->left;
//                 }
//         }
//         return floor ;
// }

// L-43

// LC - 401 INSERT GIVEN NODE 
// class Solution {
// public:
//     TreeNode* insertIntoBST(TreeNode* root, int val) {
//         if (root == NULL) 
//             return new TreeNode(val); // ✅ handle empty tree case
//         TreeNode* retroot = root;
//         TreeNode* temp = root;
//         while (temp != NULL) {   
//             root = temp;
//             if (temp->val > val)
//                 temp = temp->left;
//             else 
//                 temp = temp->right;
//         }
//         TreeNode* insert = new TreeNode(val);
//         if (root->val > val) 
//             root->left = insert;
//         else 
//             root->right = insert;
//         return retroot;
//     }
// };

// L-44

// LC -450 DELETE A GIVEN NODE
//  */class Solution {
// public:
//     TreeNode* deleteNode(TreeNode* root, int key) {
//         if (root == NULL) {
//             return NULL;
//         }
//         if (root->val == key) {
//             return helper(root);
//         }
//         TreeNode* dummy = root;
//         while (root != NULL) {
//             if (root->val > key) {
//                 if (root->left != NULL && root->left->val == key) {
//                     root->left = helper(root->left);
//                     break;
//                 } else {
//                     root = root->left;
//                 }
//             } else {
//                 if (root->right != NULL && root->right->val == key) {
//                     root->right = helper(root->right);
//                     break;
//                 } else {
//                     root = root->right;
//                 }
//             }
//         }
//         return dummy;
//     }
//     TreeNode* helper(TreeNode* root) {
//         if (root->left == NULL) {
//             return root->right;
//         } else if (root->right == NULL) {
//             return root->left;
//         }
//         TreeNode* rightChild = root->right;
//         TreeNode* lastRight = findLastRight(root->left);
//         lastRight->right = rightChild;
//         return root->left;
//     }
//     TreeNode* findLastRight(TreeNode* root) {
//         if (root->right == NULL) {
//             return root;
//         }
//         return findLastRight(root->right);
//     }
// };

// L-45

// LC -240 KTH SMALLEST / LARGEST ELEMENT 
// class Solution {
// public:
//     int kthSmallest(TreeNode* root, int k) {
//         stack<TreeNode*> st;
//         TreeNode* curr = root;
//         while (curr != nullptr || !st.empty()) {
//             // Go to the leftmost node
//             while (curr != nullptr) {
//                 st.push(curr);
//                 curr = curr->left;
//             }
//             curr = st.top(); 
//             st.pop();
//             // Decrease k when visiting a node
//             if (--k == 0) return curr->val;
//             // Move to right subtree
//             curr = curr->right;
//         }
//         return -1; // should never reach here if k is valid
//     }
// };

// L-46

// LC -98 CHECK IF TREE IS BST
// class Solution {
// public:
//     bool isValidBST(TreeNode* root) {
//         return isValidBST(root, LONG_MIN, LONG_MAX);
//     }
// private:
//     bool isValidBST(TreeNode* root, long minVal, long maxVal) {
//         if (root == nullptr) return true;
//         if (root->val <= minVal || root->val >= maxVal) return false;
//         return isValidBST(root->left, minVal, root->val) &&
//                isValidBST(root->right, root->val, maxVal);
//     }
// };

// L-47

// LC -235 LCA IN BST
// class Solution {
// public:
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         if(root==NULL) return NULL ;
//         int  curr = root->val  ;
//         if(curr < p->val && curr < q->val)
//             return lowestCommonAncestor(root->right,p,q) ;
//         if(curr > p->val && curr > q->val)
//             return lowestCommonAncestor(root->left,p,q) ; 
//             return root ;
//     }
// };

// L-48

// LC -00 CONSTRUCT A BST
// TreeNode* bst(vector<int> A)
// {
//         int i =0;
//         return build(A,i,INT_MAX) ;
// }
// TreeNode* build(vector<int>& A,int& i,int& bound)
// {       
//         if(i==A.size() || A[i] > bound) return NULL ;
//         TreeNode* root=new TreeNode(a[i++]) ;
//         root->left = build(A,i,root->val) ;
//         root->right = build(A,i,bound) ;
//         return root ;
// }

// L-49

// LC -00 INORDER SUCCESSOR / PREDESESSOR
// TreeNode* inorder_successor(TreeNode* root,TreeNode* p)
// {
//         TreeNode* succesor = NULL ;
//         while(root!=NULL)
//         {
//                 if(p->val >= root->val ) 
//                         root = root->right ;// never be successor on left
//                 else{
//                         succesor = root ;
//                         root = root->left;
//                                 }
//         }
//         return successor ;
// }

// L-50

// LC -173  BST ITERATOR
// class BSTIterator {
// public:
// stack<TreeNode*> st ;
//     BSTIterator(TreeNode* root) {
//         pushALL(root) ;
//     }
// // return next smallest number 
//     int next() {
//         TreeNode* x = st.top() ;
//         st.pop() ;
//         pushALL(x->right) ;
//         return x->val ;
//     }
// // next element exists or not    
//     bool hasNext() {
//         return !st.empty() ;
//     }
// void pushALL(TreeNode* node)
// {
//     while(node != NULL) {
//     st.push(node);
//     node = node->left;
// }
// }
// };

// L-51

// LC -653 TWO SUM IN BST
// class Solution {
// public:
// vector<int> inorder ;
// void traversal(TreeNode* root )
// {
//     if(root==NULL) return ;
//     traversal(root->left) ;
//     inorder.push_back(root->val) ;
//     traversal(root->right) ;
//     return ;
// }
// bool ans(int k)
// {   int sum =0 ; int i=0;int j = inorder.size() -1 ;
//     while(i<j)
//     {
//         sum = inorder[i] + inorder[j] ;
//         if(sum == k) return true ;
//         else if(sum > k) j--;
//         else i++ ;
//     }
//     return false ;
// }
//     bool findTarget(TreeNode* root, int k) {
//         traversal(root) ;
//         return ans(k) ;
//     }
// };

// L-52

// LC -99 RECOVER BST 
// class Solution {
// public:
// TreeNode* first ;
// TreeNode* middle ;
// TreeNode* last ;
// TreeNode* prev ;
// void inorder(TreeNode* root)
// {
//     if(root == NULL) return  ;
//     inorder(root->left ) ;
//     if(prev!=NULL && (root->val < prev->val))
//     {
//         // if first violation
//         if(first == NULL){
//             first = prev ;
//             middle = root ;
//         }
//         // second violation
//         else last = root ;
//     } 
//     prev = root ;
//     inorder(root->right) ;
// }
//     void recoverTree(TreeNode* root) {
//         first = middle=last= NULL ;
//         prev = new TreeNode(INT_MIN) ;
//         inorder(root) ;
//         if(first && last) swap(first->val , last->val) ;
//         else if(first && middle) swap(first->val,middle->val) ;
//     }
// };

// L-53

// LC -00 LARGEST BST 




